#include <iostream>
#include "Game.h"
#include <crtdbg.h>

int main(int argv, char** args) {
	Game* game = new Game();
	game->init("Grapple", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);

	Uint32 previous = SDL_GetTicks();
	Uint32 lag = 0.0;
	Uint32 MS_PER_UPDATE = 1000 / 60;

	while (game->isRunning()) {
		Uint32 current = SDL_GetTicks();
		Uint32 elapsed = current - previous;
		previous = current;
		lag += elapsed;

		game->handleInputs();

		while (lag >= MS_PER_UPDATE)
		{
			game->update();
			lag -= MS_PER_UPDATE;
		}

		game->draw();
	}

	game->clean();

	delete game;
	
	_CrtDumpMemoryLeaks();

	return 0;
}