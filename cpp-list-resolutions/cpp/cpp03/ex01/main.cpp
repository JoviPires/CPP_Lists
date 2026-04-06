#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavvy");

    clap.attack("a target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    scav.attack("a target");
    scav.takeDamage(10);
    scav.beRepaired(5);
    scav.guardGate();

    return 0;
}
