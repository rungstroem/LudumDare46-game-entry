#include <SDL2/SDL.h>
#include <iostream>

//Variables
const int screenWidth = 600;
const int screenHeight = 600;

bool quit = false;
//Uint32 *pixels;

using namespace std;
int main(int argc, char* args[]){
	
	//Initialize window, screen realestate and render
	SDL_Window *window = NULL;
	SDL_Surface *screenSurface = NULL;
	SDL_Surface *backBuffer = NULL;
	SDL_Renderer *render = NULL;
	//SDL_Texture *texture = NULL;

	//Setup eventhandler
	SDL_Event inputEvent;

	//Call SDL initialization subsysten
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		cout << "SDL could not initialize\n";
		quit = true;
	} else{
		window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		//texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, screenWidth, screenHeight);	
		//SDL_CreateWindowAndRenderer(screenWidth, screenHeight, 0, &window, &render);
		//window = SDL_CreateWindowAndRenderer("spaceInvaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		quit = false;
	}
	
	//Check whether the window has been created
	if( window == NULL || render == NULL || texture == NULL){
		cout << "Window or renderer could not be created\n";
		quit = true;
	} else{
		screenSurface = SDL_GetWindowSurface(window);
		//pixels = new Uint32[screenWidth*screenHeight];
		//memset(pixels, 0, screenWidth*screenHeight*sizeof(Uint32));

		quit = false;

		//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
		//SDL_UpdateWindowSurface(window); //Updates screen with content
		//SDL_Delay(2000);
	}

	int x = 100;
	int y = 100;
	
	//Game-loop
	while(!quit){
		SDL_SetRenderDrawColor(render, 0,0,0,0);

		//SDL_UpdateTexture(texture, NULL, pixels, screenWidth*sizeof(Uint32));

		//Input event handling
		while(SDL_PollEvent(&inputEvent) != 0){
			if(inputEvent.type == SDL_QUIT || inputEvent.key.keysym.sym == SDLK_ESCAPE){
				quit = true;
			} else if(inputEvent.type = SDL_KEYDOWN){
				switch (inputEvent.key.keysym.sym){
					case SDLK_UP:
						y--;
						if(y<0) y=0;
						//Do stuff with keyinputs
						break;
					case SDLK_DOWN:
						y++;
						if(y>screenHeight) y=screenHeight;
						//Do stuff with keyinputs
						break;
					case SDLK_LEFT:
						x--;
						if(x<0) x=0;
						//Do stuff with keyinputs
						break;
					case SDLK_RIGHT:
						x++;
						if(x>screenWidth) x=screenWidth;
						//Do stuff with keyinputs
						break;
					case SDLK_SPACE:
						//Do stuff with keyinputs
						break;

				}
			}
		}
		SDL_RenderClear(render);
		//SDL_RenderCopy(render, texture, 0,0);
		//SDL_RenderPresent(render);	
		SDL_RenderDrawPoint(render, x, y);
		SDL_RenderPresent(render);

		//End of game-loop Draws to screen
		//SDL_RenderPresent(render);

		
		/* 
		 * Something to figure out later on
		 * //End of game-loop - Draws to screen
		 * SDL_BlitSurface(backBuffer, NULL, screenSurface, NULL);	//Copy the backBuffer to the screenSurface
		 * SDL_UpdateWindowSurface(window);	//Updates the window with the screenSurface
		*/
	}

	//Clean-up
	delete[] pixels;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

