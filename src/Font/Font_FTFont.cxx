// Created on: 2013-01-28
// Created by: Kirill GAVRILOV
// Copyright (c) 2013-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#include <Font_FTFont.hxx>

#include <Font_FTLibrary.hxx>
#include <Font_FontMgr.hxx>
#include <Font_TextFormatter.hxx>

#include <ft2build.h>
#include FT_FREETYPE_H

IMPLEMENT_STANDARD_RTTIEXT(Font_FTFont,Standard_Transient)

// =======================================================================
// function : Font_FTFont
// purpose  :
// =======================================================================
Font_FTFont::Font_FTFont (const Handle(Font_FTLibrary)& theFTLib)
: myFTLib       (theFTLib),
  myFTFace      (NULL),
  myPointSize   (0U),
  myWidthScaling(1.0),
  myLoadFlags   (FT_LOAD_NO_HINTING | FT_LOAD_TARGET_NORMAL),
  myIsSingleLine(false),
  myUChar       (0U)
{
  if (myFTLib.IsNull())
  {
    myFTLib = new Font_FTLibrary();
  }
}

// =======================================================================
// function : Font_FTFont
// purpose  :
// =======================================================================
Font_FTFont::~Font_FTFont()
{
  Release();
}

// =======================================================================
// function : Release
// purpose  :
// =======================================================================
void Font_FTFont::Release()
{
  myGlyphImg.Clear();
  myFontPath.Clear();
  myUChar = 0;
  if (myFTFace != NULL)
  {
    FT_Done_Face (myFTFace);
    myFTFace = NULL;
  }
}

// =======================================================================
// function : Init
// purpose  :
// =======================================================================
bool Font_FTFont::Init (const NCollection_String& theFontPath,
                        const unsigned int        thePointSize,
                        const unsigned int        theResolution)
{
  Release();
  myFontPath  = theFontPath;
  myPointSize = thePointSize;
  if (!myFTLib->IsValid())
  {
    //std::cerr << "FreeType library is unavailable!\n";
    Release();
    return false;
  }

  if (FT_New_Face (myFTLib->Instance(), myFontPath.ToCString(), 0, &myFTFace) != 0)
  {
    //std::cerr << "Font '" << myFontPath << "' fail to load!\n";
    Release();
    return false;
  }
  else if (FT_Select_Charmap (myFTFace, ft_encoding_unicode) != 0)
  {
    //std::cerr << "Font '" << myFontPath << "' doesn't contains Unicode charmap!\n";
    Release();
    return false;
  }
  else if (FT_Set_Char_Size (myFTFace, 0L, toFTPoints (thePointSize), theResolution, theResolution) != 0)
  {
    //std::cerr << "Font '" << myFontPath << "' doesn't contains Unicode charmap!\n";
    Release();
    return false;
  }
  return true;
}

// =======================================================================
// function : Init
// purpose  :
// =======================================================================
bool Font_FTFont::Init (const NCollection_String& theFontName,
                        const Font_FontAspect     theFontAspect,
                        const unsigned int        thePointSize,
                        const unsigned int        theResolution)
{
  Handle(Font_FontMgr) aFontMgr = Font_FontMgr::GetInstance();
  const Handle(TCollection_HAsciiString) aFontName = new TCollection_HAsciiString (theFontName.ToCString());
  if (Handle(Font_SystemFont) aRequestedFont = aFontMgr->FindFont (aFontName, theFontAspect, thePointSize))
  {
    myIsSingleLine = aRequestedFont->IsSingleStrokeFont();
    return Font_FTFont::Init (aRequestedFont->FontPath()->ToCString(), thePointSize, theResolution);
  }
  return false;
}

// =======================================================================
// function : loadGlyph
// purpose  :
// =======================================================================
bool Font_FTFont::loadGlyph (const Standard_Utf32Char theUChar)
{
  if (myUChar == theUChar)
  {
    return myUChar != 0;
  }

  myGlyphImg.Clear();
  myUChar = 0;
  if (theUChar == 0
   || FT_Load_Char (myFTFace, theUChar, FT_Int32(myLoadFlags)) != 0
   || myFTFace->glyph == NULL)
  {
    return false;
  }

  myUChar = theUChar;
  return true;
}

// =======================================================================
// function : RenderGlyph
// purpose  :
// =======================================================================
bool Font_FTFont::RenderGlyph (const Standard_Utf32Char theUChar)
{
  myGlyphImg.Clear();
  myUChar = 0;
  if (theUChar == 0
   || FT_Load_Char (myFTFace, theUChar, FT_Int32(myLoadFlags | FT_LOAD_RENDER)) != 0
   || myFTFace->glyph == NULL
   || myFTFace->glyph->format != FT_GLYPH_FORMAT_BITMAP)
  {
    return false;
  }

  FT_Bitmap aBitmap = myFTFace->glyph->bitmap;
  if (aBitmap.pixel_mode != FT_PIXEL_MODE_GRAY
   || aBitmap.buffer == NULL || aBitmap.width == 0 || aBitmap.rows == 0)
  {
    return false;
  }
  if (!myGlyphImg.InitWrapper (Image_Format_Alpha, aBitmap.buffer,
                               aBitmap.width, aBitmap.rows, Abs (aBitmap.pitch)))
  {
    return false;
  }
  myGlyphImg.SetTopDown (aBitmap.pitch > 0);
  myUChar = theUChar;
  return true;
}

