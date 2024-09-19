#ifndef LOGIC_SIMULATOR_H
#define LOGIC_SIMULATOR_H

#include "Device.h"
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "InputPin.h"
#include <string>
#include <vector>
class LogicSimulator {
private:
    std::vector<Device*> devices;    // All devices (logic gates)
    std::vector<InputPin*> inputPins;  // Circuit input pins
    std::vector<Device*> outputPins;  // Circuit output pins
public:
    virtual ~LogicSimulator() = default;
    
    virtual bool loadCircuit(const std::string& filePath);  // Load circuit file
    virtual std::string getTruthTable();  // Generate truth table
    virtual std::string simulate(const std::vector<int>& inputs);  // Simulate the circuit
    virtual int getNumInputs();
    virtual int getNumOutputs();
    virtual void clearCircuit();  // Clear circuit
};

#endif // LOGIC_SIMULATOR_H
