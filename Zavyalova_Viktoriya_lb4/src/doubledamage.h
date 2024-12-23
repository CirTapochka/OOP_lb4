#ifndef DOUBLE_DAMAGE_H
#define DOUBLE_DAMAGE_H

#include "vability.h"

class DoubleDamage : public Ability {
public:
    //DoubleDamage();
    bool applyAbility(GameField& field, ShipManager& shipManager, int x, int y) override;
    std::string toString() override;
    bool isActive();
    skillId getId() override;

private:
    bool active;
    skillId id = skillId::doubleDamage;
};
#endif 
