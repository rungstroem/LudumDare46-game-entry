#include <SDL2/SDL.h>
#include <iostream>

//Variables
const int screenWidth = 600;
const int screenHeight = 600;

bool quit = false;
//Uint32 *pixels;

Uint32 shipForm[20][20] = {	{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0},
				{0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0},
				{0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0},
				{0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0},
				{0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0},
				{0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0},
				{0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0},
				{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
				{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
				{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
				{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0}	};

Uint32 AlienForm[20][20] = {	{0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0},
				{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
				{0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0},
				{0,0,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,0,0},
				{0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0},
				{1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1},
				{1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1},
				{1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1},
				{1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1},
				{1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1},
				{1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1}	};

using namespace std;
int main(int argc, char* args[]){
	Uint32 shipForm1D[20*20];
	Uint32 AlienForm1D[20*20];
	for(int i = 0;i<20;i++){
		for(int j = 0;j<20;j++){
			shipForm1D[i*20+j] = shipForm[i][j];
			AlienForm1D[i*20+j] = AlienForm[i][j];
		}
	}
	for(int i = 0;i<20*20;i++){
		if(shipForm1D[i] == 1) shipForm1D[i] == 0xFFFFFFF0;
		if(AlienForm1D[i] == 1) AlienForm1D[i] == 0xFFFFFFF0;
	}

	//Initialize window and render
	SDL_Window *window = NULL;
	SDL_Renderer *render = NULL;
	
	//Setup eventhandler
	SDL_Event inputEvent;

	//Call SDL initialization subsysten
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		cout << "SDL could not initialize\n";
		quit = true;
	} else{
		window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		quit = false;
	}
	
	//Check whether the window has been created
	if( window == NULL || render == NULL ){
		cout << "Window or renderer could not be created\n";
		quit = true;
	}
	/*	
	SDL_Texture *ship = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, 20,20);
	SDL_UpdateTexture(ship, NULL, shipForm1D, 8*20);

	SDL_Rect rect;
	rect.x = 0, rect.y = 0, rect.w = 20, rect.h = 20;
	*/

	int playerPosX = screenHeight -20;
	int playerPosY = screenWidth/2;
	
	//Game-loop
	while(!quit){
		
		//Input event handling
		while(SDL_PollEvent(&inputEvent) != 0){
			if(inputEvent.type == SDL_QUIT || inputEvent.key.keysym.sym == SDLK_ESCAPE){
				quit = true;
			} else if(inputEvent.type = SDL_KEYDOWN){
				switch (inputEvent.key.keysym.sym){
					case SDLK_UP:
						playerPosY--;
						if(playerPosY<0) playerPosY=0;
						//Do stuff with keyinputs
						break;
					case SDLK_DOWN:
						playerPosY++;
						if(playerPosY>screenHeight) playerPosY=screenHeight;
						//Do stuff with keyinputs
						break;
					case SDLK_LEFT:
						playerPosX--;
						if(playerPosX<0) playerPosX=0;
						//Do stuff with keyinputs
						break;
					case SDLK_RIGHT:
						playerPosX++;
						if(playerPosX>screenWidth) playerPosX=screenWidth;
						//Do stuff with keyinputs
						break;
					case SDLK_SPACE:
						//Do stuff with keyinputs
						break;

				}
			}
		}
		/*	
		SDL_SetRenderDrawColor(render, 0,0,0,0);
		SDL_RenderClear(render);
		//SDL_RenderCopy(render, ship, NULL, NULL);
		SDL_SetRenderDrawColor(render, 255,255,255,100);
		SDL_RenderDrawRect(render, &rect);
		*/

		SDL_SetRenderDrawColor(render, 255,255,255,255);
		//SDL_RenderDrawPoint(render, x, y);
		for(int i = playerPosX; i<playerPosX+20; i++){
			for(int j = playerPosY; j<playerPosY+20; j++){
				if(shipForm[j-playerPosY][i-playerPosX] == 1){
					if(i>screenHeight) i=screenHeight-1;
					if(j>screenWidth) j=screenWidth-1;
					SDL_RenderDrawPoint(render, i,j);
				}
			}
		}
		//End of game-loop Draws to screen
		SDL_RenderPresent(render);

	}

	//Clean-up
	//SDL_DestroyTexture(ship);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

