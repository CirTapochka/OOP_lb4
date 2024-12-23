#include "gamestate.h"

//Оператор ввода
std::istream& operator>>(std::istream& is, ShipManager& manager) {
    std::string str;
    getline(is, str);
    std::vector<Ship> ships;
    while (!str.empty()) {
        std::string ship_tmp = str.substr(0, str.find(' '));
        Ship tmp = Ship(ship_tmp.size()-1, (int)ship_tmp[0]-48);
        std::vector<ShipSegment> seg;
        for (int i = 1; i < ship_tmp.size(); i++) {
            seg.emplace_back((int)ship_tmp[i]-48);
        }
        tmp.setShipSegments(seg);
        ships.push_back(tmp);
        
        str = str.substr(str.find(' ')+1);
        if (str.find(' ') == std::string::npos)
            break;
    }
    manager = ShipManager(ships);
    return is;
}

std::istream& operator>>(std::istream& is, Abilitymanager& manager) {
    std::string str;
    getline(is, str);
    if (str == "-1")
        return is;
    std::istringstream iss(str);

    std::vector<int> ids;
    int id;
    
    while (iss >> id) {
        ids.push_back(id);
    }
    manager = Abilitymanager(ids);
    return is;
}

std::istream& operator>>(std::istream& is, GameField& field) {
    std::string str;
    getline(is, str);
    std::map<std::pair<int, int>, int> mapa;
    while (!str.empty()) {
        std::string tmp = str.substr(0, str.find(' '));
        mapa.emplace(std::make_pair((int)tmp[0]-48, (int)tmp[1]-48), (int)tmp[2]-48);
        if (str.find(' ') == std::string::npos)
            break;
        str = str.substr(str.find(' ')+1);
    }
    field.updateCoordsAndPos(mapa);

    std::vector<std::vector<CellStatus>> blocks;
    bool mine;
    is >> mine;
    is.ignore();
    int x = 0;
    while(getline(is, str) && str.size()) {
        std::istringstream iss(str);
        blocks.resize(x+1);
        int block;
        while (iss >> block) {
            blocks[x].emplace_back(static_cast<CellStatus>(block));
        }
        x++;
    }
    field.updateField(blocks);
    return is;
}

std::istream& operator>>(std::istream& is, GameState& gameState) {
    //is.ignore();
    is >> gameState.userAbilityManager;
    is >> gameState.userManager;
    is >> gameState.userField;
   
    is >> gameState.enemyManager;
    is >> gameState.enemyField;
    return is;
}

//Оператор вывода
std::ostream& operator<<(std::ostream& os, GameState& gameState) {
    os << gameState.userAbilityManager.saveAbility() << std::endl;
    os << gameState.userManager.saveShipsSegAndOri() << std::endl;
    os << gameState.userField.saveShipPos() << std::endl;
    os << gameState.userField.saveField();
    
    os << std::endl;
    
    os << gameState.enemyManager.saveShipsSegAndOri() << std::endl;
    os << gameState.enemyField.saveShipPos() << std::endl;
    os << gameState.enemyField.saveField();
    
    return os;
}



//Сохранение состояния игры
void GameState::save() {
    File file("save.txt");
    std::stringstream st;
    st << *this;
    file.write(st.str());
}

//Загрузка состояния игры
void GameState::load() {
    File file("save.txt");
    std::stringstream str = file.read();
    str >> *this;
}

// std::istream& operator<<(std::istream& is, ShipManager& manager) {

// }