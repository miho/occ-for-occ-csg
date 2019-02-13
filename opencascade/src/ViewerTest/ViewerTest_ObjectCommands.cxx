// Created on: 1998-11-12
// Created by: Robert COUBLANC
// Copyright (c) 1998-1999 Matra Datavision
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

#include <ViewerTest.hxx>

#include <AIS_PlaneTrihedron.hxx>

#include <Quantity_NameOfColor.hxx>
#include <Draw_Interpretor.hxx>
#include <Draw.hxx>
#include <Draw_Appli.hxx>
#include <DBRep.hxx>
#include <DBRep_DrawableShape.hxx>

#include <Font_BRepFont.hxx>
#include <Font_BRepTextBuilder.hxx>
#include <Font_FontMgr.hxx>

#include <NCollection_List.hxx>

#include <OSD_Chronometer.hxx>
#include <TCollection_AsciiString.hxx>
#include <V3d_Viewer.hxx>
#include <V3d_View.hxx>
#include <V3d.hxx>

#include <AIS_Shape.hxx>
#include <AIS_DisplayMode.hxx>
#include <AIS_PointCloud.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <AIS_MapOfInteractive.hxx>
#include <ViewerTest_AutoUpdater.hxx>
#include <ViewerTest_DoubleMapOfInteractiveAndName.hxx>
#include <ViewerTest_DoubleMapIteratorOfDoubleMapOfInteractiveAndName.hxx>
#include <ViewerTest_EventManager.hxx>

#include <TopoDS_Solid.hxx>
#include <BRepTools.hxx>
#include <BRep_Builder.hxx>
#include <TopAbs_ShapeEnum.hxx>

#include <TopoDS.hxx>
#include <BRep_Tool.hxx>
#include <TopExp_Explorer.hxx>

#include <BRepAdaptor_Curve.hxx>
#include <BRepAdaptor_Surface.hxx>

#include <TopAbs.hxx>
#include <TopExp.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>

#include <Draw_Window.hxx>
#include <AIS_ListIteratorOfListOfInteractive.hxx>
#include <AIS_ListOfInteractive.hxx>
#include <AIS_ColoredShape.hxx>
#include <AIS_DisplayMode.hxx>
#include <AIS_Shape.hxx>

#include <AIS_InteractiveContext.hxx>
#include <Geom_Plane.hxx>
#include <gp_Pln.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_HAsciiString.hxx>
#include <GC_MakePlane.hxx>
#include <gp_Circ.hxx>
#include <AIS_Axis.hxx>
#include <Geom_Axis2Placement.hxx>
#include <Geom_Axis1Placement.hxx>
#include <AIS_Trihedron.hxx>
#include <AIS_Axis.hxx>
#include <gp_Trsf.hxx>
#include <gp_Quaternion.hxx>
#include <TopLoc_Location.hxx>

#include <HLRAlgo_Projector.hxx>
#include <HLRBRep_Algo.hxx>
#include <HLRBRep_PolyAlgo.hxx>
#include <HLRBRep_PolyHLRToShape.hxx>
#include <HLRBRep_HLRToShape.hxx>
#include <Aspect_Window.hxx>

#include <Graphic3d_ArrayOfPoints.hxx>
#include <Graphic3d_ArrayOfSegments.hxx>
#include <Graphic3d_ArrayOfPolylines.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <Graphic3d_ArrayOfTriangleFans.hxx>
#include <Graphic3d_ArrayOfTriangleStrips.hxx>
#include <Graphic3d_ArrayOfQuadrangles.hxx>
#include <Graphic3d_ArrayOfQuadrangleStrips.hxx>
#include <Graphic3d_ArrayOfPolygons.hxx>
#include <Graphic3d_AttribBuffer.hxx>
#include <Graphic3d_AspectMarker3d.hxx>
#include <Graphic3d_Group.hxx>
#include <Standard_Real.hxx>

#include <AIS_Circle.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <Geom_Circle.hxx>
#include <GC_MakeCircle.hxx>
#include <Select3D_SensitiveCircle.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <SelectMgr_Selection.hxx>
#include <StdFail_NotDone.hxx>
#include <StdPrs_ShadedShape.hxx>
#include <TopoDS_Wire.hxx>

#include <AIS_MultipleConnectedInteractive.hxx>
#include <AIS_ConnectedInteractive.hxx>
#include <AIS_TextLabel.hxx>
#include <TopLoc_Location.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TColStd_ListIteratorOfListOfInteger.hxx>

#include <Select3D_SensitiveSegment.hxx>
#include <Select3D_SensitivePrimitiveArray.hxx>
#include <Select3D_SensitiveTriangle.hxx>
#include <Select3D_SensitiveCurve.hxx>
#include <Select3D_SensitivePoint.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <StdPrs_Curve.hxx>

#include <BRepExtrema_ExtPC.hxx>
#include <BRepExtrema_ExtPF.hxx>

#include <Prs3d_Arrow.hxx>
#include <Prs3d_ArrowAspect.hxx>
#include <Prs3d_DatumAttribute.hxx>
#include <Prs3d_DatumAspect.hxx>
#include <Prs3d_Drawer.hxx>
#include <Prs3d_VertexDrawMode.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Prs3d_PointAspect.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_TextAspect.hxx>

#include <Image_AlienPixMap.hxx>
#include <TColStd_HArray1OfAsciiString.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>

extern ViewerTest_DoubleMapOfInteractiveAndName& GetMapOfAIS();
extern Standard_Boolean VDisplayAISObject (const TCollection_AsciiString& theName,
                                           const Handle(AIS_InteractiveObject)& theAISObj,
                                           Standard_Boolean theReplaceIfExists = Standard_True);
extern int ViewerMainLoop(Standard_Integer argc, const char** argv);
extern Handle(AIS_InteractiveContext)& TheAISContext();

namespace
{
  static bool convertToColor (const Handle(TColStd_HSequenceOfAsciiString)& theColorValues,
                              Quantity_Color& theColor)
  {
    const char* anArgs[3] =
    {
      theColorValues->Size() >= 1 ? theColorValues->Value (1).ToCString() : "",
      theColorValues->Size() >= 2 ? theColorValues->Value (2).ToCString() : "",
      theColorValues->Size() >= 3 ? theColorValues->Value (3).ToCString() : ""
    };
    return ViewerTest::ParseColor (theColorValues->Size(), anArgs, theColor) != 0;
  }

  static bool convertToDatumPart (const TCollection_AsciiString& theValue,
                                  Prs3d_DatumParts& theDatumPart)
  {
    TCollection_AsciiString aValue = theValue;
    aValue.LowerCase();
    if      (aValue == "origin")  theDatumPart = Prs3d_DP_Origin;
    else if (aValue == "xaxis")   theDatumPart = Prs3d_DP_XAxis;
    else if (aValue == "yaxis")   theDatumPart = Prs3d_DP_YAxis;
    else if (aValue == "zaxis")   theDatumPart = Prs3d_DP_ZAxis;
    else if (aValue == "xarrow")  theDatumPart = Prs3d_DP_XArrow;
    else if (aValue == "yarrow")  theDatumPart = Prs3d_DP_YArrow;
    else if (aValue == "zarrow")  theDatumPart = Prs3d_DP_ZArrow;
    else if (aValue == "xoyaxis") theDatumPart = Prs3d_DP_XOYAxis;
    else if (aValue == "yozaxis") theDatumPart = Prs3d_DP_YOZAxis;
    else if (aValue == "xozaxis") theDatumPart = Prs3d_DP_XOZAxis;
    else if (aValue == "whole")   theDatumPart = Prs3d_DP_None;
    else
    {
      return false;
    }
    return true;
  }

  static void convertToDatumParts (const TCollection_AsciiString& theValue,
                                   NCollection_List<Prs3d_DatumParts>& theParts)
  {
    TCollection_AsciiString aValue = theValue;
    const Standard_Integer aSplitPos = theValue.Search ("|");
    Prs3d_DatumParts aPart = Prs3d_DP_None;
    if (aSplitPos > 0)
    {
      convertToDatumParts (theValue.SubString (aSplitPos + 1, theValue.Length()), theParts);
      if (aSplitPos == 1) // first symbol
      {
        return;
      }
      aValue = theValue.SubString (1, aSplitPos - 1);
    }
    if (convertToDatumPart (aValue, aPart))
    {
      theParts.Append (aPart);
    }
  }

  static bool convertToDatumAttribute (const TCollection_AsciiString& theValue,
                                       Prs3d_DatumAttribute& theAttribute)
  {
    TCollection_AsciiString aValue = theValue;
    aValue.LowerCase();
    if      (aValue == "xaxislength")       theAttribute = Prs3d_DA_XAxisLength;
    else if (aValue == "yaxislength")       theAttribute = Prs3d_DA_YAxisLength;
    else if (aValue == "zaxislength")       theAttribute = Prs3d_DA_ZAxisLength;
    else if (aValue == "tuberadiuspercent") theAttribute = Prs3d_DP_ShadingTubeRadiusPercent;
    else if (aValue == "coneradiuspercent") theAttribute = Prs3d_DP_ShadingConeRadiusPercent;
    else if (aValue == "conelengthpercent") theAttribute = Prs3d_DP_ShadingConeLengthPercent;
    else if (aValue == "originradiuspercent") theAttribute = Prs3d_DP_ShadingOriginRadiusPercent;
    else if (aValue == "shadingnumberoffacettes") theAttribute = Prs3d_DP_ShadingNumberOfFacettes;
    else
      return false;
    return true;
  }

  static void convertToDatumAttributes (const TCollection_AsciiString& theValue,
                                        NCollection_List<Prs3d_DatumAttribute>& theAttributes)
  {
    TCollection_AsciiString aValue = theValue;
    const Standard_Integer aSplitPos = theValue.Search ("|");
    Prs3d_DatumAttribute anAttribute = Prs3d_DA_XAxisLength;
    if (aSplitPos > 0)
    {
      convertToDatumAttributes (theValue.SubString (aSplitPos + 1, theValue.Length()), theAttributes);
      if (aSplitPos == 1) // first symbol
      {
        return;
      }
      aValue = theValue.SubString (1, aSplitPos - 1);
    }
    if (convertToDatumAttribute (aValue, anAttribute))
    {
      theAttributes.Append (anAttribute);
    }
  }

  static bool convertToDatumAxes (const TCollection_AsciiString& theValue,
                                  Prs3d_DatumAxes& theDatumAxes)
  {
    TCollection_AsciiString aValue = theValue;
    aValue.LowerCase();
    if      (aValue == "x")   theDatumAxes = Prs3d_DA_XAxis;
    else if (aValue == "y")   theDatumAxes = Prs3d_DA_YAxis;
    else if (aValue == "z")   theDatumAxes = Prs3d_DA_ZAxis;
    else if (aValue == "xy")  theDatumAxes = Prs3d_DA_XYAxis;
    else if (aValue == "zy")  theDatumAxes = Prs3d_DA_YZAxis;
    else if (aValue == "xz")  theDatumAxes = Prs3d_DA_XZAxis;
    else if (aValue == "xyz") theDatumAxes = Prs3d_DA_XYZAxis;
    else
    {
      return false;
    }
    return true;
  }

  static Standard_Boolean setTrihedronParams (Standard_Integer  theArgsNb,
                                              const char** theArgVec,
                                              Handle(AIS_Trihedron) theTrihedron)
  {
    NCollection_DataMap<TCollection_AsciiString, Handle(TColStd_HSequenceOfAsciiString)> aMapOfArgs;
    TCollection_AsciiString aParseKey;
    for (Standard_Integer anArgIt = 1; anArgIt < theArgsNb; ++anArgIt)
    {
      TCollection_AsciiString anArg (theArgVec [anArgIt]);
      if (anArg.Value (1) == '-'
      && !anArg.IsRealValue())
      {
        aParseKey = anArg;
        aParseKey.Remove (1);
        aParseKey.LowerCase();
        std::string aKey = aParseKey.ToCString();
        aMapOfArgs.Bind (aParseKey, new TColStd_HSequenceOfAsciiString());
        continue;
      }

      if (aParseKey.IsEmpty())
      {
        continue;
      }

      aMapOfArgs (aParseKey)->Append (anArg);
    }

    // Check parameters
    if ((aMapOfArgs.IsBound ("xaxis") && !aMapOfArgs.IsBound ("zaxis"))
    || (!aMapOfArgs.IsBound ("xaxis") &&  aMapOfArgs.IsBound ("zaxis")))
    {
      std::cout << "Syntax error: -xaxis and -zaxis parameters are to set together.\n";
      return Standard_False;
    }

    Handle(TColStd_HSequenceOfAsciiString) aValues;
    Handle(Geom_Axis2Placement) aComponent = theTrihedron->Component();
    if (aMapOfArgs.Find ("origin", aValues))
    {
      aComponent->SetLocation (gp_Pnt (aValues->Value (1).RealValue(),
                                       aValues->Value (2).RealValue(),
                                       aValues->Value (3).RealValue()));
    }
    Handle(TColStd_HSequenceOfAsciiString) aXValues, aZValues;
    if (aMapOfArgs.Find ("xaxis", aXValues) && aMapOfArgs.Find ("zaxis", aZValues))
    {
      gp_Dir aXDir (aXValues->Value (1).RealValue(),
                    aXValues->Value (2).RealValue(),
                    aXValues->Value (3).RealValue());

      gp_Dir aZDir (aZValues->Value (1).RealValue(),
                    aZValues->Value (2).RealValue(),
                    aZValues->Value (3).RealValue());

      if (!aZDir.IsNormal (aXDir, M_PI / 180.0))
      {
        std::cout << "Syntax error - parameters 'xaxis' and 'zaxis' are not applied as VectorX is not normal to VectorZ\n";
        return Standard_False;
      }

      aComponent->SetAx2 (gp_Ax2 (aComponent->Location(), aZDir, aXDir));
    }

    if (aMapOfArgs.Find ("dispmode", aValues))
    {
      TCollection_AsciiString aValue (aValues->Value (1));
      bool isWireframe = true;
      if (aValue.IsEqual ("sh") || aValue.IsEqual ("shading"))
        isWireframe = false;
      theTrihedron->SetDatumDisplayMode (isWireframe ? Prs3d_DM_WireFrame
                                                     : Prs3d_DM_Shaded);
    }

    if (aMapOfArgs.Find ("hidelabels", aValues))
    {
      Standard_Boolean toHideLabels = Standard_True;
      if (aValues->Size() == 1)
      {
        ViewerTest::ParseOnOff (aValues->First().ToCString(), toHideLabels);
      }
      else if (aValues->Size() != 0)
      {
        std::cout << "Syntax error: -hidelabels expects parameter 'on' or 'off' after.\n";
        return Standard_False;
      }

      if (!theTrihedron->Attributes()->HasOwnDatumAspect())
      {
        theTrihedron->Attributes()->SetDatumAspect (new Prs3d_DatumAspect());
      }
      theTrihedron->Attributes()->DatumAspect()->SetDrawLabels (!toHideLabels);
    }

    if (aMapOfArgs.Find ("hidearrows", aValues))
    {
      Standard_Boolean toHideArrows = Standard_True;
      if (aValues->Size() == 1)
      {
        ViewerTest::ParseOnOff (aValues->First().ToCString(), toHideArrows);
      }
      else if (aValues->Size() != 0)
      {
        std::cout << "Syntax error: -hidearrows expects parameter 'on' or 'off' after.\n";
        return Standard_False;
      }

      if (!theTrihedron->Attributes()->HasOwnDatumAspect())
      {
        theTrihedron->Attributes()->SetDatumAspect (new Prs3d_DatumAspect());
      }
      theTrihedron->Attributes()->DatumAspect()->SetDrawArrows (!toHideArrows);
    }

    if (aMapOfArgs.Find ("color", aValues))
    {
      NCollection_List<Prs3d_DatumParts> aParts;
      if (aValues->Size() < 2)
      {
        std::cout << "Syntax error: -color wrong parameters.\n";
        return Standard_False;
      }

      convertToDatumParts (aValues->Value(1), aParts);
      aValues->Remove (1); // datum part is processed
      Quantity_Color aColor;
      if (!convertToColor (aValues, aColor))
      {
        std::cout << "Syntax error: -color wrong parameters.\n";
        return Standard_False;
      }

      for (NCollection_List<Prs3d_DatumParts>::Iterator anIterator (aParts); anIterator.More(); anIterator.Next())
      {
        Prs3d_DatumParts aDatumPart = anIterator.Value();
        if (aDatumPart == Prs3d_DP_None)
        {
          theTrihedron->SetColor (aColor);
        }
        else
        {
          theTrihedron->SetDatumPartColor (aDatumPart, aColor);
        }
      }
    }

    if (aMapOfArgs.Find ("textcolor", aValues))
    {
      Quantity_Color aColor;
      if (!convertToColor (aValues, aColor))
      {
        std::cout << "Syntax error: -textcolor wrong parameters.\n";
        return Standard_False;
      }
      theTrihedron->SetTextColor (aColor);
    }

    if (aMapOfArgs.Find ("arrowcolor", aValues))
    {
      Quantity_Color aColor;
      if (!convertToColor (aValues, aColor))
      {
        std::cout << "Syntax error: -arrowcolor wrong parameters.\n";
        return Standard_False;
      }
      theTrihedron->SetArrowColor (aColor);
    }

    if (aMapOfArgs.Find ("attribute", aValues))
    {
      NCollection_List<Prs3d_DatumAttribute> anAttributes;
      if (aValues->Size() != 2)
      {
        std::cout << "Syntax error: -attribute wrong parameters.\n";
        return Standard_False;
      }

      convertToDatumAttributes (aValues->Value (1), anAttributes);
      if (!theTrihedron->Attributes()->HasOwnDatumAspect())
        theTrihedron->Attributes()->SetDatumAspect(new Prs3d_DatumAspect());
      for (NCollection_List<Prs3d_DatumAttribute>::Iterator anIterator (anAttributes); anIterator.More(); anIterator.Next())
      {
        theTrihedron->Attributes()->DatumAspect()->SetAttribute (anIterator.Value(), aValues->Value (2).RealValue());
      }
    }

    if (aMapOfArgs.Find ("priority", aValues))
    {
      Prs3d_DatumParts aDatumPart;
      if (aValues->Size() < 2
      || !convertToDatumPart (aValues->Value (1), aDatumPart))
      {
        std::cout << "Syntax error: -priority wrong parameters.\n";
        return Standard_False;
      }
      theTrihedron->SetSelectionPriority (aDatumPart, aValues->Value (2).IntegerValue());
    }

    if (aMapOfArgs.Find ("labels", aValues)
     || aMapOfArgs.Find ("label", aValues))
    {
      Prs3d_DatumParts aDatumPart = Prs3d_DP_None;
      if (aValues->Size() >= 2
       && convertToDatumPart(aValues->Value(1), aDatumPart)
       && aDatumPart >= Prs3d_DP_XAxis
       && aDatumPart <= Prs3d_DP_ZAxis) // labels are set to axes only
      {
        theTrihedron->SetLabel (aDatumPart, aValues->Value (2));
      }
      else
      {
        std::cout << "Syntax error: -labels wrong parameters.\n";
        return Standard_False;
      }
    }

    if (aMapOfArgs.Find ("drawaxes", aValues))
    {
      Prs3d_DatumAxes aDatumAxes = Prs3d_DA_XAxis;
      if (aValues->Size() < 1
      || !convertToDatumAxes (aValues->Value (1), aDatumAxes))
      {
        std::cout << "Syntax error: -drawaxes wrong parameters.\n";
        return Standard_False;
      }
      if (!theTrihedron->Attributes()->HasOwnDatumAspect())
        theTrihedron->Attributes()->SetDatumAspect(new Prs3d_DatumAspect());
      theTrihedron->Attributes()->DatumAspect()->SetDrawDatumAxes (aDatumAxes);
    }
    return Standard_True;
  }

  //! Auxiliary function to parse font aspect style argument
  static Standard_Boolean parseFontStyle (const TCollection_AsciiString& theArg,
                                          Font_FontAspect&               theAspect)
  {
    if (theArg == "regular"
     || *theArg.ToCString() == 'r')
    {
      theAspect = Font_FA_Regular;
      return Standard_True;
    }
    else if (theArg == "bolditalic"
          || theArg == "bold-italic"
          || theArg == "italic-bold"
          || theArg == "italicbold")
    {
      theAspect = Font_FA_BoldItalic;
      return Standard_True;
    }
    else if (theArg == "bold"
          || *theArg.ToCString() == 'b')
    {
      theAspect = Font_FA_Bold;
      return Standard_True;
    }
    else if (theArg == "italic"
          || *theArg.ToCString() == 'i')
    {
      theAspect = Font_FA_Italic;
      return Standard_True;
    }
    return Standard_False;
  }
}

//==============================================================================
//function : Vtrihedron 2d
//purpose  : Create a plane with a 2D  trihedron from a faceselection
//Draw arg : vtri2d  name
//==============================================================================
static int VTrihedron2D (Draw_Interpretor& /*theDI*/,
                         Standard_Integer  theArgsNum,
                         const char**      theArgVec)
{
  if (theArgsNum != 2)
  {
    std::cerr << theArgVec[0]<< " error.\n";
    return 1;
  }

  TopTools_ListOfShape aShapes;
  ViewerTest::GetSelectedShapes (aShapes);

  if (aShapes.Extent() != 1)
  {
    std::cerr << "Error: wrong number of selected shapes.\n";
    return 1;
  }

  const TopoDS_Shape& aShape = aShapes.First();

  TopoDS_Face     aFace = TopoDS::Face (aShape);
  TopExp_Explorer aFaceExp (aFace, TopAbs_EDGE);
  TopoDS_Edge     anEdge0 = TopoDS::Edge (aFaceExp.Current());

  gp_Pnt A,B,C;
  if (aFaceExp.More())
  {
    aFaceExp.Next();
    TopoDS_Edge anEdge1 = TopoDS::Edge (aFaceExp.Current() );
    BRepAdaptor_Curve aCurve0 (anEdge0);
    BRepAdaptor_Curve aCurve1 (anEdge1);
    A = aCurve1.Value (0.1);
    B = aCurve1.Value (0.9);
    C = aCurve0.Value (0.5);
  }
  else
  {
    BRepAdaptor_Curve aCurve0 (anEdge0);
    A = aCurve0.Value (0.1);
    B = aCurve0.Value (0.9);
    C = aCurve0.Value (0.5);
  }

  GC_MakePlane aMkPlane (A,B,C);

  Handle(AIS_PlaneTrihedron) anAISPlaneTri = new AIS_PlaneTrihedron (aMkPlane.Value());
  TCollection_AsciiString aName (theArgVec[1]);

  VDisplayAISObject (aName, anAISPlaneTri);

  return 0;
}

//=======================================================================
//function : VTrihedron
//purpose  :
//=======================================================================
static int VTrihedron (Draw_Interpretor& ,
                       Standard_Integer theArgsNb,
                       const char** theArgVec)
{
  if (theArgsNb < 2)
  {
    std::cout << "Syntax error: the wrong number of input parameters.\n";
    return 1;
  }

  TCollection_AsciiString aName (theArgVec[1]);
  gp_Pln aWorkingPlane;
  Standard_Boolean toUpdate = Standard_True;

  NCollection_DataMap<TCollection_AsciiString, Standard_Real> aRealParams;
  NCollection_DataMap<TCollection_AsciiString, TCollection_AsciiString> aStringParams;

  Handle(AIS_Trihedron) aTrihedron;
  Handle(AIS_InteractiveObject) anObject;
  if (GetMapOfAIS().Find2 (aName, anObject))
  {
    aTrihedron = Handle(AIS_Trihedron)::DownCast (anObject);
    if (aTrihedron.IsNull())
    {
      std::cout << "Syntax error: no trihedron with this name.\n";
      return 1;
    }
  }
  else
  {
    Handle(Geom_Axis2Placement) aPlacement = new Geom_Axis2Placement (gp_Pnt (0.0, 0.0, 0.0),
                                                                      gp::DZ(), gp::DX());
    aTrihedron = new AIS_Trihedron (aPlacement);
  }

  if (!setTrihedronParams (theArgsNb, theArgVec, aTrihedron))
  {
    return 1;
  }

  // Redisplay a dimension after parameter changing.
  if (ViewerTest::GetAISContext()->IsDisplayed (aTrihedron))
  {
    ViewerTest::GetAISContext()->Redisplay (aTrihedron, toUpdate);
  }
  else
  {
    VDisplayAISObject (theArgVec[1], aTrihedron);
  }

  return 0;
}

//==============================================================================
//function : VSize
//author   : ege
//purpose  : Change the size of a named or selected trihedron
//           if no name : it affects the trihedrons witch are selected otherwise nothing is donne
//           if no value, the value is set at 100 by default
//Draw arg : vsize [name] [size]
//==============================================================================

static int VSize (Draw_Interpretor& di, Standard_Integer argc, const char** argv)

{
  // Declaration de booleens
  Standard_Boolean             ThereIsName;
  Standard_Boolean             ThereIsCurrent;
  Standard_Real                value;
  Standard_Boolean             hascol;

  Quantity_Color col = Quantity_NOC_BLACK;

  // Verification des arguments
  if ( argc>3 ) {di<<argv[0]<<" Syntaxe error\n"; return 1;}

  // Verification du nombre d'arguments
  if (argc==1)      {ThereIsName=Standard_False;value=100;}
  else if (argc==2) {ThereIsName=Standard_False;value=Draw::Atof(argv[1]);}
  else              {ThereIsName=Standard_True;value=Draw::Atof(argv[2]);}

  // On set le booleen ThereIsCurrent
  if (TheAISContext() -> NbSelected() > 0) {ThereIsCurrent=Standard_True;}
  else {ThereIsCurrent=Standard_False;}



  //===============================================================
  // Il n'y a pas de nom  mais des objets selectionnes
  //===============================================================
  if (!ThereIsName && ThereIsCurrent)
  {

    ViewerTest_DoubleMapIteratorOfDoubleMapOfInteractiveAndName
      it (GetMapOfAIS());

    while ( it.More() ) {

      Handle(AIS_InteractiveObject) aShape = it.Key1();

      if (!aShape.IsNull() &&  TheAISContext()->IsSelected(aShape) )
      {

        // On verifie que l'AIS InteraciveObject selectionne est bien
        // un AIS_Trihedron
        if (aShape->Type()==AIS_KOI_Datum && aShape->Signature()==3) {

          if (aShape->HasColor())
          {
            hascol = Standard_True;

            // On recupere la couleur de aShape
            aShape->Color (col);
          }
          else
          {
            hascol = Standard_False;
          }

          // On downcast aShape  de AIS_InteractiveObject a AIS_Trihedron
          // pour lui appliquer la methode SetSize()
          Handle(AIS_Trihedron) aTrihedron = Handle(AIS_Trihedron)::DownCast (aShape);

          // C'est bien un triedre,on chage sa valeur!
          aTrihedron->SetSize(value);

          // On donne la couleur au Trihedron
          if(hascol)   aTrihedron->SetColor(col);
          else         aTrihedron->UnsetColor();


          // The trihedron hasn't be errased from the map
          // so you just have to redisplay it
          TheAISContext() ->Redisplay(aTrihedron,Standard_False);

        }

      }

      it.Next();
    }

    TheAISContext() ->UpdateCurrentViewer();
  }

  //===============================================================
  // Il n'y a pas d'arguments et aucuns objets selectionne Rien A Faire!
  //===============================================================



  //===============================================================
  // Il y a un nom de triedre passe en argument
  //===============================================================
  if (ThereIsName) {
    TCollection_AsciiString name=argv[1];

    // on verifie que ce nom correspond bien a une shape
    Handle(AIS_InteractiveObject) aShape;
    if (GetMapOfAIS().Find2(name, aShape))
    {
      // On verifie que l'AIS InteraciveObject est bien
      // un AIS_Trihedron
      if (!aShape.IsNull() &&
        aShape->Type()==AIS_KOI_Datum && aShape->Signature()==3)
      {
        if (aShape->HasColor())
        {
          hascol=Standard_True;

          // On recupere la couleur de aShape
          aShape->Color (col);
        }
        else
        {
          hascol = Standard_False;
        }

        // On downcast aShape de AIS_InteractiveObject a AIS_Trihedron
        // pour lui appliquer la methode SetSize()
        Handle(AIS_Trihedron) aTrihedron = Handle(AIS_Trihedron)::DownCast (aShape);

        // C'est bien un triedre,on chage sa valeur
        aTrihedron->SetSize(value);

        // On donne la couleur au Trihedron
        if(hascol)   aTrihedron->SetColor(col);
        else         aTrihedron->UnsetColor();

        // The trihedron hasn't be errased from the map
        // so you just have to redisplay it
        TheAISContext() ->Redisplay(aTrihedron,Standard_False);

        TheAISContext() ->UpdateCurrentViewer();
      }
    }
  }
  return 0;
}


//==============================================================================

//==============================================================================
//function : VPlaneTrihedron
//purpose  : Create a plane from a trihedron selection. If no arguments are set, the default
//Draw arg : vplanetri  name
//==============================================================================
#include <AIS_Plane.hxx>



static int VPlaneTrihedron (Draw_Interpretor& di, Standard_Integer argc, const char** argv)

{
  // Verification des arguments
  if ( argc!=2) {di<<argv[0]<<" error\n"; return 1;}

  if (TheAISContext()->NbSelected() != 1)
  {
    std::cerr << "Error: Wrong number of selected shapes.\n";
    return 1;
  }

  TheAISContext()->InitSelected();
  Handle(AIS_InteractiveObject) aTest = TheAISContext()->SelectedInteractive();
  Handle(AIS_Plane) aPlane = Handle(AIS_Plane)::DownCast (aTest);
  if (aPlane.IsNull())
  {
    std::cerr << "Error: Selected shape is not a plane.\n";
    return 1;
  }

  VDisplayAISObject (argv[1], aPlane);

  return 0;
}



//==============================================================================
// Fonction        First click      2de click
//
// vaxis           vertex           vertex
//                 edge             None
// vaxispara       edge             vertex
// vaxisortho      edge             Vertex
// vaxisinter      Face             Face
//==============================================================================

//==============================================================================
//function : VAxisBuilder
//purpose  :
//Draw arg : vaxis AxisName Xa Ya Za Xb Yb Zb
//==============================================================================
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopExp.hxx>
#include <Geom_Line.hxx>

