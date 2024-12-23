#include "printerTerminal.h"

void PrinterTerminal::printField(Game game){
    game.gameField.printField(0);
    game.enemyField.printField(1);
}

void PrinterTerminal::printMessage(std::string str){
    std::cout<< str << std::endl;
}