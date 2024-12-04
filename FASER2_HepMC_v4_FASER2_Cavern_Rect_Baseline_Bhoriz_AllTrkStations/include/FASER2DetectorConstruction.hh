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
/// \file eventgenerator/HepMC/HepMCEx01/include/FASER2DetectorConstruction.hh
/// \brief Definition of the FASER2DetectorConstruction class
//
//

#ifndef FASER2DetectorConstruction_h
#define FASER2DetectorConstruction_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "FASER2DetectorConstructionMessenger.hh"

class G4VPhysicalVolume;
class G4Material;
class FASER2Detector;

class FASER2DetectorConstruction : public G4VUserDetectorConstruction {
public:
  FASER2DetectorConstruction();
  ~FASER2DetectorConstruction();

  virtual G4VPhysicalVolume* Construct();

private:
  void DefineMaterials();
  
// #include "FASER2DetectorParameterDef.hh"

  G4Material* fAir;
  G4Material* fAr;
  G4Material* fSilicon;
  G4Material* fScinti;
  G4Material* fLead;
  
  G4LogicalVolume* mag_log1;
  G4LogicalVolume* SD1_log;
  G4LogicalVolume* SD2_log;
  G4LogicalVolume* SD3_log;
  G4LogicalVolume* SD4_log;
  G4LogicalVolume* SD5_log;
  
  FASER2Detector* sensDet1;
  FASER2Detector* sensDet2;
  FASER2Detector* sensDet3;
  FASER2Detector* sensDet4;
  FASER2Detector* sensDet5;

  G4VPhysicalVolume * experimentalHall_phys;

  bool detectorCreated1{false};
  bool detectorCreated2{false};

  virtual void ConstructSDandField();
  
  FASER2DetectorConstructionMessenger* messenger;

};

#endif
