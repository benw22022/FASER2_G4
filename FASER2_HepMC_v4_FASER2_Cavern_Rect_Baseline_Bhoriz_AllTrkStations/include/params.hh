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
    
  private:
    //the singleton
    static GeometricalParameters *me;
    
    G4double fSpectrometerMagnetField;
};

#endif 