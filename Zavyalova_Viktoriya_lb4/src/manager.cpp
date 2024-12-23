#include <iostream>
#include <vector>

#include "ship.h"
#include "manager.h"
#include "customexept.h"



ShipManager::~ShipManager() {
        // for (auto& ship : ships) {
        //     delete ship;
        // }
    }

ShipManager::ShipManager(std::vector<Ship>& shipArray) {
        for (auto& ship : shipArray) {
            //Ship* ship_p = new Ship(ship.GetLength(), ship.IsVertical());
            ships.push_back(ship); 

        }
    }


Ship& ShipManager::GetShip(int index) {
    if (index < 0 || index >= ships.size()) {
        throw ShipManagerException("Index out of range");
    }
    return ships[index];
}

bool ShipManager::IsAllShipsDestroyed(){
    for (auto& ship : ships) {
        if (!ship.IsDestroyed()) {
            return false;
        }
    }
    return true;
}

int ShipManager::GetShipCount() {  
        return ships.size();  
    }  

int ShipManager::shipsAlive(){
    int i = 0;
    for (auto& ship : ships) {
        if (!ship.IsDestroyed()) {
            i++;
        }
    }
    return i;

}

std::string ShipManager::saveShipsSegAndOri(){
    std::stringstream res;
    for(auto ship : ships){
        res << ship.IsVertical();
        for(auto shp : ship.GetSegments()){
            res << static_cast<int>(shp.GetState());
        }
        res << ' ';
    }
    return res.str();
}

