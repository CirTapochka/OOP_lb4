#include "doubledamage.h"

// DoubleDamage::DoubleDamage(){
//     active = false;
// }

bool DoubleDamage::applyAbility(GameField& field, ShipManager& shipManager, int x, int y){
    return true;
}

// bool DoubleDamage::isActive(){
//     return active;
// }

skillId DoubleDamage::getId(){
    return id;
}

std::string DoubleDamage::toString() {
    return "DoubleDamage"; 
}
// прописать в майне при атаке, предварительно проверить на активность

