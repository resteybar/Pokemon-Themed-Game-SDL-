//
//  Environment.cpp
//  CSS2A_Project
//
//  Created by Raymond Esteybar on 5/10/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#include "Environment.h"

Environment::Environment(double *camX, double *camY, SDL_Setup *setup)
{
    this -> index = 0;
    
    grass[0] = *new Sprite(setup -> getRenderer(), "Images/FightingArea.png", 0 , 0, SCREEN_WIDTH, SCREEN_HEIGHT, camX, camY);
    grass[1] = *new Sprite(setup -> getRenderer(), "Images/background.png", 0 , 0, SCREEN_WIDTH, SCREEN_HEIGHT, camX, camY);
    grass[2] = *new Sprite(setup -> getRenderer(), "Images/FightingBush.png", 262 , 66, 30, 25, camX, camY);
    
    grass[3] = *new Sprite(setup -> getRenderer(), "Images/fighthp/fight50hp.png", 0 , 0, SCREEN_WIDTH, SCREEN_HEIGHT, camX, camY);
    grass[4] = *new Sprite(setup -> getRenderer(), "Images/fighthp/fight40hp.png", 0 , 0, SCREEN_WIDTH, SCREEN_HEIGHT, camX, camY);
    grass[5] = *new Sprite(setup -> getRenderer(), "Images/fighthp/fight30hp.png", 0 , 0, SCREEN_WIDTH, SCREEN_HEIGHT, camX, camY);
    grass[6] = *new Sprite(setup -> getRenderer(), "Images/fighthp/fight20hp.png", 0 , 0, SCREEN_WIDTH, SCREEN_HEIGHT, camX, camY);
    grass[7] = *new Sprite(setup -> getRenderer(), "Images/fighthp/fight10hp.png", 0 , 0, SCREEN_WIDTH, SCREEN_HEIGHT, camX, camY);
    grass[8] = *new Sprite(setup -> getRenderer(), "Images/fighthp/fight1hp.png", 0 , 0, SCREEN_WIDTH, SCREEN_HEIGHT, camX, camY);
    
    grass[9] = *new Sprite(setup -> getRenderer(), "Images/fightEnd.png", 0 , 0, SCREEN_WIDTH, SCREEN_HEIGHT, camX, camY);
}

void Environment::drawBackground()
{
    // Fighting Area + Bush
    if(index == 0 || index == 2)
    {
        grass[index].fightingAreaDraw();
        grass[2].fightingAreaDraw();
    }
    
    // Town Area
    else if(index == 1)
        grass[index].townAreaDraw();
    
    // In Battle Background
    else if(index >= 3)
        grass[index].fightingAreaDraw();
}

void Environment::setIndex(int index)
{
    assert(index >= 0 && index <= 9);
    this -> index = index;
}
