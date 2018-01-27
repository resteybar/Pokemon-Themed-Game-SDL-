//
//  collisionRectangle.hpp
//  CSS2A_proj_tutorial
//
//  Created by Irais Gopar Osorio on 5/7/17.
//  Copyright © 2017 Irais Gopar Osorio. All rights reserved.
//

#pragma once

#ifndef collisionRectangle_h
#define collisionRectangle_h

#include "Libraries.h"

class CollisionRectangle
{
protected:
    int offsetX;
    int offsetY;
    
    SDL_Rect collisionRectangle;
    
public:
    CollisionRectangle();
    CollisionRectangle(int x, int y, int w, int h);
    ~CollisionRectangle() {}
    
    void setRectangle(int x, int y, int w, int h);
    SDL_Rect getCrectangle()const {return collisionRectangle;}
    
    void setX(int x){collisionRectangle.x = x + offsetX;}
    void setY(int y){collisionRectangle.y = y + offsetY;}
};

#endif /* collisionRectangle_hpp */
