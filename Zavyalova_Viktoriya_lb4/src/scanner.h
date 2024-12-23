#ifndef SCANNER_H
#define SCANNER_H

#include "vability.h"

class Scanner : public Ability {
private:
    skillId id = skillId::scanner;
public:
    bool applyAbility(GameField& field, ShipManager& shipManager, int x, int y) override;
    std::string toString() override;
    skillId getId() override;

};

#endif