#ifndef ARMOR_H
#define ARMOR_H

struct Armor {
    int health;
    int defense;
    int intelligence;
    int speed;
    
    Armor() : health(0), defense(0), intelligence(0), speed(0) {}
    
    Armor(int h, int d, int i, int s) : health(h), defense(d), intelligence(i), speed(s) {}
};

Armor witherGoggles(0, 0, 300, 0);
Armor stormChestplate(260, 120, 250, 0);
Armor stormLeggings(230, 105, 250, 0);
Armor stormBoots(145, 65, 250, 0);

#endif // ARMOR_H