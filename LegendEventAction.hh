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
// $Id: LegendEventAction.hh 68752 2013-04-05 10:23:47Z gcosmo $
//
/// \file optical/Legend/include/LegendEventAction.hh
/// \brief Definition of the LegendEventAction class
//

#ifndef LegendEventAction_h
#define LegendEventAction_h 1

#include "LegendEventMessenger.hh"
#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"

class G4Event;
class LegendRecorderBase;

class LegendEventAction : public G4UserEventAction
{
  public:

    LegendEventAction(LegendRecorderBase*);
    virtual ~LegendEventAction();

  public:

    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);

    void SetSaveThreshold(G4int );

    void SetEventVerbose(G4int v){fVerbose=v;}

    void SetPMTThreshold(G4int t){fPMTThreshold=t;}

    void SetForceDrawPhotons(G4bool b){fForcedrawphotons=b;}
    void SetForceDrawNoPhotons(G4bool b){fForcenophotons=b;}

  private:

    LegendRecorderBase* fRecorder;
    LegendEventMessenger* fEventMessenger;

    G4int              fSaveThreshold;

    G4int              fScintCollID;
    G4int              fPMTCollID;

    G4int              fVerbose;

    G4int              fPMTThreshold;

    G4bool fForcedrawphotons;
    G4bool fForcenophotons;

};

#endif
