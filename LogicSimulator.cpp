#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Logic device class
enum GateType { AND_GATE = 1, OR_GATE, NOT_GATE, UNKNOWN_GATE };

class Device {
protected:
    vector<Device*> inputPins;  // Store the input pins connected to this device
    GateType type;  // Gate type
public:
    virtual int getOutput() = 0;  // Calculate output
    void addInput(Device* input) {
        inputPins.push_back(input);
    }
    GateType getType() const {
        return type;
    }
    virtual ~Device() = default;
};

// AND gate implementation
class ANDGate : public Device {
public:
    ANDGate() { type = AND_GATE; }
    int getOutput() override {
        int output = 1;
        for (Device* pin : inputPins) {
            output &= pin->getOutput();  // AND operation
        }
        return output;
    }
};

// OR gate implementation
class ORGate : public Device {
public:
    ORGate() { type = OR_GATE; }
    int getOutput() override {
        int output = 0;
        for (Device* pin : inputPins) {
            output |= pin->getOutput();  // OR operation
        }
        return output;
    }
};

// NOT gate implementation
class NOTGate : public Device {
public:
    NOTGate() { type = NOT_GATE; }
    int getOutput() override {
        return !inputPins[0]->getOutput();  // NOT operation, only one input
    }
};

// InputPin class representing the circuit input
class InputPin : public Device {
    int value;
public:
    InputPin() { type = UNKNOWN_GATE; }  // InputPin doesn't need a specific type
    void setValue(int v) {
        value = v;
    }
    int getOutput() override {
        return value;  // The output of the input pin is its value
    }
};

// Logic simulator class
class LogicSimulator {
private:
    vector<Device*> devices;    // All devices (logic gates)
    vector<InputPin*> inputPins;  // Circuit input pins
    vector<Device*> outputPins;  // Circuit output pins
public:
    bool loadCircuit(const string& filePath);  // Load circuit file
    string getTruthTable();  // Generate truth table
    string simulate(const vector<int>& inputs);  // Simulate the circuit
    int getNumInputs();
    int getNumOutputs();
    void clearCircuit();  // Clear circuit
    string formatHeader();  // Helper function: format table header
};

// Helper function: format the truth table header
string LogicSimulator::formatHeader() {
    stringstream s1, s2, s3;
    for (int i = 1; i <= inputPins.size(); i++) {
        s1 << "i ";
        s2 << i << " ";
        s3 << "--";
    }
    s1 << "|"; s2 << "| "; s3 << "+";
    for (int i = 1; i <= outputPins.size(); i++) {
        s1 << " o";
        s2 << i << " ";
        s3 << "--";
    }
    return s1.str() + "\n" + s2.str() + "\n" + s3.str() + "\n";
}

// Clear circuit
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

// Read and parse the circuit file
bool LogicSimulator::loadCircuit(const string& filePath) {
    ifstream file(filePath);
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

    string line;
    getline(file, line);
    // Create all logic gates
    for (int i = 0; i < numGates; ++i) {
        getline(file, line);
        int gateType;
        stringstream gateStream(line);
        gateStream >> gateType;
        Device* gate = nullptr;
        switch (gateType) {
            case GateType::AND_GATE:
                gate = new ANDGate();
                break;
            case GateType::OR_GATE:
                gate = new ORGate();
                break;
            case GateType::NOT_GATE:
                gate = new NOTGate();
                break;
            default:
                cout << "Unknown gate type: " << gateType << endl;
                return false;
        }
        devices.push_back(gate);
    }

    file.clear();
    file.seekg(0);
    file >> numInputs >> numGates;

    vector<bool> isConnected(numGates, false);

    for (int i = 0; i < numGates; ++i) {
        int gateType;
        file >> gateType;
        Device* gate = devices[i];
        string connection;
        while (file >> connection && connection != "0") {
            int conn = atoi(connection.c_str());
            if (conn < 0) {
                int inputIndex = -conn - 1;
                if (inputIndex < 0 || inputIndex >= numInputs) {
                    cout << "Input pin error!" << endl;
                    return false;
                }
                gate->addInput(inputPins[inputIndex]);
            } else {
                int gateIndex = conn - 1;
                if (gateIndex < 0 || gateIndex >= devices.size()) {
                    cout << "Gate index error!" << endl;
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

    cout << "Circuit: " << numInputs << " input pins, " << outputPins.size() << " output pins and " << numGates << " gates" << endl << endl;
    return true;
}

// Simulate the circuit and return the result
string LogicSimulator::simulate(const vector<int>& inputs) {
    stringstream result;
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

// Generate the truth table
string LogicSimulator::getTruthTable() {
    stringstream table;
    int numInputs = inputPins.size();
    int totalCombinations = 1 << numInputs;
    table << formatHeader();  // Use the helper function to generate the header

    for (int i = 0; i < totalCombinations; ++i) {
        vector<int> inputs(numInputs);
        for (int j = 0; j < numInputs; ++j) {
            inputs[j] = (i >> (numInputs - j - 1)) & 1;
        }
        table << simulate(inputs) << endl;
    }
    return table.str();
}

int LogicSimulator::getNumInputs() {
    return inputPins.size();
}

int LogicSimulator::getNumOutputs() {
    return outputPins.size();
}

class TextUI {
private:
    LogicSimulator* simulator;

    void loadingFile() {
        string filePath;
        cout << "Please key in a file path: ";
        cin >> filePath;
        if (!simulator->loadCircuit(filePath)) {
            displayError("File not found or file format error!!");
        }
    }

    void Simulation() {
        if (simulator->getNumInputs() == 0) {
            displayError("Please load an lcf file, before using this operation.");
            return;
        }
        vector<int> inputs(simulator->getNumInputs());
        for (int i = 0; i < inputs.size(); ++i) {
            cout << "Please key in the value of input pin " << i + 1 << ": ";
            cin >> inputs[i];
            if (inputs[i] != 0 && inputs[i] != 1) {
                cout << "The value of input pin must be 0/1" << endl;
                --i;  // Prompt again for the same input
            }
        }
        string result = simulator->simulate(inputs);
        result = simulator->formatHeader() + result;
        displaySimulationResult(result);
    }

    void truthTable() {
        displayTruthTable(simulator->getTruthTable());
    }

    void Exit() {
        cout << "Goodbye, thanks for using LS." << endl;
    }

    void displayError(const string& errorMsg) const {
        cout << errorMsg << endl << endl;
    }

    void displaySimulationResult(const string& result) const {
        cout << "Simulation Result: " << endl << result << endl << endl;
    }

    void displayTruthTable(const string& truthTable) const {
        cout << "Truth table: " << endl << truthTable << endl;
    }

public:
    TextUI(LogicSimulator* sim) : simulator(sim) {}

    void displayMenu() const {
        cout << "1. Load logic circuit file" << endl;
        cout << "2. Simulation" << endl;
        cout << "3. Display truth table" << endl;
        cout << "4. Exit" << endl;
        cout << "Command: ";
    }

    void processCommand(int command) {
        switch (command) {
            case 1:
                loadingFile();
                break;
            case 2:
                Simulation();
                break;
            case 3:
                truthTable();
                break;
            case 4:
                Exit();
                break;
            default:
                displayError("Invalid command!");
                break;
        }
    }
};


// Main function
int main() {
    LogicSimulator simulator;
    TextUI ui(&simulator);
    int command = 0;

    while (command != 4) {
        ui.displayMenu();
        cin >> command;
        ui.processCommand(command);
    }
    return 0;
}