static int VAxisBuilder(Draw_Interpretor& di, Standard_Integer argc, const char** argv)
{
  // Declarations
  Standard_Boolean HasArg;
  TCollection_AsciiString name;

  // Verification
  if (argc<2 || argc>8 ) {di<<" Syntaxe error\n";return 1;}
  if (argc==8) HasArg=Standard_True;
  else HasArg=Standard_False;

  name=argv[1];

  TopTools_ListOfShape aShapes;
  ViewerTest::GetSelectedShapes (aShapes);

  // Cas ou il y a des arguments
  // Purpose: Teste le constructeur AIS_Axis::AIS_Axis(x: Line from Geom)
  if (HasArg) {
    Standard_Real coord[6];
    for(Standard_Integer i=0;i<=5;i++){
      coord[i]=Draw::Atof(argv[2+i]);
    }
    gp_Pnt p1(coord[0],coord[1],coord[2]), p2(coord[3],coord[4],coord[5]) ;

    gp_Vec myVect (p1,p2);
    Handle(Geom_Line) myLine=new Geom_Line (p1 ,myVect );
    Handle(AIS_Axis) TheAxis=new AIS_Axis (myLine );
    GetMapOfAIS().Bind (TheAxis,name);
    TheAISContext()->Display(TheAxis, Standard_True);
  }

  // Pas d'arguments
  else {
    // fonction vaxis
    // Purpose: Teste le constructeur AIS_Axis::AIS_Axis (x:Axis1Placement from Geom)
    if ( !strcasecmp(argv[0], "vaxis")) {
      if (aShapes.Extent() != 2 && aShapes.Extent() != 1)
      {
        std::cerr << "Error: Wrong number of selected shapes.\n";
        return 1;
      }

      const TopoDS_Shape& aShapeA = aShapes.First();
      if (aShapeA.ShapeType() == TopAbs_VERTEX)
      {
        if (aShapes.Extent() != 2)
        {
          std::cerr << "Error: Wron number of selected shapes.\n";
          return 1;
        }

        const TopoDS_Shape& aShapeB = aShapes.Last();
        if (aShapeB.ShapeType() != TopAbs_VERTEX)
        {
          std::cerr << "Syntax error: You should select two vertices or one edge.\n";
          return 1;
        }

        // Construction de l'axe
        gp_Pnt A = BRep_Tool::Pnt (TopoDS::Vertex (aShapeA));
        gp_Pnt B = BRep_Tool::Pnt (TopoDS::Vertex (aShapeB));
        gp_Vec V (A,B);
        gp_Dir D (V);
        Handle(Geom_Axis1Placement) OrigineAndVect=new Geom_Axis1Placement (A,D);
        Handle(AIS_Axis) TheAxis=new AIS_Axis (OrigineAndVect);
        GetMapOfAIS().Bind (TheAxis,name);
        TheAISContext()->Display (TheAxis, Standard_True);
      }
      else
      {
        TopoDS_Edge    ed =TopoDS::Edge (aShapeA);
        TopoDS_Vertex  Va,Vb;
        TopExp::Vertices(ed,Va,Vb );
        gp_Pnt A=BRep_Tool::Pnt(Va);
        gp_Pnt B=BRep_Tool::Pnt(Vb);
        gp_Vec  V (A,B);
        gp_Dir   D (V);
        Handle(Geom_Axis1Placement) OrigineAndVect=new Geom_Axis1Placement (A,D);
        Handle(AIS_Axis) TheAxis=new AIS_Axis (OrigineAndVect);
        GetMapOfAIS().Bind (TheAxis,name);
        TheAISContext()->Display (TheAxis, Standard_True);
      }

    }

    // Fonction axispara
    // Purpose: Teste le constructeur AIS_Axis::AIS_Axis(x: Axis2Placement from Geom, y: TypeOfAxis from AIS)
    else if ( !strcasecmp(argv[0], "vaxispara"))
    {
      if (aShapes.Extent() != 2)
      {
        std::cerr << "Error: Wrong number of selected shapes.\n";
        return 1;
      }

      const TopoDS_Shape& aShapeA = aShapes.First();
      const TopoDS_Shape& aShapeB = aShapes.Last();
      if (!(aShapeA.ShapeType() == TopAbs_EDGE
         && aShapeB.ShapeType() == TopAbs_VERTEX))
      {
        std::cerr << "Syntax error: You should select face and then vertex.\n";
        return 1;
      }

      TopoDS_Edge    ed=TopoDS::Edge (aShapeA);
      gp_Pnt B=BRep_Tool::Pnt(TopoDS::Vertex(aShapeB));
      TopoDS_Vertex  Va,Vc;
      TopExp::Vertices(ed,Va,Vc );
      gp_Pnt A=BRep_Tool::Pnt(Va);
      gp_Pnt C=BRep_Tool::Pnt(Vc);
      gp_Vec  V (A,C);
      gp_Dir   D (V);
      Handle(Geom_Axis1Placement) OrigineAndVect=new Geom_Axis1Placement (B,D);
      Handle(AIS_Axis) TheAxis=new AIS_Axis (OrigineAndVect);
      GetMapOfAIS().Bind (TheAxis,name);
      TheAISContext()->Display (TheAxis, Standard_True);

    }

    // Fonction axisortho
    else
    {
      if (aShapes.Extent() != 2)
      {
        std::cerr << "Error: Wrong number of selected shapes.\n";
        return 1;
      }

      const TopoDS_Shape& aShapeA = aShapes.First();
      const TopoDS_Shape& aShapeB = aShapes.Last();
      if (!(aShapeA.ShapeType() == TopAbs_EDGE
         && aShapeB.ShapeType() == TopAbs_VERTEX))
      {
        std::cerr << "Syntax error: You should select face and then vertex.\n";
        return 1;
      }

      // Construction de l'axe
      TopoDS_Edge    ed=TopoDS::Edge(aShapeA) ;
      gp_Pnt B=BRep_Tool::Pnt(TopoDS::Vertex(aShapeB) );
      TopoDS_Vertex  Va,Vc;
      TopExp::Vertices(ed,Va,Vc );
      gp_Pnt A=BRep_Tool::Pnt(Va);
      gp_Pnt C=BRep_Tool::Pnt(Vc);
      gp_Pnt E(A.Y()+A.Z()-C.Y()-C.Z()  ,C.X()-A.X() ,C.X()-A.X() );
      gp_Vec  V (A,E);
      gp_Dir   D (V);
      Handle(Geom_Axis1Placement) OrigineAndVect=new Geom_Axis1Placement (B,D);
      Handle(AIS_Axis) TheAxis=new AIS_Axis (OrigineAndVect);
      GetMapOfAIS().Bind (TheAxis,name);
      TheAISContext()->Display (TheAxis, Standard_True);

    }

  }
  return 0;
}


//==============================================================================
// Fonction        First click      Result
//
// vpoint          vertex           AIS_Point=Vertex
//                 edge             AIS_Point=Middle of the edge
//==============================================================================

//==============================================================================
//function : VPointBuilder
//purpose  : Build an AIS_Point from coordinates or with a selected vertex or edge
//Draw arg : vpoint PoinName [Xa] [Ya] [Za]
//==============================================================================
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopExp.hxx>
#include <AIS_Point.hxx>
#include <Geom_CartesianPoint.hxx>

static int VPointBuilder(Draw_Interpretor& di, Standard_Integer argc, const char** argv)
{
  // Declarations
  Standard_Boolean HasArg;
  TCollection_AsciiString name;

  // Verification
  if (argc<2 || argc>5 ) {di<<" Syntaxe error\n";return 1;}
  if (argc==5) HasArg=Standard_True;
  else HasArg=Standard_False;

  name=argv[1];

  // Il y a des arguments: teste l'unique constructeur AIS_Pnt::AIS_Pnt(Point from Geom)
  if (HasArg) {
    Standard_Real thecoord[3];
    for(Standard_Integer i=0;i<=2;i++)
      thecoord[i]=Draw::Atof(argv[2+i]);
    Handle(Geom_CartesianPoint )  myGeomPoint= new Geom_CartesianPoint (thecoord[0],thecoord[1],thecoord[2]);
    Handle(AIS_Point)  myAISPoint=new AIS_Point(myGeomPoint );
    GetMapOfAIS().Bind (myAISPoint,name);
    TheAISContext()->Display (myAISPoint, Standard_True);
  }

  // Il n'a pas d'arguments
  else
  {
    TopTools_ListOfShape aShapes;
    ViewerTest::GetSelectedShapes (aShapes);

    if (aShapes.Extent() != 1)
    {
      std::cerr << "Error: Wrong number of selected shapes.\n";
      std::cerr << "\tYou should select one edge or vertex.\n";
      return 1;
    }

    const TopoDS_Shape& aShapeA = aShapes.First();

    if (aShapeA.ShapeType()==TopAbs_VERTEX )
    {
      gp_Pnt A=BRep_Tool::Pnt(TopoDS::Vertex(aShapeA ) );
      Handle(Geom_CartesianPoint) myGeomPoint= new Geom_CartesianPoint (A );
      Handle(AIS_Point)  myAISPoint = new AIS_Point  (myGeomPoint );
      GetMapOfAIS().Bind(myAISPoint,name);
      TheAISContext()->Display (myAISPoint, Standard_True);
    }
    else
    {
      TopoDS_Edge myEdge=TopoDS::Edge(aShapeA);
      TopoDS_Vertex myVertexA,myVertexB;
      TopExp::Vertices (myEdge ,myVertexA ,myVertexB );
      gp_Pnt A=BRep_Tool::Pnt(myVertexA );
      gp_Pnt B=BRep_Tool::Pnt(myVertexB );
      // M est le milieu de [AB]
      Handle(Geom_CartesianPoint) myGeomPointM= new Geom_CartesianPoint ( (A.X()+B.X())/2  , (A.Y()+B.Y())/2  , (A.Z()+B.Z())/2  );
      Handle(AIS_Point)  myAISPointM = new AIS_Point  (myGeomPointM );
      GetMapOfAIS().Bind(myAISPointM,name);
      TheAISContext()->Display (myAISPointM, Standard_True);
    }

  }
  return 0;

}

//==============================================================================
// Function        1st click   2de click  3de click
// vplane          Vertex      Vertex     Vertex
//                 Vertex      Edge
//                 Edge        Vertex
//                 Face
// vplanepara      Face        Vertex
//                 Vertex      Face
// vplaneortho     Face        Edge
//                 Edge        Face
//==============================================================================

//==============================================================================
//function : VPlaneBuilder
//purpose  : Build an AIS_Plane from selected entities or Named AIS components
//Draw arg : vplane PlaneName [AxisName]  [PointName] [TypeOfSensitivity]
//                            [PointName] [PointName] [PointName] [TypeOfSensitivity]
//                            [PlaneName] [PointName] [TypeOfSensitivity]
//==============================================================================

static Standard_Integer VPlaneBuilder (Draw_Interpretor& /*di*/,
                                       Standard_Integer argc,
                                       const char** argv)
{
  // Declarations
  Standard_Boolean hasArg;
  TCollection_AsciiString aName;

  // Verification
  if (argc<2 || argc>6 )
  {
    std::cout<<" Syntax error\n";
    return 1;
  }
  if (argc == 6 || argc==5 || argc==4)
    hasArg=Standard_True;
  else 
    hasArg=Standard_False;

  aName=argv[1];

  // There are some arguments
  if (hasArg)
  {
    Handle(AIS_InteractiveObject) aShapeA;
    if (!GetMapOfAIS().Find2 (argv[2], aShapeA))
    {
      std::cout<<"vplane: error 1st name doesn't exist in the GetMapOfAIS()\n";
      return 1;
    }

    // The first argument is an AIS_Point
    if (!aShapeA.IsNull() &&
        aShapeA->Type()==AIS_KOI_Datum &&
        aShapeA->Signature()==1)
    {
        // The second argument must also be an AIS_Point
        Handle(AIS_InteractiveObject) aShapeB;
        if (argc<5 || !GetMapOfAIS().Find2 (argv[3], aShapeB))
        {
          std::cout<<"vplane: error 2nd name doesn't exist in the GetMapOfAIS()\n";
          return 1;
        }
        // If B is not an AIS_Point
        if (aShapeB.IsNull() ||
          (!(aShapeB->Type()==AIS_KOI_Datum && aShapeB->Signature()==1)))
        {
          std::cout<<"vplane: error 2nd object is expected to be an AIS_Point.\n";
          return 1;
        }
        // The third object is an AIS_Point
        Handle(AIS_InteractiveObject) aShapeC;
        if (!GetMapOfAIS().Find2(argv[4], aShapeC)) 
        {
          std::cout<<"vplane: error 3d name doesn't exist in the GetMapOfAIS().\n";
          return 1; 
        }
        // If C is not an AIS_Point
        if (aShapeC.IsNull() ||
          (!(aShapeC->Type()==AIS_KOI_Datum && aShapeC->Signature()==1)))
        {
          std::cout<<"vplane: error 3d object is expected to be an AIS_Point.\n";
          return 1;
        }

        // Treatment of objects A, B, C
        // Downcast an AIS_IO to AIS_Point
        Handle(AIS_Point) anAISPointA = Handle(AIS_Point)::DownCast( aShapeA);
        Handle(AIS_Point) anAISPointB = Handle(AIS_Point)::DownCast( aShapeB);
        Handle(AIS_Point) anAISPointC = Handle(AIS_Point)::DownCast( aShapeC);

        Handle(Geom_CartesianPoint ) aCartPointA = 
          Handle(Geom_CartesianPoint)::DownCast( anAISPointA->Component());

        Handle(Geom_CartesianPoint ) aCartPointB = 
          Handle(Geom_CartesianPoint)::DownCast( anAISPointB->Component());

        Handle(Geom_CartesianPoint ) aCartPointC = 
          Handle(Geom_CartesianPoint)::DownCast( anAISPointC->Component());

        // Verification that the three points are different
        if(Abs(aCartPointB->X()-aCartPointA->X())<=Precision::Confusion() &&
           Abs(aCartPointB->Y()-aCartPointA->Y())<=Precision::Confusion() &&
           Abs(aCartPointB->Z()-aCartPointA->Z())<=Precision::Confusion())
        {
          // B=A
          std::cout<<"vplane error: same points\n";return 1;
        }
        if(Abs(aCartPointC->X()-aCartPointA->X())<=Precision::Confusion() &&
           Abs(aCartPointC->Y()-aCartPointA->Y())<=Precision::Confusion() &&
           Abs(aCartPointC->Z()-aCartPointA->Z())<=Precision::Confusion())
        {
          // C=A
          std::cout<<"vplane error: same points\n";return 1;
        }
        if(Abs(aCartPointC->X()-aCartPointB->X())<=Precision::Confusion() &&
           Abs(aCartPointC->Y()-aCartPointB->Y())<=Precision::Confusion() &&
           Abs(aCartPointC->Z()-aCartPointB->Z())<=Precision::Confusion())
        {
          // C=B
          std::cout<<"vplane error: same points\n";return 1;
        }

        gp_Pnt A = aCartPointA->Pnt();
        gp_Pnt B = aCartPointB->Pnt();
        gp_Pnt C = aCartPointC->Pnt();

        // Construction of AIS_Plane
        GC_MakePlane MkPlane (A,B,C);
        Handle(Geom_Plane) aGeomPlane = MkPlane.Value();
        Handle(AIS_Plane)  anAISPlane = new AIS_Plane(aGeomPlane );
        GetMapOfAIS().Bind (anAISPlane,aName );
        if (argc == 6)
        {
          Standard_Integer aType = Draw::Atoi (argv[5]);
          if (aType != 0 && aType != 1)
          {
            std::cout << "vplane error: wrong type of sensitivity!\n"
                      << "Should be one of the following values:\n"
                      << "0 - Interior\n"
                      << "1 - Boundary"
                      << std::endl;
            return 1;
          }
          else
          {
            anAISPlane->SetTypeOfSensitivity (Select3D_TypeOfSensitivity (aType));
          }
        }
        TheAISContext()->Display (anAISPlane, Standard_True);
      }

      // The first argument is an AIS_Axis
      // Creation of a plane orthogonal to the axis through a point
    else if (aShapeA->Type()==AIS_KOI_Datum && aShapeA->Signature()==2 ) {
      // The second argument should be an AIS_Point
      Handle(AIS_InteractiveObject) aShapeB;
      if (argc!=4 || !GetMapOfAIS().Find2 (argv[3], aShapeB))
      {
        std::cout<<"vplane: error 2d name doesn't exist in the GetMapOfAIS()\n";
        return 1;
      }
      // If B is not an AIS_Point
      if (aShapeB.IsNull() ||
        (!(aShapeB->Type()==AIS_KOI_Datum && aShapeB->Signature()==1)))
      {
        std::cout<<"vplane: error 2d object is expected to be an AIS_Point\n";
        return 1;
      }

      // Treatment of objects A and B
      Handle(AIS_Axis) anAISAxisA = Handle(AIS_Axis)::DownCast(aShapeA);
      Handle(AIS_Point) anAISPointB = Handle(AIS_Point)::DownCast(aShapeB);

      Handle(Geom_Line ) aGeomLineA = anAISAxisA ->Component();
      Handle(Geom_Point) aGeomPointB = anAISPointB->Component()  ;

      gp_Ax1 anAxis = aGeomLineA->Position();
      Handle(Geom_CartesianPoint) aCartPointB = 
        Handle(Geom_CartesianPoint)::DownCast(aGeomPointB);

      gp_Dir D =anAxis.Direction();
      gp_Pnt B = aCartPointB->Pnt();

      // Construction of AIS_Plane
      Handle(Geom_Plane) aGeomPlane = new Geom_Plane(B,D);
      Handle(AIS_Plane) anAISPlane = new AIS_Plane(aGeomPlane,B );
      GetMapOfAIS().Bind (anAISPlane,aName );
      if (argc == 5)
      {
        Standard_Integer aType = Draw::Atoi (argv[4]);
        if (aType != 0 && aType != 1)
        {
          std::cout << "vplane error: wrong type of sensitivity!\n"
                    << "Should be one of the following values:\n"
                    << "0 - Interior\n"
                    << "1 - Boundary"
                    << std::endl;
          return 1;
        }
        else
        {
          anAISPlane->SetTypeOfSensitivity (Select3D_TypeOfSensitivity (aType));
        }
      }
      TheAISContext()->Display (anAISPlane, Standard_True);

    }
    // The first argumnet is an AIS_Plane
    // Creation of a plane parallel to the plane passing through the point
    else if (aShapeA->Type()==AIS_KOI_Datum && aShapeA->Signature()==7)
    {
      // The second argument should be an AIS_Point
      Handle(AIS_InteractiveObject) aShapeB;
      if (argc!=4 || !GetMapOfAIS().Find2 (argv[3], aShapeB))
      {
        std::cout<<"vplane: error 2d name doesn't exist in the GetMapOfAIS()\n";
        return 1;
      }
      // B should be an AIS_Point
      if (aShapeB.IsNull() ||
         (!(aShapeB->Type()==AIS_KOI_Datum && aShapeB->Signature()==1)))
      {
        std::cout<<"vplane: error 2d object is expected to be an AIS_Point\n";
        return 1;
      }

      // Treatment of objects A and B
      Handle(AIS_Plane) anAISPlaneA = Handle(AIS_Plane)::DownCast(aShapeA);
      Handle(AIS_Point) anAISPointB = Handle(AIS_Point)::DownCast(aShapeB);

      Handle(Geom_Plane) aNewGeomPlane= anAISPlaneA->Component();
      Handle(Geom_Point) aGeomPointB = anAISPointB->Component();

      Handle(Geom_CartesianPoint) aCartPointB = 
        Handle(Geom_CartesianPoint)::DownCast(aGeomPointB);
      gp_Pnt B= aCartPointB->Pnt();

      // Construction of an AIS_Plane
      Handle(AIS_Plane) anAISPlane = new AIS_Plane(aNewGeomPlane, B);
      GetMapOfAIS().Bind (anAISPlane, aName);
      if (argc == 5)
      {
        Standard_Integer aType = Draw::Atoi (argv[4]);
        if (aType != 0 && aType != 1)
        {
          std::cout << "vplane error: wrong type of sensitivity!\n"
                    << "Should be one of the following values:\n"
                    << "0 - Interior\n"
                    << "1 - Boundary"
                    << std::endl;
          return 1;
        }
        else
        {
          anAISPlane->SetTypeOfSensitivity (Select3D_TypeOfSensitivity (aType));
        }
      }
      TheAISContext()->Display (anAISPlane, Standard_True);
    }
    // Error
    else
    {
      std::cout<<"vplane: error 1st object is not an AIS\n";
      return 1;
    }
  }
  // There are no arguments
  else 
  {
    TopTools_ListOfShape aShapes;
    ViewerTest::GetSelectedShapes (aShapes);

    // Function vplane
    // Test the constructor AIS_Plane::AIS_Plane(Geom_Plane, Standard_Boolean )
    if (!strcasecmp(argv[0], "vplane"))
    {
      if (aShapes.Extent() < 1 || aShapes.Extent() > 3)
      {
        std::cerr << "Error: Wront number of selected shapes.\n";
        std::cerr << "\tYou should one of variant: face, edge and vertex or three vertices.\n";
        return 1;
      }

      const TopoDS_Shape& aShapeA = aShapes.First();
      if (aShapeA.ShapeType() == TopAbs_VERTEX)
      {
        if (aShapes.Extent() == 2)
        {
          const TopoDS_Shape& aShapeB = aShapes.Last();
          if (aShapeB.ShapeType() != TopAbs_EDGE)
          {
            std::cerr << "Syntax error: Together with vertex should be edge.\n";
            return 1;
          }

          // Verify that the vertex is not on the edge ShapeB
          TopoDS_Edge anEdgeB = TopoDS::Edge(aShapeB);
          TopoDS_Vertex aVertA = TopoDS::Vertex(aShapeA);

          BRepExtrema_ExtPC OrthoProj(aVertA, anEdgeB);
          if (OrthoProj.SquareDistance(1)<Precision::Approximation())
          {
            // The vertex is on the edge
            std::cout<<" vplane: error point is on the edge\n";
            return 1;
          }
          else
          {
            gp_Pnt A = BRep_Tool::Pnt(aVertA);
            TopoDS_Vertex aVBa, aVBb;
            TopExp::Vertices(anEdgeB ,aVBa ,aVBb);
            gp_Pnt aBa = BRep_Tool::Pnt(aVBa);
            gp_Pnt aBb = BRep_Tool::Pnt(aVBb);
            GC_MakePlane MkPlane (A, aBa, aBb);
            Handle(Geom_Plane) aGeomPlane = MkPlane.Value();
            Handle(AIS_Plane) anAISPlane = new AIS_Plane (aGeomPlane);
            GetMapOfAIS().Bind (anAISPlane, aName);
            TheAISContext()->Display (anAISPlane, Standard_True);
          }
        }
        else if (aShapes.Extent() == 3)
        {
          TopTools_ListOfShape::Iterator anIter (aShapes);

          anIter.Next();
          const TopoDS_Shape& aShapeB = anIter.Value();

          anIter.Next();
          const TopoDS_Shape& aShapeC = anIter.Value();

          if (!(aShapeB.ShapeType() == TopAbs_VERTEX
             && aShapeC.ShapeType() == TopAbs_VERTEX))
          {
            std::cerr << "Syntax error: You should one of variant: face, edge and vertex or three vertices.\n";
            return 1;
          }

          gp_Pnt A = BRep_Tool::Pnt(TopoDS::Vertex(aShapeA));
          gp_Pnt B = BRep_Tool::Pnt(TopoDS::Vertex(aShapeB));
          gp_Pnt C = BRep_Tool::Pnt(TopoDS::Vertex(aShapeC));
          GC_MakePlane MkPlane(A, B, C);
          Handle(Geom_Plane) aGeomPlane = MkPlane.Value();
          Handle(AIS_Plane) anAISPlane = new AIS_Plane (aGeomPlane);
          GetMapOfAIS().Bind (anAISPlane, aName);
          TheAISContext()->Display (anAISPlane, Standard_True);
        }
        else
        {
          std::cerr << "Syntax error: You should one of variant: face, edge and vertex or three vertices.\n";
          return 1;
        }
      }
      else if (aShapeA.ShapeType() == TopAbs_EDGE)
      {
        if (aShapes.Extent() != 2)
        {
          std::cerr << "Error: wrong number of selected shapes.\n";
          return 1;
        }

        const TopoDS_Shape& aShapeB = aShapes.Last();
        if (aShapeB.ShapeType() != TopAbs_VERTEX)
        {
          std::cerr << "Syntax error: Together with edge should be vertex.\n";
          return 1;
        }

        // Check that the vertex aShapeB is not on the edge
        TopoDS_Edge anEdgeA = TopoDS::Edge(aShapeA);
        TopoDS_Vertex aVertB = TopoDS::Vertex(aShapeB);

        BRepExtrema_ExtPC OrthoProj (aVertB, anEdgeA);
        if (OrthoProj.SquareDistance(1)<Precision::Approximation())
        {
          // The vertex is on the edge
          std::cout<<" vplane: error point is on the edge\n";
          return 1;
        }

        gp_Pnt B = BRep_Tool::Pnt(aVertB);
        TopoDS_Vertex aVAa, aVAb;
        TopExp::Vertices(anEdgeA, aVAa, aVAb);
        gp_Pnt Aa = BRep_Tool::Pnt(aVAa);
        gp_Pnt Ab = BRep_Tool::Pnt(aVAb);
        GC_MakePlane MkPlane (B,Aa,Ab);
        Handle(Geom_Plane) aGeomPlane = MkPlane.Value();
        Handle(AIS_Plane) anAISPlane = new AIS_Plane (aGeomPlane);
        GetMapOfAIS().Bind (anAISPlane ,aName);
        TheAISContext()->Display (anAISPlane, Standard_True);
      }
      else if (aShapeA.ShapeType() == TopAbs_FACE)
      {
        TopoDS_Face aFace = TopoDS::Face(aShapeA);
        BRepAdaptor_Surface aSurface (aFace, Standard_False);
        if (aSurface.GetType()==GeomAbs_Plane)
        {
          gp_Pln aPlane = aSurface.Plane();
          Handle(Geom_Plane) aGeomPlane = new Geom_Plane(aPlane);
          Handle(AIS_Plane) anAISPlane = new AIS_Plane(aGeomPlane);
          GetMapOfAIS().Bind (anAISPlane, aName);
          TheAISContext()->Display (anAISPlane, Standard_True);
        }
        else
        {
          std::cout<<" vplane: error\n";
          return 1;
        }
      }
      else
      {
        std::cerr << "Syntax error: You should one of variant: face, edge and vertex or three vertices.\n";
        return 1;
      }
    }

    // Function vPlanePara
    // ===================
    // test the constructor AIS_Plane::AIS_Plane(Geom_Plane,gp_Pnt)
    else if (!strcasecmp(argv[0], "vplanepara"))
    {
      if (aShapes.Extent() != 2)
      {
        std::cerr << "Error: Wrong number of selected shapes.\n";
        return 1;
      }

      const TopoDS_Shape* aShapeA = &aShapes.First();
      const TopoDS_Shape* aShapeB = &aShapes.Last();
      if (aShapeA->ShapeType() != TopAbs_VERTEX)
      {
        std::swap (aShapeA, aShapeB);
      }

      if (!(aShapeA->ShapeType() == TopAbs_VERTEX
         && aShapeB->ShapeType() == TopAbs_FACE))
      {
        std::cerr << "Syntax error: you should select face and vertex.\n";
        return 1;
      }

      gp_Pnt A = BRep_Tool::Pnt(TopoDS::Vertex(*aShapeA));

      TopoDS_Face aFace = TopoDS::Face(*aShapeB);
      BRepAdaptor_Surface aSurface (aFace, Standard_False);
      if (aSurface.GetType() == GeomAbs_Plane)
      {
        gp_Pln aPlane = aSurface.Plane();
        // Construct a plane parallel to aGeomPlane through A
        aPlane.SetLocation(A);
        Handle(Geom_Plane) aGeomPlane = new Geom_Plane (aPlane);
        Handle(AIS_Plane) aAISPlane = new AIS_Plane (aGeomPlane, A);
        GetMapOfAIS().Bind (aAISPlane ,aName);
        TheAISContext()->Display (aAISPlane, Standard_True);
      }
      else
      {
        std::cerr << "Error: Builded surface is not a plane.\n";
        return 1;
      }
    }

    // Function vplaneortho
    // ====================
    // test the constructor AIS_Plane::AIS_Plane(Geom_Plane,gp_Pnt,gp_Pnt,gp_Pnt)
    else
    {
      if (aShapes.Extent() != 2)
      {
        std::cerr << "Error: wrong number of selected shapes.\n";
        return 1;
      }

      const TopoDS_Shape* aShapeA = &aShapes.First();
      const TopoDS_Shape* aShapeB = &aShapes.Last();

      if (aShapeA->ShapeType() != TopAbs_EDGE)
      {
        std::swap (aShapeA, aShapeB);
      }

      if (!(aShapeA->ShapeType() == TopAbs_EDGE
         && aShapeB->ShapeType() == TopAbs_FACE))
      {
        std::cerr << "Error: you should select edge and face.\n";
        return 1;
      }

      // Construction of plane
      TopoDS_Edge anEdgeA = TopoDS::Edge(*aShapeA);
      TopoDS_Vertex aVAa, aVAb;
      TopExp::Vertices(anEdgeA, aVAa, aVAb);
      gp_Pnt Aa = BRep_Tool::Pnt(aVAa);
      gp_Pnt Ab = BRep_Tool::Pnt(aVAb);
      gp_Vec ab (Aa,Ab);

      gp_Dir Dab (ab);
      // Creation of rotation axis
      gp_Ax1 aRotAxis (Aa,Dab);

      TopoDS_Face aFace = TopoDS::Face(*aShapeB);
      // The edge must be parallel to the face
      BRepExtrema_ExtPF aHeightA (aVAa, aFace);
      BRepExtrema_ExtPF aHeightB (aVAb, aFace);
      // Compare to heights
      if (fabs(sqrt(aHeightA.SquareDistance(1)) - sqrt(aHeightB.SquareDistance(1)))
          >Precision::Confusion())
      {
        // the edge is not parallel to the face
        std::cout<<" vplaneortho error: the edge is not parallel to the face\n";
        return 1;
      }
      // the edge is OK
      BRepAdaptor_Surface aSurface (aFace, Standard_False);
      if (aSurface.GetType()==GeomAbs_Plane)
      {
        gp_Pln aPlane = aSurface.Plane();
        // It rotates a half turn round the axis of rotation
        aPlane.Rotate(aRotAxis , M_PI/2);

        Handle(Geom_Plane) aGeomPlane = new Geom_Plane (aPlane);
        // constructed aGeomPlane parallel to a plane containing the edge (center mid-edge)
        gp_Pnt aMiddle ((Aa.X()+Ab.X() )/2 ,(Aa.Y()+Ab.Y() )/2 ,(Aa.Z()+Ab.Z() )/2 );
        Handle(AIS_Plane) anAISPlane = new AIS_Plane (aGeomPlane, aMiddle);
        GetMapOfAIS().Bind (anAISPlane, aName);
        TheAISContext()->Display (anAISPlane, Standard_True);
      }
      else
      {
        std::cout<<" vplaneortho: error\n";
        return 1;
      }
    }
  }
  return 0;
}

