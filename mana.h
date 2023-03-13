#ifndef MANA_H
#define MANA_H
#include <iostream>
#include <unistd.h>
#include <cmath>
#include <curses.h>
#include "armor.h"
#include "Player.h"
#include "statdisplay.h"
#include "health.h"

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

#endif