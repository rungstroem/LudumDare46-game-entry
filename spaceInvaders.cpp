#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

using namespace std;

//Variables
const int screenWidth = 600;
const int screenHeight = 400;

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

class alien {
	public:
	alien(){
		memcpy(form,AlienForm,sizeof(Uint32)*20*20);
	}
	int x = 0;
	int y = 10;
	int hit = 0;

	Uint32 form[20][20];
	
	Uint32 healthBar[5][20] = {	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}	};
	void reduceHealth(){
		for(int i = 0; i < 20; i++){
			if(healthBar[0][1] == 0){
				break;
			}
			if(healthBar[0][18] == 1){
				healthBar[0][18] = 0, healthBar[0][19] = 0;
				healthBar[1][18] = 0, healthBar[1][19] = 0;
				healthBar[2][18] = 0, healthBar[2][19] = 0;
				healthBar[3][18] = 0, healthBar[3][19] = 0;
				healthBar[4][18] = 0, healthBar[4][19] = 0;
				break;
			}
			if(healthBar[0][i] == 0){
				healthBar[0][i-1] = 0, healthBar[0][i-2] = 0;
				healthBar[1][i-1] = 0, healthBar[1][i-2] = 0;
				healthBar[2][i-1] = 0, healthBar[2][i-2] = 0;
				healthBar[3][i-1] = 0, healthBar[3][i-2] = 0;
				healthBar[4][i-1] = 0, healthBar[4][i-2] = 0;
				break;
			}
		}
	}
};

class bullet{
	public:
	int x = 0;
	int y = 0;

	Uint32 form[2][2] = { 	{1,1}, 
       				{1,1}	}; 
	
