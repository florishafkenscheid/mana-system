#ifndef ARMOR_H
#define ARMOR_H

class Helmet {
public:
    int health;
    int defense;
    int intelligence;
    int speed;

    Helmet(int h, int d, int i, int s) {
        health = h;
        defense = d;
        intelligence = i;
        speed = s;
    }
};

class Chestplate {
public:
    int health;
    int defense;
    int intelligence;
    int speed;
    
    Chestplate(int h, int d, int i, int s) {
        health = h;
        defense = d;
        intelligence = i;
        speed = s;
    }
};

class Leggings {
public:
    int health;
    int defense;
    int intelligence;
    int speed;
    
    Leggings(int h, int d, int i, int s) {
        health = h;
        defense = d;
        intelligence = i;
        speed = s;
    }
};

class Boots {
public:
    int health;
    int defense;
    int intelligence;
    int speed;
    
    Boots(int h, int d, int i, int s) {
        health = h;
        defense = d;
        intelligence = i;
        speed = s;
    }
};

Helmet witherGoggles(0, 0, 300, 0);
Chestplate stormChestplate(260, 120, 250, 0);
Leggings stormLeggings(230, 105, 250, 0);
Boots stormBoots(145, 65, 250, 0);

#endif // ARMOR_H