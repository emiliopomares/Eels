#include "Segment.hpp"
#include "Engine.hpp"
#include "DataSequence.hpp"

extern "C" void onAdditionComplete(DataSequence *d, Engine *e, int pass);
extern "C" void onSubstractionComplete(DataSequence *d, Engine *e, int pass);