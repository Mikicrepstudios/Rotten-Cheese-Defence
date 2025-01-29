#include <iostream>
#include <string>
#include "SDL.h"

#include "mf/core.h"
#include "mf/colors.h"
#include "mf/graphics.h"
#include "mf/logic.h"
#include "mf/sfx.h"

#include "headers/assets.h"
#include "headers/data.h"
#include "headers/graphics.h"
#include "headers/logic.h"

int main(int argc, char* argv[]) {
    bool running = true;

    // MUST USE LINE BELOW
    core::printver(2);
    std::cout << "-----Rotten Cheese Defence------"<< std::endl
			  << "-------Ver: D E V---------------"<< std::endl
			  << "Copyright Mikicrep Studios 2025" << std::endl;

    // Main stuff
    const std::string title = "Rotten Cheese Defence";
    core::MF_Window window = {};
    SDL_Event event = {};

    // Create window
    if(core::InitWindow(window, title, 1280, 800) == false) running = false;

    // Init structs
    data::Game game = {};

    // Init textue structs
    assets::Main mainAssets = {};
    assets::Cheese cheeseAssets = {};

    // Load assets
    assets::LoadMainAssets(window, mainAssets);
    assets::LoadCheeseAssets(window, cheeseAssets);

    // Other
    SDL_Rect resetButton = {window.width / 2 - 300, window.height / 2, 600, 100};

    // Clear map
    logic::ClearMap(game);

    // Main menu
    logic::MainMenu(window, game);

    // Add timers
    core::AddTimer(game.interval, [&game]() { logic::RotCheese(game); }, true);

    sfx::PlayBGMusic("assets/music.mp3");

    while(running) {
        // Prepare next frame
        SDL_GetMouseState(&window.mouse.x, &window.mouse.y);

        // Check for events
        while(SDL_PollEvent(&event) != 0) {
            // Handle window events
            window.event = event;
            switch(event.type) {
                case SDL_QUIT:
                    // Quit game
                    running = false;
                    break;
               
				case SDL_WINDOWEVENT:
					switch(event.window.event) {
						case SDL_WINDOWEVENT_RESIZED:
							// Handle resizing window
							window.width = event.window.data1;
							window.height = event.window.data2;
							break;
					}
					break;

                case SDL_MOUSEBUTTONDOWN:
                    // Mouse button is held
                    window.mouse.isDown = true;
                    logic::UnRotCheese(window, game);

                    if(game.gameOver) {
                        if(logic::IsMouseTouching(window.mouse.x, window.mouse.y, resetButton)) {
                            logic::Reset(game);
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    // Mouse button is released
                    window.mouse.isDown = false;
                    break;

                case SDL_KEYDOWN:
                    // Handle keyboard presses
                    switch(event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            // Quit game
                            running = false;
                            break;
                        case SDLK_F11:
                            // Window fullscreening
                            switch(window.fullscreen) {
                                case true:
                                    SDL_SetWindowFullscreen(window.window, 0);
                                    window.fullscreen = false;
                                    break;
                                case false:
                                    SDL_SetWindowFullscreen(window.window, SDL_WINDOW_FULLSCREEN);
                                    window.fullscreen = true;
                                    break;
                            }
                    }
                    break;
            }
        }

        // Clear frame
        SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, 255);
        SDL_RenderClear(window.renderer);

        // Draw stuff
        graphics::DrawCheese(window, game, cheeseAssets);
        draw::DrawTextureRect(window.renderer, {0, window.height - 200, window.width, 200}, mainAssets.face);
        draw::DrawLine(window.renderer, {window.mouse.x, window.mouse.y}, {window.width / 2, window.height - 100}, 10, colors::pink);
        graphics::DrawScore(window, game.score);

        if(game.gameOver) {
            graphics::DrawGameOver(window, game);
        }

        // Finish frame
        core::UpdateTimers();
        SDL_RenderPresent(window.renderer);
        core::TimeCount(window);
        SDL_Delay(1000 / window.fps);
    }

    // Cleanup variables from memory
    core::Exit(window);
    return 0;
}
