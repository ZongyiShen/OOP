#ifndef TEXT_UI_H
#define TEXT_UI_H

#include "LogicSimulator.h"
#include <sstream>
#include <string>

class TextUI {
private:
    LogicSimulator* simulator;

    void loadingFile();
    void Simulation();
    void TruthTable();
    void Exit();
    
    void displayError(const std::string& errorMsg) const;
    void displaySimulationResult(const std::string& result) const;
    void displayTruthTable(const std::string& truthTable) const;
    void formatHeader(int inputSize,int outputSize) const;

public:
    TextUI(LogicSimulator* sim);

    void displayMenu() const;
    void processCommand(int command);
};

#endif // TEXT_UI_H
