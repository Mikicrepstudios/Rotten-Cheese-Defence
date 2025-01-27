#include "mf/core.h"

#include "assets.h"

namespace assets {
    void LoadMainAssets(core::MF_Window window, assets::Main &main) {
        // Load face
        main.face = core::LoadImg(window.renderer, "assets/face.png");
    }
}