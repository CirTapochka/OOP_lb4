#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map> 

#include "manager.h"

enum class CellStatus { 
    Unknown, 
    Empty, 
    Ship,
    Destroyed  
};

class GameField {
public:

    GameField(int width, int height, ShipManager& manager);

    GameField(GameField& other);    // Конструктор копирования
    GameField(GameField&& other);    // Конструктор перемещения

    GameField& operator = (GameField& other);    // Оператор присваивания копированием
    GameField& operator = (GameField&& other);    // Оператор присваивания перемещением

    void PlaceShip(Ship& ship, int x, int y, bool isVertical, int ind);

    bool AttackCell(int x, int y, bool active);

    CellStatus GetCellStatus(int x, int y);

    int GetWidth();
    int GetHeight();

    void SetShipManager(ShipManager& manager);     // Получение доступа к управлению кораблями
    void printField(bool flag);
    std::string saveShipPos();
    std::string saveField();
    void updateField(std::vector<std::vector<CellStatus>> field); 
    void updateCoordsAndPos(std::map<std::pair<int, int>, int> mapa);


private:
    int width;
    int height;
    std::vector<std::vector<CellStatus>> field;
    std::map<std::pair<int, int>, int> shipPositions; 
    ShipManager& shipManager;
};

#endif
