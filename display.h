#include <iostream>
#include "player.h"
#include <thread>

class display_obj {
public:
    display_obj(std::vector<Player>& players) : players(players) {}

    void operator()() {
        std::cout << "\033[2J\033[H";
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            // std::unique_lock<std::mutex> lock(displayMutex);
            for (Player& player : players) {
                int displayHP = player.getHealth();
                int maxHP = player.getMaxHealth();
                std::string displayName = player.getName();            

                std::cout << "[-------------------]\n";
                std::cout << displayName << "\n";
                std::cout << displayHP << "/" << maxHP << "\n";
                std::cout << "[-------------------]\n";
            }
            std::cout << "\033[2;0H\033[K\033[H";
        }
    }

private:
    std::vector<Player>& players;
};