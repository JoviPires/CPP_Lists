#include "DiamondTrap.hpp"

int main() {
    DiamondTrap dt("Diamondy");

    dt.attack("Target1");
    dt.takeDamage(20);
    dt.beRepaired(20);
    dt.guardGate();
    dt.highFivesGuys();
    dt.whoAmI();

    return 0;
}