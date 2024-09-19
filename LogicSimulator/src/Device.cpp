#include "Device.h"

// Device class implementation
void Device::addInput(Device* input) {
    inputPins.push_back(input);
}
