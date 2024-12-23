#ifndef ABILITYMANAGER_H
#define ABILITYMANAGER_H

#include <vector>
#include <random>
#include <sstream>
#include <string>
#include "vability.h" 

class Abilitymanager
{
private:
    std::vector<Ability*> abilities; 
    std::vector<Ability*> abilityPool;
    void initializeAbilityPool();
    std::mt19937 rng;
    
public:
    Abilitymanager();
    Abilitymanager(std::vector<int> ids);
    bool applyFirstAbility(GameField& field, ShipManager& shipManager, int x, int y);
    void addAbility();  
    skillId returnIdSkills();
    std::string saveAbility();
};


#endif