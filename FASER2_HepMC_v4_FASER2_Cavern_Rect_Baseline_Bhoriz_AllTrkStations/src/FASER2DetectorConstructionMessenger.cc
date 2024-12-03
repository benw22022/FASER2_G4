#include "FASER2DetectorConstructionMessenger.hh"
#include "FASER2DetectorConstruction.hh"
// #include "geometry/GeometricalParameters.hh"
// #include "FASER2DetectorParameterDef.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcommand.hh"
#include "G4UIcmdWithABool.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4ThreeVector.hh"
#include "params.hh"
#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4RunManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

FASER2DetectorConstructionMessenger::FASER2DetectorConstructionMessenger(FASER2DetectorConstruction* manager) 
  : det(manager) {
    detDir = new G4UIdirectory("/det/");
    detDir->SetGuidance("detector control");
 
    // GENERAL OPTIONS  
    // detGdmlCmd = new G4UIcmdWithABool("/det/saveGdml", this);
    // detGdmlCmd->SetParameterName("saveGdml", true);
    // detGdmlCmd->SetDefaultValue(false);
    
    
    magnetFieldCmd = new G4UIcmdWithADoubleAndUnit("/det/magnetField", this);
    magnetFieldCmd->SetUnitCategory("Magnetic flux density");
    magnetFieldCmd->SetDefaultUnit("tesla");
    magnetFieldCmd->SetUnitCandidates("tesla kG G");
    magnetFieldCmd->SetDefaultValue(1.0);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

FASER2DetectorConstructionMessenger::~FASER2DetectorConstructionMessenger() {
//   delete detGdmlCmd;
  delete magnetFieldCmd;
  delete detDir;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void FASER2DetectorConstructionMessenger::SetNewValue(G4UIcommand* command, G4String newValues) {
  
  // flare
//   if (command == detGdmlCmd) det->SaveGDML(detGdmlCmd->GetNewBoolValue(newValues));
    if (command == magnetFieldCmd) { 
      G4cout << "Changing magnetic field!!!" << G4endl;
      GeometricalParameters::Get()->SetSpectrometerMagnetField(magnetFieldCmd->ConvertToDimensionedDouble(newValues)); 
      G4RunManager::GetRunManager()->ReinitializeGeometry();
      }; 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......