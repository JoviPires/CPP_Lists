#include "Zombie.hpp"
#include <unistd.h>

int main(void)
{
    while (1)
    {
        Zombie* heap_zombie = newZombie("HeatZombie");
        usleep(1000000);
        heap_zombie->announce();
        delete heap_zombie;
        usleep(1000000);
        randomChump("StackZombie");
        usleep(1000000);
    }
    return (0);
}