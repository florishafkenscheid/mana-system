#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;
    class Weapon {
        public:
            int Damage;
            int Strength;
            int critChance;
            int critDamage;
            int Intelligence;
            int Ferocity;
            int Rarity; // 1 = Common, 2 = Uncommon, 3 = Rare, 4 = Epic, 5 = Legendary, 6 = Mythic, 7 = Divine, 8 = Special, 9 = Very Special 
            bool Dungeon;
            Weapon(int a, int b, int c, int d, int e, int f, int g, bool h) {
                Damage = a;
                Strength = b;
                critChance = c;
                critDamage = d;
                Intelligence = e;
                Ferocity = f;
                Rarity = g;
                Dungeon = h;
            }
    };

    class Armor {
        public:
            int Strength;
            int critChance;
            int critDamage;
            int Health;
            int Defense;
            int Speed;
            int Intelligence;
            int healthRegen;
    };

    class Helmet: public Armor {
        public:
            double abilityDamage;
            Helmet(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
                Strength = a;
                critChance = b;
                critDamage = c;
                Health = d;
                Defense = e;
                Speed = f;
                Intelligence = g;
                healthRegen = h;
                abilityDamage = i;
            };
    };

    class Chestplate: public Armor {
        public:
            int trueDefense;
            Chestplate(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
                Strength = a;
                critChance = b;
                critDamage = c;
                Health = d;
                Defense = e;
                Speed = f;
                Intelligence = g;
                healthRegen = h;
                trueDefense = i;
            };
    };

    class Leggings: public Armor {
        public:
            Leggings(int a, int b, int c, int d, int e, int f, int g, int h) {
                Strength = a;
                critChance = b;
                critDamage = c;
                Health = d;
                Defense = e;
                Speed = f;
                Intelligence = g;
                healthRegen = h;
            };
    };
    class Boots: public Armor {
        public:
            Boots(int a, int b, int c, int d, int e, int f, int g, int h) {
                Strength = a;
                critChance = b;
                critDamage = c;
                Health = d;
                Defense = e;
                Speed = f;
                Intelligence = g;
                healthRegen = h;
            };
    };
    class Player {
        public:
            int magicalPower;
            string Helmet;
            string Chestplate;
            string Leggings;
            string Boots;
            string Weapon;
            Player(int a, string b, string c, string d, string e, string f) {
                magicalPower = a;
                Helmet = b;
                Chestplate = c;
                Leggings = d;
                Boots = e;
                Weapon = f;
            }

    };

Helmet shadowGoggles(0, 0, 0, 166, 55, 0, 480, 10, 49.5);

Chestplate stormChestplate(35, 15, 27, 443, 199, 0, 300, 10, 5);

Leggings stormLeggings(35, 15, 27, 410, 177, 0, 325, 10);

Boots stormBoots(35, 15, 27, 331, 138, 6, 300, 10);

Weapon Hyperion(287, 150, 0, 0, 404, 30, 5, true);

Player blousy(1347, "shadowGoggles", "stormChestplate", "stormLeggings", "stormBoots", "Hyperion");
int mpMana = 29.97 * pow((log(0.0019 * (blousy.magicalPower) + 1)), 1.2);
int armorMana = shadowGoggles.Intelligence + stormChestplate.Intelligence + stormLeggings.Intelligence + stormBoots.Intelligence;
int maxMana = armorMana + Hyperion.Intelligence + mpMana;
int currentMana = maxMana;

void witherImpact(){
    currentMana -= 120;
}

void manaRegen()
{
    if (currentMana == maxMana)
    {
        std::cout << "Max mana" << std::endl;
    }

    else if (currentMana != maxMana)
    {
        int manaRegen = maxMana / 100 * 10;
        Sleep(1500);
        while (currentMana < maxMana)
        {
            std::cout << currentMana << std::endl;
            currentMana += manaRegen;
            Sleep(1500);
        }
    }
}

int main() {
    std::cout << maxMana << endl;
    witherImpact();
    witherImpact();
    witherImpact();
    witherImpact();
    witherImpact();
    witherImpact();
    while (currentMana < maxMana)
    {
        manaRegen();
        if (currentMana > maxMana)
        {
            currentMana = maxMana;
        }
    }
}