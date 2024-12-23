#ifndef VABILITY_H
#define VABILITY_H

#include "manager.h"
#include "gameboard.h"


enum skillId{
    scanner, 
    doubleDamage,
    barrage
};

class Ability {
    
public:
    virtual bool applyAbility(GameField& field, ShipManager& shipManager, int x, int y) = 0;
    virtual std::string toString() = 0;
    virtual skillId getId() = 0;
};


#endif

