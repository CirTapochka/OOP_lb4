#include "gamemanager.h"
#include "printerTerminal.h"


template<class T, class P>
GameManager<T, P>::GameManager(Game& g, Printer<P> p, T reader): game{g}, printer{p}, reader{reader} {}


template<class T, class P>
void GameManager<T, P>::initializeField(){
    game.gameField.printField(0);
    std::vector<int> shipLengths;
    for (int i = 4; i >= 1; i--) {
        for (int j = 0; j < 5 - i; j++) {
            shipLengths.push_back(i);
        }
    }

    std::vector<Ship> ships;                 
    for (int length : shipLengths) {
        ships.emplace_back(length, true); // Передайте true или false в зависимости от ориентации
    }
   
    game.userManager = ShipManager(ships);
    game.gameField.SetShipManager(game.userManager);
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= i; j++) {
            bool vert;
            std::stringstream str;
            str << "Введите координаты для " << 4 - i << "-палубного корабля. Кол-во оставшихся кораблей:" << i - j + 1 << std::endl;
            printer.printMessage(str.str());
            std::vector<int> coord = reader.getCoord();
            printer.printMessage("Введите ориентацию корабля: 0 - горизонтально, 1 - вертикально");
            bool flag = true;
            while (flag) { 
                try
                {
                   vert = reader.getOrientation();
                   flag = false;
                   //j--;

                }
                catch(const std::exception& e)
                {   
                    reader.printExcept();
                    printer.printMessage("Введите 0 или 1");
                }
                
            }

            try{
                //Ship* ship = &userManager.GetShip(k);
                game.gameField.PlaceShip(game.userManager.GetShip(k), coord[0], coord[1], vert, k);
                game.gameField.printField(0);
                k++;
            } catch(GameFieldException& e){
                printer.printMessage(e.what());
                j--;
            } 
            
        }
    }

}


template<class T, class P>
void GameManager<T, P>::run(){
    bool def = true;
    if (game.checkSave()) {
        printer.printMessage("The save is available and will be load");
     bool ag = false;
        bool ans;
        while (!ag) {
            try {
                ans = reader.userAgree();
                ag = true;
            } catch (const std::exception& e) {
                printer.printMessage(e.what());
            }
        }
        if (ans) {
            try {
                game.state.load();
                def = true;
                printer.printMessage("Game state succesfully restored.");
            } catch (const std::exception& e) {
                printer.printMessage(e.what());
            }
        }
    }

    if (def) {
        initializeField();
        game.initializeEnemyField();
    }

    bool gameProc = true;
    while (gameProc) {
        printer.printField(game);

        commands command;
        bool val = false;
        while (!val) {
            try {
                command = reader.getCommand();
                val = true;
            } catch (const std::exception& e) {
                printer.printMessage(e.what());
            }
        }
        bool flag = true;
        bool validInp = false;
        switch (command) {
            case commands::atack:                       
                while (!validInp) {
                    try {
                        std::vector<int> coords = reader.getCoord();
                        game.playerAttack(coords);
                        validInp = true;
                    } catch (const std::exception& e) {
                        printer.printMessage(e.what());
                        continue;
                    }
                }
                break;  
            case commands::ability:
                
                while(flag){    
                    try{
                        if(game.userAbilityManager.returnIdSkills()==skillId::scanner){
                            std::vector<int> mas = reader.getCoord();
                            game.userAbilityManager.applyFirstAbility(game.enemyField, game.enemyManager, mas[0], mas[1]);
                        } else if(game.userAbilityManager.returnIdSkills()==skillId::doubleDamage){
                            game.attackflag = true;
                            //playerAttack();
                        }
                        else{
                            game.userAbilityManager.applyFirstAbility(game.enemyField, game.enemyManager, 0, 0);
                        }
                        flag = false;
                    }catch(const std::runtime_error& exc){
                        std::cout<< exc.what();
                        continue;                                                           
                    }
                }
                break;
            case commands::save:
                try {
                    game.state.save();
                    printer.printMessage("Saved!");
                    validInp = true;
                } catch (const std::exception& e) {
                    printer.printMessage(e.what());
                    continue;
                }
                continue;
            case commands::quit:
                printer.printMessage("You changes will not be saved. Do you want to save it?");
                if (reader.userAgree()) {
                    try {
                        game.state.save();
                        printer.printMessage("Succesfully saved!");
                        validInp = true;
                    } catch (const std::exception& e) {
                        printer.printMessage(e.what());
                        continue;
                    }
                }
                gameProc = false;
                break;
        }

        if (!gameProc)
            break;

        game.enemyAttack();
        printer.printField(game);

        if (game.enemyManager.IsAllShipsDestroyed()) {
            printer.printMessage("WiN");
            printer.printMessage("Starting new game...");
        }

        if (game.userManager.IsAllShipsDestroyed()) {
            printer.printMessage("YoU aRe LoSe :(");
            printer.printMessage("New game");
            initializeField();
        }
    }


}

template class GameManager<Reader, PrinterTerminal>;