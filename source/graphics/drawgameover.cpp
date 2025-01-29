#include <string>

#include "mf/core.h"
#include "mf/colors.h"
#include "mf/graphics.h"

#include "data.h"

namespace graphics {
    void DrawGameOver(core::MF_Window &window, data::Game game) {
        SDL_Rect bg = {window.width / 2 - 300, window.height / 2 - 200, 600, 300};
        SDL_Rect title = {window.width / 2 - 300, window.height / 2 - 200, 600, 100};
        SDL_Rect score = {window.width / 2 - 300, window.height / 2 - 100, 600, 100};
        SDL_Rect button = {window.width / 2 - 300, window.height / 2, 600, 100};

        draw::DrawRect(window.renderer, bg, colors::gray);
        draw::DrawText(window.renderer, window.font, title, "Game Over", colors::red);

        std::string scoreText = "Score: " + std::to_string(game.score);
        draw::DrawText(window.renderer, window.font, score, scoreText.c_str(), colors::white);

        draw::DrawButton(window.renderer, button, colors::lightgreen, window.mouse.x, window.mouse.y);
        draw::DrawText(window.renderer, window.font, button, "Restart", colors::white);
    }
}