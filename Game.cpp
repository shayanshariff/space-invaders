#include "game.hpp"
#include"Player.hpp"
#include "SpaceInvaders.hpp"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<iostream>

bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
			}
		}

	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	assets = loadTexture("assets/sprites.png");
    gTexture = loadTexture("assets/background.png");
	if(assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	bgMusic = Mix_LoadMUS( "sounds/bg.mp3" );

	if(bgMusic == NULL){
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	Mix_FreeMusic(bgMusic);
	bgMusic = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run( )
{
	bool quit = false;
	bool start = false;
	SDL_Event e;
	SpaceInvaders spaceinvaders(gRenderer, assets);
	Player* player;
	srand(time(0));  //Seeding random variable on initialization of game state
	spaceinvaders.createPlayer(300, 400);
	
	player = spaceinvaders.getPlayer();

	while( !quit )
	{
		//Handle events on queue
		
		if(start == false){
			gTexture = loadTexture("assets/titlescreen.png");
			 //removes everything from renderer
			SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
			SDL_RenderPresent(gRenderer);
		}
		else if(start == true){
			SDL_RenderClear(gRenderer);
			gTexture = loadTexture("assets/background.png");

			SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
			spaceinvaders.drawObjects();
			SDL_RenderPresent(gRenderer);
			

		}
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			if(e.key.keysym.sym == SDLK_KP_ENTER || e.key.keysym.sym == SDLK_RETURN){
				start = true;
			}
			if(e.type == SDL_MOUSEBUTTONDOWN){
				int playerX, playerY;
				playerX = player->mover()->x + 24;
				playerY = player->mover()->y + 5;
				spaceinvaders.createObject(playerX, playerY);

				
			}
			 if(e.type == SDL_KEYDOWN){
            switch(e.key.keysym.sym){
                case SDLK_w:

                    player->move('w');
                    break;
                case SDLK_a:
                    player->move('a');
                    break;
                case SDLK_s:
                    player->move('s');
                    break;
                case SDLK_d:
                    player->move('d');
                    break;
                
            	}
        	}
			

    	}
		if( Mix_PlayingMusic() == 0 )
		{
			//Play the music
			Mix_PlayMusic( bgMusic, 2 );
		}


	    SDL_Delay(2);	//causes sdl engine to delay for specified miliseconds

	}
	}
		

			

