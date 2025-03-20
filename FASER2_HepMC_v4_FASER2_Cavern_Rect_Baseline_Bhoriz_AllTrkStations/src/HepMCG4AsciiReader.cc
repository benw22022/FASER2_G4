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
/// \file eventgenerator/HepMC/HepMCEx01/src/HepMCG4AsciiReader.cc
/// \brief Implementation of the HepMCG4AsciiReader class
//
//

#include "HepMCG4AsciiReader.hh"
#include "HepMC3/ReaderAsciiHepMC2.h"
#include "HepMCG4AsciiReaderMessenger.hh"

#include <iostream>
#include <fstream>
#include <memory>

int GetHepMCVersionNumber(std::string filename)
{
  std::ifstream inputFile(filename);
  if (!inputFile.is_open()) {
      std::cerr << "Error: Could not open the file: " << filename << std::endl;
      return 0;
  }

  std::string firstLine;
  std::getline(inputFile, firstLine);
  inputFile.close();

  std::istringstream iss(firstLine);
  std::string label, versionNumber;
  iss >> label >> versionNumber;
  
  char firstDigit = '\0'; 

  for (char ch : versionNumber) {
      if (std::isdigit(ch)) {
          firstDigit = ch;
          break;
      }
  }

  int major_version_number = firstDigit - '0';

  std::cout << "major version number is " << major_version_number << std::endl; 
  return major_version_number;
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
HepMCG4AsciiReader::HepMCG4AsciiReader()
  :  filename("xxx.dat"), verbose(0)
{
  int major_version_number = GetHepMCVersionNumber(filename);

  if (major_version_number == 2) { 
    std::cout << "Using HepMC2 reader" << std::endl;
    asciiInput = new HepMC3::ReaderAsciiHepMC2(filename.c_str()); }
  else if (major_version_number == 3) { 
    std::cout << "Using HepMC3 reader" << std::endl;
    asciiInput = new HepMC3::ReaderAscii(filename.c_str()); }
  else{
    G4cout << "WARNING: HepMC version is not 2 or 3: will try using the HepMC3 reader" << G4endl;
    asciiInput = new HepMC3::ReaderAscii(filename.c_str()); 
  }
  

  messenger = new HepMCG4AsciiReaderMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
HepMCG4AsciiReader::~HepMCG4AsciiReader()
{
  delete asciiInput;
  delete messenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void HepMCG4AsciiReader::Initialize()
{
  delete asciiInput;

  int major_version_number = GetHepMCVersionNumber(filename);

  if (major_version_number == 2) { 
    std::cout << "Using HepMC2 reader" << std::endl;
    asciiInput = new HepMC3::ReaderAsciiHepMC2(filename.c_str()); }
  else if (major_version_number == 3) { 
    std::cout << "Using HepMC2 reader" << std::endl;
    asciiInput = new HepMC3::ReaderAscii(filename.c_str()); }
  else{
    G4cout << "WARNING: HepMC version is not 2 or 3: will try using the HepMC3 reader" << G4endl;
    asciiInput = new HepMC3::ReaderAscii(filename.c_str()); 
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
std::shared_ptr<HepMC3::GenEvent> HepMCG4AsciiReader::GenerateHepMCEvent()
{ 
  std::shared_ptr<HepMC3::GenEvent> evt = std::make_shared<HepMC3::GenEvent>();
  asciiInput->read_event(*evt);
  // HepMC3::Print::content(*evt);
  return evt;
}
