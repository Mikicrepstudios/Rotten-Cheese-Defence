#include "mf/core.h"
#include "mf/colors.h"
#include "mf/graphics.h"

#include "data.h"

namespace graphics {
    void DrawCheese(core::MF_Window window, data::Game &game) {
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 2; y++) {
                // Draw cheese
                draw::DrawRect(window.renderer, {(50 * (x + 1)) + (x * 100), (60 * (y + 1)) + (y * 100), 100, 100}, colors::yellow);
            }
        }
    }
}