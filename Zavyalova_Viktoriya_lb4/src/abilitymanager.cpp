#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "abilitymanager.h"
#include "barrage.h"
#include "doubledamage.h"
#include "scanner.h"
#include "customexept.h"


Abilitymanager::Abilitymanager():rng(std::random_device{}()){
    abilities.push_back(new Scanner());
    abilities.push_back(new DoubleDamage());
    abilities.push_back(new Barrage());
    std::shuffle(abilities.begin(), abilities.end(), rng);
}

void Abilitymanager::initializeAbilityPool(){ 
    abilityPool.push_back(new Scanner());
    abilityPool.push_back(new DoubleDamage());  
    abilityPool.push_back(new Barrage()); 
}

void Abilitymanager::addAbility() {
    initializeAbilityPool();
    if (!abilityPool.empty()) {
        int index = std::rand()%abilityPool.size();
        abilities.push_back(std::move(abilityPool[index])); 
        abilityPool.clear();
    } else {
        throw AbilityManagerException("The ability pool is empty.");
    }
}

bool Abilitymanager::applyFirstAbility(GameField& field, ShipManager& shipManager, int x, int y) {
    bool res = false;
    if (!abilities.empty()) {
        auto& ability = abilities.front(); // Получение первой способности
        if (ability){
            try {
                res = ability->applyAbility(field, shipManager, x, y);
            } catch (ShipManagerException& e) {
                    std::cerr << e.what() << std::endl;
            }
            abilities.erase(abilities.begin()); // Удаление способности из списка
        } else {
            throw AbilityManagerException("It is impossible to apply the ability.");
        }
    } else {
        throw AbilityManagerException("The player has no available abilities.");
    }

    return res;
}

skillId Abilitymanager::returnIdSkills(){
    return abilities.front()->getId();
}

std::string Abilitymanager::saveAbility(){
    std::stringstream res;

    if(abilities.empty()){
        return "-1";
    }
    for(auto ability : abilities){
        res<< ability->getId() <<" ";
    }
    return res.str();
}

Abilitymanager::Abilitymanager(std::vector<int> ids) {
    for (int id : ids) {
        initializeAbilityPool();
        abilities.push_back(std::move(abilityPool[id]));
        abilityPool.clear();
    }
}