#ifndef BARRAGE_H
#define BARRAGE_H

#include "vability.h"

class Barrage : public Ability {
private:
    skillId id = skillId::barrage;
public:
    bool applyAbility(GameField& field, ShipManager& shipManager, int x, int y) override;
    std::string toString() override;
    skillId getId() override;
};

#endif 