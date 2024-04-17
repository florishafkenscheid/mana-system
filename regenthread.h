#include <thread>
#include "boost/asio.hpp"
#include "player.h"

class regen_obj {
public:
    regen_obj(std::vector<Player>& players) : players(players) {}

    void operator()() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            for (Player& player : players) {
                int maxHP = player.getMaxHealth();
                int regenAmount = (1.5+maxHP/100)*204/100;
                int curHP = player.getHealth();

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