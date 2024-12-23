#include "scanner.h"
#include "customexept.h"

bool Scanner:: applyAbility(GameField& field, ShipManager& shipManager, int x, int y){

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++ ){
            CellStatus state;
            try{
                state = field.GetCellStatus(y+i, x+j);
            } catch (...){
                throw ScannerException("invalid coordinates.");
            }
            if (state == CellStatus::Ship){
                return true;
            }

        }

    }

    return false;

}

skillId Scanner::getId(){
    return id;
}

std::string Scanner::toString(){
    return "Scanner"; 
}