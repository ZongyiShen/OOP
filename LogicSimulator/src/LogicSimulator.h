#ifndef LOGIC_SIMULATOR_H
#define LOGIC_SIMULATOR_H

#include "Device.h"
#include <string>
#include <vector>

class LogicSimulator {
private:
    std::vector<Device*> devices;    // All devices (logic gates)
    std::vector<InputPin*> inputPins;  // Circuit input pins
    std::vector<Device*> outputPins;  // Circuit output pins
public:
    bool loadCircuit(const std::string& filePath);  // Load circuit file
    std::string getTruthTable();  // Generate truth table
    std::string simulate(const std::vector<int>& inputs);  // Simulate the circuit
    int getNumInputs();
    int getNumOutputs();
    void clearCircuit();  // Clear circuit
    std::string formatHeader();  // Helper function: format table header
};

#endif // LOGIC_SIMULATOR_H
