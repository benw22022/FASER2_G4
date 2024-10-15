#include "params.hh"
#include "G4SystemOfUnits.hh"

GeometricalParameters *GeometricalParameters::me = 0;

GeometricalParameters::GeometricalParameters()
{
  // **** DEFAULT VALUES ***

  fSpectrometerMagnetField = 1.0*tesla;
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
