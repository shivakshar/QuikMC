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
// $Id: B2TrackerSD.cc 87359 2014-12-01 16:04:27Z gcosmo $
//
// / \file B2TrackerSD.cc
// / \brief Implementation of the B2TrackerSD class

#include "B2TrackerSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "G4SystemOfUnits.hh"
#include <cmath>
#include "B2Analysis.hh"

B2TrackerSD::B2TrackerSD(const G4String& name,
                         const G4String& hitsCollectionName)
  : G4VSensitiveDetector(name),
  fHitsCollection(NULL) {
  // fout("OutputFile.txt",std::fstream::out|std::fstream::trunc)
  collectionName.insert(hitsCollectionName);
}

B2TrackerSD::~B2TrackerSD() {
}

void B2TrackerSD::Initialize(G4HCofThisEvent * hce) {
  // Create hits collection

  fHitsCollection
    = new B2TrackerHitsCollection(SensitiveDetectorName, collectionName[0]);

  // Add this collection in hce

  neutron_num = 0;
  gamma_num = 0;

  G4int hcID
    = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
  hce->AddHitsCollection(hcID, fHitsCollection);
}


// Tracking Particle
G4bool B2TrackerSD::ProcessHits(G4Step * aStep, G4TouchableHistory *) {
  G4AnalysisManager * aman = G4AnalysisManager::Instance();
  auto particle_def = aStep->GetTrack()->GetParticleDefinition();
G4cout << "Event!" << G4endl;
  if (particle_def->GetPDGEncoding() == 2112 && aStep->IsFirstStepInVolume()) {
    aman->FillH1(0, std::log10(aStep->GetTrack()->GetKineticEnergy()/eV));
    G4cout << "Neutron Out: " << std::log10(aStep->GetTrack()->GetKineticEnergy()/eV) << G4endl;
    return true;
  }
  if (particle_def->GetPDGEncoding() == 22 && aStep->IsFirstStepInVolume()) {
    aman->FillH1(1, std::log10(aStep->GetTrack()->GetKineticEnergy()/eV));
    G4cout << "Gamma Out: " << std::log10(aStep->GetTrack()->GetKineticEnergy()/eV) << G4endl;
    return true;
  }

  return false;
}


void B2TrackerSD::EndOfEvent(G4HCofThisEvent *) {
}
