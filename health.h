#ifndef HEALTH_H
#define HEALTH_H
#include "armor.h"
#include "Player.h"
#include "statdisplay.h"

struct HealthValues {
    int maxHealth;
    int currentHealth;
};

struct DefenseValues {
    int maxDefense;
    int currentDefense;
};

struct EffectiveHpValues {
    int maxEffectiveHp;
    int currentEffectiveHp;
};

HealthValues Health(const Player& player) {
    int maxHealth = player.health;
    int currentHealth = maxHealth;
    return { maxHealth, currentHealth };
}

DefenseValues Defense(const Player& player) {
    int maxDefense = player.defense;
    int currentDefense = maxDefense;
    return { maxDefense, currentDefense };
}

EffectiveHpValues effectiveHp(const Player& player) {
    int maxEffectiveHp = player.health * (1+ player.defense/100);
    int currentEffectiveHp = maxEffectiveHp;
    return { maxEffectiveHp, currentEffectiveHp };
}

#endif