#include "baseEngine.h"

#include <string>

#include <stdio.h>
#include <stdexcept>


#pragma region Init

void BaseEngine::initSDL() {
    if(SDL_WasInit(SDL_INIT_EVERYTHING) != 0) throw new std::runtime_error("SDL was already initialized.");
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) throw new std::runtime_error(std::string("SDL Initializing.").append(SDL_GetError()));
}

void BaseEngine::initWindow(const char* title, Uint32 SDL_flags) {
    _window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_flags);
    
    int width = 0, height = 0;
    SDL_GetWindowSize(_window, &width, &height);

    onSizeChanged(width, height);
}

void BaseEngine::onSizeChanged(int width, int height) {
    _windowWidth = width;
    _windowHeight = height;
}

#pragma endregion

#pragma region Construct/Deconstruct

BaseEngine::BaseEngine() {
    _shouldExit = false;
}

BaseEngine::~BaseEngine() {
    SDL_DestroyWindow(_window);

    SDL_Quit();
}

#pragma endregion


bool BaseEngine::getShouldExit() const { return _shouldExit; }
void BaseEngine::setShouldExit(bool shouldExit) { _shouldExit = shouldExit; }


void BaseEngine::handleEvent(SDL_Event* event) {
    switch (event->type) {
    case SDL_QUIT: _shouldExit = true; break;
    default: break;
    }
}

void BaseEngine::pollEvents() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        handleEvent(&event);
    }
}