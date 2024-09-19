#ifndef NOTGATE_H
#define NOTGATE_H
#include "Device.h"

class NotGate : public Device {
public:
    NotGate();
    int getOutput() override;
};

#endif