#pragma once

#include "SDL.h"

namespace assets {
    struct Main {
        SDL_Texture* face;
    };

    void LoadMainAssets(core::MF_Window window, assets::Main &main);
}