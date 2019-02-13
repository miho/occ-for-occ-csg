// Created on: 2015-12-15
// Created by: Varvara POSKONINA
// Copyright (c) 2005-2014 OPEN CASCADE SAS
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

#ifndef _SelectMgr_ViewClipRange_HeaderFile
#define _SelectMgr_ViewClipRange_HeaderFile

#include <Bnd_Range.hxx>
#include <Standard_TypeDef.hxx>

//! Class for handling depth clipping range.
//! It is used to perform checks in case if global (for the whole view)
//! clipping planes are defined inside of SelectMgr_RectangularFrustum class methods.
class SelectMgr_ViewClipRange
{
public:
  //! Creates an empty clip range.
  SelectMgr_ViewClipRange()
  {
    SetVoid();
  }

  //! Check if the given depth is not within clipping range(s),
  //! e.g. TRUE means depth is clipped.
  Standard_Boolean IsClipped (const Standard_Real theDepth) const
  {
    if (myUnclipRange.IsOut (theDepth))
    {
      return Standard_True;
    }
    for (size_t aRangeIter = 0; aRangeIter < myClipRanges.size(); ++aRangeIter)
    {
      if (!myClipRanges[aRangeIter].IsOut (theDepth))
      {
        return Standard_True;
      }
    }
    return Standard_False;
  }

  //! Clears clipping range.
  void SetVoid()
  {
    myClipRanges.resize (0);
    myUnclipRange = Bnd_Range (RealFirst(), RealLast());
  }

  //! Returns the main unclipped range; [-inf, inf] by default.
  Bnd_Range& ChangeUnclipRange() { return myUnclipRange; }

  //! Adds a clipping sub-range (for clipping chains).
  void AddClipSubRange (const Bnd_Range& theRange) { myClipRanges.push_back (theRange); }

private:

  std::vector<Bnd_Range> myClipRanges;
  Bnd_Range myUnclipRange;

};

#endif // _SelectMgr_ViewClipRange_HeaderFile
