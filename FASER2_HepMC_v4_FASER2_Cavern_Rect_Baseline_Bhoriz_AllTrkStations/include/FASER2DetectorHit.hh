#ifndef EXN04DETECTORHIT_HH
#define EXN04DETECTORHIT_HH

#include "G4THitsCollection.hh"
#include "G4VHit.hh"
#include "G4Types.hh"

#include <vector>


class FASER2DetectorHit : public G4VHit {
public:
  FASER2DetectorHit();
  ~FASER2DetectorHit(){};
  /// Draw pixels
  void Draw();
  ///// Get hit ID calculated as 1000 * sensorID + cellID
  //G4int ID() { return 1000 * fCopyNumSensor + fCopyNumCell; }
  inline void SetPosition(G4double x, G4double y, G4double z) {
    fPosX = x;
    fPosY = y;
    fPosZ = z;
  }

  inline void SetPDGID(G4int pdgid){
    fPDGID = pdgid;
  }

  inline void SetEnergy(G4double E){
    fEnergy = E;
  }

  inline void SetCharge(G4double charge){
    fCharge = charge;
  }

  inline void SetPx(G4double px){
    fPx = px;
  }
  
  inline void SetPy(G4double py){
    fPy = py;
  }

  inline void SetPz(G4double pz){
    fPz = pz;
  }

  inline void SetMass(G4double mass){
    fMass = mass;
  }
  inline void SetTrackID(G4int trackID){
    fTrackID = trackID;
  }
  inline void SetParentID(G4int parentID){
    fParentID = parentID;
  }


  /// Get hit X position
  inline G4double GetX() const { return fPosX; }
  /// Get hit Y position
  inline G4double GetY() const { return fPosY; }
  /// Get hit Z position
  inline G4double GetZ() const { return fPosZ; }
  /// Get hit pdgID
  inline G4double GetPDGID() const { return fPDGID; }
  /// Get hit Energy
  inline G4double GetEnergy() const { return fEnergy; }
  /// Get hit Charge
  inline G4double GetCharge() const { return fCharge; }
  /// Get hit px
  inline G4double GetPx() const { return fPx; }
  /// Get hit py
  inline G4double GetPy() const { return fPy; }
  /// Get hit pz
  inline G4double GetPz() const { return fPz; }
  /// Get hit mass
  inline G4double GetMass() const { return fMass; }
  /// Get hit track ID
  inline G4int GetTrackID() const { return fTrackID; }
  /// Get hit parent ID
  inline G4int GetParentID() const { return fParentID; }


private:
  /// Position along x axis
  G4double fPosX = -1;
  /// Position along y axis
  G4double fPosY = -1;
  /// Position along z axis
  G4double fPosZ = -1;
  /// PDGID
  G4int fPDGID = -999;
  /// Energy
  G4double fEnergy = -999.;
  //Charge
  G4double fCharge = -999.;
  // Momentum
  G4double fPx = -999.;
  G4double fPy = -999.;
  G4double fPz = -999.;
  // Mass
  G4double fMass = -999.;
  // Track ID
  G4int fTrackID = -999;
  // Parent ID
  G4int fParentID = -999;

};

typedef G4THitsCollection<FASER2DetectorHit> FASER2DetectorHitCollection;

#endif /* EXN04DETECTORHIT_HH */
