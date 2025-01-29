#include "mf/core.h"
#include "mf/colors.h"
#include "mf/graphics.h"

#include "data.h"

namespace logic {
    void MainMenu(core::MF_Window &window, data::Game &game) {
        bool running = true;
        SDL_Event event = {};

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
                        running = false;

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

            // Rects
            SDL_Rect title = {window.width / 2 - 300, 0, 600, 100};
            SDL_Rect selectText = {window.width / 2 - 200, window.height / 2 - 150, 400, 100};

            SDL_Rect easyRect = {window.width / 2 - 200, window.height / 2 - 50, 100, 100};

            // Draw stuff
            draw::DrawText(window.renderer, window.font, title, "Rotten Cheese Defence", colors::white);
            draw::DrawText(window.renderer, window.font, selectText, "Select difficulty", colors::white);

            draw::DrawButton(window.renderer, easyRect, colors::lightgreen, window.mouse.x, window.mouse.y);
            draw::DrawText(window.renderer, window.font, easyRect, "Easy", colors::white);

            // Finish frame
            SDL_RenderPresent(window.renderer);
            SDL_Delay(1000 / window.fps);
        }
    }
}