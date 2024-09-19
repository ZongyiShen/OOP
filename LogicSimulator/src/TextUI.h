#ifndef TEXT_UI_H
#define TEXT_UI_H

#include "LogicSimulator.h"
<<<<<<< HEAD
=======
#include <sstream>
>>>>>>> master
#include <string>

class TextUI {
private:
    LogicSimulator* simulator;

    void loadingFile();
    void Simulation();
<<<<<<< HEAD
    void truthTable();
    void Exit();

    void displayError(const std::string& errorMsg) const;
    void displaySimulationResult(const std::string& result) const;
    void displayTruthTable(const std::string& truthTable) const;
=======
    void TruthTable();
    void Exit();
    
    void displayError(const std::string& errorMsg) const;
    void displaySimulationResult(const std::string& result) const;
    void displayTruthTable(const std::string& truthTable) const;
    void formatHeader(int inputSize,int outputSize) const;
>>>>>>> master

public:
    TextUI(LogicSimulator* sim);

    void displayMenu() const;
    void processCommand(int command);
};

#endif // TEXT_UI_H
