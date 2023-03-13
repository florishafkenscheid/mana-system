#ifndef MAIN_CPP
#define MAIN_CPP
#include "abilities.h"
#include "Player.h"
#include "armor.h"
#include "statdisplay.h"
#include "regen.h"
#include <thread>

int reduceHealth(int& currentHealth, int& maxHealth) {
    currentHealth -= 100;
    return currentHealth;
}

double reduceMana(double& currentMana, double& maxMana) {
    currentMana -= 200;
    return currentMana;
}


int main()
{
    printf("\033[2J");
    blousy->ApplyArmorStats();
    ManaValues manaValues = Mana(*blousy);
    HealthValues healthValues = Health(*blousy);
    DefenseValues defenseValues = Defense(*blousy);
    // for (int i = 0; i < 10; i++)
    // {
    //     witherImpact(manaValues);
    // }
    reduceHealth(healthValues.currentHealth, healthValues.maxHealth);
    reduceMana(manaValues.currentMana, manaValues.maxMana);
    displayBars(healthValues.currentHealth, healthValues.maxHealth, manaValues.currentMana, manaValues.maxMana);
    
    std::cout << "\033[21;0f Press ENTER to continue...";
    std::cin.get();
    return 0;
}
#endif