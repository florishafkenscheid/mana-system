#ifndef ABILITIES_H
#define ABILITIES_H
#include "mana.h"

void witherImpact(ManaValues& manaValues) {
    if (manaValues.currentMana < 120 && manaValues.currentMana > 0) {
        std::cout << "Not enough mana \r";
        return;
    }
    manaValues.currentMana -= 120;
    if (manaValues.currentMana <= 0) {
        manaValues.currentMana = 0;
        std::cout << "No mana \r";
        return;
    }
}
#endif