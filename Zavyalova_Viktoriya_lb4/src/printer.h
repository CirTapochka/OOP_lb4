#ifndef PRINTER_H
#define PRINTER_H

#include "game.h"

template <class T>
class Printer{
private:
    T temp;
public:
    Printer(T temp);
    void printField(Game game);
    void printMessage(std::string str);

};




#endif