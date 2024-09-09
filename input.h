#include "player.h"

class input_obj {
public:
    input_obj(std::vector<Player>& players) : players(players) {}

    void operator()() {
        while (true) {
            input = std::cin.get();
            
            switch (input) {
                case 'a':
                    for (Player& player : players) {
                        int curHealth = player.getHealth();
                        player.setCurrentHealth(curHealth-5);
                    }
                    break;
            }
        }
    }
private:
    std::vector<Player>& players;
    char input;
};