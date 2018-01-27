//
//  Sprite.cpp
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/12/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#include "Sprite.h"
#include "collisionRectangle.h"

Sprite::Sprite(SDL_Renderer* passedRenderer, string FilePath, int x, int y, int w , int h, double* camX, double* camY)
{
    this -> renderer = passedRenderer;
    this -> spriteImage = NULL;
    this -> spriteImage = IMG_LoadTexture(renderer, FilePath.c_str());
    
    if(spriteImage == NULL)
        cout << "Error, could not open " << FilePath.c_str() << ".\n";
    
    this -> Cimage = NULL;
    this ->  Cimage = IMG_LoadTexture(renderer,"Images/rect.png");
    
    if(Cimage == NULL)
        cout << "Error, could not open " << "cImage.\n";
    
    // Sprite's Size
    this -> rect.x = x;
    this -> rect.y = y;
    this -> rect.w = w;
    this -> rect.h = h;
    
    SDL_QueryTexture(spriteImage, NULL, NULL, &imgWidth, &imgHeight);
    
    this -> crop.x = 0;
    this -> crop.y = 0;
    this -> crop.w = imgWidth;
    this -> crop.h = imgHeight;
    
    // For playAnimation() Function
    this -> frameX = 0;
    this -> frameY = 0;
    this -> currentFrame = 0;
    
    // Camera Control
    this -> camX = camX;
    this -> camY = camY;
    
    this -> camera.x = rect.x;
    this -> camera.y = rect.y;
    this -> camera.w = rect.w;
    this -> camera.h = rect.h;
    
    // Temporary Variables
    this -> temp = getCrectangle();
}

Sprite::~Sprite()
{
}

void Sprite::setUpAnimation(int passedX, int passedY)
{
    this -> frameX = passedX;
    this -> frameY = passedY;
}

void Sprite::playAnimation(int beginFrame, int endFrame, int row, int speed)
{
    if(animationDelay + speed < SDL_GetTicks())
    {
        if(endFrame <= currentFrame)
            currentFrame = beginFrame;
        else
            currentFrame++;
        
        crop.x = currentFrame * (imgWidth/frameX);
        crop.y = row * (imgHeight/frameY);
        crop.w = imgWidth/frameX;
        crop.h = imgHeight/frameY;
        
        animationDelay = SDL_GetTicks();
    }
}

void Sprite::fightingAreaDraw()
{
    SDL_RenderCopy(renderer, spriteImage, &crop, &rect);
}

void Sprite::townAreaDraw()
{
    temp2 = house.getCrectangle();
    temp3 = shop.getCrectangle();
    temp3 = bush.getCrectangle();
    camera.x = rect.x;
    
    if(rect.y + *camY > 0 || rect.y + *camY < SCREEN_HEIGHT - 10)
        camera.y = rect.y;
    else if(rect.y + *camY > SCREEN_HEIGHT)
        camera.y = rect.y + *camY;
    
    collisionRectangle.x = rect.x + *camX + offsetX;
    collisionRectangle.y = rect.y + *camY + offsetY;
    
    house.setX(rect.x + *camX);
    house.setY(rect.y + *camY);
    
    shop.setX(rect.x + *camX);
    shop.setY(rect.y + *camY);
    
    SDL_RenderCopy(renderer, spriteImage, &crop, &camera);
    SDL_RenderCopy(renderer, spriteImage, NULL , &temp);
    SDL_RenderCopy(renderer, spriteImage, NULL , &temp2);
    SDL_RenderCopy(renderer, spriteImage, NULL, &temp3);
}

void Sprite::characterDraw()
{
    camera.x = rect.x + *camX;
    camera.y = rect.y + *camY;
    
    SDL_RenderCopy(renderer, spriteImage, &crop, &camera);
}

void Sprite::setX(double x)
{
    this -> rect.x = x;
}

void Sprite::setY(double y)
{
    this -> rect.y = y;
}

void Sprite::setPos(double x, double y)
{
    this -> rect.x = x;
    this -> rect.y = y;
}

bool Sprite::isColliding(SDL_Rect theCollider)
{
    // Character
    int leftA = collisionRectangle.x;
    int rightA = collisionRectangle.x + collisionRectangle.w;
    int topA = collisionRectangle.y;
    int bottomA = collisionRectangle.y + collisionRectangle.h;
    
    // Background + Objects
    int leftB = theCollider.x;
    int rightB = theCollider.x + theCollider.w;
    int topB = theCollider.y;
    int bottomB = theCollider.y + theCollider.h;
    
    return !(leftA >= rightB || rightA <= leftB || topA >= bottomB || bottomA <= topB);
}
