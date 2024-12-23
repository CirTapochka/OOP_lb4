#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <vector>
#include "segment.h"


class Ship {
public:

    Ship(int length, bool isVertical);
    int GetLength();
    bool IsVertical();
    bool IsDestroyed();
    void ApplyDamage(int segmentIndex);
    void applyDoubleDamage(int segmentIndex);
    std::vector<ShipSegment>& GetSegments();
    void setShipSegments(std::vector<ShipSegment> seg);

private:
    int length;
    bool isVertical;
    std::vector<ShipSegment> segments;
};


#endif
