#ifndef LOGIC_SIMULATOR_H
#define LOGIC_SIMULATOR_H

#include "Device.h"
<<<<<<< HEAD
#include <string>
#include <vector>

=======
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "InputPin.h"
#include <string>
#include <vector>
>>>>>>> master
class LogicSimulator {
private:
    std::vector<Device*> devices;    // All devices (logic gates)
    std::vector<InputPin*> inputPins;  // Circuit input pins
    std::vector<Device*> outputPins;  // Circuit output pins
public:
<<<<<<< HEAD
    bool loadCircuit(const std::string& filePath);  // Load circuit file
    std::string getTruthTable();  // Generate truth table
    std::string simulate(const std::vector<int>& inputs);  // Simulate the circuit
    int getNumInputs();
    int getNumOutputs();
    void clearCircuit();  // Clear circuit
    std::string formatHeader();  // Helper function: format table header
=======
    virtual ~LogicSimulator() = default;
    
    virtual bool loadCircuit(const std::string& filePath);  // Load circuit file
    virtual std::string getTruthTable();  // Generate truth table
    virtual std::string simulate(const std::vector<int>& inputs);  // Simulate the circuit
    virtual int getNumInputs();
    virtual int getNumOutputs();
    virtual void clearCircuit();  // Clear circuit
>>>>>>> master
};

#endif // LOGIC_SIMULATOR_H
