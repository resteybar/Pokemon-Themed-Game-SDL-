//
//  Environment.h
//  CSS2A_Project
//
//  Created by Raymond Esteybar on 5/10/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#pragma once

#ifndef Environment_h
#define Environment_h

#include "Libraries.h"
#include "Sprite.h"
#include "SDL_Setup.h"
#include "collisionRectangle.h"

class Environment : public CollisionRectangle
{
protected:
    Sprite grass[10];
    int index;
    
public:
    // Constructor + Destructor
    Environment() {}
    Environment(double *camX, double *camY, SDL_Setup *setup);
    ~Environment() {}
    
    // Getter - Accessor
    //      - To retrieve the index of which Background to choose from
    int getIndex()const {return index;}
    
    // Setter - Mutator
    //      - To change Background after making contact with the path
    void setIndex(int index);
    
    // Member Method
    void drawBackground();
};

#endif /* Environment_h */
