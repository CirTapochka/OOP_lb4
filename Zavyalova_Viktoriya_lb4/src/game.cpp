#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map> 


#include "game.h"
#include "file.h"


void Game::initializeEnemyField() {
    srand(4);
    std::vector<int> shipLengths;
    for (int i = 4; i >= 1; i--) {
        for (int j = 0; j < 5 - i; j++) {
            shipLengths.push_back(i);
        }
    }

    std::vector<Ship> enemyShips;                 
    for (int length : shipLengths) {
        enemyShips.emplace_back(length, true); // Передайте true или false в зависимости от ориентации
    }
    
    bool flag = true;
    enemyManager  = ShipManager(enemyShips);
    enemyField.SetShipManager(enemyManager);
    int x, y;
    bool vert;
    for (int i = 0; i < 10; i++){
        //enemyField.printField(1);
        while(true){
            x = std::rand()%10;
            y = std::rand()%10;
            vert = std::rand()%2;
            //Ship* ship = &enemyManager.GetShip(i);
            //std::cout<< enemyShips[i].GetLength();
            //std::cout<< enemyManager.GetShip(i).GetLength();
            try{
                enemyField.PlaceShip(enemyManager.GetShip(i), x, y, vert, i);
                //flag = false;

            }catch (const std::runtime_error& exc) {
                continue;
            }
            break;
        }  


    }

    return; 
    
}

bool Game::checkSave() {
    try {
        File file("save.txt");
        return true;
    } catch (...) {
        return false;
    }
}


void Game::playerAttack(std::vector<int> mas) {
    int k = enemyManager.shipsAlive();
    enemyField.AttackCell(mas[0], mas[1], attackflag);
    attackflag = 0;
    if(k < enemyManager.shipsAlive()){
        userAbilityManager.addAbility();
    }
    
}

void Game::enemyAttack() {

    int x, y;
    x = std::rand()%10;
    y = std::rand()%10;
    gameField.AttackCell(x, y, 0);

}


// void Game::useAbility(){
//     bool flag = true;
//     while(flag){    
//         try{
//             if(userAbilityManager.returnIdSkills()==skillId::scanner){
//                 std::vector<int> mas = getCoord();
//                 userAbilityManager.applyFirstAbility(enemyField, enemyManager, mas[0], mas[1]);
//             } else if(userAbilityManager.returnIdSkills()==skillId::doubleDamage){
//                 attackflag = true;
//                 //playerAttack();
//             }
//             else{
//                 userAbilityManager.applyFirstAbility(enemyField, enemyManager, 0, 0);
//             }
//             flag = false;
//         }catch(const std::runtime_error& exc){
//             std::cout<< exc.what();
//             continue;                                                           
//         }
//     }
        
// }

void Game::startNewRound() {
    //state.newRound();
    std::cout << "Новый раунд начался." << std::endl;
}


// void Game::playerTurn(){  
//     std::cout<<"Вы хотите атаковать врага? Введите 'y' или 'n' "<<std::endl;
//     if(userAgree()){
//         playerAttack();
//         enemyField.printField(1);
//         std::cout<<"\n\n";
//     }else{useAbility();}
// }

// void Game::playGame() {
//     bool flag = true;
//     while (flag) {
//         playerTurn();
//         if (enemyManager.IsAllShipsDestroyed()) {
//             std::cout << "Раунд завершен. Начинается новый раунд." << std::endl;
//             std::cout << "Хотите загрузить игру? Y/n" << std::endl;
//             if(userAgree()){
//                 state.load();
//             }
//             //startNewRound();
//             enemyField = GameField(10,10, enemyManager);
//             initializeEnemyField();
//             startNewRound();
//             flag = false;
//         }
//         enemyAttack();
//         if (userManager.IsAllShipsDestroyed()) {
//             std::cout << "Игра окончена. Игрок проиграл." << std::endl;
//             enemyField = GameField(10,10, enemyManager);
//             gameField = GameField(10,10, userManager);
//             initializeEnemyField();
//             initializeField();
//             flag = false;
//         }
        
//     }

// }

// void Game::startGame(){
//     std::cout<<"Хотите закрузить игру? Y/n"<<std::endl;
//     if(userAgree()){
//         state.load();
//         playGame();
//     }
//     else{
//         initializeEnemyField();
//         gameField.printField(0);
//         initializeField();
//         gameField.printField(0);
//         state.save(); 
//         std::cout<<"\n\n";
//         enemyField.printField(1);
//         playGame();

//     }

// }




