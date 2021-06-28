#include "Game.h"
#include "Entity.h"
#include <iostream>
#include "EntityManager.h"
#include "Components.h"
#include "AssetManager.h"
#include "MainGame.h"
#include "GameScene.h"
#include "Entity.h"

SDL_Renderer* Game::renderer = nullptr;

AssetManager* Game::assets = new AssetManager();

Game::Game()
{
	window = nullptr;
	renderer = nullptr;
	isRunning_ = false;
}

Game::~Game()
{
}

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, x, y, width, height, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
		if (window) {
			std::cout << "Window Created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created" << std::endl;
		}
		isRunning_ = true;
	}
	else {
		isRunning_ = false;
	}
	entityManager = new EntityManager();

	gameScene = new MainGame(entityManager);
	gameScene->init();
}

void Game::handleInputs()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case(SDL_QUIT):
			isRunning_ = false;
			break;
		default:
			entityManager->handleInput(event);
			break;
		}
	}
}

void Game::update()
{
	entityManager->update();
}

void Game::draw()
{
	SDL_RenderClear(renderer);

	entityManager->draw();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	
	delete assets;

	std::cout << "Cleaned Up" << std::endl;
}

bool Game::isRunning()
{
	return isRunning_;
}
