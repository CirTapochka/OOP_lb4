#ifndef SEGMENT_H
#define SEGMENT_H

enum class SegmentState { 
    Intact, 
    Damaged, 
    Destroyed, 
    HideDamage
};


class ShipSegment {
public:
    ShipSegment();
    ShipSegment(int state);
    SegmentState GetState();

    void ApplyDamage();
    void applyDoubleDamage();

private:
    SegmentState state;
};

#endif 

