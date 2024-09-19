#ifndef INPUTPIN
#define INPUTPIN
#include "Device.h"

class InputPin : public Device {
private:
    int value;
public:
    InputPin();
    void setValue(int v);
    int getOutput() override;
};
#endif