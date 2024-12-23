#include <ctime>
#include "barrage.h"

bool Barrage::applyAbility(GameField& field, ShipManager& shipManager, int x, int y){
    bool staS = true; 
    srand(time(0));
    while(staS){

        int ind = std::rand()%10;
        Ship ship = shipManager.GetShip(ind); 
        int segmentind = std::rand()%ship.GetLength();

        try{
            ship.ApplyDamage(segmentind);
            staS = false;
        } catch(...){ }
    }
    
    return true;

}

skillId Barrage::getId(){
    return id;
}

std::string Barrage::toString() {
    return "Barrage";
}