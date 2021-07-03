#pragma once
#include <SDL.h>

#define SDL_MAIN_HANDLED
class GameScene;
class EntityManager;
class AssetManager;
class Game {
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void handleInputs();
	void update();
	void draw();
	void clean();
	bool isRunning();

	void positionCamera(int pX, int pY);

	static SDL_Rect camera;
	static SDL_Renderer* renderer;
	static AssetManager* assets;
private:
	bool isRunning_;
	SDL_Window* window;
	SDL_Rect boundBox;
	EntityManager* entityManager;
	GameScene* gameScene;
};