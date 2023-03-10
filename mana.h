#ifndef MANA_H
#define MANA_H
#include <iostream>
#include <unistd.h>
#include <cmath>
#include <curses.h>
#include "armor.h"
#include "Player.h"

struct ManaValues {
    double maxMana;
    double currentMana;
};

ManaValues Mana(const Player& player) {
    int mpMana = 29.97 * std::pow((std::log(0.0019 * 1500 + 1)), 1.2);
    int armorMana = player.intelligence;
    double maxMana = armorMana + mpMana;
    double currentMana = maxMana;
    return { maxMana, currentMana };
};

void progressBar(double currentMana, double maxMana)
{
    int percentageMana = currentMana / maxMana * 100;

    int numFilledBlocks = percentageMana / 10;
    int numEmptyBlocks = 10 - numFilledBlocks;

    std::cout << "[";
    for (int i = 0; i < numFilledBlocks; i++) {
        std::cout << "#";
    }
    for (int i = 0; i < numEmptyBlocks; i++) {
        std::cout << "=";
    }
    std::cout << "]    " << currentMana << "/" << maxMana << "\r";
    std::cout.flush();
}

void manaRegen(double& currentMana, double maxMana) {
    if (currentMana != maxMana)
    {
        int manaRegen = maxMana * 0.02;
        usleep(1000000);
        printf("\033[2J");
        progressBar(currentMana, maxMana);
        while (currentMana < maxMana)
        {
            currentMana += manaRegen + 8;
            if (currentMana > maxMana)
            {
                currentMana = maxMana;
            }
            usleep(1000000);
            
            progressBar(currentMana, maxMana);
        }
    }
}

#endif