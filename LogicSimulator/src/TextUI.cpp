#include "TextUI.h"
#include <iostream>

TextUI::TextUI(LogicSimulator* sim) : simulator(sim) {}

<<<<<<< HEAD
=======
void TextUI::formatHeader(int inputSize,int outputSize) const{
    std::stringstream s1, s2, s3;
    for (int i = 1; i <= inputSize; i++) {
        s1 << "i ";
        s2 << i << " ";
        s3 << "--";
    }
    s1 << "|"; s2 << "| "; s3 << "+";
    for (int i = 1; i <= outputSize; i++) {
        s1 << " o";
        s2 << i << " ";
        s3 << "--";
    }
    std::cout << s1.str() + "\n" + s2.str() + "\n" + s3.str() + "\n";
}

>>>>>>> master
void TextUI::loadingFile() {
    std::string filePath;
    std::cout << "Please key in a file path: ";
    std::cin >> filePath;
    if (!simulator->loadCircuit(filePath)) {
        displayError("File not found or file format error!!");
    }
}

void TextUI::Simulation() {
    if (simulator->getNumInputs() == 0) {
        displayError("Please load an lcf file, before using this operation.");
        return;
    }
    std::vector<int> inputs(simulator->getNumInputs());
    for (int i = 0; i < inputs.size(); ++i) {
        std::cout << "Please key in the value of input pin " << i + 1 << ": ";
        std::cin >> inputs[i];
        if (inputs[i] != 0 && inputs[i] != 1) {
            std::cout << "The value of input pin must be 0/1" << std::endl;
            --i;  // Prompt again for the same input
        }
    }
    std::string result = simulator->simulate(inputs);
<<<<<<< HEAD
    result = simulator->formatHeader() + result;
    displaySimulationResult(result);
}

void TextUI::truthTable() {
=======
    displaySimulationResult(result);
}

void TextUI::TruthTable() {
>>>>>>> master
    displayTruthTable(simulator->getTruthTable());
}

void TextUI::Exit() {
    std::cout << "Goodbye, thanks for using LS." << std::endl;
}

void TextUI::displayError(const std::string& errorMsg) const {
    std::cout << errorMsg << std::endl << std::endl;
}

void TextUI::displaySimulationResult(const std::string& result) const {
<<<<<<< HEAD
    std::cout << "Simulation Result: " << std::endl << result << std::endl << std::endl;
}

void TextUI::displayTruthTable(const std::string& truthTable) const {
    std::cout << "Truth table: " << std::endl << truthTable << std::endl;
=======
    std::cout << "Simulation Result: " << std::endl;
    formatHeader(simulator->getNumInputs(),simulator->getNumOutputs());
    std::cout << result << std::endl << std::endl;
}

void TextUI::displayTruthTable(const std::string& truthTable) const {
    std::cout << "Truth table: " << std::endl;
    formatHeader(simulator->getNumInputs(),simulator->getNumOutputs());
    std::cout << truthTable << std::endl;
>>>>>>> master
}

void TextUI::displayMenu() const {
    std::cout << "1. Load logic circuit file" << std::endl;
    std::cout << "2. Simulation" << std::endl;
    std::cout << "3. Display truth table" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Command: ";
}

void TextUI::processCommand(int command) {
    switch (command) {
        case 1:
            loadingFile();
            break;
        case 2:
            Simulation();
            break;
        case 3:
<<<<<<< HEAD
            truthTable();
=======
            TruthTable();
>>>>>>> master
            break;
        case 4:
            Exit();
            break;
        default:
            displayError("Invalid command!");
            break;
    }
}
