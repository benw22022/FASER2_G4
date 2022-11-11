//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file eventgenerator/HepMC/HepMCEx01/src/ExN04DetectorConstruction.cc
/// \brief Implementation of the ExN04DetectorConstruction class
//
//

#include "G4Box.hh"
#include "G4Colour.hh"
#include "G4Element.hh"
#include "G4NistManager.hh"
#include "G4FieldManager.hh"
#include "G4LogicalVolume.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4PVParameterised.hh"
#include "G4PVPlacement.hh"
#include "G4ThreeVector.hh"
#include "G4Tubs.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4TransportationManager.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"
#include "ExN04CalorimeterParametrisation.hh"
#include "ExN04CalorimeterROGeometry.hh"
#include "ExN04CalorimeterSD.hh"
#include "ExN04DetectorConstruction.hh"
#include "ExN04Field.hh"
#include "ExN04MuonSD.hh"
#include "ExN04TrackerParametrisation.hh"
#include "ExN04TrackerSD.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
ExN04DetectorConstruction::ExN04DetectorConstruction()
 : G4VUserDetectorConstruction()
{
#include "ExN04DetectorParameterDef.icc"
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
ExN04DetectorConstruction::~ExN04DetectorConstruction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void ExN04DetectorConstruction::DefineMaterials()
{
  //-------------------------------------------------------------------------
  // Materials
  //-------------------------------------------------------------------------
  G4NistManager* nistManager = G4NistManager::Instance();
  fAir = nistManager->FindOrBuildMaterial("G4_AIR");
  fLead = nistManager->FindOrBuildMaterial("G4_Pb");
  fSilicon = nistManager->FindOrBuildMaterial("G4_Si");

  G4double a, z, density;
  G4int nel;

  // Argon gas
  a= 39.95*g/mole;
  density= 1.782e-03*g/cm3;
  fAr= new G4Material("ArgonGas", z=18., a, density);

  // Scintillator
  G4Element* elH = nistManager->FindOrBuildElement("H");
  G4Element* elC = nistManager->FindOrBuildElement("C");
  fScinti = new G4Material("Scintillator", density= 1.032*g/cm3, nel=2);
  fScinti-> AddElement(elC, 9);
  fScinti-> AddElement(elH, 10);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4VPhysicalVolume* ExN04DetectorConstruction::Construct()
{
  //-------------------------------------------------------------------------
  // Magnetic field
  //-------------------------------------------------------------------------

  /*
  static G4bool fieldIsInitialized = false;
  if ( !fieldIsInitialized ) {
    ExN04Field* myField = new ExN04Field;
    G4FieldManager* fieldMgr
      = G4TransportationManager::GetTransportationManager()->
        GetFieldManager();
    fieldMgr-> SetDetectorField(myField);
    fieldMgr-> CreateChordFinder(myField);
    fieldIsInitialized = true;
  }
  */
  
  //-------------------------------------------------------------------------
  // Materials
  //-------------------------------------------------------------------------
  DefineMaterials();

  //-------------------------------------------------------------------------
  // Detector geometry
  //-------------------------------------------------------------------------

  //------------------------------ experimental hall
  G4Box* experimentalHall_box =
         new G4Box("expHall_b", fexpHall_x, fexpHall_y, fexpHall_z);
  G4LogicalVolume* experimentalHall_log =
         new G4LogicalVolume(experimentalHall_box, fAir,"expHall_L", 0,0,0);
  G4VPhysicalVolume * experimentalHall_phys =
         new G4PVPlacement(0, G4ThreeVector(), experimentalHall_log,
                           "expHall_P", 0, false,0);
  G4VisAttributes* experimentalHallVisAtt =
         new G4VisAttributes(G4Colour(1.,1.,1.));
  experimentalHallVisAtt-> SetForceWireframe(true);
  experimentalHall_log-> SetVisAttributes(experimentalHallVisAtt);



  //------------------------------ Magnet 1
  G4VSolid* magcase_tubs1 = new G4Tubs("magcaseTubs_tubs1", fmag_rmax, fmagcase_rmax, fmag1_dz/2, fmag_sphi, fmag_dphi);
  G4LogicalVolume* magcase_log1 = new G4LogicalVolume(magcase_tubs1, fAir,"magcaseT_L1",0,0,0);
  //G4VPhysicalVolume * magcase_phys1 =
    new G4PVPlacement(0,G4ThreeVector(0,0,fmag1_locz+(fmag1_dz/2.)), magcase_log1, "magcase_phys1", experimentalHall_log, false, 0);
  G4VisAttributes* magcase_logVisAtt1 = new G4VisAttributes(G4Colour(1.0,0.0,1.0,0.1));
  //magcase_logVisAtt->SetForceWireframe(true);
  magcase_logVisAtt1->SetForceSolid(true);
  magcase_log1->SetVisAttributes(magcase_logVisAtt1);

  G4VSolid* mag_tubs1 = new G4Tubs("magTubs_tubs1", 0, fmag_rmax, fmag1_dz/2, fmag_sphi, fmag_dphi);
  G4LogicalVolume* mag_log1  = new G4LogicalVolume(mag_tubs1, fAir,"magT_L1",0,0,0);
  //G4VPhysicalVolume * mag_phys1 =
    new G4PVPlacement(0,G4ThreeVector(0,0,fmag1_locz+(fmag1_dz/2.)), mag_log1, "mag_phys1", experimentalHall_log, false, 0);
  G4VisAttributes* mag_logVisAtt1 = new G4VisAttributes(G4Colour(1.0,1.0,1.0,0.05));
  mag_logVisAtt1->SetForceWireframe(true);
  mag_logVisAtt1->SetForceSolid(false);
  mag_log1->SetVisAttributes(mag_logVisAtt1);

  
  ExN04Field* myField1 = new ExN04Field;
  myField1->fzmin=0;
  myField1->fzmax=fmag1_dz;
  G4FieldManager* localFieldMgr1 = new G4FieldManager(myField1);
  localFieldMgr1->SetDetectorField(myField1);
  localFieldMgr1->CreateChordFinder(myField1);
  mag_log1->SetFieldManager(localFieldMgr1, true);
  

  
  //------------------------------ Magnet 2
  G4VSolid* magcase_tubs2 = new G4Tubs("magcaseTubs_tubs2", fmag_rmax, fmagcase_rmax, fmag2_dz/2, fmag_sphi, fmag_dphi);
  G4LogicalVolume* magcase_log2 = new G4LogicalVolume(magcase_tubs2, fAir,"magcaseT_L2",0,0,0);
  //G4VPhysicalVolume * magcase_phys2 =
    new G4PVPlacement(0,G4ThreeVector(0,0,fmag2_locz+(fmag2_dz/2.)), magcase_log2, "magcase_phys2",experimentalHall_log, false, 0);
  G4VisAttributes* magcase_logVisAtt2 = new G4VisAttributes(G4Colour(0.0,1.0,0.0,0.1));
  //magcase_logVisAtt->SetForceWireframe(true);
  magcase_logVisAtt2->SetForceSolid(true);
  magcase_log2->SetVisAttributes(magcase_logVisAtt2);

  G4VSolid* mag_tubs2 = new G4Tubs("magTubs_tubs2", 0, fmag_rmax, fmag2_dz/2, fmag_sphi, fmag_dphi);
  G4LogicalVolume* mag_log2  = new G4LogicalVolume(mag_tubs2, fAir,"magT_L2",0,0,0);
  //G4VPhysicalVolume * mag_phys2 =
    new G4PVPlacement(0,G4ThreeVector(0,0,fmag2_locz+(fmag2_dz/2.)), mag_log2, "mag_phys2", experimentalHall_log, false, 0);
  G4VisAttributes* mag_logVisAtt2 = new G4VisAttributes(G4Colour(1.0,1.0,1.0,0.1));
  mag_logVisAtt2->SetForceWireframe(false);
  mag_logVisAtt2->SetForceSolid(true);
  mag_log2->SetVisAttributes(mag_logVisAtt2);


  ExN04Field* myField2 = new ExN04Field;
  //myField2->fzmin=100*m;//fmag2_locz;
  //myField2->fzmax=100*m;//fmag2_locz+fmag2_dz;
  myField2->fzmin=fmag2_locz;
  myField2->fzmax=fmag2_locz+fmag2_dz;
  G4FieldManager* localFieldMgr2 = new G4FieldManager(myField2);
  localFieldMgr2->SetDetectorField(myField2);
  localFieldMgr2->CreateChordFinder(myField2);
  mag_log2->SetFieldManager(localFieldMgr2, true);
  


 
    
  //------------------------------------------------------------------
  // Digitizer modules
  //------------------------------------------------------------------

  return experimentalHall_phys;
}
