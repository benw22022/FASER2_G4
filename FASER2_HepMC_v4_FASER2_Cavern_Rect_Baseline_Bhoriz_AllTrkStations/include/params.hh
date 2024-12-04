#ifndef GeometricalParameters_hh
#define GeometricalParameters_hh

#include <set>

#include "G4String.hh"
#include "G4ThreeVector.hh"

/** This class stores geometrical parameters for quick access
 *  It can be called form any other class to retrieve 
 *  configuration options or parameters whenever needed
**/

class GeometricalParameters  {
  private:
    GeometricalParameters();
  public:
    static GeometricalParameters* Get();
    virtual ~GeometricalParameters() {}

    void SetSpectrometerMagnetField(G4double val) { fSpectrometerMagnetField = val; }
    G4ThreeVector GetSpectrometerMagnetField();

    G4double fmagField_x;
    G4double fmagField_y;
    G4double fmagField_z;

    G4double fexpHall_x;
    G4double fexpHall_y;
    G4double fexpHall_z;

    G4double fmag_sphi;
    G4double fmag_dphi;
    G4double fmagcase_rmax;
    G4double fmag_rmax;

    G4double fmag_xmax;
    G4double fmag_xmin;
    G4double fmag_ymax;
    G4double fmag_ymin;

    G4double fmag1_dz;
    G4double fmag1_locz;

    // For detector
    G4double SD1_locz;
    G4double SD2_locz;
    G4double SD3_locz;
    G4double SD4_locz;
    G4double SD5_locz;


    G4double fmag2_dz;
    G4double fmag2_locz;

    G4double fmag3_dz;
    G4double fmag3_locz;

    G4double ftrkTubs_rmax;
    G4double ftrkTubs_rmin;
    G4double ftrkTubs_dz;
    G4double ftrkTubs_sphi;
    G4double ftrkTubs_dphi;

    G4int fnotrkLayers;
    G4double ftracker_radius[5];
    G4double ftracker_thick;
    G4double ftracker_length[5];

    G4double fcaloTubs_rmax;
    G4double fcaloTubs_rmin;
    G4double fcaloTubs_dz;
    G4double fcaloTubs_sphi;
    G4double fcaloTubs_dphi;

    G4int fnocaloLayers;
    G4double fabsorber_thick;
    G4double fscinti_thick;

    G4int fsegmentsinZ;
    G4double fcaloRing_rmax;
    G4double fcaloRing_rmin;
    G4double fcaloRing_dz;
    G4double fcaloRing_sphi;
    G4double fcaloRing_dphi;

    G4int fsegmentsinPhi;
    G4double fcaloCell_rmax;
    G4double fcaloCell_rmin;
    G4double fcaloCell_dz;
    G4double fcaloCell_sphi;
    G4double fcaloCell_dphi;

    G4int fnomucounter;
    G4double fmuBox_radius;
    G4double fmuBox_width;
    G4double fmuBox_thick;
    G4double fmuBox_length;
    
  private:
    //the singleton
    static GeometricalParameters *me;
    
    G4double fSpectrometerMagnetField;
};

#endif 