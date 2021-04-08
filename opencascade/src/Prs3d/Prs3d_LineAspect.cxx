// Copyright (c) 1995-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
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

#include <Prs3d_LineAspect.hxx>

#include <Standard_Dump.hxx>

IMPLEMENT_STANDARD_RTTIEXT(Prs3d_LineAspect, Prs3d_BasicAspect)

// =======================================================================
// function : Prs3d_LineAspect
// purpose  :
// =======================================================================
Prs3d_LineAspect::Prs3d_LineAspect (const Quantity_Color& theColor,
                                    const Aspect_TypeOfLine theType,
                                    const Standard_Real theWidth)
: myAspect (new Graphic3d_AspectLine3d (theColor, theType, theWidth))
{
  //
}

// =======================================================================
// function : DumpJson
// purpose  :
// =======================================================================
void Prs3d_LineAspect::DumpJson (Standard_OStream& theOStream, Standard_Integer theDepth) const
{
  OCCT_DUMP_TRANSIENT_CLASS_BEGIN (theOStream)
  OCCT_DUMP_FIELD_VALUES_DUMPED (theOStream, theDepth, myAspect.get())
}