// =======================================================================
// function : GlyphMaxSizeX
// purpose  :
// =======================================================================
unsigned int Font_FTFont::GlyphMaxSizeX() const
{
  float aWidth = (FT_IS_SCALABLE(myFTFace) != 0)
               ? float(myFTFace->bbox.xMax - myFTFace->bbox.xMin) * (float(myFTFace->size->metrics.x_ppem) / float(myFTFace->units_per_EM))
               : fromFTPoints<float> (myFTFace->size->metrics.max_advance);
  return (unsigned int)(aWidth + 0.5f);
}

// =======================================================================
// function : GlyphMaxSizeY
// purpose  :
// =======================================================================
unsigned int Font_FTFont::GlyphMaxSizeY() const
{
  float aHeight = (FT_IS_SCALABLE(myFTFace) != 0)
                ? float(myFTFace->bbox.yMax - myFTFace->bbox.yMin) * (float(myFTFace->size->metrics.y_ppem) / float(myFTFace->units_per_EM))
                : fromFTPoints<float> (myFTFace->size->metrics.height);
  return (unsigned int)(aHeight + 0.5f);
}

// =======================================================================
// function : Ascender
// purpose  :
// =======================================================================
float Font_FTFont::Ascender() const
{
  return float(myFTFace->ascender) * (float(myFTFace->size->metrics.y_ppem) / float(myFTFace->units_per_EM));
}

// =======================================================================
// function : Descender
// purpose  :
// =======================================================================
float Font_FTFont::Descender() const
{
  return float(myFTFace->descender) * (float(myFTFace->size->metrics.y_ppem) / float(myFTFace->units_per_EM));
}

// =======================================================================
// function : LineSpacing
// purpose  :
// =======================================================================
float Font_FTFont::LineSpacing() const
{
  return float(myFTFace->height) * (float(myFTFace->size->metrics.y_ppem) / float(myFTFace->units_per_EM));
}

// =======================================================================
// function : AdvanceX
// purpose  :
// =======================================================================
float Font_FTFont::AdvanceX (Standard_Utf32Char theUChar,
                             Standard_Utf32Char theUCharNext)
{
  loadGlyph (theUChar);
  return AdvanceX (theUCharNext);
}

// =======================================================================
// function : AdvanceY
// purpose  :
// =======================================================================
float Font_FTFont::AdvanceY (Standard_Utf32Char theUChar,
                             Standard_Utf32Char theUCharNext)
{
  loadGlyph (theUChar);
  return AdvanceY (theUCharNext);
}

bool Font_FTFont::getKerning (FT_Vector& theKern,
                              Standard_Utf32Char theUCharCurr,
                              Standard_Utf32Char theUCharNext) const
{
  theKern.x = 0;
  theKern.y = 0;
  if (theUCharNext != 0 && FT_HAS_KERNING(myFTFace) != 0)
  {
    const FT_UInt aCharCurr = FT_Get_Char_Index (myFTFace, theUCharCurr);
    const FT_UInt aCharNext = FT_Get_Char_Index (myFTFace, theUCharNext);
    if (aCharCurr == 0 || aCharNext == 0
     || FT_Get_Kerning (myFTFace, aCharCurr, aCharNext, FT_KERNING_UNFITTED, &theKern) != 0)
    {
      theKern.x = 0;
      theKern.y = 0;
      return false;
    }
    return true;
  }
  return false;
}

// =======================================================================
// function : AdvanceX
// purpose  :
// =======================================================================
float Font_FTFont::AdvanceX (Standard_Utf32Char theUCharNext) const
{
  if (myUChar == 0)
  {
    return 0.0f;
  }

  FT_Vector aKern;
  getKerning (aKern, myUChar, theUCharNext);
  return myWidthScaling * fromFTPoints<float> (myFTFace->glyph->advance.x + aKern.x);
}

// =======================================================================
// function : AdvanceY
// purpose  :
// =======================================================================
float Font_FTFont::AdvanceY (Standard_Utf32Char theUCharNext) const
{
  if (myUChar == 0)
  {
    return 0.0f;
  }

  FT_Vector aKern;
  getKerning (aKern, myUChar, theUCharNext);
  return fromFTPoints<float> (myFTFace->glyph->advance.y + aKern.y);
}

// =======================================================================
// function : GlyphsNumber
// purpose  :
// =======================================================================
Standard_Integer Font_FTFont::GlyphsNumber() const
{
  return myFTFace->num_glyphs;
}

// =======================================================================
// function : theRect
// purpose  :
// =======================================================================
void Font_FTFont::GlyphRect (Font_Rect& theRect) const
{
  const FT_Bitmap& aBitmap = myFTFace->glyph->bitmap;
  theRect.Left   = float(myFTFace->glyph->bitmap_left);
  theRect.Top    = float(myFTFace->glyph->bitmap_top);
  theRect.Right  = float(myFTFace->glyph->bitmap_left + (int )aBitmap.width);
  theRect.Bottom = float(myFTFace->glyph->bitmap_top  - (int )aBitmap.rows);
}

// =======================================================================
// function : BoundingBox
// purpose  :
// =======================================================================
Font_Rect Font_FTFont::BoundingBox (const NCollection_String&               theString,
                                    const Graphic3d_HorizontalTextAlignment theAlignX,
                                    const Graphic3d_VerticalTextAlignment   theAlignY)
{
  Font_TextFormatter aFormatter;
  aFormatter.SetupAlignment (theAlignX, theAlignY);
  aFormatter.Reset();

  aFormatter.Append (theString, *this);
  aFormatter.Format();

  Font_Rect aBndBox;
  aFormatter.BndBox (aBndBox);
  return aBndBox;
}
