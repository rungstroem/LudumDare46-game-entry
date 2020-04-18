#include <SDL2/SDL.h>
#include <iostream>

const int screenWidth = 600;
const int screenHeight = 800;

using namespace std;
int main(int argc, char* args[]){
	
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		cout << "SDL could not initialize\n";
	} else{
		window = SDL_CreateWindow("SDL tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	}

	if( window == NULL){
		cout << "Window could not be created\n";
	} else {
		screenSurface = SDL_GetWindowSurface(window);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
		
		SDL_UpdateWindowSurface(window); //Updates screen with content
		SDL_Delay(2000);
	}

	//
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

