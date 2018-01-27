//
//  RPG.h
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/6/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//
#pragma once

#ifndef RPG_h
#define RPG_h

#include "Libraries.h"

#include "Sprite.h"
#include "Character.h"
#include "SDL_Setup.h"
#include "Environment.h"
#include "collisionRectangle.h"
#include "Text1.h"

class RPG
{
private:
    // MUSIC
    Mix_Music* music;
    
    // Set Up for Window
    SDL_Setup* setup;
    
    // Character + Background Objects
    Character* gilbert;
    Environment* background;
    //Text1 *hey;
    
    // Camera
    double camX;
    double camY;
    
    // if(window cannot open)
    bool noWindow;
    
    int counter;
public:
    // Constructor + Destructor
    RPG();
    ~RPG();
    
    // Member Methods
    void gameLoop();
};

#endif /* RPG_h */
