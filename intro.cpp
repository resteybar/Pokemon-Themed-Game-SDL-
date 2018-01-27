/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
 and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include "Libraries.h"
#include "intro.h"
#include <string>


Intro::Intro()
{
    //loadSurface(pat);
    
    //The window we'll be rendering to
    gWindow = NULL;
    
    //The surface contained by the window
    gScreenSurface = NULL;
    
    //Current displayed PNG image
    gPNGSurface = NULL;
}
bool Intro::init()
{
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }
            else
            {
                //Get window surface
                gScreenSurface = SDL_GetWindowSurface( gWindow );
            }
        }
    }
    
    return success;
}

bool Intro::loadMedia()
{
    //Loading success flag
    bool success = true;
    
    //Load PNG surface
    gPNGSurface = loadSurface( "Images/conquestOfEvil.png" );
    if( gPNGSurface == NULL )
    {
        printf( "Failed to load PNG image!\n" );
        success = false;
    }
    
    return success;
}

void Intro::close()
{
    //Free loaded image
    SDL_FreeSurface( gPNGSurface );
    gPNGSurface = NULL;
    
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Surface* Intro::loadSurface( std::string path )
{
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;
    
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, NULL );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    
    return optimizedSurface;
}

void Intro::showUp()
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;
            
            //Event handler
            SDL_Event e;
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e) )
                {
                    //User requests quit
                    //					if( e.type == SDL_QUIT )
                    //					{
                    //						quit = true;
                    //					}{
                    /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
                    switch( e.type )
                    {
                        case SDL_KEYDOWN:
                            switch (e.key.keysym.sym) {
                                case SDLK_x:
                                    quit = true;
                                    break;
                                    
                                default:
                                    break;
                            }
                            // printf( "Key press detected\n" );
                            //break;
                            
                        case SDL_KEYUP:
                            printf( "Key release detected\n" );
                            break;
                            
                        default:
                            break;
                    }
                }

            //While application is running
                    //Apply the PNG image
                SDL_BlitSurface( gPNGSurface, NULL, gScreenSurface, NULL );
                
                //Update the surface
                SDL_UpdateWindowSurface( gWindow );
            }
        }
    }
    
    //Free resources and close SDL
    close();
    
}
