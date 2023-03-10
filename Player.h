#ifndef PLAYER_H
#define PLAYER_H

class Player {
public: // Non-methods
    float x,y;
    int health;
    int defense;
    int intelligence;
    int speed;

    int helmetIntelligence;
    int chestplateIntelligence;
    int leggingsIntelligence;
    int bootsIntelligence;

    Player() {
        x = 0.0f;
        y = 0.0f;
        health = 100;
        defense = 0;
        intelligence = 100;
        speed = 100;
        helmetIntelligence = 0;
        chestplateIntelligence = 0;
        leggingsIntelligence = 0;
        bootsIntelligence = 0;
    }

public: // Methods
    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
    void ApplyArmorStats() {
        intelligence += helmetIntelligence + chestplateIntelligence + leggingsIntelligence + bootsIntelligence;
    }
};

Player* blousy = new Player();

#endif
