//
//  Character.cpp
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/21/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#include "Character.h"
#include "Text1.h"

Character::Character(SDL_Setup* passedSetup, double* passedBackgroundX, double* passedBackgroundY, Environment* passedEnvironment)
{
    // Passed in RPG.cpp
    this -> background = passedEnvironment;
    
    // Movement Position of Character
    //                      Example: Character's Movement is increasing by "movePos"
    this -> movePos = 10;
    
    // Background's Rectangle
    //                          Preconditions:
    //                              passedBackgroundX = 0
    //                              passedBackgroundY = 0
    this -> backgroundX = passedBackgroundX;
    this -> backgroundY = passedBackgroundY;
    
    // Shop + House Rectangles
//    this -> shop.x;
//    this -> shop.y;
//    this -> shop.w;
//    this -> shop.h;
    
    
    // House Positions
    //                  - Right Side
    //                              ( x == 225 )
    //                              ( h >= 250 && h < 100)
    //
    //                  - Left  Side
    //                              ( x == 55)
    //                              ( h >= 220 && h < 100)
    //                              ( w >= 85  && w < 195)
    
    this -> house.x = 0;
    this -> house.y = 0;
    this -> house.w = 0;
    this -> house.h = 0;
    
    // SDL Setup
    this -> setup = passedSetup;
    
    // Controls
    this -> moveLeft = false;
    this -> moveRight = false;
    this -> moveUp = false;
    this -> moveDown = false;
    
    // Setting up
    this ->  character = new Sprite(setup -> getRenderer(), "Images/Sprite.jpg", 125, 185, CHAR_WIDTH, CHAR_HEIGHT, backgroundX, backgroundY);
    
    this -> character -> setUpAnimation(4, 4);
    this -> character -> playAnimation(0, 0, 0, 100);
    
    this -> timeCheck = SDL_GetTicks();
    
    // Character Development Variables
    lvl = 1;
    exp = 0;
    maxhp = 30;
    //name = "";
    //gender = ' ';
    for(int i = 0; i < 5; i++)
        backpack[i] = "";
    gp = 0;
    item1 = items[0];
    item2 = items[1];
    item3 = items[2];
    item1val = itemVals[0];
    item2val = itemVals[1];
    item3val = itemVals[2];
    
    // Fighting Variables
    this -> fightStart = false;
    this -> quit = false;
    this -> fightDone = false;
    this -> fightCounter = 3;
    
    // Character
    this -> hp = 50;
    this -> damage = 10;
    
    // Monster
    this -> monsterHealth = 50;
    this -> monsterDamage = 10;
}

Character::~Character()
{
    delete character;
    delete background;
}

void Character::update()
{
    // Character's Animation + Position
    updateAnimation();
    updateControl();
}

void Character::updateAnimation()
{
    // Updates the Character's Animation
    //      - Iterates through the Character's Position depending on Direction
    
    switch(setup -> getEvent() -> type)
    {
        case SDL_KEYDOWN:
            switch(setup -> getEvent() -> key.keysym.sym)
        {
            case SDLK_w:
                cout << "↑\n";
                moveUp = true;
                character -> playAnimation(0, 3, 3, 100);
                break;
                
            case SDLK_a:
                cout << "←\n";
                moveLeft = true;
                character -> playAnimation(0, 3, 1, 100);
                break;
                
            case SDLK_d:
                cout << "→\n";
                moveRight = true;
                character -> playAnimation(0, 3, 2, 100);
                break;
                
            case SDLK_s:
                cout << "↓\n";
                moveDown = true;
                character -> playAnimation(0, 3, 0, 100);
                break;
                
            case SDLK_q:
                if(fightStart == true)
                {
                    cout << "User has quit.\n";
                    quit = true;
                }
                break;
                
            case SDLK_x:
                if(fightStart == true)
                {
                    if(fightCounter == 3)
                    {
                        background -> setIndex(fightCounter);
                        fightCounter++;
                        background -> setIndex(fightCounter);
                    }
                    else if(fightCounter >= 4 && fightCounter <= 8)
                    {
                        if(fightCounter == 7)
                        {
                            monsterDamage = 9;
                            damage = 9;
                        }
                        fightCounter++;
                        background -> setIndex(fightCounter);
                    }
                    cout << "ATTACK PRESSED.\n";
                    monsterHealth -= damage;
                    
                    if(monsterHealth <= 0)
                    {
                        fightStart = false;
                        background -> setIndex(9);
                        fightDone = true;
                    }
                }
                break;
                
            default:
                break;
        }
            break;
            
        case SDL_KEYUP:
            switch(setup -> getEvent() -> key.keysym.sym)
        {
            case SDLK_w:
                moveUp = false;
                character -> playAnimation(0, 0, 3, 100);
                break;
                
            case SDLK_a:
                moveLeft = false;
                character -> playAnimation(0, 0, 1, 100);
                break;
                
            case SDLK_d:
                moveRight = false;
                character -> playAnimation(0, 0, 2, 100);
                break;
                
            case SDLK_s:
                moveDown = false;
                character -> playAnimation(0, 0, 0, 100);
                break;
                
            case SDLK_q:
                if(fightStart == true)
                    quit = false;
                break;
                
            case SDLK_x:
                if(fightStart == true)
                    hp -= monsterDamage;
                break;
                
            default:
                break;
        }
            break;
            
        default:
            break;
    }
}

