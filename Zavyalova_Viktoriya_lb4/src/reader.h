#ifndef READER_H
#define READER_H

#include "game.h"

#include <sstream>
#include <unordered_map>

#include "file.h"
#include "ship.h"
#include "game.h"

enum commands {atack, ability, save, quit};

class Reader{
private:
    std::unordered_map<char, commands> commandMap;
    
public:
    Reader();
    commands getCommand();
    void printExcept();
    //int getLength();
    bool getOrientation();
    bool userAgree();
    std::vector<int> getCoord();
};




#endif