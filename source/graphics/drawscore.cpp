#include <string>

#include "mf/core.h"
#include "mf/colors.h"
#include "mf/graphics.h"

namespace graphics {
    void DrawScore(core::MF_Window window, int score) {
        std::string text = "Score: " + std::to_string(score);
        draw::DrawText(window.renderer, window.font, {window.width / 2 - 200, 0, 400, 50}, text.c_str(), colors::white);
    }
}