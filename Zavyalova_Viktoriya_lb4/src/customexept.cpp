#include "customexept.h"

GameFieldException::GameFieldException(const char* message) : runtime_error(message) {}

ShipManagerException::ShipManagerException(const char* message) : runtime_error(message) {}

AbilityManagerException::AbilityManagerException(const char* message) : runtime_error(message) {}

ShipSegmentException::ShipSegmentException(const char* message) : runtime_error(message) {}

ShipException::ShipException(const char* message) : runtime_error(message) {}

ScannerException::ScannerException(const char* message) : runtime_error(message) {}