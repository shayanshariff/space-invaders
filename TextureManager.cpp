#include"TextureManager.hpp" 

 SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* renderer){

    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tempText = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tempText;
}