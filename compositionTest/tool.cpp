#include <iostream>
#include "point2d.h"
#include "creature.h"

std::ostream& operator<<(std::ostream& out, const Point2D& point){
    out << "(" << point.m_x << ", " << point.m_y << ")";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Creature& creature){
    out << creature.m_name << " is at " << creature.m_location;
    return out;
}
