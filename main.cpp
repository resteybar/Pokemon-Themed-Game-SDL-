//
//  Main_RPG.cpp
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/6/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#include "RPG.h"
#include "Text1.h"
#include "Libraries.h"
#include "Intro.h"

int main()
{
    // MUSIC
    Mix_Music* music;
    
    string message, message2;
    message = "Brought to you by:";
    message2 = "R.I.G. Gaming";

    LTexture text = *new LTexture();
    text.show(message, 0);
    text.show(message2, 1);
    
    Intro intro = *new Intro();
    
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    music = Mix_LoadMUS("Music/Intro.wav");
    Mix_PlayMusic(music, -1);
    
    intro.showUp();
    
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    
    RPG* main = new RPG();
    
    main -> gameLoop();
    
    delete main;
    
    return 0;
}
