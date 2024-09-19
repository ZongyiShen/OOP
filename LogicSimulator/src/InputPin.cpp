#include "InputPin.h"

// InputPin class implementation
InputPin::InputPin() { type = UNKNOWN_GATE; }

void InputPin::setValue(int v) {
    value = v;
}

int InputPin::getOutput() {
    return value;  // The output of the input pin is its value
}