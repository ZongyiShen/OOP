#include "NotGate.h"

// NOTGate class implementation
NotGate::NotGate() { type = NOT_GATE; }

int NotGate::getOutput() {
    return !inputPins[0]->getOutput();  // NOT operation, only one input
}