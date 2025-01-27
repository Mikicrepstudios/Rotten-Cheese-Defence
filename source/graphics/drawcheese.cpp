#include "mf/core.h"
#include "mf/colors.h"
#include "mf/graphics.h"

#include "assets.h"
#include "data.h"

namespace graphics {
    void DrawCheese(core::MF_Window window, data::Game &game, assets::Cheese cheeseAssets) {
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 2; y++) {
                SDL_Rect cheeseRect = {(50 * (x + 1)) + (x * 100), (60 * (y + 1)) + (y * 100), 100, 100};
                // Draw cheese
                switch(game.map[x][y].state) {
                    case 0:
                        draw::DrawTextureRect(window.renderer, cheeseRect, cheeseAssets.rot0);
                        break;
                    case 1:
                        draw::DrawTextureRect(window.renderer, cheeseRect, cheeseAssets.rot1);
                        break;
                    case 2:
                        draw::DrawTextureRect(window.renderer, cheeseRect, cheeseAssets.rot2);
                        break;
                    case 3:
                        draw::DrawTextureRect(window.renderer, cheeseRect, cheeseAssets.rot3);
                        break;
                }
            }
        }
    }
}