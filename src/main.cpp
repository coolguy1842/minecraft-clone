#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <iostream>
#include <engine.h>

int main(int argc, char** argv){
    Engine engine = Engine();

    while(!engine.getShouldExit()) {
        engine.loop();
    }

    return 0;
}
