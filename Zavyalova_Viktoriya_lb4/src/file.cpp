#include "file.h"

File::File(const char* filename) : filename(filename) {
        stream.open(filename, std::ios::in | std::ios::out | std::ios::app); // Открываем файл для чтения, записи и добавления
    }

    // Деструктор закрывает поток
File::~File() {
    if (stream.is_open()) {
        stream.close();
    }
}



void File::write(std::string str){
    stream << str ;
}

std::stringstream File::read(){
    std::stringstream res;
    res << stream.rdbuf();
    return res;
}