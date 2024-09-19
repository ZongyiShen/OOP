#include "AndGate.h"

// ANDGate class implementation
AndGate::AndGate() { type = AND_GATE; }

int AndGate::getOutput() {
    int output = 1;
    for (Device* pin : inputPins) {
        output &= pin->getOutput();  // AND operation
    }
    return output;
}