//===============================================================================================
//function : VChangePlane
//purpose  :
//===============================================================================================
static int VChangePlane (Draw_Interpretor& /*theDi*/, Standard_Integer theArgsNb, const char** theArgVec)
{
  Handle(AIS_InteractiveContext) aContextAIS = ViewerTest::GetAISContext();
  if (aContextAIS.IsNull())
  {
    std::cout << theArgVec[0] << "AIS context is not available.\n";
    return 1;
  }

  if (theArgsNb < 3 || theArgsNb > 11)
  {
    std::cerr << theArgVec[0] 
              << ": incorrect number of command arguments.\n"
              << "Type help for more information.\n";
    return 1;
  }

  TCollection_AsciiString aName (theArgVec[1]);

  Handle(AIS_Plane) aPlane = GetMapOfAIS().IsBound2(aName)
    ? Handle(AIS_Plane)::DownCast (GetMapOfAIS().Find2 (aName))
    : NULL;

  if ( aPlane.IsNull() )
  {
    std::cout << theArgVec[0] 
              << ": there is no interactive plane with the given name."
              << "Type help for more information.\n";
    return 1;
  }

  Standard_Real aCenterX = aPlane->Center().X();
  Standard_Real aCenterY = aPlane->Center().Y();
  Standard_Real aCenterZ = aPlane->Center().Z();

  Standard_Real aDirX = aPlane->Component()->Axis().Direction().X();
  Standard_Real aDirY = aPlane->Component()->Axis().Direction().Y();
  Standard_Real aDirZ = aPlane->Component()->Axis().Direction().Z();

  Standard_Real aSizeX = 0.0;
  Standard_Real aSizeY = 0.0;
  aPlane->Size (aSizeX, aSizeY);
  Standard_Boolean isUpdate = Standard_True;

  TCollection_AsciiString aPName, aPValue;
  for (Standard_Integer anArgIt = 1; anArgIt < theArgsNb; ++anArgIt)
  {
    const TCollection_AsciiString anArg = theArgVec[anArgIt];
    TCollection_AsciiString anArgCase = anArg;
    anArgCase.UpperCase();
    if (ViewerTest::SplitParameter (anArg, aPName, aPValue))
    {
      aPName.UpperCase();
      if (aPName.IsEqual ("X"))
      {
        aCenterX = aPValue.RealValue();
      }
      else if (aPName.IsEqual ("Y"))
      {
        aCenterY = aPValue.RealValue();
      }
      else if (aPName.IsEqual ("Z"))
      {
        aCenterZ = aPValue.RealValue();
      }
      else if (aPName.IsEqual ("DX"))
      {
        aDirX = aPValue.RealValue();
      }
      else if (aPName.IsEqual ("DY"))
      {
        aDirY = aPValue.RealValue();
      }
      else if (aPName.IsEqual ("DZ"))
      {
        aDirZ = aPValue.RealValue();
      }
      else if (aPName.IsEqual ("SX"))
      {
        aSizeX = aPValue.RealValue();
      }
      else if (aPName.IsEqual ("SY"))
      {
        aSizeY = aPValue.RealValue();
      }
    }
    else if (anArg.IsEqual ("NOUPDATE"))
    {
      isUpdate = Standard_False;
    }
  }

  gp_Dir aDirection (aDirX, aDirY, aDirZ);
  gp_Pnt aCenterPnt (aCenterX, aCenterY, aCenterZ);
  aPlane->SetCenter (aCenterPnt);
  aPlane->SetComponent (new Geom_Plane (aCenterPnt, aDirection));
  aPlane->SetSize (aSizeX, aSizeY);

  aContextAIS->Update (aPlane, isUpdate);

  return 0;
}

//==============================================================================
// Fonction  vline
// ---------------  Uniquement par parametre. Pas de selection dans le viewer.
//==============================================================================

//==============================================================================
//function : VLineBuilder
//purpose  : Build an AIS_Line
//Draw arg : vline LineName  [AIS_PointName] [AIS_PointName]
//                           [Xa] [Ya] [Za]   [Xb] [Yb] [Zb]
//==============================================================================
#include <Geom_CartesianPoint.hxx>
#include <AIS_Line.hxx>


static int VLineBuilder(Draw_Interpretor& di, Standard_Integer argc, const char** argv)
{
  // Verifications
  if (argc!=4 && argc!=8 && argc!=2 )  {di<<"vline error: number of arguments not correct \n";return 1; }

  // On recupere les parametres
  Handle(AIS_InteractiveObject) theShapeA;
  Handle(AIS_InteractiveObject) theShapeB;

  // Parametres: AIS_Point AIS_Point
  // ===============================
  if (argc==4) {
    GetMapOfAIS().Find2 (argv[2], theShapeA);
    // On verifie que c'est bien une AIS_Point
    if (!theShapeA.IsNull() &&
      theShapeA->Type()==AIS_KOI_Datum && theShapeA->Signature()==1) {
        // on recupere le deuxieme AIS_Point
        GetMapOfAIS().Find2 (argv[3], theShapeB);
        if (theShapeB.IsNull() ||
          (!(theShapeB->Type()==AIS_KOI_Datum && theShapeB->Signature()==1)))
        {
          di <<"vline error: wrong type of 2de argument.\n";
          return 1;
        }
      }
    else {di <<"vline error: wrong type of 1st argument.\n";return 1; }
    // Les deux parametres sont du bon type. On verifie que les points ne sont pas confondus
    Handle(AIS_Point) theAISPointA= Handle(AIS_Point)::DownCast (theShapeA);
    Handle(AIS_Point) theAISPointB= Handle(AIS_Point)::DownCast (theShapeB);

    Handle(Geom_Point ) myGeomPointBA=  theAISPointA->Component();
    Handle(Geom_CartesianPoint ) myCartPointA= Handle(Geom_CartesianPoint)::DownCast (myGeomPointBA);
    //    Handle(Geom_CartesianPoint ) myCartPointA= *(Handle(Geom_CartesianPoint)*)& (theAISPointA->Component() ) ;

    Handle(Geom_Point ) myGeomPointB=  theAISPointB->Component();
    Handle(Geom_CartesianPoint ) myCartPointB= Handle(Geom_CartesianPoint)::DownCast (myGeomPointB);
    //    Handle(Geom_CartesianPoint ) myCartPointB= *(Handle(Geom_CartesianPoint)*)& (theAISPointB->Component() ) ;

    if (myCartPointB->X()==myCartPointA->X() && myCartPointB->Y()==myCartPointA->Y() && myCartPointB->Z()==myCartPointA->Z() ) {
      // B=A
      di<<"vline error: same points\n";return 1;
    }
    // Les deux points sont OK...Construction de l'AIS_Line (en faite, le segment AB)
    Handle(AIS_Line) theAISLine= new AIS_Line(myCartPointA,myCartPointB );
    GetMapOfAIS().Bind(theAISLine,argv[1] );
    TheAISContext()->Display (theAISLine, Standard_True);

  }

  // Parametres 6 Reals
  // ==================

  else if (argc==8) {
    // On verifie que les deux points ne sont pas confondus

    Standard_Real coord[6];
    for(Standard_Integer i=0;i<=2;i++){
      coord[i]=Draw::Atof(argv[2+i]);
      coord[i+3]=Draw::Atof(argv[5+i]);
    }

    Handle(Geom_CartesianPoint ) myCartPointA=new Geom_CartesianPoint (coord[0],coord[1],coord[2] );
    Handle(Geom_CartesianPoint ) myCartPointB=new Geom_CartesianPoint (coord[3],coord[4],coord[5] );

    Handle(AIS_Line) theAISLine= new AIS_Line(myCartPointA,myCartPointB );
    GetMapOfAIS().Bind(theAISLine,argv[1] );
    TheAISContext()->Display (theAISLine, Standard_True);

  }

  // Pas de parametres: Selection dans le viewer.
  // ============================================

  else
  {
    TopTools_ListOfShape aShapes;
    ViewerTest::GetSelectedShapes (aShapes);
    if (aShapes.Extent() != 2)
    {
      std::cerr << "Error: wrong number of selected shapes.\n";
      return 1;
    }

    const TopoDS_Shape& aShapeA = aShapes.First();
    const TopoDS_Shape& aShapeB = aShapes.Last();

    if (!(aShapeA.ShapeType() == TopAbs_VERTEX
       && aShapeB.ShapeType() == TopAbs_VERTEX))
    {
      std::cerr << "Error: you should select two different vertex.\n";
      return 1;
    }

    // Construction de la line
    gp_Pnt A = BRep_Tool::Pnt (TopoDS::Vertex (aShapeA));
    gp_Pnt B = BRep_Tool::Pnt (TopoDS::Vertex (aShapeB));

    Handle(Geom_CartesianPoint ) myCartPointA=new Geom_CartesianPoint(A);
    Handle(Geom_CartesianPoint ) myCartPointB=new Geom_CartesianPoint(B);

    Handle(AIS_Line) theAISLine= new AIS_Line(myCartPointA,myCartPointB );
    GetMapOfAIS().Bind(theAISLine,argv[1] );
    TheAISContext()->Display (theAISLine, Standard_True);
  }

  return 0;
}

//==============================================================================
// class   : FilledCircle
// purpose : creates filled circle based on AIS_InteractiveObject 
//           and Geom_Circle.
//           This class is used to check method Matches() of class 
//           Select3D_SensitiveCircle with member myFillStatus = Standard_True, 
//           because none of AIS classes provides creation of 
//           Select3D_SensitiveCircle with member myFillStatus = Standard_True 
//           (look method ComputeSelection() )
//============================================================================== 

Handle(Geom_Circle) CreateCircle(gp_Pnt theCenter, Standard_Real theRadius) 
{
  gp_Ax2 anAxes(theCenter, gp_Dir(gp_Vec(0., 0., 1.))); 
  gp_Circ aCirc(anAxes, theRadius);
  Handle(Geom_Circle) aCircle = new Geom_Circle(aCirc);
  return aCircle;
}

class FilledCircle : public AIS_InteractiveObject 
{
public:
    // CASCADE RTTI
    DEFINE_STANDARD_RTTI_INLINE(FilledCircle,AIS_InteractiveObject); 

    FilledCircle(gp_Pnt theCenter, Standard_Real theRadius);
    FilledCircle(Handle(Geom_Circle) theCircle);

private:
    TopoDS_Face ComputeFace();

    // Virtual methods implementation
    void Compute (  const Handle(PrsMgr_PresentationManager3d)& thePresentationManager,
                  const Handle(Prs3d_Presentation)& thePresentation,
                  const Standard_Integer theMode) Standard_OVERRIDE;

    void ComputeSelection (  const Handle(SelectMgr_Selection)& theSelection, 
                           const Standard_Integer theMode) Standard_OVERRIDE;

protected:
    Handle(Geom_Circle) myCircle;
    Standard_Boolean myFilledStatus;

}; 


FilledCircle::FilledCircle(gp_Pnt theCenter, Standard_Real theRadius) 
{
  myCircle = CreateCircle(theCenter, theRadius);
  myFilledStatus = Standard_True;
}

FilledCircle::FilledCircle(Handle(Geom_Circle) theCircle) 
{
  myCircle = theCircle;
  myFilledStatus = Standard_True;
}

TopoDS_Face FilledCircle::ComputeFace() 
{
  // Create edge from myCircle 
  BRepBuilderAPI_MakeEdge anEdgeMaker(myCircle->Circ());
  TopoDS_Edge anEdge = anEdgeMaker.Edge(); 

  // Create wire from anEdge 
  BRepBuilderAPI_MakeWire aWireMaker(anEdge);
  TopoDS_Wire aWire = aWireMaker.Wire();

  // Create face from aWire
  BRepBuilderAPI_MakeFace aFaceMaker(aWire);
  TopoDS_Face aFace = aFaceMaker.Face();

  return aFace;
}

void FilledCircle::Compute(const Handle(PrsMgr_PresentationManager3d) &/*thePresentationManager*/, 
                           const Handle(Prs3d_Presentation) &thePresentation, 
                           const Standard_Integer theMode) 
{
  thePresentation->Clear();

  TopoDS_Face aFace = ComputeFace();

  if (aFace.IsNull()) return;
  if (theMode != 0) return;

  StdPrs_ShadedShape::Add(thePresentation, aFace, myDrawer);
}

void FilledCircle::ComputeSelection(const Handle(SelectMgr_Selection) &theSelection, 
                                    const Standard_Integer /*theMode*/)
{
  Handle(SelectMgr_EntityOwner) anEntityOwner = new SelectMgr_EntityOwner(this);
  Handle(Select3D_SensitiveCircle) aSensitiveCircle = new Select3D_SensitiveCircle(anEntityOwner, 
      myCircle, myFilledStatus);
  theSelection->Add(aSensitiveCircle);
}

//==============================================================================
// Fonction  vcircle
// -----------------  Uniquement par parametre. Pas de selection dans le viewer.
//==============================================================================

//==============================================================================
//function : VCircleBuilder
//purpose  : Build an AIS_Circle
//Draw arg : vcircle CircleName PlaneName PointName Radius IsFilled
//                              PointName PointName PointName IsFilled
//==============================================================================

void DisplayCircle (Handle (Geom_Circle) theGeomCircle,
                    TCollection_AsciiString theName, 
                    Standard_Boolean isFilled) 
{
  Handle(AIS_InteractiveObject) aCircle;
  if (isFilled) 
  {
    aCircle = new FilledCircle(theGeomCircle);
  }
  else
  {
    aCircle = new AIS_Circle(theGeomCircle);
    Handle(AIS_Circle)::DownCast (aCircle)->SetFilledCircleSens (Standard_False);
  }

  // Check if there is an object with given name
  // and remove it from context
  if (GetMapOfAIS().IsBound2(theName)) 
  {
    Handle(AIS_InteractiveObject) anInterObj = GetMapOfAIS().Find2(theName);
    TheAISContext()->Remove(anInterObj, Standard_False);
    GetMapOfAIS().UnBind2(theName);
   }

   // Bind the circle to its name
   GetMapOfAIS().Bind(aCircle, theName);

   // Display the circle
   TheAISContext()->Display (aCircle, Standard_True);
  
}

static int VCircleBuilder(Draw_Interpretor& /*di*/, Standard_Integer argc, const char** argv)
{
  // Verification of the arguments
  if (argc>6 || argc<2) 
  { 
    std::cout << "vcircle error: expect 4 arguments.\n"; 
    return 1; // TCL_ERROR 
  }

  // There are all arguments
  if (argc == 6) 
  {
    // Get arguments
    TCollection_AsciiString aName(argv[1]);
    Standard_Boolean isFilled = Draw::Atoi(argv[5]) != 0;

    Handle(AIS_InteractiveObject) theShapeA, theShapeB;
    GetMapOfAIS().Find2 (argv[2], theShapeA);
    GetMapOfAIS().Find2 (argv[3], theShapeB);

    // Arguments: AIS_Point AIS_Point AIS_Point
    // ========================================
    if (!theShapeA.IsNull() && !theShapeB.IsNull() &&
      theShapeA->Type()==AIS_KOI_Datum && theShapeA->Signature()==1)
    {
      if (theShapeB->Type()!=AIS_KOI_Datum || theShapeB->Signature()!=1 ) 
      {
        std::cout << "vcircle error: 2d argument is unexpected to be a point.\n";
        return 1; // TCL_ERROR 
      }
      // The third object must be a point
      Handle(AIS_InteractiveObject) theShapeC;
      GetMapOfAIS().Find2 (argv[4], theShapeC);
      if (theShapeC.IsNull() ||
        theShapeC->Type()!=AIS_KOI_Datum || theShapeC->Signature()!=1 ) 
      {
        std::cout << "vcircle error: 3d argument is unexpected to be a point.\n";
        return 1; // TCL_ERROR 
      }
        // tag
        // Verify that the three points are different
        Handle(AIS_Point) theAISPointA = Handle(AIS_Point)::DownCast(theShapeA);
        Handle(AIS_Point) theAISPointB = Handle(AIS_Point)::DownCast(theShapeB);
        Handle(AIS_Point) theAISPointC = Handle(AIS_Point)::DownCast(theShapeC);
        
        Handle(Geom_Point) myGeomPointA = theAISPointA->Component();
        Handle(Geom_CartesianPoint) myCartPointA = 
          Handle(Geom_CartesianPoint)::DownCast(myGeomPointA);

        Handle(Geom_Point) myGeomPointB = theAISPointB->Component();
        Handle(Geom_CartesianPoint) myCartPointB =
          Handle(Geom_CartesianPoint)::DownCast(myGeomPointB);

        Handle(Geom_Point) myGeomPointC = theAISPointC->Component();
        Handle(Geom_CartesianPoint) myCartPointC =
          Handle(Geom_CartesianPoint)::DownCast(myGeomPointC);

        // Test A=B
        if (Abs(myCartPointA->X()-myCartPointB->X()) <= Precision::Confusion() && 
            Abs(myCartPointA->Y()-myCartPointB->Y()) <= Precision::Confusion() && 
            Abs(myCartPointA->Z()-myCartPointB->Z()) <= Precision::Confusion() ) 
        {
          std::cout << "vcircle error: Same points.\n"; 
          return 1; // TCL_ERROR 
        }
        // Test A=C
        if (Abs(myCartPointA->X()-myCartPointC->X()) <= Precision::Confusion() &&
            Abs(myCartPointA->Y()-myCartPointC->Y()) <= Precision::Confusion() && 
            Abs(myCartPointA->Z()-myCartPointC->Z()) <= Precision::Confusion() ) 
        {
          std::cout << "vcircle error: Same points.\n"; 
          return 1; // TCL_ERROR 
        }
        // Test B=C
        if (Abs(myCartPointB->X()-myCartPointC->X()) <= Precision::Confusion() && 
            Abs(myCartPointB->Y()-myCartPointC->Y()) <= Precision::Confusion() && 
            Abs(myCartPointB->Z()-myCartPointC->Z()) <= Precision::Confusion() ) 
        {
          std::cout << "vcircle error: Same points.\n"; 
          return 1;// TCL_ERROR 
        }
        // Construction of the circle
        GC_MakeCircle Cir = GC_MakeCircle (myCartPointA->Pnt(), 
          myCartPointB->Pnt(), myCartPointC->Pnt() );
        Handle (Geom_Circle) theGeomCircle;
        try 
        {
          theGeomCircle = Cir.Value();
        }
        catch (StdFail_NotDone)
        {
          std::cout << "vcircle error: can't create circle\n";
          return -1; // TCL_ERROR
        }
        
        DisplayCircle(theGeomCircle, aName, isFilled);
    }

    // Arguments: AIS_Plane AIS_Point Real
    // ===================================
    else if (theShapeA->Type() == AIS_KOI_Datum && 
      theShapeA->Signature() == 7 ) 
    {
      if (theShapeB->Type() != AIS_KOI_Datum || 
        theShapeB->Signature() != 1 ) 
      {
        std::cout << "vcircle error: 2d element is a unexpected to be a point.\n"; 
        return 1; // TCL_ERROR 
      }
      // Check that the radius is >= 0
      if (Draw::Atof(argv[4]) <= 0 ) 
      {
        std::cout << "vcircle error: the radius must be >=0.\n"; 
        return 1; // TCL_ERROR 
      }

      // Recover the normal to the plane
      Handle(AIS_Plane) theAISPlane = Handle(AIS_Plane)::DownCast(theShapeA);
      Handle(AIS_Point) theAISPointB = Handle(AIS_Point)::DownCast(theShapeB); 

      Handle(Geom_Plane) myGeomPlane = theAISPlane->Component();
      Handle(Geom_Point) myGeomPointB = theAISPointB->Component();
      Handle(Geom_CartesianPoint) myCartPointB = 
        Handle(Geom_CartesianPoint)::DownCast(myGeomPointB);

      gp_Pln mygpPlane = myGeomPlane->Pln();
      gp_Ax1 thegpAxe = mygpPlane.Axis();
      gp_Dir theDir = thegpAxe.Direction();
      gp_Pnt theCenter = myCartPointB->Pnt();
      Standard_Real TheR = Draw::Atof(argv[4]);
      GC_MakeCircle Cir = GC_MakeCircle (theCenter, theDir ,TheR);
      Handle (Geom_Circle) theGeomCircle;
      try 
      {
        theGeomCircle = Cir.Value();
      }
      catch (StdFail_NotDone)
      {
        std::cout << "vcircle error: can't create circle\n";
        return -1; // TCL_ERROR
      }

      DisplayCircle(theGeomCircle, aName, isFilled);

    }

    // Error
    else
    {
      std::cout << "vcircle error: 1st argument is a unexpected type.\n"; 
      return 1; // TCL_ERROR 
    }

  }
  // No arguments: selection in the viewer
  // =========================================
  else 
  {
    // Get the name of the circle 
    TCollection_AsciiString aName(argv[1]);

    TopTools_ListOfShape aShapes;
    ViewerTest::GetSelectedShapes (aShapes);
    if (aShapes.Extent() != 3 && aShapes.Extent() != 2)
    {
      std::cerr << "Error: Wrong number of selected shapes.\n";
      return 1;
    }

    const TopoDS_Shape& aShapeA = aShapes.First();
    if (aShapeA.ShapeType() == TopAbs_VERTEX ) 
    {
      if (aShapes.Extent() != 3)
      {
        std::cerr << "Error: wrong number of selected shapes.\n";
        return 1;
      }

      TopTools_ListOfShape::Iterator anIter (aShapes);

      anIter.Next();
      const TopoDS_Shape& aShapeB = anIter.Value();

      anIter.Next();
      const TopoDS_Shape& aShapeC = anIter.Value();
      
      // Get isFilled
      Standard_Boolean isFilled;
      std::cout << "Enter filled status (0 or 1)\n";
      cin >> isFilled;

      // Construction of the circle
      gp_Pnt A = BRep_Tool::Pnt (TopoDS::Vertex (aShapeA));
      gp_Pnt B = BRep_Tool::Pnt (TopoDS::Vertex (aShapeB));
      gp_Pnt C = BRep_Tool::Pnt (TopoDS::Vertex (aShapeC));

      GC_MakeCircle Cir = GC_MakeCircle (A, B, C);
      Handle (Geom_Circle) theGeomCircle;
      try 
      {
        theGeomCircle = Cir.Value();
      }
      catch (StdFail_NotDone)
      {
        std::cout << "vcircle error: can't create circle\n";
        return -1; // TCL_ERROR
      }

      DisplayCircle(theGeomCircle, aName, isFilled);

    }
    else if (aShapeA.ShapeType() == TopAbs_FACE)
    {
      const TopoDS_Shape& aShapeB = aShapes.Last();

      // Recover the radius 
      Standard_Real theRad;
      do 
      {
        std::cout << " Enter the value of the radius:\n";
        cin >> theRad;
      } while (theRad <= 0);
      
      // Get filled status
      Standard_Boolean isFilled;
      std::cout << "Enter filled status (0 or 1)\n";
      cin >> isFilled;

      // Recover the normal to the plane. tag
      TopoDS_Face myFace = TopoDS::Face(aShapeA);
      BRepAdaptor_Surface mySurface (myFace, Standard_False);
      gp_Pln myPlane = mySurface.Plane();
      Handle(Geom_Plane) theGeomPlane = new Geom_Plane (myPlane);
      gp_Pln mygpPlane = theGeomPlane->Pln();
      gp_Ax1 thegpAxe = mygpPlane.Axis();
      gp_Dir theDir = thegpAxe.Direction();

      // Recover the center
      gp_Pnt theCenter = BRep_Tool::Pnt (TopoDS::Vertex (aShapeB));

      // Construct the circle
      GC_MakeCircle Cir = GC_MakeCircle (theCenter, theDir ,theRad);
      Handle (Geom_Circle) theGeomCircle;
      try 
      {
        theGeomCircle = Cir.Value();
      }
      catch (StdFail_NotDone)
      {
        std::cout << "vcircle error: can't create circle\n";
        return -1; // TCL_ERROR
      }

      DisplayCircle(theGeomCircle, aName, isFilled);
    }
    else
    {
      std::cerr << "Error: You should select face and vertex or three vertices.\n";
      return 1;
    }
  }

  return 0;
}

