#include "player.h"

class input_obj {
public:
    input_obj(std::vector<Player>& players) : players(players) {}

    void operator()() {
        // input = getch();
        
    }
private:
    std::vector<Player>& players;
    std::string input;
};