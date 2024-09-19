#include "OrGate.h"

// ORGate class implementation
OrGate::OrGate() { type = OR_GATE; }

int OrGate::getOutput() {
    int output = 0;
    for (Device* pin : inputPins) {
        output |= pin->getOutput();  // OR operation
    }
    return output;
}