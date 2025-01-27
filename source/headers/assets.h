#pragma once

#include "SDL.h"

namespace assets {
    struct Main {
        SDL_Texture* face; // Face at bottom of game
    };

    struct Cheese {
        SDL_Texture* rot0; // Rotten
        SDL_Texture* rot1; // Mostly rotten
        SDL_Texture* rot2; // Little rotten
        SDL_Texture* rot3; // Fresh
    };

    void LoadMainAssets(core::MF_Window window, assets::Main &main);
    void LoadCheeseAssets(core::MF_Window window, assets::Cheese &cheese);
}