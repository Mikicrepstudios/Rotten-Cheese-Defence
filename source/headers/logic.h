#pragma once

#include "data.h"

namespace logic {
    void ClearMap(data::Game& game);

    void RotCheese(data::Game &game);
    void UnRotCheese(core::MF_Window &window, data::Game &game);
}