#include "ExN04Detector.hh"
#include "G4SystemOfUnits.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) :
  G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector(){}
 
G4bool MySensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist){
  /*
  G4Track* track = aStep->GetTrack();
  track->SetTrackStatus(fStopAndKill);
  G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
  G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

  G4ThreeVector posHit = preStepPoint->GetPosition();
  G4int pdgid = track->GetParticleDefinition()->GetPDGEncoding();
  G4cout << "track pos: " << posHit << ", pdgid: " << pdgid << G4endl;

  G4int evt_number = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
  
  G4AnalysisManager* man = G4AnalysisManager::Instance();
  man->FillNtupleIColumn(0,evt_number);
  man->FillNtupleIColumn(1,pdgid);
  man->FillNtupleDColumn(2,posHit[0]/mm);
  man->FillNtupleDColumn(3,posHit[1]/mm);
  man->FillNtupleDColumn(4,posHit[2]/mm);
  */
  
}
