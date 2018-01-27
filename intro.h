//
//  intro.hpp
//  CSS2A_gameProj
//
//  Created by Irais Gopar Osorio on 5/14/17.
//  Copyright © 2017 Irais Gopar Osorio. All rights reserved.
//

#ifndef intro_h
#define intro_h

#include <stdio.h>
#include "Libraries.h"

class Intro
{
public:
    //Starts up SDL and creates window
    
    //Screen dimension constants
    
    //Starts up SDL and creates window
    bool init();
    
    //Loads media
    bool loadMedia();
    
    //Frees media and shuts down SDL
    void close();
    void showUp();

    Intro();
    
    
    
    
private:
    SDL_Surface* loadSurface( std::string path );
    
    //The window we'll be rendering to
    SDL_Window* gWindow;
    
    //The surface contained by the window
    SDL_Surface* gScreenSurface;
    
    //Current displayed PNG image
    SDL_Surface* gPNGSurface;
};

#endif /* intro_h */
