#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <map> 

#include "manager.h"
#include "gameboard.h"
#include "segment.h"
#include "abilitymanager.h"
#include "ship.h"
#include "gamestate.h"
#include "customexept.h"



class Game{

public:
    //Game(int width, int height);
    //Game();
    void initializeEnemyField();
    void initializeField();

    //~Game();

    // void start_new_game();
    // void player_turn();

    // void enemy_turn();

    // void check_game_over();

    void startNewRound();

    void playGame();
    void startGame();
    void playerAttack(std::vector<int> mas);
    void useAbility();
    void enemyAttack();
    void playerTurn();
    GameField& gameField = state.userField;
    GameField& enemyField = state.enemyField;
    bool checkSave();
    GameState state = GameState();
    bool attackflag = false;
    ShipManager& userManager = state.userManager;
    ShipManager& enemyManager = state.enemyManager;
    Abilitymanager& userAbilityManager = state.userAbilityManager;

};






#endif