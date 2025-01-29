#pragma once

#include "mf/core.h"

#include "data.h"

namespace graphics {
    void DrawCheese(core::MF_Window window, data::Game &game, assets::Cheese cheeseAssets);
    void DrawScore(core::MF_Window window, int score);
}