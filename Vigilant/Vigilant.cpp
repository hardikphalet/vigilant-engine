#include "Polynomial.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>


//Screen dimension constants
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;   //setting the screen size

bool init();   //Starts up SDL and creates window
bool loadMedia();   //Loads media

void close();   //Frees media and shuts down SDL

SDL_Window* gWindow = NULL;   //The window we'll be rendering to
SDL_Renderer* gRenderer = NULL;   //The window renderer

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialise ! SDL Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            std::cout << "Warning: Linear texture filtering not enabled." << std::endl;
        }

        //Create window
        gWindow = SDL_CreateWindow("Vigilant-Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL)
            {
                std::cout << "Renderer could not be created! SDL_Error :: " << SDL_GetError() << std::endl;
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    std::cout << "SDL_image could not initialize! SDL_image error: " << IMG_GetError() << std::endl;
                    success = false;
                }
            }
        }
    }
    return success;
}

bool loadMedia()
{
    bool success = true;

    // Nothing to load :/
    return success;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    //Quitting SDL subsystems 
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* loadTexture(std::string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

int main(int argc, char* args[])
{
    std::cout << "Vigilant starting..." << std::endl;
    Polynomial poly(2);
    double arr[] = {
        1.0, -2.0, 1.0
    };
    poly.setCoeff(arr);
    std::cout << "Value of polynomial at 1 is " << poly.valueAt(1.1) << std::endl;
    std::cout << "Value of polynomial at 1 is " << poly.valueAt(2) << std::endl;
                                              
    std::cout << "Value of derivative at 1 is " << poly.derivative().valueAt(1) << std::endl;
    std::cout << "Value of derivative at 1 is " << poly.derivative().valueAt(2) << std::endl;
    std::cout << "Zero of the given Polynomial is " << poly.newtonRaphson(1.1) << std::endl;

    std::cout << "Program has ended. Please press enter to exit." << std::endl;
    std::cin.get();

    if (!init())
    {
        std::cout << "Failed to initialise!\n";
    }
    else
    {
        //Load Media
        if (!loadMedia())
        {
            std::cout << "Failed to load media!\n";
        }
        else
        {
            // Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            while (!quit)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }

                //Clear screen after every render
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                //Render sample 
                SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);
                SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);
                SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

                SDL_RenderPresent(gRenderer);
            }
        }
    }
    return 0;
}