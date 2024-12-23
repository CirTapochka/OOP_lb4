#ifndef CUSTOMEXCEPT_H
#define CUSTOMEXCEPT_H

#include <stdexcept>

class GameFieldException : public std::runtime_error {
public:
    GameFieldException(const char* message);
};

class ShipManagerException : public std::runtime_error {
public:
    ShipManagerException(const char* message);
};

class AbilityManagerException : public std::runtime_error {
public:
    AbilityManagerException(const char* message);
};

class ShipSegmentException : public std::runtime_error {
public:
    ShipSegmentException(const char* message);
};

class ShipException : public std::runtime_error {
public:
    ShipException(const char* message);
};

class ScannerException : public std::runtime_error {
public:
    ScannerException(const char* message);
};

#endif 