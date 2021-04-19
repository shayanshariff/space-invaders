#include"TextureManager.hpp" 

 SDL_Texture* TextureManager::LoadTexture(const char* texture){

    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tempText = SDL_CreateTextureFromSurface(Game::gRenderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tempText;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst){
        SDL_RenderCopy(Game::gRenderer, tex, &src, &dst);
    }