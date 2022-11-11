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
/// \file eventgenerator/HepMC/HepMCEx01/src/ExN04EventAction.cc
/// \brief Implementation of the ExN04EventAction class
//
//

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4ios.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UImanager.hh"
#include "G4VHitsCollection.hh"
#include "ExN04EventAction.hh"
#include "ExN04CalorimeterHit.hh"
#include "ExN04DetectorHit.hh"
#include "ExN04MuonHit.hh"
#include "ExN04TrackerHit.hh"






//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
ExN04EventAction::ExN04EventAction()
 : G4UserEventAction(),
   ftrackerCollID(-1),
   fcalorimeterCollID(-1),
   fmuonCollID(-1)
{
  man = G4AnalysisManager::Instance();
  man->OpenFile("output.root");

  man->CreateNtuple("Hits","Hits");
  man->CreateNtupleIColumn("fEvent");
  man->CreateNtupleDColumn("ep_x");
  man->CreateNtupleDColumn("ep_y");
  man->CreateNtupleDColumn("ep_z");
  man->CreateNtupleDColumn("ep_E");
  man->CreateNtupleDColumn("em_x");
  man->CreateNtupleDColumn("em_y");
  man->CreateNtupleDColumn("em_z");
  man->CreateNtupleDColumn("em_E");
  man->FinishNtuple(0);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
ExN04EventAction::~ExN04EventAction()
{
  man->Write();
  man->CloseFile();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void ExN04EventAction::BeginOfEventAction(const G4Event*)
{ 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void ExN04EventAction::EndOfEventAction(const G4Event* evt)
{
  
  G4cout << ">>> Event " << evt->GetEventID() << G4endl;

  man->FillNtupleIColumn(0,evt->GetEventID());
    
  auto hce = evt->GetHCofThisEvent();
  auto sdManager = G4SDManager::GetSDMpointer();
  G4int collId;

  collId = sdManager->GetCollectionID("ExN04DetectorHitCollection");
  auto hc = hce->GetHC(collId);
  if (!hc)
    return;

  G4int count_elpair=0;
  
  for (unsigned int i = 0; i < hc->GetSize(); ++i) {
    auto hit = static_cast<ExN04DetectorHit *>(hc->GetHit(i));
    //G4cout << "hitX: " << hit->GetX() << G4endl;

    if (hit->GetPDGID() == -11){
      man->FillNtupleDColumn(1,hit->GetX());
      man->FillNtupleDColumn(2,hit->GetY());
      man->FillNtupleDColumn(3,hit->GetZ());
      man->FillNtupleDColumn(4,hit->GetEnergy());
      count_elpair+=1;
    }else if(hit->GetPDGID() == 11){
      man->FillNtupleDColumn(5,hit->GetX());
      man->FillNtupleDColumn(6,hit->GetY());
      man->FillNtupleDColumn(7,hit->GetZ());
      man->FillNtupleDColumn(8,hit->GetEnergy());
      count_elpair+=1;
    }
  }

  if (count_elpair>=2){
    man->AddNtupleRow(0);
  }
  if (count_elpair!=2){
    G4cout << "WARNING: Found " << count_elpair << " e+/e- candidates, should be = 2" << G4endl; 
  }
  
  /*
  if( ftrackerCollID<0 || fcalorimeterCollID<0 || fmuonCollID<0) return;

  G4HCofThisEvent* HCE = evt-> GetHCofThisEvent();
  ExN04TrackerHitsCollection* THC = NULL;
  ExN04CalorimeterHitsCollection* CHC = NULL;
  ExN04MuonHitsCollection* MHC = NULL;

  if( HCE ) {
    THC = (ExN04TrackerHitsCollection*)(HCE->GetHC(ftrackerCollID));
    CHC = (ExN04CalorimeterHitsCollection*)(HCE->GetHC(fcalorimeterCollID));
    MHC = (ExN04MuonHitsCollection*)(HCE->GetHC(fmuonCollID));
  }

  if( THC ) {
    G4int n_hit = THC-> entries();
    G4cout << "     " << n_hit
         << " hits are stored in ExN04TrackerHitsCollection." << G4endl;
  }

  if( CHC ) {
    G4int n_hit = CHC-> entries();
    G4cout << "     " << n_hit
         << " hits are stored in ExN04CalorimeterHitsCollection." << G4endl;
    G4double totE = 0;
    for( int i = 0; i < n_hit; i++ ) {
      totE += (*CHC)[i]-> GetEdep();
    }
    G4cout << "     Total energy deposition in calorimeter : "
         << totE / GeV << " (GeV)" << G4endl;
  }

  if( MHC ) {
    G4int n_hit = MHC-> entries();
    G4cout << "     " << n_hit
         << " hits are stored in ExN04MuonHitsCollection." << G4endl;
  }
  */
}

