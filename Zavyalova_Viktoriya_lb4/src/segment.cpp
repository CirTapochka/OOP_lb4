#include <iostream>
#include "customexept.h"
#include "segment.h"


ShipSegment::ShipSegment() : state(SegmentState::Intact) {}
ShipSegment::ShipSegment(int state) : state(static_cast<SegmentState> (state) ) {}

SegmentState ShipSegment::GetState() { return state; }

void ShipSegment::ApplyDamage() {
    if (state == SegmentState::Intact) {
        state = SegmentState::Damaged;
    } else if (state == SegmentState::Damaged) {
        state = SegmentState::Destroyed;
    }
    else{
        throw ShipSegmentException("Already destroyed.");
    }
}

void ShipSegment::applyDoubleDamage() {
    if (state != SegmentState::Destroyed) {
        state = SegmentState::Destroyed;
    }else{
        throw ShipSegmentException("Already destroyed.");
    }
}