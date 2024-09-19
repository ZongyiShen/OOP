#ifndef ORGATE_H
#define ORGATE_H
#include "Device.h"

class OrGate : public Device {
public:
    OrGate();
    int getOutput() override;
};
#endif