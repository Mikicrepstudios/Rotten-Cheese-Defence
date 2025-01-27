#pragma once

namespace data {
    struct Cheese {
        int unrot = 0; // How much cheese is rotten
    };

    struct Game {
        Cheese map[8][2] = {};
    };
}