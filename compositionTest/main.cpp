#include "tool.h"
#include "creature.h"
int main()
{
    std::cout << "Enter a name for your creature: ";
    std::string name;
    std::cin >> name;
    Creature creature(name, Point2D(4, 7));
    Creature creature2(creature); // will call the default copy constructor if not implemented specifically
    creature2.moveTo(0,0);
    std::cout << "creature2:" << creature2 << std::endl;

    while (1)
    {
        // print the creature's name and location
        std::cout << creature << '\n';

        std::cout << "Enter new X location for creature (-1 to quit): ";
        int x=0;
        std::cin >> x;
        if (x == -1)
            break;

        std::cout << "Enter new Y location for creature (-1 to quit): ";
        int y=0;
        std::cin >> y;
        if (y == -1)
            break;

        creature.moveTo(x, y);
        }

    return 0;
}
