#include "xAODRootAccess/TEvent.h"

void copyfiles ()
{
  // Load up the ATLAS libraries. The release should have already
  // been setup at this point.
  
  xAOD::Init();

  // Open the file. It should have been copied to this location
  // (or mounted here via docker's mount commands).
  auto inputFile (TFile::Open ("/data/inputfile.root"));

  xAOD::TEvent event;
  event.readFrom (inputFile);
  auto outputFile (TFile::Open ("/output/slimmed.root", "RECREATE"));
  event.writeTo (outputFile);

  for (unsigned int eventIndex = 0; eventIndex < 10; eventIndex++) // loop over events
  {
    event.getEntry (eventIndex);
    event.copy("AntiKt4EMTopoJets");
    event.copy("InDetTrackParticles");
    event.copy("TruthParticles");
    event.copy("EventInfo");
    event.copy("Muons");
    event.copy("Kt4EMPFlowEventShape");
    event.copy("Kt4EMPFlowPUSBEventShape");
    event.copy("Kt4EMTopoOriginEventShape");
    event.copy("TopoClusterIsoCentralEventShape");
    event.copy("TopoClusterIsoForwardEventShape");
    event.copy("NeutralParticleFlowIsoForwardEventShape");
    event.copy("NeutralParticleFlowIsoCentralEventShape");
    event.copy("PrimaryVertices");
    event.copy("MET_Track");
    event.copy("AntiKt4TruthJets");
    event.fill();
  }

  event.finishWritingTo(outputFile);
  delete outputFile;
  delete inputFile;
}
