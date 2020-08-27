#include "Window.hpp"

static SDL_Event e;
namespace Solo
{
namespace Render
{
    Window::Window(const char* windowTitle, const int& windowWidth, const int& windowHeight):
        mWindowWidth(windowWidth), mWindowHeight(windowHeight), mWindowTitle(windowTitle)
    {
    }

    void Window::mInit()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        mWindow = SDL_CreateWindow(mWindowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWindowWidth, mWindowHeight, SDL_WINDOW_SHOWN);
        mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        
        if (mWindow == nullptr || mRenderer == nullptr)
            mOpen = false;
        else
            mOpen = true;
    }

    void Window::mPollEvents()
    {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT)
            mOpen = false;
    }

    Window::~Window()
    {
        SDL_DestroyWindow(mWindow);
        SDL_DestroyRenderer(mRenderer);
        SDL_Quit();
    }

    SDL_Window* Window::mGetWindow()
    {
        return mWindow;
    }

    SDL_Renderer* Window::mGetRenderingContext()
    {
        return mRenderer;
    }

    bool Window::mWindowShouldClose()
    {
        return mOpen;
    }
};
};
