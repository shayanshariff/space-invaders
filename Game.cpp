#include"Game.hpp"
#include<iostream>

SDL_Texture* playerTex;
SDL_Rect srcR, dstR;

Game::~Game()
{}
Game::Game()
{}
    int count = 0;
void Game::init(const char* title, int xPos, int yPos, bool fullscreen){
    int flags = 0;

    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "init done" << std::endl;

        gWindow = SDL_CreateWindow(title, xPos, yPos, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
        if(gWindow){
            std::cout << "window made" << std::endl;
        }
        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED );
        if(gRenderer){
            SDL_SetRenderDrawColor(gRenderer, 104, 56, 108, 255);
            std::cout << "Renderer was made" << std::endl;
        }
        isRunning = true;
    }
    else{
        isRunning = false;
    }
    SDL_Surface* tempSurface = IMG_Load("assets/player.png");
    playerTex = SDL_CreateTextureFromSurface(gRenderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}
void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}
void Game::update(){
    count++;
    dstR.h = 64;
    dstR.w = 64;
    dstR.y = 536;
    dstR.x = count;
    if(count> 1000){
        count = 0;
    }

}

void Game::render(){
    SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, playerTex, NULL, &dstR);
    SDL_RenderPresent(gRenderer);
}
void Game::close(){
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

bool Game::running(){
        return isRunning;
    }
