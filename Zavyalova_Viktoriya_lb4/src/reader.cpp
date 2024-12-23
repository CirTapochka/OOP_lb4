#include "reader.h"

Reader::Reader() {
    try {
        File file("commands.txt");
        std::stringstream str = file.read();
        size_t i = 0;
        char com;
        while (str >> com) {
            auto it = commandMap.find(com);
            if (it != commandMap.end())
        throw std::exception();
            commandMap[com] = static_cast<commands>(i);
            i++;
        }
        if (i < 4)
            throw std::exception();
    } catch (...) {
        std::cout<<"The default values will be used."<<std::endl;
        commandMap['e'] = commands::quit;
        commandMap['a'] = commands::atack;
        commandMap['q'] = commands::ability;
        commandMap['s'] = commands::save; 
    }

}

commands Reader::getCommand() {
    std::cout << "Input command: ";
    char comm;
    std::cin >> comm;
    comm = tolower(comm);

    auto it = commandMap.find(comm);
    if (it == commandMap.end())
        throw std::runtime_error("Not a command!");
    return it->second;
}


bool Reader::userAgree(){
    char ans = getchar();
    while ((tolower(ans) != 'n') && (tolower(ans) != 'y')) {
        //printError();
        ans = getchar();
    }
    return (ans == 'n') ? false : true; 
}


std::vector<int> Reader::getCoord(){
    std::vector<int> arr(2);
    bool flag = true;
    while (flag)
    {
       try{
            std::cout << "Введите координаты х и у" << std::endl;
            std::cin >> arr[0] >> arr[1];
            flag = false;
            return arr;
        }catch(const std::runtime_error& exc){
            std::cout<< exc.what();

        }
    }
    return arr;
}

// int Reader::getLength() {
//     std::cout << "Please, enter ship length: ";
//     int len;
//     if (!(std::cin >> len))
//         throw std::exception();
//     if (len < 1 || len > 4) {
//             throw ShipException("Invalid ship length.");
//         }
//     return len;
// }

bool Reader::getOrientation() {
    bool orientation;
    if (!(std::cin >> orientation))
        throw std::exception();
    return orientation;
}

void Reader:: printExcept(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

