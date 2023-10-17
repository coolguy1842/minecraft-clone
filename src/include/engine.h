#include <baseEngine.h>
#include <gl/glew.h>
#include <SDL2/SDL_opengl_glext.h>

#include <stdexcept>
#include <string>

class Engine : public BaseEngine {
private:
    SDL_GLContext _context;

    void initOpenGLOptions() {    
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    }

    void initRenderer() {
        _context = SDL_GL_CreateContext(_window);
        SDL_GL_MakeCurrent(_window, _context);
    }

    void initOpenGL() {
        glewExperimental = GL_TRUE;
        GLenum error = glewInit();
        if(error != GLEW_OK) {
            fprintf(stderr, "Error initializing GLEW:\n%s\n", glewGetErrorString(error));
            throw new std::runtime_error("Failed to initialize GLEW");
        }
    }

    void onSizeChanged(int width, int height) {
        BaseEngine::onSizeChanged(width, height);

        glViewport(0, 0, _windowWidth, _windowHeight);
    }

public:
    Engine() : BaseEngine() {
        initSDL();
        initOpenGLOptions();
        initWindow("Game", SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
        initRenderer();
        initOpenGL();
    }

    ~Engine() {
        SDL_GL_DeleteContext(_context);
    }


    void loop() {
        pollEvents();

        render();
    }

    void render() {
        glClearColor(0.29f, 0.59f, 1.0f, 0.9f);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(_window);
    }

    void handleEvent(SDL_Event* event) {
        BaseEngine::handleEvent(event);

        switch(event->type) {
        case SDL_WINDOWEVENT:
            switch(event->window.event) {
            case SDL_WINDOWEVENT_SIZE_CHANGED:
                _windowWidth = event->window.data1;
                _windowHeight = event->window.data2;
            default: break;
            }
        default: break;
        }
    }
};