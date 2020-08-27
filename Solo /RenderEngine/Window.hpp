#pragma once
#include <SDL2/SDL.h>

namespace Solo
{
namespace Render
{
class Window
{
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    
    const int& mWindowWidth, mWindowHeight;
    const char* mWindowTitle;
    
    bool mOpen = true;
public:
    Window(const char* windowTitle, const int& windowWidth, const int& windowHeight);
    void mInit();
    void mPollEvents();
    ~Window();
    
    SDL_Window* mGetWindow();
    SDL_Renderer* mGetRenderingContext(); // TODO: Make Renderer as its own object
    bool mWindowShouldClose();
};
};
};
