#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class Player {
public:
    float x, y;
    int health;
    int defense;
    int intelligence;
    int speed;

    Armor armor[4]; // array to store armor pieces

    Player() : x(0.0f), y(0.0f), health(100), defense(0), intelligence(100), speed(100) {
        // initialize armor array with armor instances
        armor[0] = witherGoggles;
        armor[1] = stormChestplate;
        armor[2] = stormLeggings;
        armor[3] = stormBoots;
    }

public: // Methods
    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
    
    void ApplyArmorStats() {
        // loop through armor array and add up stats
        for (int i = 0; i < 4; i++) {
            intelligence += armor[i].intelligence;
            health += armor[i].health;
            defense += armor[i].defense;
        }
    }
};

Player* blousy = new Player();

#endif
