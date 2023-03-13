#ifndef REGEN_H
#define REGEN_H
#include "health.h"
#include "mana.h"
#include "statdisplay.h"
#include <thread>
#define LOG(x) std::cout << x << std::endl


void hpRegen(int currentHealth, int maxHealth) {
    if (currentHealth < maxHealth)
    { 
        double hpRegen = maxHealth / 100.0 + 1.5;
        usleep(1000000);
        hpBar(currentHealth, maxHealth);
        while (currentHealth < maxHealth)
        {
            currentHealth += hpRegen;
            if (currentHealth > maxHealth)
            {
                currentHealth = maxHealth;
            }
            usleep(1000000);
            hpBar(currentHealth, maxHealth);
        }
    }
}

void manaRegen(double currentMana, double maxMana) {
    if (currentMana < maxMana)
    {
        int manaRegen = maxMana * 0.02;
        usleep(1000000);
        manaBar(currentMana, maxMana);
        while (currentMana < maxMana)
        {
            currentMana += manaRegen + 8;
            if (currentMana > maxMana)
            {
                currentMana = maxMana;
            }
            usleep(1000000);
            manaBar(currentMana, maxMana);
        }
    }
}

void displayBars(int currentHealth, int maxHealth, double currentMana, double maxMana) {
    printf("\033[2J");
    
    std::thread x (hpRegen, currentHealth, maxHealth);
    std::thread y (manaRegen, currentMana, maxMana);
    x.join();
    y.join();
    
    usleep(50000);
}

#endif