#ifndef CREATURE_H
#define CREATURE_H
#include <string>
#include <iostream>
#include "point2d.h"
class Creature{
private:
    std::string m_name;
    Point2D m_location;
public:
    Creature(std::string name, const Point2D& point);
    void moveTo(int x, int y);
    friend std::ostream& operator<<(std::ostream& out, const Creature& creature);
};

#endif // CREATURE_H
