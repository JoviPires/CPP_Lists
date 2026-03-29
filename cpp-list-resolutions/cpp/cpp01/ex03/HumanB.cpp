#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
{
    this->name = name;
    this->weapon = NULL;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack(void) const
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " is unarmed" << std::endl;
}