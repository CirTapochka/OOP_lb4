#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "ship.h"

class ShipManager {
public:

    ShipManager(std::vector<Ship>& shipArray);
    ~ShipManager();

    ShipManager(){}

    Ship& GetShip(int index);

    int GetShipCount();

    bool IsAllShipsDestroyed();
    int shipsAlive();
    std::string saveShipsSegAndOri();

private:
    std::vector <Ship> ships;
};

#endif