//=======================================================================
//function : VDrawText
//purpose  :
//=======================================================================
static int VDrawText (Draw_Interpretor& theDI,
                      Standard_Integer  theArgsNb,
                      const char**      theArgVec)
{
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext();
  if (theArgsNb < 3)
  {
    std::cout << "Error: wrong number of arguments! See usage:\n";
    theDI.PrintHelp (theArgVec[0]);
    return 1;
  }
  else if (aContext.IsNull())
  {
    std::cout << "Error: no active view!\n";
    return 1;
  }

  Standard_Integer           anArgIt = 1;
  TCollection_ExtendedString aName (theArgVec[anArgIt++], Standard_True);
  TCollection_ExtendedString aText (theArgVec[anArgIt++], Standard_True);
  Handle(AIS_TextLabel)      aTextPrs;
  ViewerTest_AutoUpdater     anAutoUpdater (aContext, ViewerTest::CurrentView());

  Standard_Boolean isNewPrs = Standard_False;
  if (GetMapOfAIS().IsBound2 (aName))
  {
    aTextPrs = Handle(AIS_TextLabel)::DownCast (GetMapOfAIS().Find2 (aName));
  }

  if (aTextPrs.IsNull())
  {
    isNewPrs = Standard_True;
    aTextPrs = new AIS_TextLabel();
    aTextPrs->SetFont ("Courier");
  }

  aTextPrs->SetText (aText);

  Handle(Graphic3d_TransformPers) aTrsfPers;
  Aspect_TypeOfDisplayText aDisplayType = Aspect_TODT_NORMAL;

  Standard_Boolean aHasPlane = Standard_False;
  gp_Dir           aNormal;
  gp_Dir           aDirection;
  gp_Pnt           aPos;

  for (; anArgIt < theArgsNb; ++anArgIt)
  {
    TCollection_AsciiString aParam (theArgVec[anArgIt]);
    aParam.LowerCase();

    if (anAutoUpdater.parseRedrawMode (aParam))
    {
      continue;
    }
    else if (aParam == "-pos"
          || aParam == "-position")
    {
      if (anArgIt + 3 >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      aPos.SetX (Draw::Atof (theArgVec[++anArgIt]));
      aPos.SetY (Draw::Atof (theArgVec[++anArgIt]));
      aPos.SetZ (Draw::Atof (theArgVec[++anArgIt]));
      aTextPrs->SetPosition (aPos);
    }
    else if (aParam == "-color")
    {
      if (anArgIt + 1 >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      TCollection_AsciiString aColor (theArgVec[anArgIt + 1]);
      Quantity_NameOfColor aNameOfColor = Quantity_NOC_BLACK;
      if (Quantity_Color::ColorFromName (aColor.ToCString(), aNameOfColor))
      {
        anArgIt += 1;
        aTextPrs->SetColor (aNameOfColor);
        continue;
      }
      else if (anArgIt + 3 >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      TCollection_AsciiString aGreen (theArgVec[anArgIt + 2]);
      TCollection_AsciiString aBlue  (theArgVec[anArgIt + 3]);
      if (!aColor.IsRealValue()
       || !aGreen.IsRealValue()
       || !aBlue.IsRealValue())
      {
        std::cout << "Error: wrong syntax at '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      const Graphic3d_Vec3d anRGB (aColor.RealValue(),
                                   aGreen.RealValue(),
                                   aBlue.RealValue());

      aTextPrs->SetColor (Quantity_Color (anRGB.r(), anRGB.g(), anRGB.b(), Quantity_TOC_RGB));
      anArgIt += 3;
    }
    else if (aParam == "-halign")
    {
      if (++anArgIt >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      TCollection_AsciiString aType (theArgVec[anArgIt]);
      aType.LowerCase();
      if (aType == "left")
      {
        aTextPrs->SetHJustification (Graphic3d_HTA_LEFT);
      }
      else if (aType == "center")
      {
        aTextPrs->SetHJustification (Graphic3d_HTA_CENTER);
      }
      else if (aType == "right")
      {
        aTextPrs->SetHJustification (Graphic3d_HTA_RIGHT);
      }
      else
      {
        std::cout << "Error: wrong syntax at '" << aParam.ToCString() << "'.\n";
        return 1;
      }
    }
    else if (aParam == "-valign")
    {
      if (++anArgIt >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      TCollection_AsciiString aType (theArgVec[anArgIt]);
      aType.LowerCase();
      if (aType == "top")
      {
        aTextPrs->SetVJustification (Graphic3d_VTA_TOP);
      }
      else if (aType == "center")
      {
        aTextPrs->SetVJustification (Graphic3d_VTA_CENTER);
      }
      else if (aType == "bottom")
      {
        aTextPrs->SetVJustification (Graphic3d_VTA_BOTTOM);
      }
      else if (aType == "topfirstline")
      {
        aTextPrs->SetVJustification (Graphic3d_VTA_TOPFIRSTLINE);
      }
      else
      {
        std::cout << "Error: wrong syntax at '" << aParam.ToCString() << "'.\n";
        return 1;
      }
    }
    else if (aParam == "-angle")
    {
      if (++anArgIt >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      aTextPrs->SetAngle (Draw::Atof (theArgVec[anArgIt]) * (M_PI / 180.0));
    }
    else if (aParam == "-zoom")
    {
      if (++anArgIt >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      aTextPrs->SetZoomable (Draw::Atoi (theArgVec[anArgIt]) == 1);
    }
    else if (aParam == "-height")
    {
      if (++anArgIt >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      aTextPrs->SetHeight (Draw::Atof(theArgVec[anArgIt]));
    }
    else if (aParam == "-aspect")
    {
      if (++anArgIt >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      TCollection_AsciiString anOption (theArgVec[anArgIt]);
      anOption.LowerCase();
      Font_FontAspect aFontAspect = Font_FA_Undefined;
      if (!parseFontStyle (anOption, aFontAspect))
      {
        std::cout << "Error: unknown font aspect '" << anOption << "'.\n";
        return 1;
      }
      aTextPrs->SetFontAspect (aFontAspect);
    }
    else if (aParam == "-font")
    {
      if (++anArgIt >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      aTextPrs->SetFont (theArgVec[anArgIt]);
    }
    else if (aParam == "-plane")
    {
      if (anArgIt + 6 >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      Standard_Real aX = Draw::Atof (theArgVec[++anArgIt]);
      Standard_Real aY = Draw::Atof (theArgVec[++anArgIt]);
      Standard_Real aZ = Draw::Atof (theArgVec[++anArgIt]);
      aNormal.SetCoord (aX, aY, aZ);

      aX = Draw::Atof (theArgVec[++anArgIt]);
      aY = Draw::Atof (theArgVec[++anArgIt]);
      aZ = Draw::Atof (theArgVec[++anArgIt]);
      aDirection.SetCoord (aX, aY, aZ);

      aHasPlane = Standard_True;
    }
    else if (aParam == "-flipping")
    {
      aTextPrs->SetFlipping (Standard_True);
    }
    else if (aParam == "-disptype"
          || aParam == "-displaytype")
    {
      if (++anArgIt >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }
      TCollection_AsciiString aType (theArgVec[anArgIt]);
      aType.LowerCase();
      if (aType == "subtitle")
        aDisplayType = Aspect_TODT_SUBTITLE;
      else if (aType == "decal")
        aDisplayType = Aspect_TODT_DEKALE;
      else if (aType == "blend")
        aDisplayType = Aspect_TODT_BLEND;
      else if (aType == "dimension")
        aDisplayType = Aspect_TODT_DIMENSION;
      else if (aType == "normal")
        aDisplayType = Aspect_TODT_NORMAL;
      else if (aType == "shadow")
        aDisplayType = Aspect_TODT_SHADOW;
      else
      {
        std::cout << "Error: wrong display type '" << aType << "'.\n";
        return 1;
      }
    }
    else if (aParam == "-subcolor"
          || aParam == "-subtitlecolor")
    {
      if (anArgIt + 1 >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      TCollection_AsciiString aColor (theArgVec[anArgIt + 1]);
      Quantity_NameOfColor aNameOfColor = Quantity_NOC_BLACK;
      if (Quantity_Color::ColorFromName (aColor.ToCString(), aNameOfColor))
      {
        anArgIt += 1;
        aTextPrs->SetColorSubTitle (aNameOfColor);
        continue;
      }
      else if (anArgIt + 3 >= theArgsNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      TCollection_AsciiString aGreen (theArgVec[anArgIt + 2]);
      TCollection_AsciiString aBlue  (theArgVec[anArgIt + 3]);
      if (!aColor.IsRealValue()
       || !aGreen.IsRealValue()
       || !aBlue.IsRealValue())
      {
        std::cout << "Error: wrong syntax at '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      const Graphic3d_Vec3d anRGB (aColor.RealValue(),
                                   aGreen.RealValue(),
                                   aBlue.RealValue());

      aTextPrs->SetColorSubTitle (Quantity_Color (anRGB.r(), anRGB.g(), anRGB.b(), Quantity_TOC_RGB));
      anArgIt += 3;
    }
    else if (aParam == "-2d")
    {
      aTrsfPers = new Graphic3d_TransformPers (Graphic3d_TMF_2d);
    }
    else if (aParam == "-trsfperspos"
          || aParam == "-perspos")
    {
      if (anArgIt + 2 >= theArgsNb)
      {
        std::cerr << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      TCollection_AsciiString aX (theArgVec[++anArgIt]);
      TCollection_AsciiString aY (theArgVec[++anArgIt]);
      TCollection_AsciiString aZ = "0";
      if (!aX.IsIntegerValue()
       || !aY.IsIntegerValue())
      {
        std::cerr << "Error: wrong syntax at '" << aParam << "'.\n";
        return 1;
      }
      if (anArgIt + 1 < theArgsNb)
      {
        TCollection_AsciiString aTemp = theArgVec[anArgIt + 1];
        if (aTemp.IsIntegerValue())
        {
          aZ = aTemp;
          ++anArgIt;
        }
      }

      aTrsfPers = Graphic3d_TransformPers::FromDeprecatedParams (Graphic3d_TMF_2d, gp_Pnt (aX.IntegerValue(), aY.IntegerValue(), aZ.IntegerValue()));
    }
    else
    {
      std::cout << "Error: unknown argument '" << aParam << "'\n";
      return 1;
    }
  }

  if (aHasPlane)
  {
    aTextPrs->SetOrientation3D (gp_Ax2 (aPos, aNormal, aDirection));
  }

  aTextPrs->SetDisplayType (aDisplayType);

  if (!aTrsfPers.IsNull())
  {
    aContext->SetTransformPersistence (aTextPrs, aTrsfPers);
    aTextPrs->SetZLayer(Graphic3d_ZLayerId_TopOSD);
    if (aTextPrs->Position().Z() != 0)
    {
      aTextPrs->SetPosition (gp_Pnt(aTextPrs->Position().X(), aTextPrs->Position().Y(), 0));
    }
  }
  else if (!aTextPrs->TransformPersistence().IsNull())
  {
    aContext->SetTransformPersistence (aTextPrs, Handle(Graphic3d_TransformPers)());
  }

  if (isNewPrs)
  {
    ViewerTest::Display (aName, aTextPrs, Standard_False);
  }
  else
  {
    aContext->Redisplay (aTextPrs, Standard_False, Standard_True);
  }
  return 0;
}

#include <math.h>
#include <gp_Pnt.hxx>
#include <Graphic3d_ArrayOfPoints.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <Poly_Array1OfTriangle.hxx>
#include <Poly_Triangle.hxx>
#include <Poly_Triangulation.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TShort_Array1OfShortReal.hxx>
#include <TShort_HArray1OfShortReal.hxx>

#include <AIS_Triangulation.hxx>
#include <StdPrs_ToolTriangulatedShape.hxx>
#include <Poly_Connect.hxx>
#include <TColgp_Array1OfDir.hxx>
#include <Graphic3d_GraphicDriver.hxx>

#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>

#include <BRepPrimAPI_MakeCylinder.hxx>
#include <TopoDS_Shape.hxx>
#include <TopExp_Explorer.hxx>
#include <TopAbs.hxx>
#include <StdSelect_ShapeTypeFilter.hxx>
#include <AIS_InteractiveObject.hxx>


//===============================================================================================
//function : CalculationOfSphere
//author   : psn
//purpose  : Create a Sphere
//===============================================================================================

Handle( Poly_Triangulation ) CalculationOfSphere( double X , double Y , double Z ,
                                                  int res ,
                                                  double Radius ){
  double mRadius = Radius;
  double mCenter[3] = {X,Y,Z};
  int mThetaResolution;
  int mPhiResolution;
  double mStartTheta = 0;//StartTheta;
  double mEndTheta = 360;//EndTheta;
  double mStartPhi = 0;//StartPhi;
  double mEndPhi = 180;//EndPhi;
  res = res < 4 ? 4 : res;

  mThetaResolution = res;
  mPhiResolution = res;

  int i, j;
  int jStart, jEnd, numOffset;
  double x[3], n[3], deltaPhi, deltaTheta, phi, theta, radius;
  double startTheta, endTheta, startPhi, endPhi;
  int base, numPoles=0, thetaResolution, phiResolution;

  int pts[3];
  int piece = -1;
  int numPieces = 1;
  if ( numPieces > mThetaResolution ) {
    numPieces = mThetaResolution;
  }

  int localThetaResolution =  mThetaResolution;
  double localStartTheta =  mStartTheta;
  double localEndTheta =  mEndTheta;

  while ( localEndTheta < localStartTheta ) {
    localEndTheta += 360.0;
  }

  deltaTheta = (localEndTheta - localStartTheta) / localThetaResolution;

  // Change the ivars based on pieces.
  int start, end;
  start = piece * localThetaResolution / numPieces;
  end = (piece+1) * localThetaResolution / numPieces;
  localEndTheta = localStartTheta + (double)(end) * deltaTheta;
  localStartTheta = localStartTheta + (double)(start) * deltaTheta;
  localThetaResolution = end - start;

  // Create north pole if needed
  int number_point = 0;
  int number_pointArray = 0;

  if ( mStartPhi <= 0.0 ) {
    number_pointArray++;
    numPoles++;
  }
  if ( mEndPhi >= 180.0 ) {
    number_pointArray++;
    numPoles++;
  }

  // Check data, determine increments, and convert to radians
  startTheta = (localStartTheta < localEndTheta ? localStartTheta : localEndTheta);
  startTheta *= M_PI  / 180.0;
  endTheta = (localEndTheta > localStartTheta ? localEndTheta : localStartTheta);
  endTheta *= M_PI  / 180.0;


  startPhi = ( mStartPhi <  mEndPhi ?  mStartPhi :  mEndPhi);
  startPhi *= M_PI  / 180.0;
  endPhi = ( mEndPhi >  mStartPhi ?  mEndPhi :  mStartPhi);
  endPhi *= M_PI  / 180.0;

  phiResolution =  mPhiResolution - numPoles;
  deltaPhi = (endPhi - startPhi) / ( mPhiResolution - 1);
  thetaResolution = localThetaResolution;
  if ( fabs(localStartTheta - localEndTheta) < 360.0 ) {
    ++localThetaResolution;
  }
  deltaTheta = (endTheta - startTheta) / thetaResolution;

  jStart = ( mStartPhi <= 0.0 ? 1 : 0);
  jEnd = ( mEndPhi >= 180.0 ?  mPhiResolution - 1 :  mPhiResolution);

  // Create intermediate points
  for ( i = 0; i < localThetaResolution; i++ ) {
    for ( j = jStart; j < jEnd; j++ ) {
        number_pointArray++;
    }
  }

  //Generate mesh connectivity
  base = phiResolution * localThetaResolution;

  int number_triangle = 0 ;
  if ( mStartPhi <= 0.0 ) { // around north pole
    number_triangle += localThetaResolution;
  }

  if ( mEndPhi >= 180.0 ) { // around south pole
    number_triangle += localThetaResolution;
  }

  // bands in-between poles
  for ( i=0; i < localThetaResolution; i++){
    for ( j=0; j < (phiResolution-1); j++){
       number_triangle +=2;
    }
  }

  Handle( Poly_Triangulation ) polyTriangulation = new Poly_Triangulation(number_pointArray, number_triangle, false);
  TColgp_Array1OfPnt& PointsOfArray = polyTriangulation->ChangeNodes();
  Poly_Array1OfTriangle& pArrayTriangle = polyTriangulation->ChangeTriangles();

  if (  mStartPhi <= 0.0 ){
      x[0] =  mCenter[0];
      x[1] =  mCenter[1];
      x[2] =  mCenter[2] +  mRadius;
      PointsOfArray.SetValue(1,gp_Pnt(x[0],x[1],x[2]));
  }

  // Create south pole if needed
  if (  mEndPhi >= 180.0 ){
      x[0] =  mCenter[0];
      x[1] =  mCenter[1];
      x[2] =  mCenter[2] -  mRadius;
      PointsOfArray.SetValue(2,gp_Pnt(x[0],x[1],x[2]));
  }

  number_point = 3;
  for ( i=0; i < localThetaResolution; i++){
    theta = localStartTheta * M_PI / 180.0 + i*deltaTheta;
    for ( j = jStart; j < jEnd; j++){
        phi = startPhi + j*deltaPhi;
        radius =  mRadius * sin((double)phi);
        n[0] = radius * cos((double)theta);
        n[1] = radius * sin((double)theta);
        n[2] =  mRadius * cos((double)phi);
        x[0] = n[0] +  mCenter[0];
        x[1] = n[1] +  mCenter[1];
        x[2] = n[2] +  mCenter[2];
        PointsOfArray.SetValue(number_point,gp_Pnt(x[0],x[1],x[2]));
        number_point++;
      }
    }

  numPoles = 3;
  number_triangle = 1;
  if ( mStartPhi <= 0.0 ){// around north pole
    for (i=0; i < localThetaResolution; i++){
        pts[0] = phiResolution*i + numPoles;
        pts[1] = (phiResolution*(i+1) % base) + numPoles;
        pts[2] = 1;
        pArrayTriangle.SetValue(number_triangle,Poly_Triangle(pts[0],pts[1],pts[2]));
        number_triangle++;
      }
    }

  if (  mEndPhi >= 180.0 ){ // around south pole
    numOffset = phiResolution - 1 + numPoles;
    for (i=0; i < localThetaResolution; i++){
        pts[0] = phiResolution*i + numOffset;
        pts[2] = ((phiResolution*(i+1)) % base) + numOffset;
        pts[1] = numPoles - 1;
        pArrayTriangle.SetValue(number_triangle,Poly_Triangle(pts[0],pts[1],pts[2]));
        number_triangle++;
      }
    }

  // bands in-between poles

  for (i=0; i < localThetaResolution; i++){
    for (j=0; j < (phiResolution-1); j++){
        pts[0] = phiResolution*i + j + numPoles;
        pts[1] = pts[0] + 1;
        pts[2] = ((phiResolution*(i+1)+j) % base) + numPoles + 1;
        pArrayTriangle.SetValue(number_triangle,Poly_Triangle(pts[0],pts[1],pts[2]));
        number_triangle++;
        pts[1] = pts[2];
        pts[2] = pts[1] - 1;
        pArrayTriangle.SetValue(number_triangle,Poly_Triangle(pts[0],pts[1],pts[2]));
        number_triangle++;
      }
    }

  Poly_Connect* pc = new Poly_Connect(polyTriangulation);

  Handle(TShort_HArray1OfShortReal) Normals = new TShort_HArray1OfShortReal(1, polyTriangulation->NbNodes() * 3);

  Standard_Integer index[3];
  Standard_Real Tol = Precision::Confusion();

  gp_Dir Nor;
  for (i = PointsOfArray.Lower(); i <= PointsOfArray.Upper(); i++) {
      gp_XYZ eqPlan(0, 0, 0);
      for ( pc->Initialize(i); pc->More(); pc->Next()) {
        pArrayTriangle(pc->Value()).Get(index[0], index[1], index[2]);
        gp_XYZ v1(PointsOfArray(index[1]).Coord()-PointsOfArray(index[0]).Coord());
        gp_XYZ v2(PointsOfArray(index[2]).Coord()-PointsOfArray(index[1]).Coord());
        gp_XYZ vv = v1^v2;
        Standard_Real mod = vv.Modulus();
        if(mod < Tol) continue;
        eqPlan += vv/mod;
      }

      Standard_Real modmax = eqPlan.Modulus();

      if(modmax > Tol)
        Nor = gp_Dir(eqPlan);
      else
        Nor = gp_Dir(0., 0., 1.);
      
      Standard_Integer k = (i - PointsOfArray.Lower()) * 3;
      Normals->SetValue(k + 1, (Standard_ShortReal)Nor.X());
      Normals->SetValue(k + 2, (Standard_ShortReal)Nor.Y());
      Normals->SetValue(k + 3, (Standard_ShortReal)Nor.Z());
  }

  delete pc;
  polyTriangulation->SetNormals(Normals);

  return polyTriangulation;
}

//===============================================================================================
//function : VDrawSphere
//author   : psn
//purpose  : Create an AIS shape.
//===============================================================================================
static int VDrawSphere (Draw_Interpretor& /*di*/, Standard_Integer argc, const char** argv)
{
  // check for errors
  Handle(AIS_InteractiveContext) aContextAIS = ViewerTest::GetAISContext();
  if (aContextAIS.IsNull())
  {
    std::cout << "Call vinit before!\n";
    return 1;
  }
  else if (argc < 3)
  {
    std::cout << "Use: " << argv[0]
              << " shapeName Fineness [X=0.0 Y=0.0 Z=0.0] [Radius=100.0] [ToShowEdges=0]\n";
    return 1;
  }

  // read the arguments
  TCollection_AsciiString aShapeName (argv[1]);
  Standard_Integer aResolution = Draw::Atoi (argv[2]);
  Standard_Real aCenterX = (argc > 5) ? Draw::Atof (argv[3]) : 0.0;
  Standard_Real aCenterY = (argc > 5) ? Draw::Atof (argv[4]) : 0.0;
  Standard_Real aCenterZ = (argc > 5) ? Draw::Atof (argv[5]) : 0.0;
  Standard_Real aRadius =  (argc > 6) ? Draw::Atof (argv[6]) : 100.0;
  Standard_Boolean toShowEdges = (argc > 7) ? Draw::Atoi (argv[7]) == 1 : Standard_False;
  Standard_Boolean toPrintInfo = (argc > 8) ? Draw::Atoi (argv[8]) == 1 : Standard_True;

  // remove AIS object with given name from map
  VDisplayAISObject (aShapeName, Handle(AIS_InteractiveObject)());

  if (toPrintInfo)
    std::cout << "Compute Triangulation...\n";
  Handle(AIS_Triangulation) aShape
    = new AIS_Triangulation (CalculationOfSphere (aCenterX, aCenterY, aCenterZ,
                                                  aResolution,
                                                  aRadius));
  Standard_Integer aNumberPoints    = aShape->GetTriangulation()->Nodes().Length();
  Standard_Integer aNumberTriangles = aShape->GetTriangulation()->Triangles().Length();

  // stupid initialization of Green color in RGBA space as integer
  // probably wrong for big-endian CPUs
  const Graphic3d_Vec4ub aColor (0, 255, 0, 0);

  // setup colors array per vertex
  Handle(TColStd_HArray1OfInteger) aColorArray = new TColStd_HArray1OfInteger (1, aNumberPoints);
  for (Standard_Integer aNodeId = 1; aNodeId <= aNumberPoints; ++aNodeId)
  {
    aColorArray->SetValue (aNodeId, *reinterpret_cast<const Standard_Integer*> (aColor.GetData()));
  }
  aShape->SetColors (aColorArray);

  // show statistics
  Standard_Integer aPointsSize      = aNumberPoints * 3 * sizeof(float);  // 3x GLfloat
  Standard_Integer aNormalsSize     = aNumberPoints * 3 * sizeof(float);  // 3x GLfloat
  Standard_Integer aColorsSize      = aNumberPoints * 3 * sizeof(float);  // 3x GLfloat without alpha
  Standard_Integer aTrianglesSize   = aNumberTriangles * 3 * sizeof(int); // 3x GLint
  Standard_Integer aPolyConnectSize = aNumberPoints * 4 + aNumberTriangles * 6 * 4;
  Standard_Integer aTotalSize       = aPointsSize + aNormalsSize + aColorsSize + aTrianglesSize;
  aTotalSize >>= 20; //MB
  aNormalsSize >>= 20;
  aColorsSize >>= 20;
  aTrianglesSize >>= 20;
  aPolyConnectSize >>= 20;
  if (toPrintInfo)
  {
    std::cout << "NumberOfPoints:    " << aNumberPoints << "\n"
      << "NumberOfTriangles: " << aNumberTriangles << "\n"
      << "Amount of memory required for PolyTriangulation without Normals: " << (aTotalSize - aNormalsSize) << " Mb\n"
      << "Amount of memory for colors: " << aColorsSize << " Mb\n"
      << "Amount of memory for PolyConnect: " << aPolyConnectSize << " Mb\n"
      << "Amount of graphic card memory required: " << aTotalSize << " Mb\n";
  }

  // Setting material properties, very important for desirable visual result!
  Graphic3d_MaterialAspect aMat (Graphic3d_NOM_PLASTIC);
  aMat.SetAmbient  (0.2f);
  aMat.SetSpecular (0.5f);
  Handle(Graphic3d_AspectFillArea3d) anAspect
    = new Graphic3d_AspectFillArea3d (Aspect_IS_SOLID,
                                      Quantity_NOC_RED,
                                      Quantity_NOC_YELLOW,
                                      Aspect_TOL_SOLID,
                                      1.0,
                                      aMat,
                                      aMat);
  Handle(Prs3d_ShadingAspect) aShAsp = new Prs3d_ShadingAspect();
  if (toShowEdges)
  {
    anAspect->SetEdgeOn();
  }
  else
  {
    anAspect->SetEdgeOff();
  }
  aShAsp->SetAspect (anAspect);
  aShape->Attributes()->SetShadingAspect (aShAsp);

  VDisplayAISObject (aShapeName, aShape);
  return 0;
}

//=============================================================================
//function : VComputeHLR
//purpose  :
//=============================================================================

static int VComputeHLR (Draw_Interpretor& ,
                        Standard_Integer theArgNb,
                        const char** theArgVec)
{
  TCollection_AsciiString aShapeName, aHlrName;
  TopoDS_Shape aSh;
  gp_Pnt anEye;
  gp_Dir aDir;
  gp_Ax2 aProjAx;
  bool hasViewDirArg = false;
  Prs3d_TypeOfHLR anAlgoType = Prs3d_TOH_PolyAlgo;
  bool toShowTangentEdges = false, toShowHiddenEdges = false;
  int aNbIsolines = 0;
  if (Handle(V3d_Viewer) aViewer = ViewerTest::GetViewerFromContext())
  {
    gp_Dir aRight;
    Handle(V3d_View) aView = ViewerTest::CurrentView();
    Standard_Integer aWidth, aHeight;
    Standard_Real aCentX, aCentY, aCentZ, aDirX, aDirY, aDirZ;
    Standard_Real aRightX, aRightY, aRightZ;
    aView->Window()->Size (aWidth, aHeight);

    aView->ConvertWithProj (aWidth, aHeight/2, 
                            aRightX, aRightY, aRightZ,
                            aDirX, aDirY, aDirZ);
    aView->ConvertWithProj (aWidth/2, aHeight/2, 
                            aCentX, aCentY, aCentZ,
                            aDirX, aDirY, aDirZ);

    anEye.SetCoord (-aCentX, -aCentY, -aCentZ);
    aDir.SetCoord (-aDirX, -aDirY, -aDirZ);
    aRight.SetCoord (aRightX - aCentX, aRightY - aCentY, aRightZ - aCentZ);
    aProjAx.SetLocation (anEye);
    aProjAx.SetDirection (aDir);
    aProjAx.SetXDirection (aRight);
  }
  for (Standard_Integer anArgIter = 1; anArgIter < theArgNb; ++anArgIter)
  {
    TCollection_AsciiString anArgCase (theArgVec[anArgIter]);
    anArgCase.LowerCase();
    if (anArgIter + 1 < theArgNb
     && (anArgCase == "-algotype"
      || anArgCase == "-algo"
      || anArgCase == "-type"))
    {
      TCollection_AsciiString anArgNext (theArgVec[++anArgIter]);
      anArgNext.LowerCase();
      if (anArgNext == "polyalgo")
      {
        anAlgoType = Prs3d_TOH_PolyAlgo;
      }
      else if (anArgNext == "algo")
      {
        anAlgoType = Prs3d_TOH_Algo;
      }
      else
      {
        std::cout << "Syntax error: unknown algo type '" << anArgNext << "'\n";
        return 1;
      }
    }
    else if (anArgCase == "-showhiddenedges"
          || anArgCase == "-hiddenedges"
          || anArgCase == "-hidden")
    {
      toShowHiddenEdges = true;
      if (anArgIter + 1 < theArgNb
       && ViewerTest::ParseOnOff (theArgVec[anArgIter + 1], toShowHiddenEdges))
      {
        ++anArgIter;
      }
    }
    else if (anArgCase == "-showtangentedges"
          || anArgCase == "-tangentedges"
          || anArgCase == "-tangent")
    {
      toShowTangentEdges = true;
      if (anArgIter + 1 < theArgNb
       && ViewerTest::ParseOnOff (theArgVec[anArgIter + 1], toShowTangentEdges))
      {
        ++anArgIter;
      }
    }
    else if (anArgIter + 1 < theArgNb
          && (anArgCase == "-nbiso"
           || anArgCase == "-nbisolines"))
    {
      aNbIsolines = Draw::Atoi (theArgVec[++anArgIter]);
    }
    else if (aSh.IsNull())
    {
      aSh = DBRep::Get (theArgVec[anArgIter]);
      aShapeName = theArgVec[anArgIter];
      if (aSh.IsNull())
      {
        BRep_Builder aBrepBuilder;
        BRepTools::Read (aSh, theArgVec[anArgIter], aBrepBuilder);
        if (aSh.IsNull())
        {
          std::cout << "Syntax error: no shape with name " << theArgVec[anArgIter] << " found\n";
          return 1;
        }
      }
    }
    else if (aHlrName.IsEmpty())
    {
      aHlrName = theArgVec[anArgIter];
    }
    else if (!hasViewDirArg
          && anArgIter + 8 < theArgNb)
    {
      hasViewDirArg = true;
      gp_Dir anUp;
      anEye.SetCoord (Draw::Atof (theArgVec[anArgIter + 0]), Draw::Atof (theArgVec[anArgIter + 1]), Draw::Atof (theArgVec[anArgIter + 2]));
      aDir .SetCoord (Draw::Atof (theArgVec[anArgIter + 3]), Draw::Atof (theArgVec[anArgIter + 4]), Draw::Atof (theArgVec[anArgIter + 5]));
      anUp .SetCoord (Draw::Atof (theArgVec[anArgIter + 6]), Draw::Atof (theArgVec[anArgIter + 7]), Draw::Atof (theArgVec[anArgIter + 8]));
      aProjAx.SetLocation (anEye);
      aProjAx.SetDirection (aDir);
      aProjAx.SetYDirection (anUp);
      anArgIter += 8;
    }
    else
    {
      std::cout << "Syntax error: unknown argument '" << theArgVec[anArgIter] << "'\n";
      return 1;
    }
  }

  if (aHlrName.IsEmpty() || aSh.IsNull()
   || (ViewerTest::GetAISContext().IsNull() && hasViewDirArg))
  {
    std::cout << "Syntax error: wrong number of arguments\n";
    return 1;
  }

  HLRAlgo_Projector aProjector (aProjAx);
  TopoDS_Shape aVisible[6];
  TopoDS_Shape aHidden[6];
  if (anAlgoType == Prs3d_TOH_PolyAlgo)
  {
    Handle(HLRBRep_PolyAlgo) aPolyAlgo = new HLRBRep_PolyAlgo();
    aPolyAlgo->Projector (aProjector);
    aPolyAlgo->Load (aSh);
    aPolyAlgo->Update();

    HLRBRep_PolyHLRToShape aHLRToShape;
    aHLRToShape.Update (aPolyAlgo);

    aVisible[HLRBRep_Sharp]   = aHLRToShape.VCompound();
    aVisible[HLRBRep_OutLine] = aHLRToShape.OutLineVCompound(); // extract visible outlines
    aVisible[HLRBRep_RgNLine] = aHLRToShape.RgNLineVCompound();
    if (toShowTangentEdges)
    {
      aVisible[HLRBRep_Rg1Line] = aHLRToShape.Rg1LineVCompound();
    }
    if (toShowHiddenEdges)
    {
      aHidden[HLRBRep_Sharp]   = aHLRToShape.HCompound();
      aHidden[HLRBRep_OutLine] = aHLRToShape.OutLineHCompound();
      aHidden[HLRBRep_RgNLine] = aHLRToShape.RgNLineHCompound();
      if (toShowTangentEdges)
      {
        aHidden[HLRBRep_Rg1Line] = aHLRToShape.Rg1LineHCompound();
      }
    }
  }
  else
  {
    Handle(HLRBRep_Algo) aHlrAlgo = new HLRBRep_Algo();
    aHlrAlgo->Add (aSh, aNbIsolines);
    aHlrAlgo->Projector (aProjector);
    aHlrAlgo->Update();
    aHlrAlgo->Hide();

    HLRBRep_HLRToShape aHLRToShape (aHlrAlgo);
    aVisible[HLRBRep_Sharp]   = aHLRToShape.VCompound();
    aVisible[HLRBRep_OutLine] = aHLRToShape.OutLineVCompound();
    aVisible[HLRBRep_RgNLine] = aHLRToShape.RgNLineVCompound();
    if (toShowTangentEdges)
    {
      aVisible[HLRBRep_Rg1Line] = aHLRToShape.Rg1LineVCompound();
    }
    aVisible[HLRBRep_IsoLine] = aHLRToShape.IsoLineVCompound();

    if (toShowHiddenEdges)
    {
      aHidden[HLRBRep_Sharp]   = aHLRToShape.HCompound();
      aHidden[HLRBRep_OutLine] = aHLRToShape.OutLineHCompound();
      aHidden[HLRBRep_RgNLine] = aHLRToShape.RgNLineHCompound();
      if (toShowTangentEdges)
      {
        aHidden[HLRBRep_Rg1Line] = aHLRToShape.Rg1LineHCompound();
      }
      aHidden[HLRBRep_IsoLine] = aHLRToShape.IsoLineHCompound();
    }
    // extract 3d
    //aVisible[HLRBRep_Sharp]   = aHLRToShape.CompoundOfEdges (HLRBRep_Sharp, Standard_True, Standard_True);
    //aVisible[HLRBRep_OutLine] = aHLRToShape.OutLineVCompound3d();
  }

  TopoDS_Compound aCompRes, aCompVis, aCompHid;
  BRep_Builder aBuilder;
  aBuilder.MakeCompound (aCompVis);
  aBuilder.MakeCompound (aCompHid);
  aBuilder.MakeCompound (aCompRes);
  for (int aTypeIter = 0; aTypeIter < 6; ++aTypeIter)
  {
    if (!aVisible[aTypeIter].IsNull())
    {
      aBuilder.Add (aCompVis, aVisible[aTypeIter]);
    }
    if (!aHidden[aTypeIter].IsNull())
    {
      aBuilder.Add (aCompHid, aHidden[aTypeIter]);
    }
  }
  aBuilder.Add (aCompRes, aCompVis);
  aBuilder.Add (aCompRes, aCompHid);

  // create an AIS shape and display it
  if (!ViewerTest::GetAISContext().IsNull())
  {
    Handle(AIS_ColoredShape) anObject = new AIS_ColoredShape (aCompRes);
    if (toShowHiddenEdges)
    {
      Handle(Prs3d_LineAspect) aLineAspect = new Prs3d_LineAspect (Quantity_Color (Quantity_NOC_RED), Aspect_TOL_DASH, 1.0f);
      for (int aTypeIter = 0; aTypeIter < 6; ++aTypeIter)
      {
        if (!aHidden[aTypeIter].IsNull())
        {
          Handle(AIS_ColoredDrawer) aDrawer = anObject->CustomAspects (aHidden[aTypeIter]);
          aDrawer->SetLineAspect (aLineAspect);
          aDrawer->SetWireAspect (aLineAspect);
          aDrawer->SetFreeBoundaryAspect (aLineAspect);
          aDrawer->SetUnFreeBoundaryAspect (aLineAspect);
        }
      }
    }
    ViewerTest::Display (aHlrName, anObject, true);
  }

  DBRep::Set (aHlrName.ToCString(), aCompRes);
  return 0;
}

// This class is a wrap for Graphic3d_ArrayOfPrimitives; it is used for
// manipulating and displaying such an array with AIS context

class MyPArrayObject : public AIS_InteractiveObject
{

public:

  MyPArrayObject (const Handle(Graphic3d_ArrayOfPrimitives)& thePArray) : myPArray (thePArray) {}

  MyPArrayObject (Graphic3d_TypeOfPrimitiveArray thePrimType,
                  const Handle(TColStd_HArray1OfAsciiString)& theDesc,
                  const Handle(Graphic3d_AspectMarker3d)& theMarkerAspect)
  {
    Init (thePrimType, theDesc, theMarkerAspect, Standard_False);
  }

  //! Initialize the array from specified description.
  Standard_Boolean Init (Graphic3d_TypeOfPrimitiveArray thePrimType,
                         const Handle(TColStd_HArray1OfAsciiString)& theDesc,
                         const Handle(Graphic3d_AspectMarker3d)& theMarkerAspect,
                         Standard_Boolean theToPatch);

  DEFINE_STANDARD_RTTI_INLINE(MyPArrayObject,AIS_InteractiveObject);

  virtual Standard_Boolean AcceptDisplayMode (const Standard_Integer theMode) const Standard_OVERRIDE { return theMode == 0; }

private:

  void Compute (const Handle(PrsMgr_PresentationManager3d)& aPresentationManager,
                const Handle(Prs3d_Presentation)& aPresentation,
                const Standard_Integer aMode) Standard_OVERRIDE;

  void ComputeSelection (const Handle(SelectMgr_Selection)& theSelection,
                         const Standard_Integer /*theMode*/) Standard_OVERRIDE;

  bool CheckInputCommand (const TCollection_AsciiString theCommand,
                          const Handle(TColStd_HArray1OfAsciiString)& theArgsArray,
                          Standard_Integer &theArgIndex,
                          Standard_Integer theArgCount,
                          Standard_Integer theMaxArgs);

protected:

  Handle(Graphic3d_AspectMarker3d) myMarkerAspect;
  Handle(Graphic3d_ArrayOfPrimitives) myPArray;

};

void MyPArrayObject::Compute (const Handle(PrsMgr_PresentationManager3d)& /*aPresentationManager*/,
                              const Handle(Prs3d_Presentation)& thePrs,
                              const Standard_Integer theMode)
{
  if (myPArray.IsNull() || theMode != 0)
  {
    return;
  }

  Handle(Graphic3d_Group) aGroup = thePrs->NewGroup();
  if (!myMarkerAspect.IsNull())
  {
    aGroup->SetGroupPrimitivesAspect (myMarkerAspect);
  }
  aGroup->SetGroupPrimitivesAspect (myDrawer->LineAspect()->Aspect());
  aGroup->SetGroupPrimitivesAspect (myDrawer->ShadingAspect()->Aspect());
  aGroup->AddPrimitiveArray (myPArray);
}

Standard_Boolean MyPArrayObject::Init (Graphic3d_TypeOfPrimitiveArray thePrimType,
                                       const Handle(TColStd_HArray1OfAsciiString)& theDesc,
                                       const Handle(Graphic3d_AspectMarker3d)& theMarkerAspect,
                                       Standard_Boolean theToPatch)
{
  myMarkerAspect = theMarkerAspect;
  if (!theToPatch)
  {
    myPArray.Nullify();
  }

  // Parsing array description
  Standard_Integer aVertexNum = 0, aBoundNum = 0, aEdgeNum = 0;
  Graphic3d_ArrayFlags anArrayFlags = Graphic3d_ArrayFlags_None;

  const Standard_Integer anArgsCount = theDesc->Length();
  TCollection_AsciiString aCommand;
  for (Standard_Integer anArgIndex = theDesc->Lower(); anArgIndex <= theDesc->Upper(); )
  {
    aCommand = theDesc->Value (anArgIndex);
    aCommand.LowerCase();

    if (CheckInputCommand ("-deinterleaved", theDesc, anArgIndex, 0, anArgsCount))
    {
      anArrayFlags |= Graphic3d_ArrayFlags_AttribsDeinterleaved;
    }
    else if (CheckInputCommand ("-mutable", theDesc, anArgIndex, 0, anArgsCount))
    {
      anArrayFlags |= Graphic3d_ArrayFlags_AttribsMutable;
      anArrayFlags |= Graphic3d_ArrayFlags_IndexesMutable;
    }
    // vertex command
    else if (CheckInputCommand ("v", theDesc, anArgIndex, 3, anArgsCount))
    {
      // vertex has a normal or normal with color or texel
      if (CheckInputCommand ("n", theDesc, anArgIndex, 3, anArgsCount))
      {
        anArrayFlags = anArrayFlags | Graphic3d_ArrayFlags_VertexNormal;
      }

      // vertex has a color
      if (CheckInputCommand ("c", theDesc, anArgIndex, 3, anArgsCount))
      {
        anArrayFlags = anArrayFlags | Graphic3d_ArrayFlags_VertexColor;
      }

      // vertex has a texel
      if (CheckInputCommand ("t", theDesc, anArgIndex, 2, anArgsCount))
      {
        anArrayFlags = anArrayFlags | Graphic3d_ArrayFlags_VertexTexel;
      }

      aVertexNum++;
    }
    // bound command
    else if (CheckInputCommand ("b", theDesc, anArgIndex, 1, anArgsCount))
    {
      // bound has color
      if (CheckInputCommand ("c", theDesc, anArgIndex, 3, anArgsCount))
      {
        anArrayFlags = anArrayFlags | Graphic3d_ArrayFlags_BoundColor;
      }

      aBoundNum++;
    }
    // edge command
    else if (CheckInputCommand ("e", theDesc, anArgIndex, 1, anArgsCount))
    {
      aEdgeNum++;
    }
    // unknown command
    else
      anArgIndex++;
  }

  if (myPArray.IsNull())
  {
    myPArray = Graphic3d_ArrayOfPrimitives::CreateArray (thePrimType, aVertexNum, aBoundNum, aEdgeNum, anArrayFlags);
  }
  else
  {
    if (myPArray->Type() != thePrimType
    ||  aVertexNum > myPArray->VertexNumberAllocated()
    ||  aEdgeNum   > myPArray->EdgeNumberAllocated()
    ||  aBoundNum  > myPArray->BoundNumberAllocated()
    || !myPArray->Attributes()->IsMutable()
    || (!myPArray->Indices().IsNull() && !myPArray->Indices()->IsMutable()))
    {
      std::cout << "Syntax error: array cannot be patched\n";
      return Standard_False;
    }

    myPArray->Attributes()->NbElements = aVertexNum;
    if (Handle(Graphic3d_AttribBuffer) anAttribs = Handle(Graphic3d_AttribBuffer)::DownCast (myPArray->Attributes()))
    {
      anAttribs->Invalidate (0, aVertexNum - 1);
    }
    if (!myPArray->Indices().IsNull())
    {
      myPArray->Indices()->NbElements = aEdgeNum;
    }
    if (!myPArray->Bounds().IsNull())
    {
      myPArray->Bounds()->NbBounds = aBoundNum;
    }
  }

  Standard_Integer aVertIndex = 0;
  for (Standard_Integer anArgIndex = theDesc->Lower(); anArgIndex <= theDesc->Upper(); )
  {
    aCommand = theDesc->Value (anArgIndex);
    aCommand.LowerCase();
    if (!aCommand.IsAscii()
      || aCommand.IsEmpty())
    {
      break;
    }

    // skip beautifiers (syntax is not actually validated)
    if (aCommand == "-deinterleaved"
     || aCommand == "-mutable"
     || aCommand.Value (1) == '('
     || aCommand.Value (1) == ')'
     || aCommand.Value (1) == ',')
    {
      ++anArgIndex;
    }
    // vertex command
    else if (CheckInputCommand ("v", theDesc, anArgIndex, 3, anArgsCount))
    {
      const Graphic3d_Vec3 aVert ((float )theDesc->Value (anArgIndex - 3).RealValue(),
                                  (float )theDesc->Value (anArgIndex - 2).RealValue(),
                                  (float )theDesc->Value (anArgIndex - 1).RealValue());
      if ((anArrayFlags & Graphic3d_ArrayFlags_AttribsDeinterleaved) != 0
       || (anArrayFlags & Graphic3d_ArrayFlags_AttribsMutable) != 0)
      {
        ++aVertIndex;
        myPArray->SetVertice (aVertIndex, aVert.x(), aVert.y(), aVert.z());
      }
      else
      {
        aVertIndex = myPArray->AddVertex (aVert);
      }

      // vertex has a normal or normal with color or texel
      if (CheckInputCommand ("n", theDesc, anArgIndex, 3, anArgsCount))
      {
        const Graphic3d_Vec3 aNorm ((float )theDesc->Value (anArgIndex - 3).RealValue(),
                                    (float )theDesc->Value (anArgIndex - 2).RealValue(),
                                    (float )theDesc->Value (anArgIndex - 1).RealValue());
        myPArray->SetVertexNormal (aVertIndex, aNorm.x(), aNorm.y(), aNorm.z());
      }
      
      if (CheckInputCommand ("c", theDesc, anArgIndex, 3, anArgsCount))
      {
        const Graphic3d_Vec3d aCol (theDesc->Value (anArgIndex - 3).RealValue(),
                                    theDesc->Value (anArgIndex - 2).RealValue(),
                                    theDesc->Value (anArgIndex - 1).RealValue());
        myPArray->SetVertexColor (aVertIndex, aCol.r(), aCol.g(), aCol.b());
      }
      if (CheckInputCommand ("t", theDesc, anArgIndex, 2, anArgsCount))
      {
        const Graphic3d_Vec2 aTex ((float )theDesc->Value (anArgIndex - 2).RealValue(),
                                   (float )theDesc->Value (anArgIndex - 1).RealValue());
        myPArray->SetVertexTexel (aVertIndex, aTex.x(), aTex.y());
      }
    }
    // bounds command
    else if (CheckInputCommand ("b", theDesc, anArgIndex, 1, anArgsCount))
    {
      Standard_Integer aVertCount = theDesc->Value (anArgIndex - 1).IntegerValue();

      if (CheckInputCommand ("c", theDesc, anArgIndex, 3, anArgsCount))
        myPArray->AddBound (aVertCount,
                            theDesc->Value (anArgIndex - 3).RealValue(),
                            theDesc->Value (anArgIndex - 2).RealValue(),
                            theDesc->Value (anArgIndex - 1).RealValue());

      else
        myPArray->AddBound (aVertCount);
    }
    // edge command
    else if (CheckInputCommand ("e", theDesc, anArgIndex, 1, anArgsCount))
    {
      const Standard_Integer anEdge = theDesc->Value (anArgIndex - 1).IntegerValue();
      myPArray->AddEdge (anEdge);
    }
    // unknown command
    else
    {
      std::cout << "Syntax error: unknown argument '" << theDesc->Value(anArgIndex) << "'\n";
      return Standard_False;
    }
  }
  return Standard_True;
}

void MyPArrayObject::ComputeSelection (const Handle(SelectMgr_Selection)& theSelection,
                                       const Standard_Integer theMode)
{
  if (theMode != 0
   || myPArray.IsNull())
  {
    return;
  }

  Handle(SelectMgr_EntityOwner) anOwner = new SelectMgr_EntityOwner (this);
  if (Handle(Graphic3d_ArrayOfTriangles) aTris = Handle(Graphic3d_ArrayOfTriangles)::DownCast (myPArray))
  {
    Handle(Select3D_SensitivePrimitiveArray) aSensitive = new Select3D_SensitivePrimitiveArray (anOwner);
    aSensitive->InitTriangulation (myPArray->Attributes(), myPArray->Indices(), TopLoc_Location(), true);
    theSelection->Add (aSensitive);
  }
  else if (Handle(Graphic3d_ArrayOfSegments) aSegs = Handle(Graphic3d_ArrayOfSegments)::DownCast (myPArray))
  {
    if (aSegs->EdgeNumber() > 0)
    {
      for (Standard_Integer aPntIter = 1; aPntIter <= aSegs->EdgeNumber(); aPntIter += 2)
      {
        Handle(Select3D_SensitiveSegment) aSeg = new Select3D_SensitiveSegment (anOwner, aSegs->Vertice (aSegs->Edge (aPntIter)), aSegs->Vertice (aSegs->Edge (aPntIter + 1)));
        aSeg->SetSensitivityFactor (4);
        theSelection->Add (aSeg);
      }
    }
    else
    {
      for (Standard_Integer aPntIter = 1; aPntIter <= aSegs->VertexNumber(); aPntIter += 2)
      {
        Handle(Select3D_SensitiveSegment) aSeg = new Select3D_SensitiveSegment (anOwner, aSegs->Vertice (aPntIter), aSegs->Vertice (aPntIter + 1));
        aSeg->SetSensitivityFactor (4);
        theSelection->Add (aSeg);
      }
    }
  }
  else
  {
    Handle(Select3D_SensitivePrimitiveArray) aSensitive = new Select3D_SensitivePrimitiveArray (anOwner);
    aSensitive->SetSensitivityFactor (8);
    aSensitive->InitPoints (myPArray->Attributes(), myPArray->Indices(), TopLoc_Location(), true);
    theSelection->Add (aSensitive);
  }
}

bool MyPArrayObject::CheckInputCommand (const TCollection_AsciiString theCommand,
                                       const Handle(TColStd_HArray1OfAsciiString)& theArgsArray,
                                       Standard_Integer &theArgIndex,
                                       Standard_Integer theArgCount,
                                       Standard_Integer theMaxArgs)
{
  // check if there is more elements than expected
  if (theArgIndex >= theMaxArgs)
    return false;

  TCollection_AsciiString aStrCommand = theArgsArray->Value (theArgIndex);
  aStrCommand.LowerCase();
  if (aStrCommand.Search(theCommand) != 1 ||
      theArgIndex + (theArgCount - 1) >= theMaxArgs)
    return false;

  // go to the first data element
  theArgIndex++;

  // check data if it can be converted to numeric
  for (int aElement = 0; aElement < theArgCount; aElement++, theArgIndex++)
  {
    aStrCommand = theArgsArray->Value (theArgIndex);
    if (!aStrCommand.IsRealValue())
      return false;
  }

  return true;
}

//=============================================================================
//function : VDrawPArray
//purpose  : Draws primitives array from list of vertexes, bounds, edges
//=============================================================================

static int VDrawPArray (Draw_Interpretor& di, Standard_Integer argc, const char** argv)
{
  Handle(AIS_InteractiveContext) aContextAIS = ViewerTest::GetAISContext();
  if (aContextAIS.IsNull())
  {
    std::cout << "Error: no active Viewer\n";
    return 1;
  }
  else if (argc < 3)
  {
    std::cout << "Syntax error: wrong number of arguments\n";
    return 1;
  }

  // read the arguments
  Standard_Integer anArgIndex = 1;
  TCollection_AsciiString aName (argv[anArgIndex++]);
  TCollection_AsciiString anArrayType (argv[anArgIndex++]);
  anArrayType.LowerCase();
  Handle(MyPArrayObject) aPObject;
  if (anArrayType == "-shape")
  {
    Standard_CString aShapeName = argv[anArgIndex++];
    TopoDS_Shape aShape = DBRep::Get (aShapeName);
    Handle(Graphic3d_ArrayOfPrimitives) aTris = StdPrs_ShadedShape::FillTriangles (aShape);
    if (aShape.IsNull())
    {
      std::cout << "Syntax error: shape '" << aShapeName << "' is not found\n";
      return 1;
    }
    else if (aTris.IsNull())
    {
      std::cout << "Syntax error: shape '" << aShapeName << "' is not triangulated\n";
      return 1;
    }

    aPObject = new MyPArrayObject (aTris);
    ViewerTest::Display (aName, aPObject);
    return 0;
  }
  else if (anArrayType == "-patch"
        || anArrayType == "-modify"
        || anArrayType == "-edit")
  {
    if (argc >= 3)
    {
      anArrayType = argv[anArgIndex++];
      anArrayType.LowerCase();
    }

    if (GetMapOfAIS().IsBound2 (aName))
    {
      aPObject = Handle(MyPArrayObject)::DownCast (GetMapOfAIS().Find2 (aName));
    }
    if (aPObject.IsNull())
    {
      std::cout << "Syntax error: object '" << aName << "' cannot be found\n";
      return 1;
    }
  }

  Standard_Boolean hasVertex = Standard_False;

  Graphic3d_TypeOfPrimitiveArray aPrimType = Graphic3d_TOPA_UNDEFINED;
  if (anArrayType == "points")
  {
    aPrimType = Graphic3d_TOPA_POINTS;
  }
  else if (anArrayType == "segments")
  {
    aPrimType = Graphic3d_TOPA_SEGMENTS;
  }
  else if (anArrayType == "polylines")
  {
    aPrimType = Graphic3d_TOPA_POLYLINES;
  }
  else if (anArrayType == "triangles")
  {
    aPrimType = Graphic3d_TOPA_TRIANGLES;
  }
  else if (anArrayType == "trianglefans")
  {
    aPrimType = Graphic3d_TOPA_TRIANGLEFANS;
  }
  else if (anArrayType == "trianglestrips")
  {
    aPrimType = Graphic3d_TOPA_TRIANGLESTRIPS;
  }
  else if (anArrayType == "quads")
  {
    aPrimType = Graphic3d_TOPA_QUADRANGLES;
  }
  else if (anArrayType == "quadstrips")
  {
    aPrimType = Graphic3d_TOPA_QUADRANGLESTRIPS;
  }
  else if (anArrayType == "polygons")
  {
    aPrimType = Graphic3d_TOPA_POLYGONS;
  }
  if (aPrimType == Graphic3d_TOPA_UNDEFINED)
  {
    std::cout << "Syntax error: unexpected type of primitives array\n";
    return 1;
  }

  Standard_Integer aLowerArg = anArgIndex;
  Handle(TColStd_HArray1OfAsciiString) anArgsArray = new TColStd_HArray1OfAsciiString (0, argc - 3);
  for (; anArgIndex < argc; ++anArgIndex)
  {
    TCollection_AsciiString aCommand (argv[anArgIndex]);
    aCommand.LowerCase();
    if (!aCommand.IsAscii())
    {
      di << "Unexpected argument: #" << anArgIndex - 1 << " , "
         << "should be an array element: 'v', 'b', 'e' \n";
      break;
    }

    if (aCommand == "v")
    {
      hasVertex = Standard_True;
    }

    anArgsArray->SetValue (anArgIndex - aLowerArg, aCommand);
  }

  if (!hasVertex)
  {
    di << "You should pass any verticies in the list of array elements\n";
    return 1;
  }

  Handle(Graphic3d_AspectMarker3d)    anAspPoints;
  if (aPrimType == Graphic3d_TOPA_POINTS)
  {
    anAspPoints = new Graphic3d_AspectMarker3d (Aspect_TOM_POINT, Quantity_NOC_YELLOW, 1.0f);
  }

  // create primitives array object
  if (aPObject.IsNull())
  {
    // register the object in map
    aPObject = new MyPArrayObject (aPrimType, anArgsArray, anAspPoints);
    VDisplayAISObject (aName, aPObject);
  }
  else
  {
    aPObject->Init (aPrimType, anArgsArray, anAspPoints, Standard_True);
    ViewerTest::CurrentView()->Redraw();
  }
  return 0;
}

namespace
{
  //! Auxiliary function for parsing translation vector - either 2D or 3D.
  static Standard_Integer parseTranslationVec (Standard_Integer theArgNb,
                                               const char**     theArgVec,
                                               gp_Vec&          theVec)
  {
    if (theArgNb < 2)
    {
      return 0;
    }

    TCollection_AsciiString anX (theArgVec[0]);
    TCollection_AsciiString anY (theArgVec[1]);
    if (!anX.IsRealValue()
     || !anY.IsRealValue())
    {
      return 0;
    }

    theVec.SetX (anX.RealValue());
    theVec.SetY (anY.RealValue());
    if (theArgNb >= 3)
    {
      TCollection_AsciiString anZ (theArgVec[2]);
      if (anZ.IsRealValue())
      {
        theVec.SetZ (anZ.RealValue());
        return 3;
      }
    }
    return 2;
  }
}

//=======================================================================
//function : VSetLocation
//purpose  : Change location of AIS interactive object
//=======================================================================

static Standard_Integer VSetLocation (Draw_Interpretor& theDI,
                                      Standard_Integer  theArgNb,
                                      const char**      theArgVec)
{
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext();
  ViewerTest_AutoUpdater anUpdateTool (aContext, ViewerTest::CurrentView());
  if (aContext.IsNull())
  {
    std::cout << "Error: no active view!\n";
    return 1;
  }

  Standard_Boolean toPrintInfo = Standard_True;
  Handle(AIS_InteractiveObject) anObj;
  TCollection_AsciiString aCmdName (theArgVec[0]);
  aCmdName.LowerCase();
  for (Standard_Integer anArgIter = 1; anArgIter < theArgNb; ++anArgIter)
  {
    TCollection_AsciiString anArg = theArgVec[anArgIter];
    anArg.LowerCase();
    if (anUpdateTool.parseRedrawMode (anArg))
    {
      continue;
    }
    else if (anObj.IsNull())
    {
      const TCollection_AsciiString aName (theArgVec[anArgIter]);
      GetMapOfAIS().Find2 (aName, anObj);
      if (anObj.IsNull())
      {
        std::cout << "Error: object '" << aName << "' is not displayed!\n";
        return 1;
      }
    }
    else if (anArg == "-reset")
    {
      toPrintInfo = Standard_False;
      aContext->SetLocation (anObj, gp_Trsf());
    }
    else if (anArg == "-copyfrom"
          || anArg == "-copy")
    {
      if (anArgIter + 1 >= theArgNb)
      {
        std::cout << "Syntax error at '" << anArg << "'\n";
        return 1;
      }

      const TCollection_AsciiString aName2 (theArgVec[anArgIter + 1]);
      Handle(AIS_InteractiveObject) anObj2;
      GetMapOfAIS().Find2 (aName2, anObj2);
      if (anObj2.IsNull())
      {
        std::cout << "Error: object '" << aName2 << "' is not displayed!\n";
        return 1;
      }

      ++anArgIter;
      aContext->SetLocation (anObj, anObj2->LocalTransformation());
    }
    else if (anArg == "-rotate")
    {
      toPrintInfo = Standard_False;
      if (anArgIter + 7 >= theArgNb)
      {
        std::cout << "Syntax error at '" << anArg << "'\n";
        return 1;
      }

      gp_Trsf aTrsf;
      aTrsf.SetRotation (gp_Ax1 (gp_Pnt (Draw::Atof (theArgVec[anArgIter + 1]),
                                         Draw::Atof (theArgVec[anArgIter + 2]),
                                         Draw::Atof (theArgVec[anArgIter + 3])),
                                 gp_Vec (Draw::Atof (theArgVec[anArgIter + 4]),
                                         Draw::Atof (theArgVec[anArgIter + 5]),
                                         Draw::Atof (theArgVec[anArgIter + 6]))),
                                         Draw::Atof (theArgVec[anArgIter + 7]) * (M_PI / 180.0));
      anArgIter += 7;

      aTrsf = anObj->LocalTransformation() * aTrsf;
      aContext->SetLocation (anObj, aTrsf);
    }
    else if (anArg == "-translate")
    {
      toPrintInfo = Standard_False;
      gp_Vec aLocVec;
      Standard_Integer aNbParsed = parseTranslationVec (theArgNb - anArgIter - 1, theArgVec + anArgIter + 1, aLocVec);
      anArgIter += aNbParsed;
      if (aNbParsed == 0)
      {
        std::cout << "Syntax error at '" << anArg << "'\n";
        return 1;
      }

      gp_Trsf aTrsf;
      aTrsf.SetTranslationPart (aLocVec);
      aTrsf = anObj->LocalTransformation() * aTrsf;
      aContext->SetLocation (anObj, aTrsf);
    }
    else if (anArg == "-scale"
          || anArg == "-setscale")
    {
      toPrintInfo = Standard_False;
      gp_XYZ aScaleLoc;
      Standard_Real aScale = 1.0;
      Standard_Boolean toPrintScale = Standard_True;
      Standard_Boolean hasScaleLoc  = Standard_False;
      if (anArgIter + 4 < theArgNb)
      {
        TCollection_AsciiString aScaleArgs[4] =
        {
          TCollection_AsciiString (theArgVec[anArgIter + 1]),
          TCollection_AsciiString (theArgVec[anArgIter + 2]),
          TCollection_AsciiString (theArgVec[anArgIter + 3]),
          TCollection_AsciiString (theArgVec[anArgIter + 4])
        };
        Standard_Integer aScaleArgIter = 0;
        for (; aScaleArgIter < 4; ++aScaleArgIter)
        {
          if (!aScaleArgs[aScaleArgIter].IsRealValue())
          {
            break;
          }
        }
        if (aScaleArgIter == 4)
        {
          aScaleLoc.SetCoord (aScaleArgs[0].RealValue(), aScaleArgs[1].RealValue(), aScaleArgs[2].RealValue());
          aScale = aScaleArgs[3].RealValue();
          anArgIter += 4;
          toPrintScale = Standard_False;
          hasScaleLoc  = Standard_True;
        }
        else if (aScaleArgIter >= 1)
        {
          aScale = aScaleArgs[0].RealValue();
          ++anArgIter;
          toPrintScale = Standard_False;
        }
      }
      else if (anArgIter + 1 < theArgNb)
      {
        TCollection_AsciiString aScaleArg (theArgVec[anArgIter + 1]);
        if (aScaleArg.IsRealValue())
        {
          aScale = aScaleArg.RealValue();
          ++anArgIter;
          toPrintScale = Standard_False;
        }
      }

      if (toPrintScale)
      {
        if (anArg == "-setscale")
        {
          std::cout << "Syntax error at '" << anArg << "'\n";
          return 1;
        }

        char aText[1024];
        Sprintf (aText, "%g ", anObj->LocalTransformation().ScaleFactor());
        theDI << aText;
        continue;
      }

      if (anArg == "-setscale")
      {
        gp_Trsf aTrsf = anObj->LocalTransformation();
        if (hasScaleLoc)
        {
          aTrsf.SetScale (aScaleLoc, aScale);
        }
        else
        {
          aTrsf.SetScaleFactor (aScale);
        }
        aContext->SetLocation (anObj, aTrsf);
      }
      else
      {
        gp_Trsf aTrsf;
        if (hasScaleLoc)
        {
          aTrsf.SetScale (aScaleLoc, aScale);
          aTrsf = anObj->LocalTransformation() * aTrsf;
        }
        else
        {
          aTrsf = anObj->LocalTransformation();
          aTrsf.SetScaleFactor (aTrsf.ScaleFactor() * aScale);
        }
        aContext->SetLocation (anObj, aTrsf);
      }
    }
    else if (anArg == "-mirror")
    {
      toPrintInfo = Standard_False;
      if (anArgIter + 6 >= theArgNb)
      {
        std::cout << "Syntax error at '" << anArg << "'\n";
        return 1;
      }

      gp_Trsf aTrsf;
      aTrsf.SetMirror (gp_Ax2 (gp_Pnt (Draw::Atof(theArgVec[theArgNb - 6]),
                                       Draw::Atof(theArgVec[theArgNb - 5]),
                                       Draw::Atof(theArgVec[theArgNb - 4])),
                               gp_Vec (Draw::Atof(theArgVec[theArgNb - 3]),
                                       Draw::Atof(theArgVec[theArgNb - 2]),
                                       Draw::Atof(theArgVec[theArgNb - 1]))));
      anArgIter += 6;
      aTrsf = anObj->LocalTransformation() * aTrsf;
      aContext->SetLocation (anObj, aTrsf);
    }
    else if (anArg == "-setrotation"
          || anArg == "-rotation")
    {
      toPrintInfo = Standard_False;
      if (anArgIter + 4 < theArgNb)
      {
        TCollection_AsciiString aQuatArgs[4] =
        {
          TCollection_AsciiString (theArgVec[anArgIter + 1]),
          TCollection_AsciiString (theArgVec[anArgIter + 2]),
          TCollection_AsciiString (theArgVec[anArgIter + 3]),
          TCollection_AsciiString (theArgVec[anArgIter + 4])
        };
        Standard_Integer aQuatArgIter = 0;
        for (; aQuatArgIter < 4; ++aQuatArgIter)
        {
          if (!aQuatArgs[aQuatArgIter].IsRealValue())
          {
            break;
          }
        }

        if (aQuatArgIter == 4)
        {
          anArgIter += 4;
          const gp_Quaternion aQuat (aQuatArgs[0].RealValue(),
                                     aQuatArgs[1].RealValue(),
                                     aQuatArgs[2].RealValue(),
                                     aQuatArgs[3].RealValue());
          gp_Trsf aTrsf = anObj->LocalTransformation();
          aTrsf.SetRotation (aQuat);
          aContext->SetLocation (anObj, aTrsf);
          continue;
        }
        else if (anArg == "-setrotation")
        {
          std::cout << "Syntax error at '" << anArg << "'\n";
          return 1;
        }
      }

      char aText[1024];
      const gp_Quaternion aQuat = anObj->LocalTransformation().GetRotation();
      Sprintf (aText, "%g %g %g %g ", aQuat.X(), aQuat.Y(), aQuat.Z(), aQuat.W());
      theDI << aText;
    }
    else if (anArg == "-setlocation"
          || anArg == "-location")
    {
      toPrintInfo = Standard_False;
      gp_Vec aLocVec;
      Standard_Integer aNbParsed = parseTranslationVec (theArgNb - anArgIter - 1, theArgVec + anArgIter + 1, aLocVec);
      anArgIter += aNbParsed;
      if (aNbParsed != 0)
      {
        gp_Trsf aTrsf = anObj->LocalTransformation();
        aTrsf.SetTranslationPart (aLocVec);
        aContext->SetLocation (anObj, aTrsf);
      }
      else if (anArg == "-setlocation")
      {
        std::cout << "Syntax error at '" << anArg << "'\n";
        return 1;
      }

      char aText[1024];
      const gp_XYZ aLoc = anObj->LocalTransformation().TranslationPart();
      Sprintf (aText, "%g %g %g ", aLoc.X(), aLoc.Y(), aLoc.Z());
      theDI << aText;
    }
    else if (aCmdName == "vsetlocation")
    {
      // compatibility with old syntax
      gp_Vec aLocVec;
      Standard_Integer aNbParsed = parseTranslationVec (theArgNb - anArgIter, theArgVec + anArgIter, aLocVec);
      if (aNbParsed == 0)
      {
        std::cout << "Syntax error at '" << anArg << "'\n";
        return 1;
      }
      anArgIter = anArgIter + aNbParsed - 1;

      gp_Trsf aTrsf;
      aTrsf.SetTranslationPart (aLocVec);
      aContext->SetLocation (anObj, aTrsf);
      toPrintInfo = Standard_False;
    }
    else
    {
      std::cout << "Error: unknown argument '" << anArg << "'\n";
      return 1;
    }
  }

  if (anObj.IsNull())
  {
    std::cout << "Syntax error - wrong number of arguments\n";
    return 1;
  }
  else if (!toPrintInfo)
  {
    return 0;
  }

  const gp_Trsf       aTrsf = anObj->LocalTransformation();
  const gp_XYZ        aLoc  = aTrsf.TranslationPart();
  const gp_Quaternion aRot  = aTrsf.GetRotation();
  char aText[4096];
  Sprintf (aText, "Location: %g %g %g\n"
                  "Rotation: %g %g %g %g\n"
                  "Scale:    %g\n",
                  aLoc.X(), aLoc.Y(), aLoc.Z(),
                  aRot.X(), aRot.Y(), aRot.Z(), aRot.W(),
                  aTrsf.ScaleFactor());
  theDI << aText;
  return 0;
}

//===============================================================================================
//function : VConnect
//purpose  : Creates and displays AIS_ConnectedInteractive object from input object and location 
//Draw arg : vconnect name Xo Yo Zo object1 object2 ... [color=NAME]
//===============================================================================================

static Standard_Integer VConnect (Draw_Interpretor& /*di*/, 
                                  Standard_Integer argc, 
                                  const char ** argv) 
{
  // Check the viewer
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext();
  if (aContext.IsNull())
  {
    std::cout << "vconnect error : call vinit before\n";
    return 1; // TCL_ERROR
  }
  // Check argumnets 
  if (argc < 6)
  {
    std::cout << "vconnect error: expect at least 5 arguments\n";
    return 1; // TCL_ERROR
  }

  // Get values
  Standard_Integer anArgIter = 1;
  TCollection_AsciiString aName (argv[anArgIter++]);
  Handle(AIS_MultipleConnectedInteractive) anOriginObject;
  TCollection_AsciiString aColorString (argv[argc-1]);
  Standard_CString aColorName = "";
  Standard_Boolean hasColor = Standard_False;
  if (aColorString.Search ("color=") != -1)
  {
    hasColor = Standard_True;
    aColorString.Remove (1, 6);
    aColorName = aColorString.ToCString();
  }
  Handle(AIS_InteractiveObject) anObject;

  // AIS_MultipleConnectedInteractive
  const Standard_Integer aNbShapes = hasColor ? (argc - 1) : argc;
  for (Standard_Integer i = 5; i < aNbShapes; ++i)
  {
    TCollection_AsciiString anOriginObjectName (argv[i]);
    if (aName.IsEqual (anOriginObjectName))
    {
      std::cout << "vconnect error: equal names for connected objects\n";
      continue;
    }
    if (GetMapOfAIS().Find2 (anOriginObjectName, anObject))
    {
      if (anObject.IsNull())
      {
        std::cout << "Object " << anOriginObjectName << " is used for non AIS viewer\n";
        continue;
      }
    }
    else
    {
      Standard_CString aOriginName = anOriginObjectName.ToCString();
      TopoDS_Shape aTDShape = DBRep::Get (aOriginName);
      if (aTDShape.IsNull())
      {
        std::cout << "vconnect error: object " << anOriginObjectName << " doesn't exist\n";
        continue;
      }
      anObject = new AIS_Shape (aTDShape);
      aContext->Load (anObject);
      anObject->SetColor (ViewerTest::GetColorFromName (aColorName));
    }

    if (anOriginObject.IsNull())
    {
      anOriginObject = new AIS_MultipleConnectedInteractive();
    }

    anOriginObject->Connect (anObject);
  }
  if (anOriginObject.IsNull())
  {
    std::cout << "vconect error : can't connect input objects\n";
    return 1; // TCL_ERROR
  }

  // Get location data
  Standard_Real aXo = Draw::Atof (argv[anArgIter++]);
  Standard_Real aYo = Draw::Atof (argv[anArgIter++]);
  Standard_Real aZo = Draw::Atof (argv[anArgIter++]);

  // Create transformation
  gp_Vec aTranslation (aXo, aYo, aZo);

  gp_Trsf aTrsf; 
  aTrsf.SetTranslationPart (aTranslation);
  TopLoc_Location aLocation (aTrsf);

  anOriginObject->SetLocalTransformation (aTrsf);

  // Check if there is another object with given name
  // and remove it from context
  Handle(AIS_InteractiveObject) anObj;
  if (GetMapOfAIS().Find2 (aName, anObj))
  {
    TheAISContext()->Remove(anObj, Standard_False);
    GetMapOfAIS().UnBind2(aName);
  }

  // Bind connected object to its name
  GetMapOfAIS().Bind (anOriginObject, aName);

  // Display connected object
  TheAISContext()->Display (anOriginObject, Standard_True);

  return 0;
}

//===============================================================================================
//function : VConnectTo
//purpose  : Creates and displays AIS_ConnectedInteractive object from input object and location 
//Draw arg : vconnectto name Xo Yo Zo object [-nodisplay|-noupdate|-update]
//===============================================================================================

static Standard_Integer VConnectTo (Draw_Interpretor& /*di*/, 
                                    Standard_Integer argc, 
                                    const char ** argv) 
{
  // Check the viewer
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext();
  ViewerTest_AutoUpdater anUpdateTool (aContext, ViewerTest::CurrentView());
  if (aContext.IsNull())
  {
    std::cout << "vconnect error : call vinit before\n";
    return 1; // TCL_ERROR
  }
  // Check argumnets 
  if (argc != 6 && argc != 7)
  {
    std::cout << "vconnect error: expect at least 5 arguments\n";
    return 1; // TCL_ERROR
  }

  // Get values
  Standard_Integer anArgIter = 1;
  TCollection_AsciiString aName (argv[anArgIter++]);
  Handle(AIS_InteractiveObject) anOriginObject;

  TCollection_AsciiString anOriginObjectName(argv[5]);
  if (aName.IsEqual (anOriginObjectName))
  {
    std::cout << "vconnect error: equal names for connected objects\n"; 
    return 1; // TCL_ERROR
  }
  if (GetMapOfAIS().Find2 (anOriginObjectName, anOriginObject))
  {
    if (anOriginObject.IsNull())
    {
      std::cout << "Object " << anOriginObjectName << " is used for non AIS viewer\n";
      return 1; // TCL_ERROR
    }
  }
  else
  {
    Standard_CString aOriginName = anOriginObjectName.ToCString();
    TopoDS_Shape aTDShape = DBRep::Get (aOriginName);
    if (aTDShape.IsNull())
    {
      std::cout << "vconnect error: object " << anOriginObjectName << " doesn't exist\n";
      return 1; // TCL_ERROR
    }
    anOriginObject = new AIS_Shape (aTDShape);
    GetMapOfAIS().Bind (anOriginObject, anOriginObjectName);
  }
 
  // Get location data
  Standard_Real aXo = Draw::Atof (argv[anArgIter++]);
  Standard_Real aYo = Draw::Atof (argv[anArgIter++]);
  Standard_Real aZo = Draw::Atof (argv[anArgIter++]);

  // Create transformation
  gp_Vec aTranslation (aXo, aYo, aZo);

  gp_Trsf aTrsf; 
  aTrsf.SetTranslationPart (aTranslation);
 
  Handle(AIS_ConnectedInteractive) aConnected;

  aConnected = new AIS_ConnectedInteractive();

  aConnected->Connect (anOriginObject, aTrsf);

  // Check if there is another object with given name
  // and remove it from context
  Handle(AIS_InteractiveObject) anObj;
  if (GetMapOfAIS().Find2 (aName, anObj))
  {
    TheAISContext()->Remove (anObj, Standard_False);
    GetMapOfAIS().UnBind2(aName);
  }

  // Bind connected object to its name
  GetMapOfAIS().Bind (aConnected, aName);

  if (argc == 7)
  {
    TCollection_AsciiString anArg = argv[6];
    anArg.LowerCase();
    if (anArg == "-nodisplay")
      return 0;

    if (!anUpdateTool.parseRedrawMode (anArg))
    {
      std::cout << "Warning! Unknown argument '" << anArg << "' passed, -nodisplay|-noupdate|-update expected at this point.\n";
    }
  }

  // Display connected object
  TheAISContext()->Display (aConnected, Standard_False);

  return 0;
}

//=======================================================================
//function : VDisconnect
//purpose  :
//=======================================================================
static Standard_Integer VDisconnect (Draw_Interpretor& di,
                                     Standard_Integer argc,
                                     const char ** argv)
{
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext();
  if (aContext.IsNull())
  {
    std::cout << argv[0] << "ERROR : use 'vinit' command before \n";
    return 1;
  }
  
  if (argc != 3)
  {
    std::cout << "ERROR : Usage : " << argv[0] << " name object\n";
    return 1;
  }

  TCollection_AsciiString aName (argv[1]);
  TCollection_AsciiString anObject (argv[2]);
  Standard_Integer anObjectNumber = Draw::Atoi (argv[2]);

  // find objects
  ViewerTest_DoubleMapOfInteractiveAndName& aMap = GetMapOfAIS();
  Handle(AIS_MultipleConnectedInteractive) anAssembly;
  if (!aMap.IsBound2 (aName) )
  {
    std::cout << "Use 'vdisplay' before\n";
    return 1;
  }

  anAssembly = Handle(AIS_MultipleConnectedInteractive)::DownCast (aMap.Find2 (aName));
  if (anAssembly.IsNull())
  {
    di << "Not an assembly\n";
    return 1;
  }

  Handle(AIS_InteractiveObject) anIObj;
  if (!aMap.Find2 (anObject, anIObj))
  {
    // try to interpret second argument as child number
    if (anObjectNumber > 0 && anObjectNumber <= anAssembly->Children().Size())
    {
      Standard_Integer aCounter = 1;
      for (PrsMgr_ListOfPresentableObjectsIter anIter (anAssembly->Children()); anIter.More(); anIter.Next())
      {
        if (aCounter == anObjectNumber)
        {
          anIObj = Handle(AIS_InteractiveObject)::DownCast (anIter.Value());
          break;
        }
        ++aCounter;
      }
    }
    else
    {
      std::cout << "Use 'vdisplay' before\n";
      return 1;
    }    
  }

  aContext->Disconnect (anAssembly, anIObj);
  aContext->UpdateCurrentViewer();
  return 0;
}

//=======================================================================
//function : VAddConnected
//purpose  :
//=======================================================================
static Standard_Integer VAddConnected (Draw_Interpretor& di,
                                       Standard_Integer argc,
                                       const char ** argv)
{
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext();
  if (aContext.IsNull())
  {
    std::cout << argv[0] << "error : use 'vinit' command before \n";
    return 1;
  }
  
  if (argc != 6)
  {
    std::cout << argv[0] << " error: expect 5 arguments\n";
    return 1;
  }

  TCollection_AsciiString aName (argv[1]);
  TCollection_AsciiString anObject (argv[5]);
  Standard_Real aX = Draw::Atof (argv[2]);
  Standard_Real aY = Draw::Atof (argv[3]);
  Standard_Real aZ = Draw::Atof (argv[4]);

  // find object
  ViewerTest_DoubleMapOfInteractiveAndName& aMap = GetMapOfAIS();
  Handle(AIS_MultipleConnectedInteractive) anAssembly;
  if (!aMap.IsBound2 (aName) )
  {
    std::cout << "Use 'vdisplay' before\n";
    return 1;
  }

  anAssembly = Handle(AIS_MultipleConnectedInteractive)::DownCast (aMap.Find2 (aName));
  if (anAssembly.IsNull())
  {
    di << "Not an assembly\n";
    return 1;
  }

  Handle(AIS_InteractiveObject) anIObj;
  if (!aMap.Find2 (anObject, anIObj))
  {
      std::cout << "Use 'vdisplay' before\n";
      return 1; 
  }

  gp_Trsf aTrsf;
  aTrsf.SetTranslation (gp_Vec (aX, aY, aZ));
 
  anAssembly->Connect (anIObj, aTrsf);
  TheAISContext()->Display (anAssembly, Standard_False);
  TheAISContext()->RecomputeSelectionOnly (anAssembly);
  aContext->UpdateCurrentViewer();

  return 0;
}

//=======================================================================
//function : VListConnected
//purpose  :
//=======================================================================
static Standard_Integer VListConnected (Draw_Interpretor& /*di*/,
                                        Standard_Integer argc,
                                        const char ** argv)
{
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext();
  if (aContext.IsNull())
  {
    std::cout << argv[0] << "ERROR : use 'vinit' command before \n";
    return 1;
  }
  
  if (argc != 2)
  {
    std::cout << "ERROR : Usage : " << argv[0] << " name\n";
    return 1;
  }

  TCollection_AsciiString aName (argv[1]);

  // find object
  ViewerTest_DoubleMapOfInteractiveAndName& aMap = GetMapOfAIS();
  Handle(AIS_MultipleConnectedInteractive) anAssembly;
  if (!aMap.IsBound2 (aName) )
  {
    std::cout << "Use 'vdisplay' before\n";
    return 1;
  }

  anAssembly = Handle(AIS_MultipleConnectedInteractive)::DownCast (aMap.Find2 (aName));
  if (anAssembly.IsNull())
  {
    std::cout << "Not an assembly\n";
    return 1;
  }

  std::cout << "Children of " << aName << ":\n";

  Standard_Integer aCounter = 1;
  for (PrsMgr_ListOfPresentableObjectsIter anIter (anAssembly->Children()); anIter.More(); anIter.Next())
  {
    Handle(AIS_InteractiveObject) anObj = Handle(AIS_InteractiveObject)::DownCast (anIter.Value());
    if (GetMapOfAIS().IsBound1 (anObj))
    {
      TCollection_AsciiString aCuurrentName = GetMapOfAIS().Find1 (anObj);
      std::cout << aCounter << ")  " << aCuurrentName << "    (" << anIter.Value()->DynamicType()->Name() << ")";
    }

    std::cout << aCounter << ")  " << anIter.Value()->DynamicType()->Name();

    Handle(AIS_ConnectedInteractive) aConnected = Handle(AIS_ConnectedInteractive)::DownCast (anIter.Value());
    if (!aConnected.IsNull() && !aConnected->ConnectedTo().IsNull() && aMap.IsBound1 (aConnected->ConnectedTo()))
    {
      std::cout << " connected to " << aMap.Find1 (aConnected->ConnectedTo());
    }
    std::cout << std::endl;
    
    ++aCounter;
  }

  return 0;
}

//===============================================================================================
//function : VSetSelectionMode
//purpose  : vselmode
//===============================================================================================
static Standard_Integer VSetSelectionMode (Draw_Interpretor& /*di*/,
                                           Standard_Integer  theNbArgs,
                                           const char**      theArgv)
{
  // Check errors
  Handle(AIS_InteractiveContext) anAISContext = ViewerTest::GetAISContext();
  if (anAISContext.IsNull())
  {
    std::cout << "Error: no active Viewer\n";
    return 1;
  }

  NCollection_Sequence<TCollection_AsciiString> anObjNames;
  Standard_Integer aSelectionMode = -1;
  Standard_Boolean toTurnOn = Standard_True;
  AIS_SelectionModesConcurrency aSelModeConcurrency = AIS_SelectionModesConcurrency_GlobalOrLocal;
  for (Standard_Integer anArgIter = 1; anArgIter < theNbArgs; ++anArgIter)
  {
    TCollection_AsciiString anArgCase (theArgv[anArgIter]);
    anArgCase.LowerCase();
    if (anArgCase == "-set"
     || anArgCase == "-replace"
     || anArgCase == "-single"
     || anArgCase == "-exclusive")
    {
      aSelModeConcurrency = AIS_SelectionModesConcurrency_Single;
    }
    else if (anArgCase == "-add"
          || anArgCase == "-combine"
          || anArgCase == "-combination"
          || anArgCase == "-multiple")
    {
      aSelModeConcurrency = AIS_SelectionModesConcurrency_Multiple;
    }
    else if (anArgCase == "-globalorlocal"
          || anArgCase == "-localorglobal")
    {
      aSelModeConcurrency = AIS_SelectionModesConcurrency_GlobalOrLocal;
    }
    else
    {
      anObjNames.Append (theArgv[anArgIter]);
    }
  }
  if (anObjNames.Size() < 2
  || !ViewerTest::ParseOnOff (anObjNames.Last().ToCString(), toTurnOn))
  {
    std::cout << "Syntax error: wrong number of arguments\n";
    return 1;
  }
  anObjNames.Remove (anObjNames.Upper());
  {
    const TCollection_AsciiString aSelModeString = anObjNames.Last();
    anObjNames.Remove (anObjNames.Upper());
    TopAbs_ShapeEnum aShapeType = TopAbs_SHAPE;
    if (aSelModeString.IsIntegerValue())
    {
      aSelectionMode = aSelModeString.IntegerValue();
    }
    else if (TopAbs::ShapeTypeFromString (aSelModeString.ToCString(), aShapeType))
    {
      aSelectionMode = AIS_Shape::SelectionMode (aShapeType);
    }
    else
    {
      std::cout << "Syntax error: unknown selection mode '" << aSelModeString  << "'\n";
      return 1;
    }
  }

  AIS_ListOfInteractive aTargetIOs;
  for (NCollection_Sequence<TCollection_AsciiString>::Iterator anObjIter (anObjNames); anObjIter.More(); anObjIter.Next())
  {
    const TCollection_AsciiString& aNameIO = anObjIter.Value();
    Handle(AIS_InteractiveObject) anIO;
    GetMapOfAIS().Find2 (aNameIO, anIO);
    if (anIO.IsNull())
    {
      std::cout << "Syntax error: undefined presentable object " << aNameIO << "\n";
      return 1;
    }
    aTargetIOs.Append (anIO);
  }
  if (aTargetIOs.IsEmpty())
  {
    anAISContext->DisplayedObjects (aTargetIOs);
  }

  for (AIS_ListIteratorOfListOfInteractive aTargetIt (aTargetIOs); aTargetIt.More(); aTargetIt.Next())
  {
    const Handle(AIS_InteractiveObject)& anIO = aTargetIt.Value();
    anAISContext->SetSelectionModeActive (anIO, aSelectionMode, toTurnOn, aSelModeConcurrency);
  }
  return 0;
}

//===============================================================================================
//function : VSelectionNext
//purpose  : 
//===============================================================================================
static Standard_Integer VSelectionNext(Draw_Interpretor& /*theDI*/,
                                 Standard_Integer /*theArgsNb*/,
                                 const char** /*theArgVec*/)
{
  // Check errors
  Handle(AIS_InteractiveContext) anAISContext = ViewerTest::GetAISContext();
  Handle(V3d_View) aView = ViewerTest::CurrentView();

  if (anAISContext.IsNull())
  {
    std::cerr << "Call vinit before!" << std::endl;
    return 1;
  }

  anAISContext->HilightNextDetected (aView);
  return 0;
}

//===============================================================================================
//function : VSelectionPrevious
//purpose  : 
//===============================================================================================
static Standard_Integer VSelectionPrevious(Draw_Interpretor& /*theDI*/,
                                 Standard_Integer /*theArgsNb*/,
                                 const char** /*theArgVec*/)
{
  // Check errors
  Handle(AIS_InteractiveContext) anAISContext = ViewerTest::GetAISContext();
  Handle(V3d_View) aView = ViewerTest::CurrentView();

  if (anAISContext.IsNull())
  {
    std::cerr << "Call vinit before!" << std::endl;
    return 1;
  }

  anAISContext->HilightPreviousDetected (aView);
  return 0;
}

//===========================================================================
//function : VTriangle 
//Draw arg : vtriangle Name PointName PointName PointName
//purpose  : creates and displays Triangle
//===========================================================================
static Standard_Integer VTriangle (Draw_Interpretor& /*di*/,
                                   Standard_Integer argc,
                                   const char ** argv)
{
  const Standard_Boolean isTri = TCollection_AsciiString (argv[0]) == "vtriangle";
  Handle(Graphic3d_ArrayOfPrimitives) aPrims;
  if (isTri)
  {
    aPrims = new Graphic3d_ArrayOfTriangles (3);
  }
  else
  {
    aPrims = new Graphic3d_ArrayOfSegments (2);
  }

  if (argc != (2 + aPrims->VertexNumberAllocated()))
  {
    std::cout << "Syntax error: wrong number of arguments\n";
    return 1;
  }

  gp_Pnt aPnts[3];
  for (Standard_Integer aPntIter = 0; aPntIter < aPrims->VertexNumberAllocated(); ++aPntIter)
  {
    const TCollection_AsciiString aName (argv[2 + aPntIter]);
    if (Handle(AIS_Point) aPntPrs = Handle(AIS_Point)::DownCast (GetMapOfAIS().IsBound2 (aName) ? GetMapOfAIS().Find2 (aName) : NULL))
    {
      aPnts[aPntIter] = aPntPrs->Component()->Pnt();
    }
    else
    {
      TopoDS_Shape aShape = DBRep::Get (argv[2 + aPntIter]);
      if (aShape.IsNull()
       || aShape.ShapeType() != TopAbs_VERTEX)
      {
        std::cout << "Syntax error: argument " << aName << " must be a point\n";
        return 1;
      }
      aPnts[aPntIter] = BRep_Tool::Pnt (TopoDS::Vertex (aShape));
    }

    for (Standard_Integer aPnt2Iter = 0; aPnt2Iter < aPntIter; ++aPnt2Iter)
    {
      if (aPnts[aPnt2Iter].IsEqual (aPnts[aPntIter], Precision::Confusion()))
      {
        std::cout << "Syntax error: points should not be equal\n";
        return 1;
      }
    }

    aPrims->AddVertex (aPnts[aPntIter]);
  }

  ViewerTest::Display (argv[1], new MyPArrayObject (aPrims));
  return 0;
}

//=======================================================================
//function : VObjZLayer
//purpose  : Set or get z layer id for presentable object
//=======================================================================

static Standard_Integer VObjZLayer (Draw_Interpretor& di,
                                    Standard_Integer argc,
                                    const char ** argv)
{
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext();
  if (aContext.IsNull())
  {
    di << argv[0] << "Call 'vinit' before!\n";
    return 1;
  }

  // get operation
  TCollection_AsciiString aOperation;
  if (argc >= 2)
    aOperation = TCollection_AsciiString (argv [1]);

  // check for correct arguments
  if (!(argc == 4 && aOperation.IsEqual ("set")) &&
      !(argc == 3 && aOperation.IsEqual ("get")))
  {
    di << "Usage : " << argv[0] << " set/get object [layerid]\n";
    di << " set - set layer id for interactive object, layerid - z layer id\n";
    di << " get - get layer id of interactive object\n";
    di << " argument layerid should be passed for set operation only\n";
    return 1;
  }

  // find object
  TCollection_AsciiString aName (argv[2]);
  Handle(AIS_InteractiveObject) anInterObj;
  GetMapOfAIS().Find2 (aName, anInterObj);
  if (anInterObj.IsNull())
  {
    std::cout << "Syntax error: object '" << aName << "' is not displayed\n";
    return 1;
  }

  // process operation
  if (aOperation.IsEqual ("set"))
  {
    Standard_Integer aLayerId = Draw::Atoi (argv [3]);
    aContext->SetZLayer (anInterObj, aLayerId);
  }
  else if (aOperation.IsEqual ("get"))
  {
    di << "Z layer id: " << aContext->GetZLayer (anInterObj);
  }
  
  return 0;
}

//=======================================================================
//function : VPolygonOffset
//purpose  : Set or get polygon offset parameters
//=======================================================================
static Standard_Integer VPolygonOffset(Draw_Interpretor& /*di*/,
                                       Standard_Integer argc,
                                       const char ** argv)
{
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext();
  if (aContext.IsNull())
  {
    std::cout << argv[0] << " Call 'vinit' before!\n";
    return 1;
  }

  if (argc > 2 && argc != 5)
  {
    std::cout << "Usage : " << argv[0] << " [object [mode factor units]] - sets/gets polygon offset parameters for an object,"
      "without arguments prints the default values" << std::endl;
    return 1;
  }

  // find object
  Handle(AIS_InteractiveObject) anInterObj;
  if (argc >= 2)
  {
    TCollection_AsciiString aName (argv[1]);
    if (!GetMapOfAIS().Find2 (aName, anInterObj)
      || anInterObj.IsNull())
    {
      std::cout << "Syntax error: object '" << aName << "' is not displayed\n";
      return 1;
    }
  }

  Standard_Integer aMode;
  Standard_ShortReal    aFactor, aUnits;
  if (argc == 5)
  {
    aMode   = Draw::Atoi(argv[2]);
    aFactor = (Standard_ShortReal) Draw::Atof(argv[3]);
    aUnits  = (Standard_ShortReal) Draw::Atof(argv[4]);

    anInterObj->SetPolygonOffsets(aMode, aFactor, aUnits);
    aContext->UpdateCurrentViewer();
    return 0;
  }
  else if (argc == 2)
  {
    if (anInterObj->HasPolygonOffsets())
    {
      anInterObj->PolygonOffsets(aMode, aFactor, aUnits);
      std::cout << "Current polygon offset parameters for " << argv[1] << ":" << std::endl;
      std::cout << "\tMode: "   << aMode   << std::endl;
      std::cout << "\tFactor: " << aFactor << std::endl;
      std::cout << "\tUnits: "  << aUnits  << std::endl;
      return 0;
    }
    else
    {
      std::cout << "Specific polygon offset parameters are not set for " << argv[1] << std::endl;
    }
  }

  std::cout << "Default polygon offset parameters:" << std::endl;
  aContext->DefaultDrawer()->ShadingAspect()->Aspect()->PolygonOffsets(aMode, aFactor, aUnits);
  std::cout << "\tMode: "   << aMode   << std::endl;
  std::cout << "\tFactor: " << aFactor << std::endl;
  std::cout << "\tUnits: "  << aUnits  << std::endl;

  return 0;
}

//=======================================================================
//function : VShowFaceBoundaries
//purpose  : Set face boundaries drawing on/off for ais object
//=======================================================================
static Standard_Integer VShowFaceBoundary (Draw_Interpretor& /*di*/,
                                           Standard_Integer argc,
                                           const char ** argv)
{
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext ();
  if (aContext.IsNull ())
  {
    std::cout << argv[0] << " Call 'vinit' before!\n";
    return 1;
  }

  if ((argc != 3 && argc < 6) || argc > 8)
  {
    std::cout << "Usage :\n " << argv[0]
              << " ObjectName isOn [R G B [LineWidth [LineStyle]]]\n"
              << "   ObjectName - name of AIS interactive object. \n"
              << "                if ObjectName = \"\", then set as default\n"
              << "                settings for all newly displayed objects\n"
              << "   isOn       - flag indicating whether the boundaries\n"
              << "                should be turned on or off (can be set\n"
              << "                to 0 (off) or 1 (on)).\n"
              << "   R, G, B    - red, green and blue components of boundary\n"
              << "                color in range (0 - 255).\n"
              << "                (default is (0, 0, 0)\n"
              << "   LineWidth  - line width\n"
              << "                (default is 1)\n"
              << "   LineStyle  - line fill style :\n"
              << "                 0 - solid  \n"
              << "                 1 - dashed \n"
              << "                 2 - dot    \n"
              << "                 3 - dashdot\n"
              << "                 (default is solid)";
    return 1;
  }

  TCollection_AsciiString aName (argv[1]);

  Standard_Real aRed   = 0.0;
  Standard_Real aGreen = 0.0;
  Standard_Real aBlue  = 0.0;
  Standard_Real aWidth = 1.0;
  Aspect_TypeOfLine aLineType = Aspect_TOL_SOLID;
  
  // find object
  Handle(AIS_InteractiveObject) anInterObj;

  // if name is empty - apply attributes for default aspect
  if (!aName.IsEmpty ())
  {
    if (!GetMapOfAIS().Find2 (aName, anInterObj)
      || anInterObj.IsNull())
    {
      std::cout << "Use 'vdisplay' on " << aName << " before" << std::endl;
      return 1;
    }
  }
  
  const Handle(Prs3d_Drawer)& aDrawer = (aName.IsEmpty ()) ?
    TheAISContext ()->DefaultDrawer () : anInterObj->Attributes ();

  // turn boundaries on/off
  Standard_Boolean isBoundaryDraw = (Draw::Atoi (argv[2]) == 1);
  aDrawer->SetFaceBoundaryDraw (isBoundaryDraw);
  
  // set boundary line color
  if (argc >= 6)
  {
    // Text color
    aRed   = Draw::Atof (argv[3])/255.;
    aGreen = Draw::Atof (argv[4])/255.;
    aBlue  = Draw::Atof (argv[5])/255.;
  }

  // set line width
  if (argc >= 7)
  {
    aWidth = (Standard_Real)Draw::Atof (argv[6]);
  }

  // select appropriate line type
  if (argc == 8)
  {
    if (!ViewerTest::ParseLineType (argv[7], aLineType))
    {
      std::cout << "Syntax error: unknown line type '" << argv[7] << "'\n";
      return 1;
    }
  }

  Quantity_Color aColor (aRed, aGreen, aBlue, Quantity_TOC_RGB);

  Handle(Prs3d_LineAspect) aBoundaryAspect = 
    new Prs3d_LineAspect (aColor, aLineType, aWidth);

  aDrawer->SetFaceBoundaryAspect (aBoundaryAspect);

  TheAISContext()->Redisplay (anInterObj, Standard_True);
  
  return 0;
}

// This class is used for testing markers.

class ViewerTest_MarkersArrayObject : public AIS_InteractiveObject
{

public:

  ViewerTest_MarkersArrayObject (const gp_XYZ& theStartPoint,
                                 const Standard_Integer& thePointsOnSide,
                                 Handle(Graphic3d_AspectMarker3d) theMarkerAspect = NULL)
  {
    myStartPoint = theStartPoint;
    myPointsOnSide = thePointsOnSide;
    myMarkerAspect = theMarkerAspect;
  }

  DEFINE_STANDARD_RTTI_INLINE(ViewerTest_MarkersArrayObject,AIS_InteractiveObject);

private:

  void Compute (const Handle(PrsMgr_PresentationManager3d)& aPresentationManager,
                const Handle(Prs3d_Presentation)& aPresentation,
                const Standard_Integer aMode) Standard_OVERRIDE;

  void ComputeSelection (const Handle(SelectMgr_Selection)& theSelection,
                         const Standard_Integer /*theMode*/) Standard_OVERRIDE;

protected:

  gp_XYZ myStartPoint;
  Standard_Integer myPointsOnSide;
  Handle(Graphic3d_AspectMarker3d) myMarkerAspect;
};


void ViewerTest_MarkersArrayObject::Compute (const Handle(PrsMgr_PresentationManager3d)& /*aPresentationManager*/,
                              const Handle(Prs3d_Presentation)& aPresentation,
                              const Standard_Integer /*aMode*/)
{
  Handle(Graphic3d_ArrayOfPrimitives) anArray = new Graphic3d_ArrayOfPoints ((Standard_Integer )Pow (myPointsOnSide, 3), myPointsOnSide != 1);
  if (myPointsOnSide == 1)
  {
    anArray->AddVertex (myStartPoint);
  }
  else
  {
    for (Standard_Real i = 1; i <= myPointsOnSide; i++)
    {
      for (Standard_Real j = 1; j <= myPointsOnSide; j++)
      {
        for (Standard_Real k = 1; k <= myPointsOnSide; k++)
        {
          anArray->AddVertex (myStartPoint.X() + i, myStartPoint.Y() + j, myStartPoint.Z() + k);
          anArray->SetVertexColor (anArray->VertexNumber(),
                                   i / myPointsOnSide,
                                   j / myPointsOnSide,
                                   k / myPointsOnSide);
        }
      }
    }
  }

  aPresentation->Clear();
  if (!myMarkerAspect.IsNull())
  {
    Prs3d_Root::CurrentGroup (aPresentation)->SetGroupPrimitivesAspect (myMarkerAspect);
  }
  Prs3d_Root::CurrentGroup (aPresentation)->AddPrimitiveArray (anArray);
}

void ViewerTest_MarkersArrayObject::ComputeSelection (const Handle(SelectMgr_Selection)& theSelection,
                                       const Standard_Integer /*theMode*/)
{
  Handle(SelectMgr_EntityOwner) anEntityOwner = new SelectMgr_EntityOwner (this);

  if (myPointsOnSide == 1)
  {
    gp_Pnt aPoint (myStartPoint);
    Handle(Select3D_SensitivePoint) aSensetivePoint = new Select3D_SensitivePoint (anEntityOwner, aPoint);
    theSelection->Add (aSensetivePoint);
  }
  else
  {
    for (Standard_Real i = 1; i <= myPointsOnSide; i++)
    {
      for (Standard_Real j = 1; j <= myPointsOnSide; j++)
      {
        for (Standard_Real k = 1; k <= myPointsOnSide; k++)
        {
          gp_Pnt aPoint (myStartPoint.X() + i, myStartPoint.Y() + j, myStartPoint.Z() + k);
          Handle(Select3D_SensitivePoint) aSensetivePoint = new Select3D_SensitivePoint (anEntityOwner, aPoint);
          theSelection->Add (aSensetivePoint);
        }
      }
    }
  }
}
//=======================================================================
//function : VMarkersTest
//purpose  : Draws an array of markers for testing purposes.
//=======================================================================
static Standard_Integer VMarkersTest (Draw_Interpretor&,
                                      Standard_Integer  theArgNb,
                                      const char**      theArgVec)
{
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext();
  if (aContext.IsNull())
  {
    std::cerr << "Call 'vinit' before!\n";
    return 1;
  }

  if (theArgNb < 5)
  {
    std::cerr << "Usage :\n " << theArgVec[0]
              << "name X Y Z [PointsOnSide=10] [MarkerType=0] [Scale=1.0] [FileName=ImageFile]\n";
    return 1;
  }

  Standard_Integer anArgIter = 1;

  TCollection_AsciiString aName (theArgVec[anArgIter++]);
  TCollection_AsciiString aFileName;
  gp_XYZ aPnt (Atof (theArgVec[anArgIter]),
               Atof (theArgVec[anArgIter + 1]),
               Atof (theArgVec[anArgIter + 2]));
  anArgIter += 3;

  Standard_Integer aPointsOnSide = 10;
  Standard_Integer aMarkerType   = -1;
  Standard_Real    aScale        = 1.0;
  for (; anArgIter < theArgNb; ++anArgIter)
  {
    const TCollection_AsciiString anArg (theArgVec[anArgIter]);
    if (anArg.Search ("PointsOnSide=") > -1)
    {
      aPointsOnSide = anArg.Token ("=", 2).IntegerValue();
    }
    else if (anArg.Search ("MarkerType=") > -1)
    {
      aMarkerType = anArg.Token ("=", 2).IntegerValue();
    }
    else if (anArg.Search ("Scale=") > -1)
    {
      aScale = anArg.Token ("=", 2).RealValue();
    }
    else if (anArg.Search ("FileName=") > -1)
    {
      aFileName = anArg.Token ("=", 2);
    }
    else
    {
      std::cerr << "Wrong argument: " << anArg << "\n";
      return 1;
    }
  }

  Handle(Graphic3d_AspectMarker3d) anAspect;
  Handle(Image_AlienPixMap) anImage;
  Quantity_Color aColor (Quantity_NOC_GREEN1);
  if ((aMarkerType == Aspect_TOM_USERDEFINED || aMarkerType < 0)
   && !aFileName.IsEmpty())
  {
    anImage = new Image_AlienPixMap();
    if (!anImage->Load (aFileName))
    {
      std::cerr << "Could not load image from file '" << aFileName << "'!\n";
      return 1;
    }
    if (anImage->Format() == Image_Format_Gray)
    {
      anImage->SetFormat (Image_Format_Alpha);
    }
    else if (anImage->Format() == Image_Format_GrayF)
    {
      anImage->SetFormat (Image_Format_AlphaF);
    }
    anAspect = new Graphic3d_AspectMarker3d (anImage);
  }
  else
  {
    anAspect = new Graphic3d_AspectMarker3d (aMarkerType >= 0 ? (Aspect_TypeOfMarker )aMarkerType : Aspect_TOM_POINT, aColor, aScale);
  }

  Handle(ViewerTest_MarkersArrayObject) aMarkersArray = new ViewerTest_MarkersArrayObject (aPnt, aPointsOnSide, anAspect);
  VDisplayAISObject (aName, aMarkersArray);

  return 0;
}

//=======================================================================
//function : TextToBrep
//purpose  : Tool for conversion text to occt-shapes
//=======================================================================
static int TextToBRep (Draw_Interpretor& /*theDI*/,
                       Standard_Integer  theArgNb,
                       const char**      theArgVec)
{
  // Check arguments
  if (theArgNb < 3)
  {
    std::cerr << "Error: " << theArgVec[0] << " - invalid syntax\n";
    return 1;
  }

  Standard_Integer anArgIt = 1;
  Standard_CString aName   = theArgVec[anArgIt++];
  Standard_CString aText   = theArgVec[anArgIt++];

  Font_BRepFont           aFont;
  TCollection_AsciiString aFontName ("Courier");
  Standard_Real           aTextHeight        = 16.0;
  Font_FontAspect         aFontAspect        = Font_FA_Regular;
  Standard_Boolean        anIsCompositeCurve = Standard_False;
  gp_Ax3                  aPenAx3    (gp::XOY());
  gp_Dir                  aNormal    (0.0, 0.0, 1.0);
  gp_Dir                  aDirection (1.0, 0.0, 0.0);
  gp_Pnt                  aPenLoc;

  Graphic3d_HorizontalTextAlignment aHJustification = Graphic3d_HTA_LEFT;
  Graphic3d_VerticalTextAlignment   aVJustification = Graphic3d_VTA_BOTTOM;

  for (; anArgIt < theArgNb; ++anArgIt)
  {
    TCollection_AsciiString aParam (theArgVec[anArgIt]);
    aParam.LowerCase();

    if (aParam == "-pos"
     || aParam == "-position")
    {
      if (anArgIt + 3 >= theArgNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      aPenLoc.SetX (Draw::Atof(theArgVec[++anArgIt]));
      aPenLoc.SetY (Draw::Atof(theArgVec[++anArgIt]));
      aPenLoc.SetZ (Draw::Atof(theArgVec[++anArgIt]));
    }
    else if (aParam == "-halign")
    {
      if (++anArgIt >= theArgNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      TCollection_AsciiString aType (theArgVec[anArgIt]);
      aType.LowerCase();
      if (aType == "left")
      {
        aHJustification = Graphic3d_HTA_LEFT;
      }
      else if (aType == "center")
      {
        aHJustification = Graphic3d_HTA_CENTER;
      }
      else if (aType == "right")
      {
        aHJustification = Graphic3d_HTA_RIGHT;
      }
      else
      {
        std::cout << "Error: wrong syntax at '" << aParam.ToCString() << "'.\n";
        return 1;
      }
    }
    else if (aParam == "-valign")
    {
      if (++anArgIt >= theArgNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      TCollection_AsciiString aType (theArgVec[anArgIt]);
      aType.LowerCase();
      if (aType == "top")
      {
        aVJustification = Graphic3d_VTA_TOP;
      }
      else if (aType == "center")
      {
        aVJustification = Graphic3d_VTA_CENTER;
      }
      else if (aType == "bottom")
      {
        aVJustification = Graphic3d_VTA_BOTTOM;
      }
      else if (aType == "topfirstline")
      {
        aVJustification = Graphic3d_VTA_TOPFIRSTLINE;
      }
      else
      {
        std::cout << "Error: wrong syntax at '" << aParam.ToCString() << "'.\n";
        return 1;
      }
    }
    else if (aParam == "-height")
    {
      if (++anArgIt >= theArgNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      aTextHeight = Draw::Atof(theArgVec[anArgIt]);
    }
    else if (aParam == "-aspect")
    {
      if (++anArgIt >= theArgNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      TCollection_AsciiString anOption (theArgVec[anArgIt]);
      anOption.LowerCase();
      if (!parseFontStyle (anOption, aFontAspect))
      {
        std::cout << "Error: unknown font aspect '" << anOption << "'.\n";
        return 1;
      }
    }
    else if (aParam == "-font")
    {
      if (++anArgIt >= theArgNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      aFontName = theArgVec[anArgIt];
    }
    else if (aParam == "-composite")
    {
      if (++anArgIt >= theArgNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      ViewerTest::ParseOnOff (theArgVec[anArgIt], anIsCompositeCurve);
    }
    else if (aParam == "-plane")
    {
      if (anArgIt + 6 >= theArgNb)
      {
        std::cout << "Error: wrong number of values for parameter '" << aParam.ToCString() << "'.\n";
        return 1;
      }

      Standard_Real aX = Draw::Atof (theArgVec[++anArgIt]);
      Standard_Real aY = Draw::Atof (theArgVec[++anArgIt]);
      Standard_Real aZ = Draw::Atof (theArgVec[++anArgIt]);
      aNormal.SetCoord (aX, aY, aZ);

      aX = Draw::Atof (theArgVec[++anArgIt]);
      aY = Draw::Atof (theArgVec[++anArgIt]);
      aZ = Draw::Atof (theArgVec[++anArgIt]);
      aDirection.SetCoord (aX, aY, aZ);
    }
    else
    {
      std::cerr << "Warning! Unknown argument '" << aParam << "'\n";
    }
  }

  aFont.SetCompositeCurveMode (anIsCompositeCurve);
  if (!aFont.Init (aFontName.ToCString(), aFontAspect, aTextHeight))
  {
    std::cerr << "Font initialization error\n";
    return 1;
  }

  aPenAx3 = gp_Ax3 (aPenLoc, aNormal, aDirection);

  Font_BRepTextBuilder aBuilder;
  DBRep::Set (aName, aBuilder.Perform (aFont, aText, aPenAx3, aHJustification, aVJustification));
  return 0;
}

//=======================================================================
//function : VFont
//purpose  : Font management
//=======================================================================

static int VFont (Draw_Interpretor& theDI,
                  Standard_Integer  theArgNb,
                  const char**      theArgVec)
{
  Handle(Font_FontMgr) aMgr = Font_FontMgr::GetInstance();
  if (theArgNb < 2)
  {
    // just print the list of available fonts
    Standard_Boolean isFirst = Standard_True;
    const Font_NListOfSystemFont aFonts = aMgr->GetAvailableFonts();
    for (Font_NListOfSystemFont::Iterator anIter (aFonts); anIter.More(); anIter.Next())
    {
      const Handle(Font_SystemFont)& aFont = anIter.Value();
      if (!isFirst)
      {
        theDI << "\n";
      }

      theDI << aFont->ToString();
      isFirst = Standard_False;
    }
    return 0;
  }

  for (Standard_Integer anArgIter = 1; anArgIter < theArgNb; ++anArgIter)
  {
    const TCollection_AsciiString anArg (theArgVec[anArgIter]);
    TCollection_AsciiString anArgCase (anArg);
    anArgCase.LowerCase();
    if (anArgIter + 1 < theArgNb
     && (anArgCase == "-find"
      || anArgCase == "find"))
    {
      Standard_CString aFontName   = theArgVec[++anArgIter];
      Font_FontAspect  aFontAspect = Font_FA_Undefined;
      if (++anArgIter < theArgNb)
      {
        anArgCase = theArgVec[anArgIter];
        anArgCase.LowerCase();
        if (!parseFontStyle (anArgCase, aFontAspect))
        {
          --anArgIter;
        }
      }

      if (Handle(Font_SystemFont) aFont = aMgr->FindFont (aFontName, aFontAspect))
      {
        theDI << aFont->ToString();
      }
      else
      {
        std::cerr << "Error: font '" << aFontName << "' is not found!\n";
      }
    }
    else if (anArgIter + 1 < theArgNb
          && (anArgCase == "-add"
           || anArgCase == "add"
           || anArgCase == "-register"
           || anArgCase == "register"))
    {
      ++anArgIter;
      Standard_CString aFontPath = theArgVec[anArgIter++];
      TCollection_AsciiString aFontName;
      Font_FontAspect  aFontAspect = Font_FA_Undefined;
      Standard_Integer isSingelStroke = -1;
      for (; anArgIter < theArgNb; ++anArgIter)
      {
        anArgCase = theArgVec[anArgIter];
        anArgCase.LowerCase();
        if (aFontAspect == Font_FontAspect_UNDEFINED
         && parseFontStyle (anArgCase, aFontAspect))
        {
          continue;
        }
        else if (anArgCase == "singlestroke"
              || anArgCase == "singleline"
              || anArgCase == "oneline")
        {
          isSingelStroke = 1;
        }
        else if (aFontName.IsEmpty())
        {
          aFontName = theArgVec[anArgIter];
        }
        else
        {
          --anArgIter;
          break;
        }
      }

      Handle(Font_SystemFont) aFont = aMgr->CheckFont (aFontPath);
      if (aFont.IsNull())
      {
        std::cerr << "Error: font '" << aFontPath << "' is not found!\n";
        continue;
      }

      if (aFontAspect != Font_FontAspect_UNDEFINED
      || !aFontName.IsEmpty())
      {
        TCollection_AsciiString aName = aFont->FontName();
        if (!aFontName.IsEmpty())
        {
          aName = aFontName;
        }
        Handle(Font_SystemFont) aFont2 = new Font_SystemFont (aName);
        if (aFontAspect != Font_FontAspect_UNDEFINED)
        {
          aFont2->SetFontPath (aFontAspect, aFontPath);
        }
        else
        {
          for (int anAspectIter = 0; anAspectIter < Font_FontAspect_NB; ++anAspectIter)
          {
            aFont2->SetFontPath ((Font_FontAspect )anAspectIter, aFont->FontPath ((Font_FontAspect )anAspectIter));
          }
        }
        aFont = aFont2;
      }
      if (isSingelStroke != -1)
      {
        aFont->SetSingleStrokeFont (isSingelStroke == 1);
      }

      aMgr->RegisterFont (aFont, Standard_True);
      theDI << aFont->ToString();
    }
    else if (anArgCase == "-verbose"
          || anArgCase == "-trace")
    {
      bool toEnable = true;
      if (anArgIter + 1 < theArgNb
       && ViewerTest::ParseOnOff (theArgVec[anArgIter + 1], toEnable))
      {
        ++anArgIter;
      }
      aMgr->SetTraceAliases (toEnable);
    }
    else
    {
      std::cerr << "Warning! Unknown argument '" << anArg << "'\n";
    }
  }

  return 0;
}

//=======================================================================
//function : VSetEdgeType
//purpose  : Edges type management
//=======================================================================

static int VSetEdgeType (Draw_Interpretor& theDI,
                         Standard_Integer  theArgNum,
                         const char**      theArgs)
{
  if (theArgNum < 4 || theArgNum > 9)
  {
    theDI << theArgs[0] << " error: wrong number of parameters. Type 'help "
          << theArgs[0] << "' for more information.\n";
    return 1;
  }

  Standard_Boolean isForceRedisplay = Standard_False;

  // Get shape name
  TCollection_AsciiString aName(theArgs[1]);
  Handle(AIS_InteractiveObject) anObject;
  if (!GetMapOfAIS().Find2 (aName, anObject))
  {
    theDI <<  theArgs[0] << " error: wrong object name.\n";
    return 1;
  }
  
  // Enable triangle edge mode
  if (!anObject->Attributes()->HasOwnShadingAspect())
  {
    anObject->Attributes()->SetShadingAspect (new Prs3d_ShadingAspect());
    *anObject->Attributes()->ShadingAspect()->Aspect() = *anObject->Attributes()->Link()->ShadingAspect()->Aspect();
  }
  const Handle(Prs3d_ShadingAspect)& aFillAreaAspect = anObject->Attributes()->ShadingAspect();
  aFillAreaAspect->Aspect()->SetEdgeOn();

  // Parse parameters
  for (Standard_Integer anIt = 2; anIt < theArgNum; ++anIt)
  {
    TCollection_AsciiString aParam ((theArgs[anIt]));
    if (aParam.Value (1) == '-' && !aParam.IsRealValue())
    {
      if (aParam.IsEqual ("-type"))
      {
        if (theArgNum <= anIt + 1)
        {
          theDI <<  theArgs[0] << " error: wrong number of values for parameter '"
                << aParam.ToCString() << "'.\n";
          return 1;
        }

        ++anIt;
        Aspect_TypeOfLine aTypeEnum = Aspect_TOL_SOLID;
        if (!ViewerTest::ParseLineType (theArgs[anIt], aTypeEnum))
        {
          std::cout << "Syntax error: wrong line type: '" << theArgs[anIt] << "'.\n";
          return 1;
        }
        anObject->Attributes()->ShadingAspect()->Aspect()->SetEdgeLineType (aTypeEnum);
      }
      else if (aParam.IsEqual ("-color"))
      {
        if (theArgNum <= anIt + 3)
        {
          theDI <<  theArgs[0] << " error: wrong number of values for parameter '"
                << aParam.ToCString() << "'.\n";
          return 1;
        }

        Standard_Real aR = Draw::Atof(theArgs[++anIt]);
        Standard_Real aG = Draw::Atof(theArgs[++anIt]);
        Standard_Real aB = Draw::Atof(theArgs[++anIt]);
        Quantity_Color aColor = Quantity_Color (aR > 1 ? aR / 255.0 : aR,
                                                aG > 1 ? aG / 255.0 : aG,
                                                aB > 1 ? aB / 255.0 : aB,
                                                Quantity_TOC_RGB);

        aFillAreaAspect->Aspect()->SetEdgeColor (aColor);
      }
      else if (aParam.IsEqual ("-force"))
      {
        isForceRedisplay = Standard_True;
      }
      else
      {
        theDI <<  theArgs[0] << " error: unknown parameter '"
              << aParam.ToCString() << "'.\n";
        return 1;
      }
    }
  }

  // Update shape presentation as aspect parameters were changed
  if (isForceRedisplay)
  {
    ViewerTest::GetAISContext()->Redisplay (anObject, Standard_False);
  }
  else
  {
    anObject->SetAspect (aFillAreaAspect);
  }

  //Update view
  ViewerTest::CurrentView()->Redraw();

  return 0;
}

//=======================================================================
//function : VUnsetEdgeType
//purpose  : Unsets edges visibility in shading mode
//=======================================================================

static int VUnsetEdgeType (Draw_Interpretor& theDI,
                         Standard_Integer  theArgNum,
                         const char**      theArgs)
{
  if (theArgNum != 2 && theArgNum != 3)
  {
    theDI << theArgs[0] << " error: wrong number of parameters. Type 'help "
          << theArgs[0] << "' for more information.\n";
    return 1;
  }

  Standard_Boolean isForceRedisplay = Standard_False;

  // Get shape name
  TCollection_AsciiString aName (theArgs[1]);
  Handle(AIS_InteractiveObject) anObject;
  if (!GetMapOfAIS().Find2 (aName, anObject))
  {
    theDI <<  theArgs[0] << " error: wrong object name.\n";
    return 1;
  }

  // Enable trianle edge mode
  anObject->Attributes()->ShadingAspect()->Aspect()->SetEdgeOff();

  // Parse parameters
  if (theArgNum == 3)
  {
    TCollection_AsciiString aParam ((theArgs[2]));
    if (aParam.IsEqual ("-force"))
    {
      isForceRedisplay = Standard_True;
    }
    else
    {
       theDI <<  theArgs[0] << " error: unknown parameter '"
              << aParam.ToCString() << "'.\n";
       return 1;
    }
  }

  // Update shape presentation as aspect parameters were changed
  if (isForceRedisplay)
  {
    ViewerTest::GetAISContext()->Redisplay (anObject, Standard_False);
  }
  else
  {
    anObject->SetAspect (anObject->Attributes()->ShadingAspect());
  }

  //Update view
  ViewerTest::CurrentView()->Redraw();

  return 0;
}


//=======================================================================
//function : VVertexMode
//purpose  : Switches vertex display mode for AIS_Shape or displays the current value
//=======================================================================

static int VVertexMode (Draw_Interpretor& theDI,
                         Standard_Integer  theArgNum,
                         const char**      theArgs)
{
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext();
  if (aContext.IsNull())
  {
    std::cout << "Error: no view available, call 'vinit' before!" << std::endl;
    return 1;
  }

  // No arguments --> print the current default vertex draw mode
  if (theArgNum == 1)
  {
    Prs3d_VertexDrawMode aCurrMode = aContext->DefaultDrawer()->VertexDrawMode();
    theDI <<  "Default vertex draw mode: " << (aCurrMode == Prs3d_VDM_Isolated ? "'isolated'" : "'all'") << "\n";
    return 0;
  }

  // -set argument --> change the default vertex draw mode and the mode for all displayed or given object(s)
  TCollection_AsciiString aParam (theArgs[1]);
  if (aParam == "-set")
  {
    if (theArgNum == 2)
    {
      std::cout << "Error: '-set' option not followed by the mode and optional object name(s)" << std::endl;
      std::cout << "Type 'help vvertexmode' for usage hints" << std::endl;
      return 1;
    }

    TCollection_AsciiString aModeStr (theArgs[2]);
    Prs3d_VertexDrawMode aNewMode =
       aModeStr == "isolated" ? Prs3d_VDM_Isolated :
      (aModeStr == "all"      ? Prs3d_VDM_All :
                                Prs3d_VDM_Inherited);

    Standard_Boolean aRedrawNeeded = Standard_False;
    AIS_ListOfInteractive anObjs;

    // No object(s) specified -> use all displayed
    if (theArgNum == 3)
    {
      theDI << "Setting the default vertex draw mode and updating all displayed objects...\n";
      aContext->DisplayedObjects (anObjs);
      aContext->DefaultDrawer()->SetVertexDrawMode (aNewMode);
      aRedrawNeeded = Standard_True;
    }

    Handle(AIS_InteractiveObject) anObject;
    for (Standard_Integer aCount = 3; aCount < theArgNum; aCount++)
    {
      TCollection_AsciiString aName (theArgs[aCount]);
      if (!GetMapOfAIS().Find2 (aName, anObject))
      {
        theDI << "Warning: wrong object name ignored - " << theArgs[0] << "\n";
        continue;
      }
      anObjs.Append (anObject);
    }

    for (AIS_ListIteratorOfListOfInteractive anIt (anObjs); anIt.More(); anIt.Next())
    {
      anObject = anIt.Value();
      anObject->Attributes()->SetVertexDrawMode (aNewMode);
      aContext->Redisplay (anObject, Standard_False);
      aRedrawNeeded = Standard_True;
    }

    if (aRedrawNeeded)
      ViewerTest::CurrentView()->Redraw();

    return 0;
  }

  Handle(AIS_InteractiveObject) anObject;
  if (theArgNum > 2
  || !GetMapOfAIS().Find2 (aParam, anObject))
  {
    std::cout << "Error: invalid number of arguments" << std::endl;
    return 1;
  }

  // One argument (object name) --> print the current vertex draw mode for the object
  Prs3d_VertexDrawMode aCurrMode = anObject->Attributes()->VertexDrawMode();
  theDI <<  "Object's vertex draw mode: " << (aCurrMode == Prs3d_VDM_Isolated ? "'isolated'" : "'all'") << "\n";
  return 0;
}

//=======================================================================
//function : VPointCloud
//purpose  : Create interactive object for arbitary set of points.
//=======================================================================
static Standard_Integer VPointCloud (Draw_Interpretor& theDI,
                                     Standard_Integer  theArgNum,
                                     const char**      theArgs)
{
  Handle(AIS_InteractiveContext) anAISContext = ViewerTest::GetAISContext();
  if (anAISContext.IsNull())
  {
    std::cerr << "Error: no active view!\n";
    return 1;
  }

  // command to execute
  enum Command
  {
    CloudForShape, // generate point cloud for shape
    CloudSphere,   // generate point cloud for generic sphere
    Unknow
  };

  // count number of non-optional command arguments
  Command aCmd = Unknow;
  Standard_Integer aCmdArgs = 0;
  for (Standard_Integer anArgIter = 1; anArgIter < theArgNum; ++anArgIter)
  {
    Standard_CString anArg = theArgs[anArgIter];
    TCollection_AsciiString aFlag (anArg);
    aFlag.LowerCase();
    if (aFlag.IsRealValue() || aFlag.Search ("-") != 1)
    {
      aCmdArgs++;
    }
  }
  switch (aCmdArgs)
  {
    case 2  : aCmd = CloudForShape; break;
    case 7  : aCmd = CloudSphere; break;
    default :
      std::cout << "Error: wrong number of arguments! See usage:\n";
      theDI.PrintHelp (theArgs[0]);
      return 1;
  }

  // parse options
  Standard_Boolean toRandColors = Standard_False;
  Standard_Boolean hasNormals   = Standard_True;
  Standard_Boolean isSetArgNorm = Standard_False;
  for (Standard_Integer anArgIter = 1; anArgIter < theArgNum; ++anArgIter)
  {
    Standard_CString anArg = theArgs[anArgIter];
    TCollection_AsciiString aFlag (anArg);
    aFlag.LowerCase();
    if (aFlag == "-randcolors"
     || aFlag == "-randcolor")
    {
      if (isSetArgNorm && hasNormals)
      {
        std::cout << "Error: wrong syntax - normals can not be enabled with colors at the same time\n";
        return 1;
      }
      toRandColors = Standard_True;
      hasNormals   = Standard_False;
    }
    else if (aFlag == "-normals"
          || aFlag == "-normal")
    {
      if (toRandColors)
      {
        std::cout << "Error: wrong syntax - normals can not be enabled with colors at the same time\n";
        return 1;
      }
      isSetArgNorm = Standard_True;
      hasNormals   = Standard_True;
    }
    else if (aFlag == "-nonormals"
          || aFlag == "-nonormal")
    {
      isSetArgNorm = Standard_True;
      hasNormals   = Standard_False;
    }
  }

  Standard_CString aName = theArgs[1];

  // generate arbitrary set of points
  Handle(Graphic3d_ArrayOfPoints) anArrayPoints;
  if (aCmd == CloudForShape)
  {
    Standard_CString aShapeName = theArgs[2];
    TopoDS_Shape     aShape     = DBRep::Get (aShapeName);

    if (aShape.IsNull())
    {
      std::cout << "Error: no shape with name '" << aShapeName << "' found\n";
      return 1;
    }

    // calculate number of points
    TopLoc_Location  aLocation;
    Standard_Integer aNbPoints = 0;
    for (TopExp_Explorer aFaceIt (aShape, TopAbs_FACE); aFaceIt.More(); aFaceIt.Next())
    {
      const TopoDS_Face& aFace = TopoDS::Face (aFaceIt.Current());
      Handle(Poly_Triangulation) aTriangulation = BRep_Tool::Triangulation (aFace, aLocation);
      if (!aTriangulation.IsNull())
      {
        aNbPoints += aTriangulation->NbNodes();
      }
    }
    if (aNbPoints < 3)
    {
      std::cout << "Error: shape should be triangulated!\n";
      return 1;
    }

    anArrayPoints = new Graphic3d_ArrayOfPoints (aNbPoints, toRandColors, hasNormals);
    for (TopExp_Explorer aFaceIt (aShape, TopAbs_FACE); aFaceIt.More(); aFaceIt.Next())
    {
      const TopoDS_Face& aFace = TopoDS::Face (aFaceIt.Current());
      Handle(Poly_Triangulation) aTriangulation = BRep_Tool::Triangulation (aFace, aLocation);
      if (aTriangulation.IsNull())
      {
        continue;
      }

      const TColgp_Array1OfPnt& aNodes = aTriangulation->Nodes();
      const gp_Trsf&            aTrsf  = aLocation.Transformation();

      // extract normals from nodes
      TColgp_Array1OfDir aNormals (aNodes.Lower(), hasNormals ? aNodes.Upper() : aNodes.Lower());
      if (hasNormals)
      {
        Poly_Connect aPolyConnect (aTriangulation);
        StdPrs_ToolTriangulatedShape::Normal (aFace, aPolyConnect, aNormals);
      }

      for (Standard_Integer aNodeIter = aNodes.Lower(); aNodeIter <= aNodes.Upper(); ++aNodeIter)
      {
        gp_Pnt aPoint = aNodes (aNodeIter);
        if (!aLocation.IsIdentity())
        {
          aPoint.Transform (aTrsf);
          if (hasNormals)
          {
            aNormals (aNodeIter).Transform (aTrsf);
          }
        }

        // add vertex into array of points
        const Standard_Integer anIndexOfPoint = anArrayPoints->AddVertex (aPoint);
        if (toRandColors)
        {
          Quantity_Color aColor (360.0 * Standard_Real(anIndexOfPoint) / Standard_Real(aNbPoints),
                                 1.0, 0.5, Quantity_TOC_HLS);
          anArrayPoints->SetVertexColor (anIndexOfPoint, aColor);
        }

        if (hasNormals)
        {
          anArrayPoints->SetVertexNormal (anIndexOfPoint, aNormals (aNodeIter));
        }
      }
    }
  }
  else if (aCmd == CloudSphere)
  {
    Standard_Real aCenterX       = Draw::Atof (theArgs[2]);
    Standard_Real aCenterY       = Draw::Atof (theArgs[3]);
    Standard_Real aCenterZ       = Draw::Atof (theArgs[4]);
    Standard_Real aRadius        = Draw::Atof (theArgs[5]);
    Standard_Integer aNbPoints   = Draw::Atoi (theArgs[6]);

    TCollection_AsciiString aDistribution = TCollection_AsciiString(theArgs[7]);
    aDistribution.LowerCase();
    if ( aDistribution != "surface" && aDistribution != "volume" )
    {
      std::cout << "Error: wrong arguments! See usage:\n";
      theDI.PrintHelp (theArgs[0]);
      return 1;
    }
    Standard_Boolean isSurface = aDistribution == "surface";

    gp_Pnt aCenter(aCenterX, aCenterY, aCenterZ);

    anArrayPoints = new Graphic3d_ArrayOfPoints (aNbPoints, toRandColors, hasNormals);
    for (Standard_Integer aPntIt = 0; aPntIt < aNbPoints; ++aPntIt)
    {
      Standard_Real anAlpha   = (Standard_Real (rand() % 2000) / 1000.0) * M_PI;
      Standard_Real aBeta     = (Standard_Real (rand() % 2000) / 1000.0) * M_PI;
      Standard_Real aDistance = isSurface ?
        aRadius : (Standard_Real (rand() % aNbPoints) / aNbPoints) * aRadius;

      gp_Dir aDir (Cos (anAlpha) * Sin (aBeta),
                   Sin (anAlpha),
                   Cos (anAlpha) * Cos (aBeta));
      gp_Pnt aPoint = aCenter.Translated (aDir.XYZ() * aDistance);

      const Standard_Integer anIndexOfPoint = anArrayPoints->AddVertex (aPoint);
      if (toRandColors)
      {
        Quantity_Color aColor (360.0 * Standard_Real (anIndexOfPoint) / Standard_Real (aNbPoints),
                               1.0, 0.5, Quantity_TOC_HLS);
        anArrayPoints->SetVertexColor (anIndexOfPoint, aColor);
      }

      if (hasNormals)
      {
        anArrayPoints->SetVertexNormal (anIndexOfPoint, aDir);
      }
    }
  }

  // set array of points in point cloud object
  Handle(AIS_PointCloud) aPointCloud = new AIS_PointCloud();
  aPointCloud->SetPoints (anArrayPoints);
  VDisplayAISObject (aName, aPointCloud);
  return 0;
}

//=======================================================================
//function : VPriority
//purpose  : Prints or sets the display priority for an object
//=======================================================================

static int VPriority (Draw_Interpretor& theDI,
                      Standard_Integer  theArgNum,
                      const char**      theArgs)
{
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext();
  ViewerTest_AutoUpdater anUpdateTool (aContext, ViewerTest::CurrentView());
  if (aContext.IsNull())
  {
    std::cout << "Error: no view available, call 'vinit' before!" << std::endl;
    return 1;
  }

  TCollection_AsciiString aLastArg (theArgs[theArgNum - 1]);
  Standard_Integer aPriority = -1;
  Standard_Integer aNbArgs   = theArgNum;
  if (aLastArg.IsIntegerValue())
  {
    aPriority = aLastArg.IntegerValue();
    --aNbArgs;
    if (aPriority < 0 || aPriority > 10)
    {
      std::cout << "Error: the specified display priority value '" << aLastArg
                << "' is outside the valid range [0..10]" << std::endl;
      return 1;
    }
  }
  else
  {
    anUpdateTool.Invalidate();
  }

  if (aNbArgs < 2)
  {
    std::cout << "Error: wrong number of arguments! See usage:\n";
    theDI.PrintHelp (theArgs[0]);
    return 1;
  }

  for (Standard_Integer anArgIter = 1; anArgIter < aNbArgs; ++anArgIter)
  {
    if (anUpdateTool.parseRedrawMode (theArgs[anArgIter]))
    {
      continue;
    }

    TCollection_AsciiString aName (theArgs[anArgIter]);
    Handle(AIS_InteractiveObject) anIObj;
    GetMapOfAIS().Find2 (aName, anIObj);
    if (anIObj.IsNull())
    {
      std::cout << "Error: the object '" << theArgs[1] << "' is not displayed" << std::endl;
      return 1;
    }

    if (aPriority < 1)
    {
      theDI << aContext->DisplayPriority (anIObj) << " ";
    }
    else
    {
      aContext->SetDisplayPriority (anIObj, aPriority);
    }
  }
  return 0;
}

//! Auxiliary class for command vnormals.
class MyShapeWithNormals : public AIS_Shape
{
  DEFINE_STANDARD_RTTI_INLINE(MyShapeWithNormals, AIS_Shape);
public:

  Standard_Real    NormalLength;
  Standard_Integer NbAlongU;
  Standard_Integer NbAlongV;
  Standard_Boolean ToUseMesh;
  Standard_Boolean ToOrient;

public:

  //! Main constructor.
  MyShapeWithNormals (const TopoDS_Shape& theShape)
  : AIS_Shape   (theShape),
    NormalLength(10),
    NbAlongU  (1),
    NbAlongV  (1),
    ToUseMesh (Standard_False),
    ToOrient  (Standard_False) {}

protected:

  //! Comnpute presentation.
  virtual void Compute (const Handle(PrsMgr_PresentationManager3d)& thePrsMgr,
                        const Handle(Prs3d_Presentation)&           thePrs,
                        const Standard_Integer                      theMode) Standard_OVERRIDE
  {
    AIS_Shape::Compute (thePrsMgr, thePrs, theMode);

    NCollection_DataMap<TopoDS_Face, NCollection_Vector<std::pair<gp_Pnt, gp_Pnt> > > aNormalMap;
    if (ToUseMesh)
    {
      DBRep_DrawableShape::addMeshNormals (aNormalMap, myshape, NormalLength);
    }
    else
    {
      DBRep_DrawableShape::addSurfaceNormals (aNormalMap, myshape, NormalLength, NbAlongU, NbAlongV);
    }

    Handle(Graphic3d_Group) aPrsGroup = Prs3d_Root::NewGroup (thePrs);
    aPrsGroup->SetGroupPrimitivesAspect (myDrawer->ArrowAspect()->Aspect());

    const Standard_Real aArrowAngle  = myDrawer->ArrowAspect()->Angle();
    const Standard_Real aArrowLength = myDrawer->ArrowAspect()->Length();
    for (NCollection_DataMap<TopoDS_Face, NCollection_Vector<std::pair<gp_Pnt, gp_Pnt> > >::Iterator aFaceIt (aNormalMap);
         aFaceIt.More(); aFaceIt.Next())
    {
      const Standard_Boolean toReverse = ToOrient && aFaceIt.Key().Orientation() == TopAbs_REVERSED;
      Handle(Graphic3d_ArrayOfSegments) aSegments = new Graphic3d_ArrayOfSegments (2 * aFaceIt.Value().Size());
      for (NCollection_Vector<std::pair<gp_Pnt, gp_Pnt> >::Iterator aPntIt (aFaceIt.Value()); aPntIt.More(); aPntIt.Next())
      {
        std::pair<gp_Pnt, gp_Pnt> aPair = aPntIt.Value();
        if (toReverse)
        {
          const gp_Vec aDir = aPair.first.XYZ() - aPair.second.XYZ();
          aPair.second = aPair.first.XYZ() + aDir.XYZ();
        }

        aSegments->AddVertex (aPair.first);
        aSegments->AddVertex (aPair.second);
        Prs3d_Arrow::Draw (aPrsGroup, aPair.second, gp_Vec(aPair.first, aPair.second), aArrowAngle, aArrowLength);
      }

      aPrsGroup->AddPrimitiveArray (aSegments);
    }
  }

};

//=======================================================================
//function : VNormals
//purpose  : Displays/Hides normals calculated on shape geometry or retrieved from triangulation
//=======================================================================
static int VNormals (Draw_Interpretor& theDI,
                     Standard_Integer  theArgNum,
                     const char**      theArgs)
{
  Handle(AIS_InteractiveContext) aContext = ViewerTest::GetAISContext();
  if (aContext.IsNull())
  {
    std::cout << "Error: no view available, call 'vinit' before!\n";
    return 1;
  }
  else if (theArgNum < 2)
  {
    std::cout << "Error: wrong number of arguments! See usage:\n";
    theDI.PrintHelp (theArgs[0]);
    return 1;
  }

  Standard_Integer anArgIter = 1;
  Standard_CString aShapeName = theArgs[anArgIter++];
  TopoDS_Shape     aShape     = DBRep::Get (aShapeName);
  Standard_Boolean isOn = Standard_True;
  if (aShape.IsNull())
  {
    std::cout << "Error: shape with name '" << aShapeName << "' is not found\n";
    return 1;
  }

  ViewerTest_DoubleMapOfInteractiveAndName& aMap = GetMapOfAIS();
  Handle(MyShapeWithNormals) aShapePrs;
  if (aMap.IsBound2 (aShapeName))
  {
    aShapePrs = Handle(MyShapeWithNormals)::DownCast (aMap.Find2 (aShapeName));
  }

  Standard_Boolean isUseMesh = Standard_False;
  Standard_Real    aLength = 10.0;
  Standard_Integer aNbAlongU = 1, aNbAlongV = 1;
  Standard_Boolean isOriented = Standard_False;
  for (; anArgIter < theArgNum; ++anArgIter)
  {
    TCollection_AsciiString aParam (theArgs[anArgIter]);
    aParam.LowerCase();
    if (anArgIter == 2
     && ViewerTest::ParseOnOff (aParam.ToCString(), isOn))
    {
      continue;
    }
    else if (aParam == "-usemesh"
          || aParam == "-mesh")
    {
      isUseMesh = Standard_True;
    }
    else if (aParam == "-length"
          || aParam == "-len")
    {
      ++anArgIter;
      aLength = anArgIter < theArgNum ? Draw::Atof (theArgs[anArgIter]) : 0.0;
      if (Abs (aLength) <= gp::Resolution())
      {
        std::cout << "Syntax error: length should not be zero\n";
        return 1;
      }
    }
    else if (aParam == "-orient"
          || aParam == "-oriented")
    {
      isOriented = Standard_True;
      if (anArgIter + 1 < theArgNum
        && ViewerTest::ParseOnOff (theArgs[anArgIter + 1], isOriented))
      {
        ++anArgIter;
      }
    }
    else if (aParam == "-nbalongu"
          || aParam == "-nbu")
    {
      ++anArgIter;
      aNbAlongU = anArgIter < theArgNum ? Draw::Atoi (theArgs[anArgIter]) : 0;
      if (aNbAlongU < 1)
      {
        std::cout << "Syntax error: NbAlongU should be >=1\n";
        return 1;
      }
    }
    else if (aParam == "-nbalongv"
          || aParam == "-nbv")
    {
      ++anArgIter;
      aNbAlongV = anArgIter < theArgNum ? Draw::Atoi (theArgs[anArgIter]) : 0;
      if (aNbAlongV < 1)
      {
        std::cout << "Syntax error: NbAlongV should be >=1\n";
        return 1;
      }
    }
    else if (aParam == "-nbalong"
          || aParam == "-nbuv")
    {
      ++anArgIter;
      aNbAlongU = anArgIter < theArgNum ? Draw::Atoi (theArgs[anArgIter]) : 0;
      aNbAlongV = aNbAlongU;
      if (aNbAlongU < 1)
      {
        std::cout << "Syntax error: NbAlong should be >=1\n";
        return 1;
      }
    }
    else
    {
      std::cout << "Syntax error: unknwon argument '" << aParam << "'\n";
      return 1;
    }
  }

  if (isOn)
  {
    if (aShapePrs.IsNull())
    {
      aShapePrs = new MyShapeWithNormals (aShape);
    }
    aShapePrs->ToUseMesh    = isUseMesh;
    aShapePrs->ToOrient     = isOriented;
    aShapePrs->NormalLength = aLength;
    aShapePrs->NbAlongU     = aNbAlongU;
    aShapePrs->NbAlongV     = aNbAlongV;
    VDisplayAISObject (aShapeName, aShapePrs);
  }
  else if (!aShapePrs.IsNull())
  {
    VDisplayAISObject (aShapeName, new AIS_Shape (aShape));
  }

  return 0;
}

//=======================================================================
//function : ObjectsCommands
//purpose  :
//=======================================================================

void ViewerTest::ObjectCommands(Draw_Interpretor& theCommands)
{
  const char *group ="AISObjects";

  theCommands.Add ("vtrihedron",
                   "vtrihedron : vtrihedron name"
                   "\n\t\t: [-dispMode {wireframe|shading} ]"
                   "\n\t\t: [-origin x y z ]"
                   "\n\t\t: [-zaxis u v w -xaxis u v w ]"
                   "\n\t\t: [-drawAxes {X|Y|Z|XY|YZ|XZ|XYZ}]"
                   "\n\t\t: [-hideLabels {on|off}]"
                   "\n\t\t: [-hideArrows {on|off}]"
                   "\n\t\t: [-label {XAxis|YAxis|ZAxis} value]"
                   "\n\t\t: [-attribute {XAxisLength|YAxisLength|ZAxisLength"
                   "\n\t\t:             |TubeRadiusPercent|ConeRadiusPercent"
                   "\n\t\t:             |ConeLengthPercent|OriginRadiusPercent"
                   "\n\t\t:             |ShadingNumberOfFacettes} value]"
                   "\n\t\t: [-color {Origin|XAxis|YAxis|ZAxis|XOYAxis|YOZAxis"
                   "\n\t\t:         |XOZAxis|Whole} {r g b | colorName}]"
                   "\n\t\t: [-textColor {r g b | colorName}]"
                   "\n\t\t: [-arrowColor {r g b | colorName}]"
                   "\n\t\t: [-priority {Origin|XAxis|YAxis|ZAxis|XArrow"
                   "\n\t\t:            |YArrow|ZArrow|XOYAxis|YOZAxis"
                   "\n\t\t:            |XOZAxis|Whole} value]"
                   "\n\t\t:"
                   "\n\t\t: Creates a new *AIS_Trihedron* object or changes parameters of "
                   "\n\t\t: existing trihedron. If no argument is set,"
                   "\n\t\t: the default trihedron (0XYZ) is created."
                   "\n\t\t: -dispMode mode of visualization: wf - wireframe,"
                   "\n\t\t:                                  sh - shading."
                   "\n\t\t:               Default value is wireframe."
                   "\n\t\t: -origin allows to set trihedron location."
                   "\n\t\t: -zaxis/-xaxis allows to set trihedron X and Z"
                   "\n\t\t:               directions. The directions should"
                   "\n\t\t:               be orthogonal. Y direction is calculated."
                   "\n\t\t: -drawAxes allows to set what axes are drawn in the"
                   "\n\t\t:           trihedron, default state is XYZ"
                   "\n\t\t: -hideLabels allows to show/hide trihedron labels"
                   "\n\t\t: -hideArrows allows to show/hide trihedron arrows"
                   "\n\t\t: -label allows to change default X/Y/Z titles of axes"
                   "\n\t\t: -attribute sets parameters of trihedron"
                   "\n\t\t: -color sets color properties of parts of trihedron"
                   "\n\t\t: -textColor sets color properties of trihedron labels"
                   "\n\t\t: -arrowColor sets color properties of trihedron arrows"
                   "\n\t\t: -priority allows to change default selection priority"
                   "\n\t\t: of trihedron components",
                   __FILE__,VTrihedron,group);

  theCommands.Add("vtri2d",
    "vtri2d Name"
    "\n\t\t: Creates a plane with a 2D trihedron from an interactively selected face.",
    __FILE__,VTrihedron2D ,group);

  theCommands.Add("vplanetri",
    "vplanetri name"
    "\n\t\t: Create a plane from a trihedron selection. If no arguments are set, the default",
    __FILE__,VPlaneTrihedron ,group);

  theCommands.Add("vsize",
    "vsize       : vsize [name(Default=Current)] [size(Default=100)] "
    "\n\t\t: Changes the size of a named or selected trihedron."
    "\n\t\t: If the name is not defined: it affects the selected trihedrons otherwise nothing is done."
    "\n\t\t: If the value is not defined: it is set to 100 by default.",
    __FILE__,VSize,group);

  theCommands.Add("vaxis",
    "vaxis name [Xa] [Ya] [Za] [Xb] [Yb] [Zb]"
    "\n\t\t: Creates an axis. If  the values are not defined, an axis is created by interactive selection of two vertices or one edge",
    __FILE__,VAxisBuilder,group);

  theCommands.Add("vaxispara",
    "vaxispara name "
    "\n\t\t: Creates an axis by interactive selection of an edge and a vertex.",
    __FILE__,VAxisBuilder,group);

  theCommands.Add("vaxisortho",
    "vaxisortho name "
    "\n\t\t: Creates an axis by interactive selection of an edge and a vertex. The axis will be orthogonal to the selected edge.",
    __FILE__,VAxisBuilder,group);

  theCommands.Add("vpoint",
    "vpoint  PointName [Xa] [Ya] [Za] "
    "\n\t\t: Creates a point from coordinates. If the values are not defined,"
    "\n\t\t: a point is created by interactive selection of a vertice or an edge (in the center of the edge).",
    __FILE__,VPointBuilder,group);

  theCommands.Add("vplane",
    "vplane  PlaneName [AxisName/PlaneName/PointName] [PointName/PointName/PointName] [Nothing/Nothing/PointName] [TypeOfSensitivity {0|1}]"
    "\n\t\t: Creates a plane from named or interactively selected entities."
    "\n\t\t: TypeOfSensitivity:"
    "\n\t\t:   0 - Interior"
    "\n\t\t:   1 - Boundary",
    __FILE__,VPlaneBuilder,group);

  theCommands.Add ("vchangeplane", "vchangeplane usage: \n"
    "   vchangeplane <plane_name>"
    " [x=center_x y=center_y z=center_z]"
    " [dx=dir_x dy=dir_y dz=dir_z]"
    " [sx=size_x sy=size_y]"
    " [noupdate]\n"
    "   - changes parameters of the plane:\n"
    "   - x y z     - center\n"
    "   - dx dy dz  - normal\n"
    "   - sx sy     - plane sizes\n"
    "   - noupdate  - do not update/redisplay the plane in context\n"
    "   Please enter coordinates in format \"param=value\" in arbitrary order.",
    __FILE__, VChangePlane, group);

  theCommands.Add("vplanepara",
    "vplanepara  PlaneName  "
    "\n\t\t: Creates a plane from interactively selected vertex and face.",
    __FILE__,VPlaneBuilder,group);

  theCommands.Add("vplaneortho",
    "vplaneortho  PlaneName  "
    "\n\t\t: Creates a plane from interactive selected face and coplanar edge. ",
    __FILE__,VPlaneBuilder,group);

  theCommands.Add("vline",
    "vline LineName [Xa/PointName] [Ya/PointName] [Za] [Xb] [Yb] [Zb]  "
    "\n\t\t: Creates a line from coordinates, named or interactively selected vertices. ",
    __FILE__,VLineBuilder,group);

  theCommands.Add("vcircle",
    "vcircle CircleName [PointName PointName PointName IsFilled]\n\t\t\t\t\t[PlaneName PointName Radius IsFilled]"
    "\n\t\t: Creates a circle from named or interactively selected entities."
    "\n\t\t: Parameter IsFilled is defined as 0 or 1.",
    __FILE__,VCircleBuilder,group);

  theCommands.Add ("vdrawtext",
                   "vdrawtext name text"
                   "\n\t\t: [-pos X=0 Y=0 Z=0]"
                   "\n\t\t: [-color {R G B|name}=yellow]"
                   "\n\t\t: [-halign {left|center|right}=left]"
                   "\n\t\t: [-valign {top|center|bottom|topfirstline}=bottom}]"
                   "\n\t\t: [-angle angle=0]"
                   "\n\t\t: [-zoom {0|1}=0]"
                   "\n\t\t: [-height height=16]"
                   "\n\t\t: [-aspect {regular|bold|italic|boldItalic}=regular]"
                   "\n\t\t: [-font font=Times]"
                   "\n\t\t: [-2d]"
                   "\n\t\t: [-perspos {X Y Z}=0 0 0], where"
                   "\n\t\t X and Y define the coordinate origin in 2d space relative to the view window"
                   "\n\t\t Example: X=0 Y=0 is center, X=1 Y=1 is upper right corner etc..."
                   "\n\t\t Z coordinate defines the gap from border of view window (except center position)."
                   "\n\t\t: [-disptype {blend|decal|shadow|subtitle|dimension|normal}=normal}"
                   "\n\t\t: [-subcolor {R G B|name}=white]"
                   "\n\t\t: [-noupdate]"
                   "\n\t\t: [-plane NormX NormY NormZ DirX DirY DirZ]"
                   "\n\t\t: [-flipping]"
                   "\n\t\t: Display text label at specified position.",
    __FILE__, VDrawText, group);

  theCommands.Add("vdrawsphere",
    "vdrawsphere: vdrawsphere shapeName Fineness [X=0.0 Y=0.0 Z=0.0] [Radius=100.0] [ToShowEdges=0] [ToPrintInfo=1]\n",
    __FILE__,VDrawSphere,group);

  theCommands.Add ("vlocation",
                "vlocation name"
      "\n\t\t:   [-reset]"
      "\n\t\t:   [-copyFrom otherName]"
      "\n\t\t:   [-translate X Y [Z]]"
      "\n\t\t:   [-rotate x y z dx dy dz angle]"
      "\n\t\t:   [-scale [X Y Z] scale]"
      "\n\t\t:   [-mirror x y z dx dy dz]"
      "\n\t\t:   [-setLocation X Y [Z]]"
      "\n\t\t:   [-setRotation QX QY QZ QW]"
      "\n\t\t:   [-setScale [X Y Z] scale]"
      "\n\t\t: Object local transformation management:"
      "\n\t\t:   -reset       reset transformation to identity"
      "\n\t\t:   -translate   translate object"
      "\n\t\t:   -rotate      applies rotation to local transformation"
      "\n\t\t:   -scale       applies scale    to local transformation"
      "\n\t\t:   -mirror      applies mirror   to local transformation"
      "\n\t\t:   -setLocation assign object location"
      "\n\t\t:   -setRotation assign object rotation (quaternion)"
      "\n\t\t:   -setScale    assign object scale factor",
        __FILE__, VSetLocation, group);
  theCommands.Add ("vsetlocation",
                   "alias for vlocation",
        __FILE__, VSetLocation, group);

  theCommands.Add ("vcomputehlr",
                "vcomputehlr shapeInput hlrResult [-algoType {algo|polyAlgo}=polyAlgo]"
      "\n\t\t:   [eyeX eyeY eyeZ dirX dirY dirZ upX upY upZ]"
      "\n\t\t:   [-showTangentEdges {on|off}=off] [-nbIsolines N=0] [-showHiddenEdges {on|off}=off]"
      "\n\t\t: Arguments:"
      "\n\t\t:  shapeInput - name of the initial shape"
      "\n\t\t:  hlrResult - result HLR object from initial shape"
      "\n\t\t:  eye, dir are eye position and look direction"
      "\n\t\t:  up is the look up direction vector"
      "\n\t\t:  -algoType HLR algorithm to use"
      "\n\t\t:  -showTangentEdges include tangent edges"
      "\n\t\t:  -nbIsolines include isolines"
      "\n\t\t:  -showHiddenEdges include hidden edges"
      "\n\t\t: Use vtop to see projected HLR shape.",
    __FILE__, VComputeHLR, group);

  theCommands.Add("vdrawparray",
                "vdrawparray name TypeOfArray={points|segments|polylines|triangles"
      "\n\t\t:                                |trianglefans|trianglestrips|quads|quadstrips|polygons}"
      "\n\t\t:              [-deinterleaved|-mutable]"
      "\n\t\t:              [vertex={'v' x y z [normal={'n' nx ny nz}] [color={'c' r g b}] [texel={'t' tx ty}]]"
      "\n\t\t:              [bound= {'b' nbVertices [bound_color={'c' r g b}]]"
      "\n\t\t:              [edge=  {'e' vertexId]"
      "\n\t\t:              [-shape shapeName] [-patch]"
      "\n\t\t: Commands create an Interactive Object for specified Primitive Array definition (Graphic3d_ArrayOfPrimitives)"
      "\n\t\t: with the main purpose is covering various combinations by tests",
    __FILE__,VDrawPArray,group);

  theCommands.Add("vconnect", 
    "vconnect name Xo Yo Zo object1 object2 ... [color=NAME]"
    "\n\t\t: Creates and displays AIS_ConnectedInteractive object from input object and location.",
    __FILE__, VConnect, group);

  theCommands.Add("vconnectto",
    "vconnectto : instance_name Xo Yo Zo object [-nodisplay|-noupdate|-update]"
    "  Makes an instance 'instance_name' of 'object' with position (Xo Yo Zo)."
    "\n\t\t:   -nodisplay - only creates interactive object, but not displays it",
    __FILE__, VConnectTo,group);

  theCommands.Add("vdisconnect",
    "vdisconnect assembly_name (object_name | object_number | 'all')"
    "  Disconnects all objects from assembly or disconnects object by name or number (use vlistconnected to enumerate assembly children).",
    __FILE__,VDisconnect,group);

  theCommands.Add("vaddconnected",
    "vaddconnected assembly_name object_name"
    "Adds object to assembly.",
    __FILE__,VAddConnected,group);

  theCommands.Add("vlistconnected",
    "vlistconnected assembly_name"
    "Lists objects in assembly.",
    __FILE__,VListConnected,group);


  theCommands.Add("vselmode", 
                "vselmode [object] selectionMode {on|off}"
      "\n\t\t:            [{-add|-set|-globalOrLocal}=-globalOrLocal]"
      "\n\t\t: Switches selection mode for the specified object or for all objects in context."
      "\n\t\t: Selection mode is either an integer number specific to Interactive Object,"
      "\n\t\t: or sub-shape type in case of AIS_Shape:"
      "\n\t\t:   Shape, Vertex, Edge, Wire, Face, Shell, Solid, CompSolid, Compound"
      "\n\t\t: The integer mode 0 (Shape in case of AIS_Shape) is reserved for selecting object as whole."
      "\n\t\t: Additional options:"
      "\n\t\t:  -add           already activated selection modes will be left activated"
      "\n\t\t:  -set           already activated selection modes will be deactivated"
      "\n\t\t:  -globalOrLocal (default) if new mode is Global selection mode,"
      "\n\t\t:                 then active local selection modes will be deactivated"
      "\n\t\t:                 and the samthen active local selection modes will be deactivated",
    __FILE__, VSetSelectionMode, group);

  theCommands.Add("vselnext",
    "vselnext : hilight next detected",
    __FILE__, VSelectionNext, group);

  theCommands.Add("vselprev",
    "vselnext : hilight previous detected",
    __FILE__, VSelectionPrevious, group);

  theCommands.Add("vtriangle",
    "vtriangle Name PointName PointName PointName"
    "\n\t\t: Creates and displays a filled triangle from named points.", 
    __FILE__, VTriangle,group);

  theCommands.Add("vsegment",
    "vsegment Name PointName PointName"
    "\n\t\t: Creates and displays a segment from named points.", 
    __FILE__, VTriangle,group);

  theCommands.Add("vobjzlayer",
    "vobjzlayer : set/get object [layerid] - set or get z layer id for the interactive object",
    __FILE__, VObjZLayer, group);
  
  theCommands.Add("vpolygonoffset",
    "vpolygonoffset : [object [mode factor units]] - sets/gets polygon offset parameters for an object, without arguments prints the default values",
    __FILE__, VPolygonOffset, group);

  theCommands.Add ("vshowfaceboundary",
    "vshowfaceboundary : ObjectName isOn (1/0) [R G B [LineWidth [LineStyle]]]"
    "- turns on/off drawing of face boundaries for ais object "
    "and defines boundary line style.",
    __FILE__, VShowFaceBoundary, group);

  theCommands.Add ("vmarkerstest",
                   "vmarkerstest: name X Y Z [PointsOnSide=10] [MarkerType=0] [Scale=1.0] [FileName=ImageFile]\n",
                   __FILE__, VMarkersTest, group);

  theCommands.Add ("text2brep",
                   "text2brep: name text"
                   "\n\t\t: [-pos X=0 Y=0 Z=0]"
                   "\n\t\t: [-halign {left|center|right}=left]"
                   "\n\t\t: [-valign {top|center|bottom|topfirstline}=bottom}]"
                   "\n\t\t: [-height height=16]"
                   "\n\t\t: [-aspect {regular|bold|italic|boldItalic}=regular]"
                   "\n\t\t: [-font font=Courier]"
                   "\n\t\t: [-composite {on|off}=off]"
                   "\n\t\t: [-plane NormX NormY NormZ DirX DirY DirZ]",
                   __FILE__, TextToBRep, group);
  theCommands.Add ("vfont",
                            "vfont [-add pathToFont [fontName] [regular,bold,italic,boldItalic=undefined] [singleStroke]]"
                   "\n\t\t:        [-find fontName [regular,bold,italic,boldItalic=undefined]] [-verbose {on|off}]",
                   __FILE__, VFont, group);
  
  theCommands.Add ("vsetedgetype",
                   "vsetedgetype usage:\n"
                   "vsetedgetype ShapeName [-force] [-type {solid, dash, dot}] [-color R G B] "
                   "\n\t\t:        Sets edges type and color for input shape",
                   __FILE__, VSetEdgeType, group);

  theCommands.Add ("vunsetedgetype",
                   "vunsetedgetype usage:\n"
                   "vunsetedgetype ShapeName [-force]"
                   "\n\t\t:        Unsets edges type and color for input shape",
                   __FILE__, VUnsetEdgeType, group);

  theCommands.Add ("vvertexmode",
                   "vvertexmode [name | -set {isolated | all | inherited} [name1 name2 ...]]\n"
                   "vvertexmode - prints the default vertex draw mode\n"
                   "vvertexmode name - prints the vertex draw mode of the given object\n"
                   "vvertexmode -set {isolated | all | inherited} - sets the default vertex draw mode and updates the mode for all displayed objects\n"
                   "vvertexmode -set {isolated | all | inherited} name1 name2 ... - sets the vertex draw mode for the specified object(s)\n",
                   __FILE__, VVertexMode, group);

  theCommands.Add ("vpointcloud",
                   "vpointcloud name shape [-randColor] [-normals] [-noNormals]"
                   "\n\t\t: Create an interactive object for arbitary set of points"
                   "\n\t\t: from triangulated shape."
                   "\n"
                   "vpointcloud name x y z r npts {surface|volume}\n"
                   "            ... [-randColor] [-normals] [-noNormals]"
                   "\n\t\t: Create arbitrary set of points (npts) randomly distributed"
                   "\n\t\t: on spheric surface or within spheric volume (x y z r)."
                   "\n\t\t:"
                   "\n\t\t: Additional options:"
                   "\n\t\t:  -randColor - generate random color per point"
                   "\n\t\t:  -normals   - generate normal per point (default)"
                   "\n\t\t:  -noNormals - do not generate normal per point"
                   "\n",
                   __FILE__, VPointCloud, group);

  theCommands.Add("vpriority",
    "vpriority [-noupdate|-update] name [value]\n\t\t  prints or sets the display priority for an object",
    __FILE__,
    VPriority, group);

  theCommands.Add ("vnormals",
                   "vnormals usage:\n"
                   "vnormals Shape [{on|off}=on] [-length {10}] [-nbAlongU {1}] [-nbAlongV {1}] [-nbAlong {1}]"
                   "\n\t\t:        [-useMesh] [-oriented {0}1}=0]"
                   "\n\t\t:  Displays/Hides normals calculated on shape geometry or retrieved from triangulation",
                   __FILE__, VNormals, group);
}
