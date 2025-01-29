#include "data.h"
#include "logic.h"

namespace logic {
    void Reset(data::Game &game) {
        game.gameOver = false;
        game.score = 0;

        logic::ClearMap(game);
    }
}