void Character::updateControl()
{
    // Updates Character Position + Background Collision
    
    if(timeCheck + 25 < SDL_GetTicks())
    {
        if(moveRight)
        {
            //cout << "(" << character -> getX() << ", " << character -> getY() << ")\n";
            character -> playAnimation(0, 3, 2, 100);
            character -> setX(character -> getX() + movePos);
            *backgroundX -= 2;
            
            if(character -> getX() < 0 || isCollideBackground() || character -> getX() + character -> getW() > SCREEN_WIDTH + 50)
            {
                character -> playAnimation(0, 3, 2, 100);
                character -> setX(character -> getX() - movePos);
                *backgroundX += 2;
            }
        }
        
        else if(moveLeft)
        {
            //cout << "(" << character -> getX() << ", " << character -> getY() << ")\n";
            character -> playAnimation(0, 3, 1, 100);
            character -> setX(character -> getX() - movePos);
            *backgroundX += 2;
            
            if(character -> getX() < 28 || isCollideBackground() || character -> getX() + character -> getW() > SCREEN_WIDTH + 50)
            {
                character -> playAnimation(0, 3, 1, 100);
                character -> setX(character -> getX() + movePos);
                *backgroundX -= 2;
            }
        }
        
        else if(moveDown)
        {
            //cout << "(" << character -> getX() << ", " << character -> getY() << ")\n";
            character -> playAnimation(0, 3, 0, 100);
            character -> setY(character -> getY() + movePos);
            *backgroundY -= 2;
            
            if(character -> getY() + character -> getH() > SCREEN_HEIGHT + 10)
            {
                //cout << "(" << character -> getX() << ", " << character -> getY() << ")\n";
                character -> playAnimation(0, 3, 0, 100);
                character -> setY(character -> getY() - movePos);
                *backgroundY += 2;
                
                if(character -> getX() >= 225 && character -> getX() <= 325)
                {
                    if(background -> getIndex() != 1)
                    {
                        // Sets Position in Town Area
                        character -> setX(character -> getX());
                        character -> setY(100);
                        background -> setIndex(1);
                    }
                }
            }
        }
        
        else if(moveUp)
        {
            //cout << "(" << character -> getX() << ", " << character -> getY() << ")\n";
            character -> playAnimation(0, 3, 3, 100);
            character -> setY(character -> getY() - movePos);
            *backgroundY += 2;
            
            // Fighting Area
            if(background -> getIndex() == 0)
            {
                if(character -> getY() < 0 || isCollideBackground())
                {
                    //cout << "(" << character -> getX() << ", " << character -> getY() << ")\n";
                    character -> playAnimation(0, 3, 3, 100);
                    character -> setY(character -> getY() + movePos);
                    *backgroundY -= 2;
                    
                    // Fighting commences
                    if(character -> getX() >= 275 && character -> getX() <= 295)
                    {
                        character -> setX(1000);
                        background -> setIndex(3);
                        fightStart = true;
                    }
                }
            }
            
            // Town Area
            if(background -> getIndex() == 1)
                if(character -> getY() < 90 || isCollideBackground())
                {
                    //cout << "(" << character -> getX() << ", " << character -> getY() << ")\n";
                    character -> playAnimation(0, 3, 3, 100);
                    character -> setY(character -> getY() + movePos);
                    *backgroundY -= 2;
                    
                    // Change Area
                    if(character -> getX() >= 225 && character -> getX() <= 335)
                    {
                        // Sets position in Fighting Area
                        character -> setX(character -> getX());
                        character -> setY(455);
                        background -> setIndex(0);
                        //cout << "(" << character -> getX() << ", " << character -> getY() << ")\n";
                    }
                    
                    // >UNUSED COLLISION<
                    if(isCollideHouse())
                    {
                        cout << "******************************\n";
                    }
                }
        }
        timeCheck = SDL_GetTicks();
    }
}

bool Character::isCollideBackground()
{
    return character -> isColliding(background -> getCrectangle());
}

bool Character::isCollideHouse()
{
    return character -> isColliding(house);
}

void Character::draw()
{
    character -> characterDraw();
}
