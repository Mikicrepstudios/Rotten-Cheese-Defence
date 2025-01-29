#include "mf/core.h"
#include "mf/logic.h"

#include "data.h"

namespace logic {
    void UnRotCheese(core::MF_Window &window, data::Game &game) {
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 2; y++) {
                SDL_Rect cheeseRect = {(50 * (x + 1)) + (x * 100), (60 * (y + 1)) + (y * 100), 100, 100};
                
                if(logic::IsMouseTouching(window.mouse.x, window.mouse.y, cheeseRect)) {
                    if(game.map[x][y].state != 3 && game.map[x][y].state != 4 && game.map[x][y].state != 0)
                        game.map[x][y].state -= 1;

                    switch(game.map[x][y].state) {
                        case 0:
                            game.score -= 50;
                            break;
                        case 1:
                            game.score += 100;
                            break;
                        case 2:
                            game.score += 50;
                            break;
                        case 3:
                            game.score -= 100;
                            break;
                    }
                }
            }
        }
    }
}