#include <iostream>
#include <vector>
#include <map>

#include "gameboard.h"
#include "customexept.h"


GameField::GameField(int width, int height, ShipManager& manager) : width(width), height(height), shipManager(manager) {
    field.resize(height, std::vector<CellStatus>(width, CellStatus::Unknown));
}

// Конструктор копирования
GameField::GameField(GameField& other) : width(other.width), height(other.height), shipManager(other.shipManager) {
    field.resize(height, std::vector<CellStatus>(width, CellStatus::Unknown));
    std::copy(other.field.begin(), other.field.end(), field.begin());
}

// Конструктор перемещения
GameField::GameField(GameField&& other) /*noexcept*/ : width(other.width), height(other.height), field(std::move(other.field)), shipManager(other.shipManager) {
    other.width = 0;
    other.height = 0;
}

// Оператор присваивания копированием
GameField& GameField::operator = (GameField& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
        field.resize(height, std::vector<CellStatus>(width, CellStatus::Unknown));
        std::copy(other.field.begin(), other.field.end(), field.begin());
    }
    return *this;
}

// Оператор присваивания перемещением
GameField& GameField::operator=(GameField&& other) /*noexcept*/ {
    if (this != &other) {
        width = other.width;
        height = other.height;
        field = std::move(other.field);
        other.width = 0;
        other.height = 0;
    }
    return *this;
}

void GameField::PlaceShip(Ship& ship, int x, int y, bool isVertical, int ind) {
    // Проверка выхода за пределы игрового поля
    if (x < 0 || x + (isVertical ? 0 : ship.GetLength()) > width ||
        y < 0 || y + (isVertical ? ship.GetLength() : 0) > height) {
        throw GameFieldException("Ship placement out of bounds.");
    }

    // Проверка на пересечение с другими кораблями
    for (int i = 0; i < ship.GetLength(); i++) {
        int cellX = x + (isVertical ? 0 : i);
        int cellY = y + (isVertical ? i : 0);
        if (GetCellStatus(cellX, cellY) != CellStatus::Unknown) {
            throw GameFieldException("Ship collision.");
        }
    }

        // Corrected neighbor check:
    for (int i = 0; i < ship.GetLength(); ++i) {
        int cellX = x + (isVertical ? 0 : i);
        int cellY = y + (isVertical ? i : 0);

        // Check all adjacent cells (including diagonals)
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue; // Skip the cell itself

                int neighborX = cellX + dx;
                int neighborY = cellY + dy;

                // Check bounds and if neighbor cell contains a ship
                if (neighborX >= 0 && neighborX < width && neighborY >= 0 && neighborY < height &&
                    GetCellStatus(neighborX, neighborY) == CellStatus::Ship) {
                    throw GameFieldException("Cannot place ship; neighboring cells contain ships.");
                }
            }
        }
    }

    // Помещение корабля на поле
    for (int i = 0; i < ship.GetLength(); i++) {
        int cellX = x + (isVertical ? 0 : i);
        int cellY = y + (isVertical ? i : 0);
        field[cellY][cellX] = CellStatus::Ship;
        shipPositions.emplace(std::make_pair(cellX, cellY), ind);
    }
}

bool GameField::AttackCell(int x, int y, bool active) {   
    // Проверяем, находятся ли координаты в пределах игрового поля
    if (x < 0 || x >= width || y < 0 || y >= height) {   
        throw GameFieldException("Invalid cell coordinates.");   
    }   
   
    CellStatus currentStatus = GetCellStatus(x, y); 
    
    if (currentStatus == CellStatus::Unknown) {   
        field[y][x] = CellStatus::Empty; 
    } 
    else if (currentStatus == CellStatus::Ship) {   
        //field[y][x] = CellStatus::Ship;
        std::pair<int, int> coords(x, y);
        auto g = shipPositions.find(coords);
        if(g != shipPositions.end()){
            Ship& attacktedShip = shipManager.GetShip(g->second);
            int segmentIndex = -1;
            while(field[y][x] == CellStatus::Ship){
                if(attacktedShip.IsVertical()){
                    y--;
                }
                else{ x--; }

                segmentIndex++;
                if(y<0 || x<0){ break; }
            }
            if(!active){attacktedShip.ApplyDamage(segmentIndex);} 
            else{
                attacktedShip.applyDoubleDamage(segmentIndex);
            }
            if(attacktedShip.IsDestroyed()){
                return true;
            }
            
        }

    }   

    return false;

}

CellStatus GameField::GetCellStatus(int x, int y){
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw GameFieldException("Invalid cell coordinates.");
    }
    return field[y][x];
}

int GameField::GetWidth() { return width; }
int GameField::GetHeight() { return height; }


void GameField::SetShipManager(ShipManager& manager) { // Получение доступа к управлению кораблями
    shipManager = manager;
}

void GameField::printField(bool flag) { 
    if(flag){
        std::cout << "  "; 
        for (int i = 0; i < width; i++) { 
            std::cout << i << " "; 
        } 
        std::cout << std::endl; 

        for (int i = 0; i < height; i++) { 
            std::cout << i << " "; 
            for (int j = 0; j < width; j++) { 
                switch (field[i][j]) { 
                    case CellStatus::Unknown: 
                        std::cout << "~ "; 
                        break; 
                    case CellStatus::Ship: 
                        std::cout << "~ "; 
                        break; 
                    case CellStatus::Empty: 
                        std::cout << "O "; 
                        break; 
                    case CellStatus::Destroyed: 
                        std::cout << "D "; 
                        break; 
                } 
            } 
            std::cout << std::endl; 
        
        } 

    }


    else{
        std::cout << "  "; 
    for (int i = 0; i < width; i++) { 
        std::cout << i << " "; 
    } 
    std::cout << std::endl; 

    for (int i = 0; i < height; i++) { 
        std::cout << i << " "; 
        for (int j = 0; j < width; j++) { 
            switch (field[i][j]) { 
                case CellStatus::Unknown: 
                    std::cout << "~ "; 
                    break; 
                case CellStatus::Ship: 
                    std::cout << "X "; 
                    break; 
                case CellStatus::Empty: 
                    std::cout << "O "; 
                    break; 
                case CellStatus::Destroyed: 
                    std::cout << "D "; 
                    break; 
            } 
        } 
        std::cout << std::endl; 
        
        } 
    }

} 

std::string GameField::saveShipPos(){
    std::stringstream res;
    for(auto it : shipPositions){
        res << it.first.first;
        res << it.first.second;
        res<< it.second;
        res << ' ';
    }
    return res.str();

}

std::string GameField::saveField(){
    std::stringstream res;

    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            res << static_cast<int>(field[i][j]) << ' ';
            res<< ' ';
        }
        res << std::endl;
    }
    return res.str();
}

void GameField::updateField(std::vector<std::vector<CellStatus>> f){
    field = f;
}

void GameField::updateCoordsAndPos(std::map<std::pair<int, int>, int> mapa){
    shipPositions = mapa;

}