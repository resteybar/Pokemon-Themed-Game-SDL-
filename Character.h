//
//  Character.h
//  SDL_Tutorial
//
//  Created by Raymond Esteybar on 4/18/17.
//  Copyright © 2017 Raymond Esteybar. All rights reserved.
//

#ifndef Character_h
#define Character_h

#include "Sprite.h"
#include "SDL_Setup.h"
#include "Environment.h"
#include "Text1.h"

class Character
{
protected:
    // Background + Character Variables
    Sprite* character;
    Environment* background;
    LTexture mes;
    
    // Rectangles for House + Shop
    SDL_Rect house;
    SDL_Rect shop;
    
    double* backgroundX;
    double* backgroundY;
    
    bool moveRight,
    moveLeft,
    moveUp,
    moveDown;
    
    int movePos;
    
    // Set Up for Window
    SDL_Setup* setup;
    
    // Character Development Variables
    int timeCheck;
    int lvl, exp, hp, maxhp;
    //string name;
    string message;
    //char gender;
    string backpack[5];
    int gp;
    string item1, item2, item3;
    int item1val, item2val, item3val;
    int damage;
    
    // Fight Variables
    bool fightStart;
    bool quit;
    bool fightDone;
    int fightCounter;
    
    // Monster
    int monsterHealth,
        monsterDamage;
    
public:
    // Constructors
    Character();
    Character(SDL_Setup* passedSetup, double* passedBackgroundX, double* passedBackgroundY, Environment* passedEnvironment);
    
    // Destructor
    ~Character();
    
    // Getter - Accessor
    bool getFight()const {return fightStart;}
    bool getQuit()const {return quit;}
    bool getFightDone()const {return fightDone;}
    
    // Member Methods
    void draw();
    void loadFight();
    void update();
    void updateControl();
    void updateAnimation();
    bool isCollideBackground();
    bool isCollideHouse();
    
    // Character Development Methods
    void addLvl(); // done
    void addExp(int x);
    void addHp(int x);
    void setDamage();
    void goHome();
    void create();
    int getDamage()const{return damage;}
    void setHealth(int hp){this->hp = hp;}
    void removeHealth(int x);
    int getMaxHealth()const{return maxhp;}
    void addGold(int x); //done
    void removeGold(int amount);
    void addItem(string item); //done
    void removeItem(); //done
    void removeItemStore(int choice); //done
    int getGP()const{return gp;} //done
    void sellItem(); //done
    friend ostream& operator <<(ostream& out, const Character& p1); // done
    //void setName(string name){this->name = name;} //done
    //void setGen(char gender){this->gender = gender;} //done
    string useItems();
    int getHealth()const{return hp;}
    int getCharLvl()const{return lvl;}
    //string getName()const {return name;}
    string items[12] = {"Wood Sword", "Wood Shield", "Minor Health Potion", "Steel Sword", "Steel Shield", "Regular Health potion", "Fire Sword", "Fire Shield", "Large Health Potion", "Stick", "Rock", "Leaf"}; //done
    int itemVals[12] = {5,2,2,10,5,5,15,10,10,1,1,1}; //done
};

#endif /* Character_h */