	void inc(){
		int y = y-6;
	}
};

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
	
	//Setup event handler
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
	alien A;
	vector<alien> Aliens;
	for(int i = 0; i < screenWidth / 25; i++){
		Aliens.push_back(A);
		Aliens[i].x = i*25;
	}
	
	//Vector holding vectors of aliens - holding rows of aliens
	vector<vector<alien>> AlienRows;
	AlienRows.push_back(Aliens);
	
	//Vector holding bullets
	bullet B;
	vector<bullet> Bullets;
	
	//Needed variables
	int spaceShipSteps = 10;
	int alienRowSeperator = 30;

	int playerPosX = screenWidth / 2 -10;
	int playerPosY = screenHeight - 20;

	int alienShiftCounter = 0;
	bool hasShifted = false;
	int newAlienRow = 0;
	
	//Game-loop
	while(!quit){
		//Clear screen
		SDL_SetRenderDrawColor(render, 0,0,0,0);
		SDL_RenderClear(render);

		//Input event handling
		while(SDL_PollEvent(&inputEvent) != 0){
			if(inputEvent.type == SDL_QUIT || inputEvent.key.keysym.sym == SDLK_ESCAPE){
				quit = true;
			} else if(inputEvent.type == SDL_KEYDOWN){	//there was an error "inputEvent.type = SDL_KEYDOWN"
				switch (inputEvent.key.keysym.sym){
					case SDLK_UP:
						playerPosY -= spaceShipSteps;
						if(playerPosY<0) playerPosY=0;
						//Do stuff with keyinputs
						break;
					case SDLK_DOWN:
						playerPosY += spaceShipSteps;
						if(playerPosY>screenHeight -20) playerPosY=screenHeight -20;
						//Do stuff with keyinputs
						break;
					case SDLK_LEFT:
						playerPosX -= spaceShipSteps;
						if(playerPosX<0) playerPosX=0;
						//Do stuff with keyinputs
						break;
					case SDLK_RIGHT:
						playerPosX += spaceShipSteps;
						if(playerPosX>screenWidth -20) playerPosX=screenWidth -20;
						//Do stuff with keyinputs
						break;
					case SDLK_SPACE:
						//Create instances for class Bullets and push to vector
						bullet B;
						B.x = playerPosX +10;
						B.y = playerPosY;
						Bullets.push_back(B);
						//Do stuff with keyinputs
						break;

				}
			}
		}
		
		//Shifts the aliens 
		if(alienShiftCounter == 100){
			for(int j = 0; j < AlienRows.size(); j++){
				if(hasShifted == false){
					for(int i = 0; i < AlienRows[j].size(); i++){
						AlienRows[j][i].x += 5;
					}
					hasShifted = true;
				} else{
					for(int i = 0; i < AlienRows[j].size(); i++){
						AlienRows[j][i].x -= 5;
					}
					hasShifted = false;
				}
			}
		}
		
		//Draw Aliens	
		for(int l = 0; l < AlienRows.size(); l++){	
			for(int k = 0; k < AlienRows[l].size(); k++){
				SDL_SetRenderDrawColor(render,255,255,255,255);
				if(AlienRows[l][k].hit > 20){
					SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
				}
				if(AlienRows[l][k].hit > 40){
					AlienRows[l].erase(AlienRows[l].begin()+k);
					continue;
				}
				for(int i = AlienRows[l][k].x; i < AlienRows[l][k].x + 20; i++){
					for(int j = AlienRows[l][k].y; j < AlienRows[l][k].y + 20; j++){
						if(AlienRows[l][k].form[j-AlienRows[l][k].y][i-AlienRows[l][k].x] == 1){
							SDL_RenderDrawPoint(render, i, j);
						}
					}
				}
			}
		}

		//Draw spaceship
		SDL_SetRenderDrawColor(render, 255,255,255,255);
		for(int i = playerPosX; i < playerPosX + 20; i++){
			for(int j = playerPosY; j < playerPosY + 20; j++){
				
				if(shipForm[j-playerPosY][i-playerPosX] == 1){
					SDL_RenderDrawPoint(render, i,j);
				}
			}
		}
		
		//Draw bullets
		SDL_SetRenderDrawColor(render, 255,255,255,255);
		for(int k = 0;k<Bullets.size(); k++){
			for(int i = Bullets[k].x; i < Bullets[k].x+2; i++){
				for(int j = Bullets[k].y; j < Bullets[k].y+2; j++){
					if(Bullets[k].form[j-Bullets[k].y][i-Bullets[k].x] == 1){
						SDL_RenderDrawPoint(render, i, j);
					}
				}
			}
		}

		//Advance alle bullets
		for(int i = 0; i<Bullets.size(); i++){
			Bullets[i].y -= 1;
			if(Bullets[i].y < 1){
				Bullets.erase(Bullets.begin()+i);
			}
		}
		
		//Collision detection
		for(int i = 0; i < AlienRows.size(); i++){	
			for(int l = 0; l < AlienRows[i].size(); l++){
				for(int k = 0; k < Bullets.size(); k++){
					if(abs(Bullets[k].x - AlienRows[i][l].x) < 20 && abs(Bullets[k].y - AlienRows[i][l].y) < 20){
						AlienRows[i][l].hit++;
					}
				}
				//Game over check
				if(AlienRows[i][l].y > screenHeight){	//Alien reached bottom of screen
					quit = true;
				}
				if(abs(AlienRows[i][l].x - playerPosX) < 20 && abs(AlienRows[i][l].y - playerPosY) < 20){	//Alien hit spaceship
					quit = true;
				}
			}
		}

		alienShiftCounter++;
		if(alienShiftCounter > 100) alienShiftCounter = 0;
	
		//Advance Aliens	
		newAlienRow++;
		if(newAlienRow > 300){
			for(int j = 0; j < AlienRows.size(); j++){
				for(int i = 0; i < AlienRows[j].size(); i++){
					if(AlienRows[j].size() < 1){
						AlienRows.erase(AlienRows.begin()+j);
					} else{
						AlienRows[j][i].y += alienRowSeperator;
					}
				}
			}
			AlienRows.push_back(Aliens);
			newAlienRow = 0;
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

