#include "LogicSimulator.h"
#include <fstream>
#include <sstream>
#include <iostream>

void LogicSimulator::clearCircuit() {
    for (Device* device : devices) {
        delete device;
    }
    for (InputPin* input : inputPins) {
        delete input;
    }
    devices.clear();
    inputPins.clear();
    outputPins.clear();
}

bool LogicSimulator::loadCircuit(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        return false;
    }

    int numInputs, numGates;
    file >> numInputs >> numGates;

    clearCircuit();  // Clear previous circuit data

    // Initialize input pins
    inputPins.resize(numInputs);
    for (int i = 0; i < numInputs; ++i) {
        inputPins[i] = new InputPin();
    }

    std::string line;
    std::getline(file, line);
    // Create all logic gates
    for (int i = 0; i < numGates; ++i) {
        std::getline(file, line);
        int gateType;
        std::stringstream gateStream(line);
        gateStream >> gateType;
        Device* gate = nullptr;
        switch (gateType) {
            case GateType::AND_GATE:
                gate = new AndGate();
                break;
            case GateType::OR_GATE:
                gate = new OrGate();
                break;
            case GateType::NOT_GATE:
                gate = new NotGate();
                break;
            default:
                return false;
        }
        devices.push_back(gate);
    }

    file.clear();
    file.seekg(0);
    file >> numInputs >> numGates;

    std::vector<bool> isConnected(numGates, false);

    for (int i = 0; i < numGates; ++i) {
        int gateType;
        file >> gateType;
        Device* gate = devices[i];
        std::string connection;
        while (file >> connection && connection != "0") {
            int conn = std::atoi(connection.c_str());
            if (conn < 0) {
                int inputIndex = -conn - 1;
                if (inputIndex < 0 || inputIndex >= numInputs) {
                    return false;
                }
                gate->addInput(inputPins[inputIndex]);
            } else {
                int gateIndex = conn - 1;
                if (gateIndex < 0 || gateIndex >= devices.size()) {
                    return false;
                }
                gate->addInput(devices[gateIndex]);
                isConnected[gateIndex] = true;
            }
        }
    }

    for (int i = 0; i < numGates; ++i) {
        if (!isConnected[i]) {
            outputPins.push_back(devices[i]);
        }
    }

    std::cout << "Circuit: " << numInputs << " input pins, " << outputPins.size() << " output pins and " << numGates << " gates" << std::endl << std::endl;
    return true;
}

std::string LogicSimulator::simulate(const std::vector<int>& inputs) {
    std::stringstream result;
    for (size_t i = 0; i < inputs.size(); ++i) {
        inputPins[i]->setValue(inputs[i]);
        result << inputs[i] << " ";
    }
    result << "| ";
    for (Device* outputPin : outputPins) {
        result << outputPin->getOutput() << " ";
    }
    return result.str();
}

std::string LogicSimulator::getTruthTable() {
    std::stringstream table;
    int numInputs = inputPins.size();
    int totalCombinations = 1 << numInputs;

    for (int i = 0; i < totalCombinations; ++i) {
        std::vector<int> inputs(numInputs);
        for (int j = 0; j < numInputs; ++j) {
            inputs[j] = (i >> (numInputs - j - 1)) & 1;
        }
        table << simulate(inputs) << std::endl;
    }
    return table.str();
}

int LogicSimulator::getNumInputs() {
    return inputPins.size();
}

int LogicSimulator::getNumOutputs() {
    return outputPins.size();
}
