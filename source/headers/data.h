#pragma once

namespace data {
    struct Cheese {
        int state = 0; // Read at bottom of file
    };

    struct Game {
        Cheese map[8][2] = {};
        int score = 0;
        bool gameOver = false;
    };
}

/* State values:
0 - Rotten cheese (default)
1 - Mostly rotten cheese
2 - Little rotten cheese
3 - Fresh cheese
4 - No cheese / Gone
*/