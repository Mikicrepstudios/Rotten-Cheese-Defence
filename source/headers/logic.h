#pragma once

#include "mf/core.h"

#include "data.h"

namespace logic {
    void MainMenu(core::MF_Window &window, data::Game &game);

    void ClearMap(data::Game& game);
    void Reset(data::Game &game);

    void RotCheese(data::Game &game);
    void UnRotCheese(core::MF_Window &window, data::Game &game);
}