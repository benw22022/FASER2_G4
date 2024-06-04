#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "ExN04DetectorHit.hh"
#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
#include "g4root.hh"

class ExN04Detector : public G4VSensitiveDetector
{
public:
  ExN04Detector(G4String);
  ~ExN04Detector();

  void Initialize(G4HCofThisEvent *HCE);
  /// Temporary map of hits is stored in hit collection, to be retrieved
  /// for analysis by the event action
  void EndOfEvent(G4HCofThisEvent *HCE);

  G4bool ProcessHits(G4Step*, G4TouchableHistory*);

private:
  /// Hit collection stored in the event, filled in at the end of event based
  /// on temporary hits
  ExN04DetectorHitCollection *fHitCollection = nullptr;
  /// ID of hit collection
  G4int fHCID = -1;
  /// Temporary map of hits (ID: hit) collected within one event
  std::vector<ExN04DetectorHit *> fTmpHits;


  
};

#endif
