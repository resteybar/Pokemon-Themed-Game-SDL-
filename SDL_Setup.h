//
//  SDL_Setup.h
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/10/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#pragma onced

#ifndef SDL_Setup_h
#define SDL_Setup_h

#include "Libraries.h"

class SDL_Setup
{
protected:
    SDL_Window* window;
    SDL_Renderer* renderer = NULL;
    SDL_Event* mainEvent;
    
public:
    // Constructor + Destructor
    SDL_Setup() {}
    SDL_Setup(bool *noWindow);
    ~SDL_Setup();
    
    // Getters - Accessors
    SDL_Renderer* getRenderer() {return renderer;}
    SDL_Event* getEvent() {return mainEvent;}
    
    // Member Methods
    void begin();
    void end();
};

#endif /* SDL_Setup_h */
