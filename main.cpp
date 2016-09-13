
#include <array>
#include <cstdio>
#include <memory>
#include <string>
#include <vector>

#ifdef WINDOWS
  #include "SDL.h"
#else
  #include "SDL2/SDL.h"
#endif

//#include "player.h"
//#include "sprite.h"

#include "engine.h"
#include "overworld.h"

int main(int argc, char** args) {
    
	auto gameEngine = std::make_unique<Engine>();

	gameEngine->init();
    gameEngine->changeState(new Overworld());

	while (gameEngine->isRunning()) {
		gameEngine->input();
		gameEngine->update();
		gameEngine->render();
	}

	SDL_Quit();
    
	return 0;
}
