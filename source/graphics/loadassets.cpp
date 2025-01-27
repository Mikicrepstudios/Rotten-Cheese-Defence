#include "mf/core.h"

#include "assets.h"

namespace assets {
    void LoadMainAssets(core::MF_Window window, assets::Main &main) {
        // Load face
        main.face = core::LoadImg(window.renderer, "assets/face.png");
    }

    void LoadCheeseAssets(core::MF_Window window, assets::Cheese &cheese) {
        // Load cheeses
        cheese.rot0 = core::LoadImg(window.renderer, "assets/rot0.png");
        cheese.rot1 = core::LoadImg(window.renderer, "assets/rot1.png");
        cheese.rot2 = core::LoadImg(window.renderer, "assets/rot2.png");
        cheese.rot3 = core::LoadImg(window.renderer, "assets/rot3.png");
    }
}