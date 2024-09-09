#include <thread>
#include "player.h"

class regen_obj {
public:
    regen_obj(std::vector<Player>& players) : players(players) {}

    void operator()() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            for (Player& player : players) {
                int regenAmount = player.getRegenAmount();
                int curHP = player.getHealth();
                int maxHP = player.getMaxHealth();

                if (curHP >= maxHP || curHP+regenAmount >= maxHP) {
                    player.setCurrentHealth(maxHP);
                } else {
                    player.setCurrentHealth(curHP + regenAmount); 
                }
            }
        }
    }

private:
    std::vector<Player>& players;
};