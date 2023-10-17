#ifndef __BASE_ENGINE_H__
#define __BASE_ENGINE_H__

#include <SDL2/SDL.h>
#include <functional>

class BaseEngine;

class BaseEngine {
protected:
    SDL_Window* _window;
    int _windowWidth;
    int _windowHeight;
    
    bool _shouldExit;
    
    virtual void initSDL();
    virtual void initWindow(const char* title, Uint32 SDL_flags);
    virtual void initRenderer() = 0;

    virtual void onSizeChanged(int width, int height);
public:
    BaseEngine();
    ~BaseEngine();

    bool getShouldExit() const;
    void setShouldExit(bool exit);

    virtual void loop() = 0;
    virtual void render() = 0;


    virtual void handleEvent(SDL_Event* event);

    // !!! SHOULD BE CALLED EVERY LOOP !!!
    void pollEvents();
};

#endif