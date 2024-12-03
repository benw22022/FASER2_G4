#include "params.hh"
#include "G4SystemOfUnits.hh"

GeometricalParameters *GeometricalParameters::me = 0;

GeometricalParameters::GeometricalParameters()
{
  // **** DEFAULT VALUES ***

  fSpectrometerMagnetField = 1.0*tesla;
  fexpHall_x = 10*m;
  fexpHall_y = 10*m;
  fexpHall_z = 50*m;

  //fmag_sphi =   0.*deg;
  //fmag_dphi = 360.*deg;
  //fmagcase_rmax =  130.*cm;
  //fmag_rmax =  100.*cm;

  fmagField_x = 0.*tesla;
  fmagField_y = 1.*tesla;  // Sim will be super slow if not changed by macro if 9999
  fmagField_z = 0.*tesla;

  fmag1_dz =  4.*m;
  fmag1_locz = 10.1*m;
  fmag_xmax =  150.*cm;
  fmag_xmin =  -150.*cm;
  fmag_ymax =  50.*cm;
  fmag_ymin =  -50.*cm;

  // For detector
  SD1_locz = 10.05*m;
  SD2_locz = 14.15*m;
  SD3_locz = 15.*m;
  SD4_locz = 16.*m;
  SD5_locz = 20.*m;

  ftrkTubs_rmax =  1.3*m;
  ftrkTubs_rmin =  1.*m;
  ftrkTubs_dz   = 5.*m;
  ftrkTubs_sphi =   0.*deg;
  ftrkTubs_dphi = 360.*deg;

  fnotrkLayers = 5;
  ftracker_radius[0] = 25.*cm;
  ftracker_radius[1] = 30.*cm;
  ftracker_radius[2] = 35.*cm;
  ftracker_radius[3] = 40.*cm;
  ftracker_radius[4] = 45.*cm;
  ftracker_thick     =  0.5*cm;
  for( int il=0; il < 5; il++ ) {
    ftracker_length[il] = ftracker_radius[il];
  }

  fcaloTubs_rmax = 300.*cm;
  fcaloTubs_rmin =  50.*cm;
  fcaloTubs_dz   = 200.*cm;
  fcaloTubs_sphi =   0.*deg;
  fcaloTubs_dphi = 360.*deg;

  fabsorber_thick = 3.*cm;
  fscinti_thick = 2.*cm;
  fnocaloLayers = int( (fcaloTubs_rmax - fcaloTubs_rmin) /
                      (fabsorber_thick + fscinti_thick) );

  fsegmentsinPhi = 48;
  fcaloCell_rmax = fcaloTubs_rmax;
  fcaloCell_rmin = fcaloTubs_rmin;
  fcaloCell_dz   = fcaloTubs_dz;
  fcaloCell_sphi = fcaloTubs_sphi;
  fcaloCell_dphi = fcaloTubs_dphi / fsegmentsinPhi;

  fsegmentsinZ = 20;
  fcaloRing_rmax = fcaloCell_rmax;
  fcaloRing_rmin = fcaloCell_rmin;
  fcaloRing_dz   = fcaloCell_dz / fsegmentsinZ ;
  fcaloRing_sphi = fcaloCell_sphi;
  fcaloRing_dphi = fcaloCell_dphi;

  fnomucounter = 4;
  fmuBox_radius = 350.*cm;
  fmuBox_width  = fmuBox_radius - 5.*cm;
  fmuBox_thick  = 1.*cm;
  fmuBox_length = fexpHall_z - 10.*cm;
}

GeometricalParameters* GeometricalParameters::Get()
{
  if (!me)
    me = new GeometricalParameters();
  return me; 
}


G4ThreeVector GeometricalParameters::GetSpectrometerMagnetField()
{
    return G4ThreeVector(0.,fSpectrometerMagnetField,0.); //field along Y
}
