#include "Device.h"

// Device class implementation
void Device::addInput(Device* input) {
    inputPins.push_back(input);
}
<<<<<<< HEAD

GateType Device::getType() const {
    return type;
}

// ANDGate class implementation
ANDGate::ANDGate() { type = AND_GATE; }

int ANDGate::getOutput() {
    int output = 1;
    for (Device* pin : inputPins) {
        output &= pin->getOutput();  // AND operation
    }
    return output;
}

// ORGate class implementation
ORGate::ORGate() { type = OR_GATE; }

int ORGate::getOutput() {
    int output = 0;
    for (Device* pin : inputPins) {
        output |= pin->getOutput();  // OR operation
    }
    return output;
}

// NOTGate class implementation
NOTGate::NOTGate() { type = NOT_GATE; }

int NOTGate::getOutput() {
    return !inputPins[0]->getOutput();  // NOT operation, only one input
}

// InputPin class implementation
InputPin::InputPin() { type = UNKNOWN_GATE; }

void InputPin::setValue(int v) {
    value = v;
}

int InputPin::getOutput() {
    return value;  // The output of the input pin is its value
}
=======
>>>>>>> master
