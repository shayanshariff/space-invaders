#include"Game.hpp"
#include<iostream>
#include"TextureManager.hpp"
#include"BaseObject.hpp"
#include"ECS.hpp"
#include"Components.hpp"

BaseObject* player;
BaseObject* player2;

Manager manager;
auto& newPlayer(manager.addEntity());

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
    player = new BaseObject("assets/sprites.png", gRenderer, 0, 536);
    player2 = new BaseObject("assets/sprites.png", gRenderer, 300, 400);

    newPlayer.addComponent<PositionComponent>();
    newPlayer.getComponent<PositionComponent>().setPos(500, 500);

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
    player->update();
    player2->update();
    manager.update();
    std::cout << newPlayer.getComponent<PositionComponent>().x() << "," << newPlayer.getComponent<PositionComponent>().y() << std::endl;;

}

void Game::render(){
    SDL_RenderClear(gRenderer);
    player->render();
    player2->render();
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
