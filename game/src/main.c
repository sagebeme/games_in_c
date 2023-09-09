#include <stdio.h>
#include <SDL2/SDL.h>
#include "./constants.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int initialize_window(void){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		fprintf(stderr, "ERROR INTITIALIZING SDL. \n");
		return FALSE;
	}
	window = SDL_CreateWindow(
			"Brick Game by Sage", 
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH,/*width*/
			WINDOW_HEIGHT, /*height*/
			SDL_WINDOW_BORDERLESS
			);

	if (!window) {
		fprintf(stderr, "Error creating window. \n");
		return FALSE;
	}
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		fprintf(stderr, "Error creating SDL renderer");
		return FALSE;
	}

	return TRUE;
}

int main () {
	printf("Game is running...\n");
	initialize_window();	
	return 0;
}
