//
//  Magnet.h
//  MagneticGame
//
//  Created by Simon Hem Pedersen on 19/05/15.
//
//

#ifndef __MagneticGame__Magnet__
#define __MagneticGame__Magnet__

#include <stdio.h>
#include "cocos2d.h"

class Magnet
{
    public:
    Magnet(int x, int y, int strength, int magnetRadius);
    
    cocos2d::Sprite* getSprite();
    int strength;
    int radius;
    
    private:
    cocos2d::Sprite* magnetSprite;
};

#endif /* defined(__MagneticGame__Magnet__) */
