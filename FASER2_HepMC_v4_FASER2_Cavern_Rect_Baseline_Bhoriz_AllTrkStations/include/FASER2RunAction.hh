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
/// \file eventgenerator/HepMC/HepMCEx01/include/FASER2RunAction.hh
/// \brief Definition of the FASER2RunAction class
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef FASER2RunAction_h
#define FASER2RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "FASER2RunActionMessenger.hh"
#include "G4AnalysisManager.hh"
#include <map>
#include <unordered_set>

class G4Run;

class FASER2RunAction : public G4UserRunAction {

public:
  FASER2RunAction();
  ~FASER2RunAction();

  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndOfRunAction(const G4Run*);
  
  G4String GetOutputFileName() const;
  void SetOutputFileName(const G4String fname);

  G4AnalysisManager* man;

  void FillHitsRow(G4double x, G4double y, G4double z, G4double E, G4int pdgc, G4double charge, G4int layernum);
  void ClearHits();
  G4int MergeHits(G4double xtol, G4double ytol);

  private:
    G4String foutputFileName;
    FASER2RunActionMessenger* messenger;

    mutable std::vector<G4double> m_hits_x;
    mutable std::vector<G4double> m_hits_y;
    mutable std::vector<G4double> m_hits_z;
    mutable std::vector<G4double> m_hits_E;
    mutable std::vector<G4int>    m_hits_pdgc;
    mutable std::vector<G4double> m_hits_charge;
    mutable std::vector<G4int>    m_hits_layernum;

    std::set<G4int> FindHitsToMerge(G4double xtol, G4double ytol) const;

};

#endif
