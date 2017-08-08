#include "creature.h"

Creature::Creature(std::string name, const Point2D &point){
    m_name = name;
    m_location = point; // will call the default copy constructor if not implemented specifically
}

void Creature::moveTo(int x, int y){
    m_location.setPoint(x, y);
}
