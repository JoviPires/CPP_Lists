#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
        Zombie();
        ~Zombie(void);
        void announce(void);
        void setName(std::string name);
    private:
        std::string name;
};

Zombie* zombie_horde(int N, std::string name);

#endif