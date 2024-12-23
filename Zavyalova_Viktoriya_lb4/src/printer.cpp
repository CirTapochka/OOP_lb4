#include "printer.h"    
#include "printerTerminal.h"

template <class T>
Printer<T>::Printer(T tmp){ temp = tmp; }

template <class T>
void Printer<T>::printField(Game game){
    temp.printField(game);
    // game.gameField.printField(0);
    // game.enemyField.printField(1);
}


template <class T>
void Printer<T>::printMessage(std::string str){
    temp.printMessage(str);
}

template class Printer<PrinterTerminal>;