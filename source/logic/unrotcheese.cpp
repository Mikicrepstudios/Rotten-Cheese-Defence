#include "mf/core.h"
#include "mf/extra.h"
#include "mf/logic.h"

#include "data.h"

namespace logic {
    void UnRotCheese(core::MF_Window &window, data::Game &game) {
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 2; y++) {
                // Variables used for scaling elements
                float wFactor = extra::castToFloat(window.width) / 1280;
                float hFactor = extra::castToFloat(window.height) / 800;

                SDL_Rect cheeseRect = {extra::castToInt(((50 * (x + 1)) + (x * 100)) *  wFactor), extra::castToInt(((60 * (y + 1)) + (y * 100)) * hFactor), extra::castToInt(100 * wFactor), extra::castToInt(100 * hFactor)};
                
                if(logic::IsMouseTouching(window.mouse.x, window.mouse.y, cheeseRect)) {
                    int originalState = game.map[x][y].state;
                    if(game.map[x][y].state != 3 && game.map[x][y].state != 4 && game.map[x][y].state != 0)
                        game.map[x][y].state -= 1;

                    switch(originalState) {
                        case 0:
                            game.score -= 300;
                            break;
                        case 1:
                            game.score += 100;
                            break;
                        case 2:
                            game.score += 50;
                            break;
                        case 3:
                            game.score -= 500;
                            break;
                    }
                }
            }
        }
    }
}