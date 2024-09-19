#ifndef ANDGATE_H
#define ANDGATE_H
#include "Device.h"

class AndGate : public Device {
public:
    AndGate();
    int getOutput() override;
};
#endif