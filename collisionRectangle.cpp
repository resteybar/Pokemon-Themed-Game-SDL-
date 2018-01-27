//
//  collisionRectangle.cpp
//  CSS2A_proj_tutorial
//
//  Created by Irais Gopar Osorio on 5/7/17.
//  Copyright © 2017 Irais Gopar Osorio. All rights reserved.
//

#include "collisionRectangle.h"
#include "Libraries.h"

CollisionRectangle::CollisionRectangle()
{
    offsetX = 0;
    offsetY = 0;
    setRectangle(0, 0, 0, 0);
}

CollisionRectangle::CollisionRectangle(int x, int y, int w, int h)
{
    offsetX = x;
    offsetY = y;
    setRectangle(0,0, w, h);
}

void CollisionRectangle::setRectangle(int x, int y, int w, int h)
{
    this -> collisionRectangle.x = x + offsetX;
    this -> collisionRectangle.y = y + offsetY;
    this -> collisionRectangle.w = w;
    this -> collisionRectangle.h = h;
}
