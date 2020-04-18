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

struct healthBar{
	Uint32 health[5][20] = 	{	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}	};
	void reduceHealth(){
		for(int i = 0; i<20; i++){
			if(health[0][1] == 0){
				break;
			}
			if(health[0][18] == 1){
				health[0][18] = 0, health[0][19] = 0;
				health[1][18] = 0, health[1][19] = 0;
				health[2][18] = 0, health[2][19] = 0;
				health[3][18] = 0, health[3][19] = 0;
				health[4][18] = 0, health[4][19] = 0;
				break;
			}
			if(health[0][i] == 0){
				health[0][i-1] = 0, health[0][i-2] = 0;
				health[1][i-1] = 0, health[1][i-2] = 0;
				health[2][i-1] = 0, health[2][i-2] = 0;
				health[3][i-1] = 0, health[3][i-2] = 0;
				health[4][i-1] = 0, health[4][i-2] = 0;
				break;
			}
		}
	}
};

struct alien{
	Uint32 form[][] = AlienForm;
	healthBar h;
	Uint32 health[][] = h.health;
};

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
		if(shipForm1D[i] == 1) shipForm1D[i] == 0xFFFFFFFF;
		if(AlienForm1D[i] == 1) AlienForm1D[i] == 0xFFFFFFFF;
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

	//Create number of aliens
	for(int i = 0; i < screenWidth / 25; i++){
		if(i>100) i = 100;
		Alien + "i"
	}


	int playerPosX = screenWidth / 2 -10;
	int playerPosY = screenHeight - 20;
	
	//Game-loop
	while(!quit){
		
		//Input event handling
		while(SDL_PollEvent(&inputEvent) != 0){
			if(inputEvent.type == SDL_QUIT || inputEvent.key.keysym.sym == SDLK_ESCAPE){
				quit = true;
			} else if(inputEvent.type = SDL_KEYDOWN){
				switch (inputEvent.key.keysym.sym){
					case SDLK_UP:
						playerPosY-=10;
						if(playerPosY<0) playerPosY=0;
						//Do stuff with keyinputs
						break;
					case SDLK_DOWN:
						playerPosY+=10;
						if(playerPosY>screenHeight -20) playerPosY=screenHeight -20;
						//Do stuff with keyinputs
						break;
					case SDLK_LEFT:
						playerPosX-=10;
						if(playerPosX<0) playerPosX=0;
						//Do stuff with keyinputs
						break;
					case SDLK_RIGHT:
						playerPosX+=10;
						if(playerPosX>screenWidth -20) playerPosX=screenWidth -20;
						//Do stuff with keyinputs
						break;
					case SDLK_SPACE:
						//Do stuff with keyinputs
						break;

				}
			}
		}
		//Clear screen
		SDL_SetRenderDrawColor(render, 0,0,0,0);
		SDL_RenderClear(render);
		
		//Draw spaceship
		SDL_SetRenderDrawColor(render, 255,255,255,255);
		for(int i = playerPosX; i < playerPosX + 20; i++){
			for(int j = playerPosY; j < playerPosY + 20; j++){
				
				if(shipForm[j-playerPosY][i-playerPosX] == 1){
					SDL_RenderDrawPoint(render, i,j);
				}
			}
		}
	
		//Draw aliens
		for(int i = 0; i < screenWidth / 25; i++){
			
		}


		//Update screen - end of game-loop
		SDL_RenderPresent(render);

	}

	//Clean-up
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

