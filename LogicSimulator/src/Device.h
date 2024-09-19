#ifndef DEVICE_H
#define DEVICE_H

#include <vector>

enum GateType { AND_GATE = 1, OR_GATE, NOT_GATE, UNKNOWN_GATE };

class Device {
protected:
    std::vector<Device*> inputPins;  // Store the input pins connected to this device
    GateType type;  // Gate type
public:
    virtual int getOutput() = 0;  // Calculate output
    void addInput(Device* input);
    virtual ~Device() = default;
};


#endif // DEVICE_H
