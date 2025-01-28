#include "mf/core.h"
#include "mf/logic.h"

#include "data.h"

#include <iostream>

namespace logic {
    void RotCheese(data::Game &game) {
        int x = logic::GenRanNum(0, 7);
        int y = logic::GenRanNum(0, 1);

        if(game.map[x][y].state != 3)
            game.map[x][y].state += 1;

        //if(game.map[x][y].state == 3)
            // Add timer here to remove cheese
    }
}