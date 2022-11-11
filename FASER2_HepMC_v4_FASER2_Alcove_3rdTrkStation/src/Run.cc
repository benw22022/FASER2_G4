#include "Run.hh"

MyRunAction::MyRunAction()
{
  man = G4AnalysisManager::Instance();
  man->OpenFile("output.root");

  man->CreateNtuple("Hits","Hits");
  man->CreateNtupleIColumn("fEvent");
  man->CreateNtupleIColumn("fx");
  man->CreateNtupleIColumn("fy");
  man->CreateNtupleIColumn("fz");
  man->FinishNtuple(0);
  
}

MyRunAction::~MyRunAction()
{  
  man->Write();
  man->CloseFile();
}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
}

void MyRunAction::EndOfRunAction(const G4Run*){
}
