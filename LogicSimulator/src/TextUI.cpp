#include "TextUI.h"
#include <iostream>

TextUI::TextUI(LogicSimulator* sim) : simulator(sim) {}

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
    result = simulator->formatHeader() + result;
    displaySimulationResult(result);
}

void TextUI::truthTable() {
    displayTruthTable(simulator->getTruthTable());
}

void TextUI::Exit() {
    std::cout << "Goodbye, thanks for using LS." << std::endl;
}

void TextUI::displayError(const std::string& errorMsg) const {
    std::cout << errorMsg << std::endl << std::endl;
}

void TextUI::displaySimulationResult(const std::string& result) const {
    std::cout << "Simulation Result: " << std::endl << result << std::endl << std::endl;
}

void TextUI::displayTruthTable(const std::string& truthTable) const {
    std::cout << "Truth table: " << std::endl << truthTable << std::endl;
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
