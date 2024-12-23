#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "gameboard.h"
#include "abilitymanager.h"
#include "customexept.h"
#include "manager.h"
#include "file.h"


class GameState {
private:
    ShipManager& returnUserManager() {
        return userManager;
    }
    ShipManager& returnEnemyManager() {
        return enemyManager;
    }
public:
    Abilitymanager userAbilityManager = Abilitymanager();
    ShipManager userManager;
    ShipManager enemyManager;
    GameField userField = GameField(10, 10, userManager);
    GameField enemyField = GameField(10, 10, enemyManager);

    friend std::istream& operator>>(std::istream& is, GameState& gameState);
    friend std::ostream& operator<<(std::ostream& os, GameState& gameState);

    void save();
    void load();
};

    

#endif