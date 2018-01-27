//
//  RPG_Implement.cpp
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/6/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#include "RPG.h"

RPG::RPG()
{
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    
    // Intro Music
    this -> music = Mix_LoadMUS("Music/Town.wav");
    Mix_PlayMusic(music, -1);
    
    // Camera
    this -> camX = 0;
    this -> camY = 0;
    
    // Window + Setup for SDL
    this -> noWindow = false;
    this -> setup = new SDL_Setup(&noWindow);
    
    // Setup Sprites
    this -> background = new Environment(&camX, &camY, setup);
    this -> gilbert = new Character(setup, &camX, &camY, background);
    
    // Creating a Counter to:
    //      - To have song place ONCE as it changes
    this -> counter = 0;
}

RPG::~RPG()
{
    delete setup;
    delete gilbert;
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}

void RPG::gameLoop(void)
{
    while(gilbert -> getQuit() == false && !noWindow && setup -> getEvent() -> type != SDL_QUIT)
    {
        setup -> begin();
        
        background -> drawBackground();
        
        gilbert -> draw();
        gilbert -> update();
        
        // When done Fighting
        if(gilbert -> getFight() == false && gilbert -> getFightDone() == true)
        {
            if(counter == 1)
            {
                Mix_FreeMusic(music);
                music = Mix_LoadMUS("Music/Won.wav");
                Mix_PlayMusic(music, -1);
                counter++;
            }
        }
        
        // When in Battle
        if(gilbert -> getFight() == true)
        {
            if(counter == 0)
            {
                Mix_FreeMusic(music);
                music = Mix_LoadMUS("Music/Battle.wav");
                Mix_PlayMusic(music, -1);
                counter++;
            }
        }
        
        setup -> end();
    }
}
