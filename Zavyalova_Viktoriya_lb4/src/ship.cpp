#include <iostream>
#include <vector>

#include "segment.h"
#include "ship.h"
#include "customexept.h"


Ship::Ship(int length, bool isVertical) : length(length), isVertical(isVertical) {
        if (length < 1 || length > 4) {
            throw ShipException("Invalid ship length.");
        }

        segments.resize(length);
    }


int Ship::GetLength(){ return length; }

bool Ship::IsVertical(){ return isVertical; }

bool Ship::IsDestroyed(){
    for (auto& segment : segments) {
        if (segment.GetState() != SegmentState::Destroyed) {
            return false;
        }
    }
    return true;
}

void Ship::ApplyDamage(int segmentIndex) {
    if (segmentIndex < 0 || segmentIndex >= length) {
        throw ShipException("Invalid segment index.");
    }
    segments[segmentIndex].ApplyDamage();
}

void Ship::applyDoubleDamage(int segmentIndex) {
    if (segmentIndex < 0 || segmentIndex >= length) {
        throw ShipException("Invalid segment index.");
    }
    segments[segmentIndex].applyDoubleDamage();
}


std::vector<ShipSegment>& Ship::GetSegments() { return segments; }

void Ship::setShipSegments(std::vector<ShipSegment> seg){
    segments = seg;
}
