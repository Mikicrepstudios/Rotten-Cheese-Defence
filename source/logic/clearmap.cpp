#include "data.h"

namespace logic {
    void ClearMap(data::Game &game) {
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 2; y++) {
                game.map[x][y].state = 0;
            }
        }
    }
}