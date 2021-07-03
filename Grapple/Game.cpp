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

SDL_Rect Game::camera = { 0,0,0,0 };

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
	camera.w = width;
	camera.h = height;
	boundBox.x = width / 12;
	boundBox.y = 0;
	boundBox.w = width / 5;
	boundBox.h = height;
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

	for (auto t : entityManager->getGroup(gameScene->groupMap)) {
		t->draw();
	}
	for (auto p : entityManager->getGroup(gameScene->groupPlayers)) {
		p->draw();
		
		
		int pX = p->getComponent<TransformC>().position.x();
		int pY = p->getComponent<TransformC>().position.y();

		positionCamera(pX, pY);
	}
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

void Game::positionCamera(int pX, int pY) {
	if (pX > (boundBox.x + camera.x + boundBox.w)) {
		camera.x = pX - boundBox.w - boundBox.x;
	}

	else if (pX < (boundBox.x + camera.x)) {
		camera.x = pX - boundBox.x;
	}

	if (pY > (boundBox.y + camera.y + boundBox.h)) {
		camera.y = pY - boundBox.h - boundBox.y;
	}

	else if (pY < (boundBox.y + camera.y)) {
		camera.y = pY - boundBox.y;
	}

	if (camera.x < 0) {
		camera.x = 0;
	}
	if (camera.y < 0) {
		camera.y = 0;
	}
	if (camera.x > camera.w) {
		camera.x = camera.w;
	}
	if (camera.y > camera.h) {
		camera.y = camera.h;
	}
}
