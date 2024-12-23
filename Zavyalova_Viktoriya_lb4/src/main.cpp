#include <iostream>
#include <vector>

#include "game.h"
#include "reader.h"
#include "printer.h"
#include "gamemanager.h"
#include "printerTerminal.h"



int main() {
//        GameField gameField(10, 10);
//     //GameField enemyField(10, 10);
//     //Game enemy;
//     //enemy.initializeEnemyField(enemyField);
    
//     std::vector<int> shipLengths = { 4, 3, 1, 2, 2 };   // Создание менеджера кораблей
//    //ShipManager shipManager(shipLengths);

//    std::vector<Ship> ships;                 
//    for (int length : shipLengths) {
//        ships.emplace_back(length, true); // Передайте true или false в зависимости от ориентации
//    }
   

//    ShipManager shipManager(ships);
//    //gameField.PlaceShip(shipManager.GetShip(0), 1, 1, true);
//    //gameField.PlaceShip(shipManager.GetShip(2), 8, 8, false);
//    //gameField.PlaceShip(shipManager.GetShip(2), 3, 4, false);
//    //gameField.PlaceShip(shipManager.GetShip(3), 8, 5, false);
//    //gameField.PlaceShip(shipManager.GetShip(2), 9, 9, false);
//    gameField.PlaceShip(shipManager.GetShip(3), 7, 9, false);
   


//    Abilitymanager man;
//    man.applyFirstAbility(gameField, shipManager, 7, 8);
        




//     // // Установка кораблей на поле
//     // gameField.PlaceShip(shipManager.GetShips()[0], 1, 1, true); // Горизонтально
// 	// shipManager.RefreshCoordinates(0, 1, 1);
//     // gameField.PlaceShip(shipManager.GetShips()[2], 3, 0, false); // Вертикально
// 	// shipManager.RefreshCoordinates(2, 3, 0);

//     // gameField.PlaceShip(shipManager.GetShips()[3], 7, 5, false); // Вертикально
// 	// shipManager.RefreshCoordinates(3, 7, 5);

// 	gameField.SetShipManager(shipManager);
    // Scanner scan;
    // scan.applyAbility(gameField, shipManager, 0, 0);
    
    
//     gameField.AttackCell(1, 1, 0);
//     Ship* ship = &shipManager.GetShip(0);
//     DoubleDamage pupupu;
//     //pupupu.applyAbility(gameField, shipManager, 1, 1);
//     //pupupu.applyAbility(gameField, shipManager, 1, 1);
//     gameField.AttackCell(1, 1, 0);
//     gameField.AttackCell(1, 2, 1);
//     gameField.AttackCell(1, 3, 1);
//     gameField.AttackCell(1, 4, 1);


//     if (shipManager.GetShip(0).IsDestroyed()){
//         printf("ff\n");
//         man.addAbility();
//     }
     
    
//     for (int i = 0; i < ship->GetLength(); i++) {
//         std::vector segs = ship->GetSegments();
//         if (segs[i].GetState() == SegmentState::Intact)
//             std::cout << "X";
//         else if (segs[i].GetState() == SegmentState::Destroyed){
//             std::cout << "D";
//         }
//         else
//             std::cout << "x";
//     }
//     std::cout << std::endl;

//     // Атака на клетки

//     //    gameField.AttackCell(3, 0, shipManager);
//     //    gameField.AttackCell(3, 0, shipManager);
//     // // gameField.AttackCell(3, 1, shipManager);
//     //     gameField.AttackCell(7, 5, shipManager);
//     //     gameField.AttackCell(7, 5, shipManager);
//     //     gameField.AttackCell(8, 5, shipManager);

//     // Проверка состояния кораблей
//     // if (shipManager.IsAllShipsDestroyed()) {
//     //     std::cout << "Все корабли уничтожены!" << std::endl;
//     // }
	
// 	// std::cout << "Список корабликов: " << std::endl;

// 	// for (auto& ship : ships) {
//     // 	for (int i = 0; i < ship.GetLength(); i++) {
// 	// 		std::vector segs = ship.GetSegments();
// 	// 		if (segs[i].GetState() == SegmentState::Intact)
// 	// 			std::cout << "X";
//     //         else if (segs[i].GetState() == SegmentState::Destroyed){
//     //             std::cout << "D";
//     //         }
// 	// 		else
//     //     		std::cout << "x";
// 	// 	}
//     // 	std::cout << std::endl;
// 	// }

// 	gameField.printField();
//     std::cout<<"\n\n";
    //enemyField.printField();
    //printf("fff");
    Game game;
    Reader com;
    PrinterTerminal print;
    //printf("fine");
    Printer<PrinterTerminal> printer(print);
    GameManager<Reader, PrinterTerminal> manager(game, printer, com);
    manager.run();
    //printf("fine");
    //game.startGame();
    //Abilitymanager man;
    //man.applyFirstAbility(game.initializeField(), game. );
    


    //GameController controller(game);





    // while (true) {
    //     std::string command;
    //     std::cout << "Введите команду (save, load, start, play, exit): ";
    //     std::cin >> command;
    //     if (command == "exit") {
    //         break;
    //     }
    //     controller.handle_input(command);
    // }


    return 0;
}

