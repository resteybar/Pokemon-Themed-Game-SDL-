//
//  Text.h
//  CSS2A_gameProj
//
//  Created by Irais Gopar Osorio on 5/13/17.
//  Copyright © 2017 Irais Gopar Osorio. All rights reserved.
//

#ifndef Text1_h
#define Text1_h

#include "Libraries.h"
#include <stdio.h>

class LTexture
{
public:
    //Initializes variables
    LTexture();
    
    //Deallocates memory
    ~LTexture();
    
    //Loads image at specified path
    bool loadFromFile( std::string path );
    
    //Creates image from font string
    bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
    
    //Deallocates texture
    void free();
    
    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );
    
    //Set blending
    void setBlendMode( SDL_BlendMode blending );
    
    void show(string message, int index);
    
    //Set alpha modulation
    void setAlpha( Uint8 alpha );
    
    //Renders texture at given point
    void renderPart1(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    void renderPart2(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    
    //Gets image dimensions
    int getWidth();
    int getHeight();
    
private:
    //The actual hardware texture
    SDL_Texture* mTexture;
    
    //Image dimensions
    int mWidth;
    int mHeight;
};

#endif /* Text_h */

//The window we'll be rendering to
//SDL_Window* gWindow = NULL;

//The window renderer
//SDL_Renderer* gRenderer = NULL;

//Globally used font
//TTF_Font *gFont = NULL;

//Rendered texture
//Text1 gTextTexture;
