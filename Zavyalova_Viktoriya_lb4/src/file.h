#ifndef FILE_H
#define FILE_H

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include "customexept.h"

class File{
private:

    std::fstream stream;
    std::string filename;

    File(const File&); 
    File& operator = (const File&); 

public:
    File(const char* filename);
    ~File();
    void write(std::string str);
    std::stringstream read();

};

#endif