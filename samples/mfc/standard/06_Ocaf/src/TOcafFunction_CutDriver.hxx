// File generated by CPPExt (Transient)
//
//                     Copyright (C) 1991,1995 by
//  
//                      MATRA DATAVISION, FRANCE
//  
// This software is furnished in accordance with the terms and conditions
// of the contract and with the inclusion of the above copyright notice.
// This software or any other copy thereof may not be provided or otherwise
// be made available to any other person. No title to an ownership of the
// software is hereby transferred.
//  
// At the termination of the contract, the software and all copies of this
// software must be deleted.
//
#ifndef _TOcafFunction_CutDriver_HeaderFile
#define _TOcafFunction_CutDriver_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif

#ifndef _TFunction_Driver_HeaderFile
#include <TFunction_Driver.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class TFunction_Logbook;


class TOcafFunction_CutDriver : public TFunction_Driver
{
public:

  Standard_EXPORT static const Standard_GUID& GetID() ;
  Standard_EXPORT TOcafFunction_CutDriver ();
  Standard_EXPORT virtual  void Validate (Handle (TFunction_Logbook)& log) const;
  Standard_EXPORT virtual  Standard_Boolean MustExecute (const Handle (TFunction_Logbook)& log) const;
  Standard_EXPORT virtual  Standard_Integer Execute (Handle (TFunction_Logbook)& log) const;

  // OCCT RTTI
  DEFINE_STANDARD_RTTIEXT(TOcafFunction_CutDriver,TFunction_Driver)
};

#endif