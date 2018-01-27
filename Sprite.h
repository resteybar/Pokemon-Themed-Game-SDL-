//
//  Sprite.hpp
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/12/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#pragma once

#ifndef Sprite_h
#define Sprite_h

#include "Libraries.h"
#include "SDL_Setup.h"
#include "collisionRectangle.h"

class Sprite : public CollisionRectangle
{
private:
    CollisionRectangle shop;
    CollisionRectangle house;
    CollisionRectangle bush;
    
    SDL_Texture* spriteImage;
    SDL_Texture* Cimage;
    SDL_Texture* Cimage2;
    SDL_Texture* Cimage3;

    SDL_Renderer* renderer;
    SDL_Rect rect;
    SDL_Rect crop;
    SDL_Rect camera;
    
    // Temp to Hold:
    //    1) collisionRect
    //    2) house
    //    3) shop
    SDL_Rect temp;
    SDL_Rect temp2;
    SDL_Rect temp3;
    
    int imgWidth,
        imgHeight;
    
    int currentFrame;
    int animationDelay;
    
    double* camX;
    double* camY;
    
    int frameX,
        frameY;
    
public:
    // Constructor
    //      1) Default
    //      2) Character
    Sprite() {}
    Sprite(SDL_Renderer* passedRenderer, string FilePath, int x, int y, int w , int h, double* camX, double* camY);
    
    // Destructor
    ~Sprite();
    
    // Getters - Accessors
    //  - For SDL_Rect rect
    int getX()const {return rect.x;}
    int getY()const {return rect.y;}
    int getW()const {return rect.w;}
    int getH()const {return rect.h;}
    
    // Setters - Mutators
    //  - For SDL_Rect rect
    void setX(double x);
    void setY(double y);
    
    // Member Methods
    //  1) Drawing Character
    //  2) Drawing Town Area
    //  3) Drawing Fighting Area
    void characterDraw();
    void townAreaDraw();
    void fightingAreaDraw();
    void setPos(double x, double y);
    void setUpAnimation(int passedX, int passedY);
    void playAnimation(int beginFrame, int endFrame, int row, int speed);
    
    bool isColliding(SDL_Rect theCollider);
};

#endif /* Sprite_h */
