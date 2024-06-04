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
#include "G4Box.hh"
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
#include "ExN04Detector.hh"


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
  /*
  G4VSolid* magcase_box1 = new G4Box("magcase_box1", fmag_xmax+15.*cm, fmag_ymax+15.*cm, (fmag1_dz/2.)-1*cm);
  G4LogicalVolume* magcase_log1 = new G4LogicalVolume(magcase_box1, fAir,"magcaseT_L1",0,0,0);
  //G4VPhysicalVolume * magcase_phys1 =
  new G4PVPlacement(0,G4ThreeVector(0,0,fmag1_locz+(fmag1_dz/2.)), magcase_log1, "magcase_phys1", experimentalHall_log, false, 0);
  G4VisAttributes* magcase_logVisAtt1 = new G4VisAttributes(G4Colour(0.0,1.0,0.0,0.1));
  //magcase_logVisAtt->SetForceWireframe(true);
  magcase_logVisAtt1->SetForceSolid(true);
  magcase_log1->SetVisAttributes(magcase_logVisAtt1);
  */


  G4VSolid* DV_box = new G4Box("DV_box", fmag_xmax, fmag_ymax, 10./2.*m);
  G4LogicalVolume* DV_log  = new G4LogicalVolume(DV_box, fAir,"DV_log",0,0,0);
  new G4PVPlacement(0,G4ThreeVector(0,0,10./2.*m), DV_log, "DV_phys", experimentalHall_log, false, 0);
  G4VisAttributes* DV_logVisAtt = new G4VisAttributes(G4Colour(0.8,0.8,0.8,0.3));
  DV_logVisAtt->SetForceWireframe(true);
  DV_logVisAtt->SetForceSolid(false);
  DV_log->SetVisAttributes(DV_logVisAtt);

  
  G4VSolid* mag_box1 = new G4Box("mag_box1", fmag_xmax, fmag_ymax, fmag1_dz/2.);
  G4LogicalVolume* mag_log1  = new G4LogicalVolume(mag_box1, fAir,"magT_L1",0,0,0);
  //G4VPhysicalVolume * mag_phys1 =
  new G4PVPlacement(0,G4ThreeVector(0,0,fmag1_locz+(fmag1_dz/2.)), mag_log1, "mag_phys1", experimentalHall_log, false, 0);
  G4VisAttributes* mag_logVisAtt1 = new G4VisAttributes(G4Colour(0.0,1.0,0.0,0.5));
  mag_logVisAtt1->SetForceWireframe(true);
  //mag_logVisAtt1->SetForceSolid(false);
  mag_log1->SetVisAttributes(mag_logVisAtt1);
  
  
  ExN04Field* myField1 = new ExN04Field;
  myField1->fzmin=fmag1_locz;
  myField1->fzmax=fmag1_locz+fmag1_dz;
  myField1->fymin=fmag_ymin;
  myField1->fymax=fmag_ymax;
  myField1->fxmin=fmag_xmin;
  myField1->fxmax=fmag_xmax;
  G4FieldManager* localFieldMgr1 = new G4FieldManager(myField1);
  localFieldMgr1->SetDetectorField(myField1);
  localFieldMgr1->CreateChordFinder(myField1);
  mag_log1->SetFieldManager(localFieldMgr1, true);
  



  //------------------------------ Sensitive detector
  G4Box* SD_box = new G4Box("SD_box", 10*m, 10*m, 1*cm);
  SD_log = new G4LogicalVolume(SD_box, fAir,"SD_log");
  G4VPhysicalVolume * SD_phys = new G4PVPlacement(0, G4ThreeVector(0,0,SD_locz), SD_log, "SD_phys", experimentalHall_log, false, 0);

  
    
  //------------------------------------------------------------------
  // Digitizer modules
  //------------------------------------------------------------------

  return experimentalHall_phys;
}


void ExN04DetectorConstruction::ConstructSDandField(){
  G4SDManager *sdman = G4SDManager::GetSDMpointer();
  
  ExN04Detector* sensDet = new ExN04Detector("sensDet");
  SD_log->SetSensitiveDetector(sensDet);

  sdman->AddNewDetector(sensDet);
  
}
