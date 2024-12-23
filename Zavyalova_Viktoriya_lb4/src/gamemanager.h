#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "printer.h"
#include "reader.h"
#include "game.h"


template <class T, class P>
class GameManager{
private:
    Game& game;
    Printer<P> printer;
    T reader;

    void initializeField();
public: 
    GameManager(Game& g, Printer<P> p, T reader);
    void run();
};

#endif