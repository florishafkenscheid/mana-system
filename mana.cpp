#include <iostream>
#include <unistd.h>
#include <cmath>

using namespace std;
class Weapon
{
public:
    int Damage;
    int Strength;
    int critChance;
    int critDamage;
    int Intelligence;
    int Ferocity;
    int Rarity; // 1 = Common, 2 = Uncommon, 3 = Rare, 4 = Epic, 5 = Legendary, 6 = Mythic, 7 = Divine, 8 = Special, 9 = Very Special
    bool Dungeon;
    Weapon(int a, int b, int c, int d, int e, int f, int g, bool h)
    {
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

class Armor
{
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

class Helmet : public Armor
{
public:
    double abilityDamage;
    Helmet(int a, int b, int c, int d, int e, int f, int g, int h, double i)
    {
        Strength = a;
        critChance = b;
        critDamage = c;
        Health = d;
        Defense = e;
        Speed = f;
        Intelligence = g;
        healthRegen = h;
        abilityDamage = i;
    }
};

class Chestplate : public Armor
{
public:
    int trueDefense;
    Chestplate(int a, int b, int c, int d, int e, int f, int g, int h, int i)
    {
        Strength = a;
        critChance = b;
        critDamage = c;
        Health = d;
        Defense = e;
        Speed = f;
        Intelligence = g;
        healthRegen = h;
        trueDefense = i;
    }
};

class Leggings : public Armor
{
public:
    Leggings(int a, int b, int c, int d, int e, int f, int g, int h)
    {
        Strength = a;
        critChance = b;
        critDamage = c;
        Health = d;
        Defense = e;
        Speed = f;
        Intelligence = g;
        healthRegen = h;
    }
};
class Boots : public Armor
{
public:
    Boots(int a, int b, int c, int d, int e, int f, int g, int h)
    {
        Strength = a;
        critChance = b;
        critDamage = c;
        Health = d;
        Defense = e;
        Speed = f;
        Intelligence = g;
        healthRegen = h;
    }
};
class Player
{
public:
    int magicalPower;
    string Helmet;
    string Chestplate;
    string Leggings;
    string Boots;
    string Weapon;
    Player(int a, string b, string c, string d, string e, string f)
    {
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

Player blousy(1500, "shadowGoggles", "stormChestplate", "stormLeggings", "stormBoots", "Hyperion");

void createPlayer() {
    string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
}

void chooseGear() {
    // show [1] [2] [3] [4] system to show equipped pieces
    int choice;
    std::cout << "Which piece of equipment would you like to modify?" << std::endl;
    std::cout << "[1] Helmet\n[2] Chestplate\n[3] Leggings\n[4] Boots\n[5] Weapon" << std::endl;
    // choose what piece to modify
    std::cin >> choice; 
    if (choice == 1) {
        int helmetChoice;
        std::cout << "[1] Wither Goggles" << std::endl;
        std::cin >> helmetChoice;
    }
    else if (choice == 2) {
        int chestplateChoice;
        std::cout << "[1] Storm Chestplate" << std::endl;
        std::cin >> chestplateChoice;
    }
    else if (choice == 3) {
        int leggingsChoice;
        std::cout << "[1] Storm Helmet" << std::endl;
        std::cin >> leggingsChoice;
    }
    else if (choice == 4) {
        int bootsChoice;
        std::cout << "[1] Storm Boots" << std::endl;
        std::cin >> bootsChoice;
    }
    else if (choice == 5) {
        int weaponChoice;
        std::cout << "[1] Hyperion" << std::endl;
        std::cin >> weaponChoice;
        if (weaponChoice == 1) {
            
        }
    }
    else if (choice > 5) {
        std::cout << "This is not a valid choice" << std::endl;
    }
    // show all pieces of that sort
    // add up all mana and hp stats
    // calculate mana and hp after user confirms
}

int mpMana = 29.97 * pow((log(0.0019 * (blousy.magicalPower) + 1)), 1.2);
int armorMana = shadowGoggles.Intelligence + stormChestplate.Intelligence + stormLeggings.Intelligence + stormBoots.Intelligence;
double maxMana = armorMana + Hyperion.Intelligence + mpMana;
double currentMana = maxMana;

void witherImpact()
{
    currentMana -= 120;
    if (currentMana <= 0) {
        currentMana = 0;
        std::cout << "No mana" << std::endl;
    }
}

void progressBar()
{
    int percentageMana = currentMana / maxMana * 100;
    std::cout << percentageMana << std::endl;
    if (percentageMana == 0)
    {
        std::cout << "[==========]    " << currentMana << "/" << maxMana << std::endl;
    }
    else if (0 < percentageMana && percentageMana <= 15)
    {
        std::cout << "[#=========]    " << currentMana << "/" << maxMana <<std::endl;
    }
    else if (15 < percentageMana && percentageMana <= 25)
    {
        std::cout << "[##========]    " << currentMana << "/" << maxMana <<std::endl;
    }
    else if (25 < percentageMana && percentageMana <= 35)
    {
        std::cout << "[###=======]    " << currentMana << "/" << maxMana <<std::endl;
    }
    else if (35 < percentageMana && percentageMana <= 45)
    {
        std::cout << "[####======]    " << currentMana << "/" << maxMana <<std::endl;
    }
    else if (45 < percentageMana && percentageMana <= 55)
    {
        std::cout << "[#####=====]    " << currentMana << "/" << maxMana <<std::endl;
    }
    else if (55 < percentageMana && percentageMana <= 65)
    {
        std::cout << "[######====]    " << currentMana << "/" << maxMana <<std::endl;
    }
    else if (65 < percentageMana && percentageMana <= 75)
    {
        std::cout << "[#######===]    " << currentMana << "/" << maxMana <<std::endl;
    }
    else if (75 < percentageMana && percentageMana <= 85)
    {
        std::cout << "[########==]    " << currentMana << "/" << maxMana <<std::endl;
    }
    else if (85 < percentageMana && percentageMana <= 99)
    {
        std::cout << "[#########=]    " << currentMana << "/" << maxMana <<std::endl;
    }
    else if (percentageMana == 100)
    {
        std::cout << "[##########]    " << currentMana << "/" << maxMana <<std::endl;
    }
}

void manaRegen()
{
    if (currentMana != maxMana)
    {
        int manaRegen = maxMana * 0.02;
        progressBar();
        usleep(1000000);
        while (currentMana < maxMana)
        {
            currentMana += manaRegen + 8;
            if (currentMana > maxMana)
            {
                currentMana = maxMana;
            }
            progressBar();
            usleep(1000000);
        }
    }
}


int main()
{
    createPlayer();
    while (currentMana < maxMana)
    {
        manaRegen();
    }
}