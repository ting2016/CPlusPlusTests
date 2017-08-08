#ifndef TOOL_H
#define TOOL_H
#include <iostream>
class Point2D;
class Creature;

std::ostream& operator<<(std::ostream& out, const Point2D& point);
std::ostream& operator<<(std::ostream& out, const Creature& creature);
#endif // TOOL_H
