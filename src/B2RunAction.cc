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
// $Id: B2RunAction.cc 75214 2013-10-29 16:04:42Z gcosmo $
//
/// \file B2RunAction.cc
/// \brief Implementation of the B2RunAction class

#include "B2RunAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"

#include "G4SystemOfUnits.hh"

#include <sstream>
#include <cstring>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B2RunAction::B2RunAction()
 : G4UserRunAction()
{
  // set printing event number per each 100 events
  G4RunManager::GetRunManager()->SetPrintProgress(10);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B2RunAction::~B2RunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



void B2RunAction::BeginOfRunAction(const G4Run*)
{
  //inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
  /*
  G4AnalysisManager* aman = G4AnalysisManager::Instance();

  std::stringstream outfile;
  outfile << runCount;
  std::string filename = "./OutFiles/Tree_" + outfile.str();
  aman->OpenFile(filename.c_str());
//i here is the number of energy bins
  aman->CreateNtuple("neutronNtuple", "Energy of outcoming neutron");
  for (int i = 0; i < 10; i++) {
    std::stringstream out;
    out << i;
    std::string binname = "NeutronOutEnergy_" + out.str();
    aman->CreateNtupleDColumn(binname.c_str());
  }
  aman->FinishNtuple();

  aman->CreateNtuple("gammaNtuple", "Energy of outcoming gamma");
  for (int i = 0; i < 10; i++) {
    std::stringstream out;
    out << i;
    std::string binname = "GammaOutEnergy_" + out.str();
    aman->CreateNtupleDColumn(binname.c_str());
  }
  aman->FinishNtuple();

  aman->CreateH1("0", "Neutron Energy", 10, -2, 8);
  aman->CreateH1("1", "Gamma Energy", 10, -2, 8);
  */

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B2RunAction::EndOfRunAction(const G4Run* ) {
/*  
  G4AnalysisManager* aman = G4AnalysisManager::Instance();

  ifstream myDatOut;
  
  
  for (int i = 0; i < 10; i++) {
    aman->FillNtupleDColumn(0, i, double(aman->GetH1(0)->bin_height(i))/1000);
    G4cout << "Bin " << i << ": " << double(aman->GetH1(0)->bin_height(i)) << G4endl;
  }
  aman->AddNtupleRow(0);

  for (int i = 0; i < 10; i++) {
    aman->FillNtupleDColumn(1, i, double(aman->GetH1(1)->bin_height(i))/1000);
  }
  aman->AddNtupleRow(1);

  aman->Write();
  aman->CloseFile();
  runCount++;
*/
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
