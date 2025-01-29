#include "mf/core.h"
#include "mf/logic.h"

#include "data.h"

#include <iostream>

namespace logic {
    void RotCheese(data::Game &game) {
        if(game.gameOver) return; // Dont waste precious CPU if game is over

        int x = logic::GenRanNum(0, 7);
        int y = logic::GenRanNum(0, 1);

        int tries = 0;

        while(game.map[x][y].state == 4) {
            x = logic::GenRanNum(0, 7);
            y = logic::GenRanNum(0, 1);
            tries++;

            if(tries == 20) {
                game.gameOver = true;
                break;
            }
        }

        game.map[x][y].state += 1;
    }
}