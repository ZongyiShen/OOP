#include "TextUI.h"
#include "LogicSimulator.h"
#include <iostream>

int main() {
    LogicSimulator simulator;
    TextUI ui(&simulator);
    int command = 0;

    while (command != 4) {
        ui.displayMenu();
        std::cin >> command;
        ui.processCommand(command);
    }
    return 0;
}
