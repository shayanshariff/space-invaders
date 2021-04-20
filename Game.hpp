#pragma once

#include <SDL.h>


class Game{
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;
    int count = 0;
    bool isRunning;

    SDL_Window* gWindow = NULL;

    public:
        Game();
        ~Game();
        void init(const char* title, int xPos, int yPos, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void close();
        bool running();

        static SDL_Renderer* gRenderer;
        static SDL_Event event;

};