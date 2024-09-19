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
<<<<<<< HEAD
    GateType getType() const;
    virtual ~Device() = default;
};

class ANDGate : public Device {
public:
    ANDGate();
    int getOutput() override;
};

class ORGate : public Device {
public:
    ORGate();
    int getOutput() override;
};

class NOTGate : public Device {
public:
    NOTGate();
    int getOutput() override;
};

class InputPin : public Device {
    int value;
public:
    InputPin();
    void setValue(int v);
    int getOutput() override;
};
=======
    virtual ~Device() = default;
};

>>>>>>> master

#endif // DEVICE_H
