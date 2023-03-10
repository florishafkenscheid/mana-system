#ifndef MAIN_CPP
#define MAIN_CPP
#include "mana.h"
#include "abilities.h"
#include "Player.h"
#include "armor.h"
#define LOG(x) std::cout << x << std::endl


int main()
{
    initscr();
    printf("\033[2J");
    blousy->helmetIntelligence = witherGoggles.intelligence;
    blousy->chestplateIntelligence = stormChestplate.intelligence;
    blousy->leggingsIntelligence = stormLeggings.intelligence;
    blousy->bootsIntelligence = stormBoots.intelligence;
    blousy->ApplyArmorStats();
    ManaValues manaValues = Mana(*blousy);
    manaRegen(manaValues.currentMana, manaValues.maxMana);
    for (int i = 0; i < 10; i++)
    {
        move(0,0);
        witherImpact(manaValues);
    }
    while (manaValues.currentMana < manaValues.maxMana)
    {
        manaRegen(manaValues.currentMana, manaValues.maxMana);
    }
    endwin();
}
#endif