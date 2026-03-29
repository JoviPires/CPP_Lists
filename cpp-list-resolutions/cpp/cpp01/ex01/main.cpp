#include "Zombie.hpp"

int main()
{
    size_t N = 5;
    Zombie *horde = zombie_horde(N, "Zed");
    if (horde == NULL)
        return (1);
    for (size_t i = 0; i < N; i++)
        horde[i].announce();
    delete[] horde;
    return (0);
}