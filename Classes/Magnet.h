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
#include "Box2D/Box2D.h"

class Magnet
{
    public:
    Magnet(int x, int y, int strength, int magnetRadius, b2World* world);
    
    cocos2d::Sprite* getSprite();
    
    private:
    int strength;
    int radius;
    cocos2d::Sprite* magnetSprite;
    b2Body* magnetB2Body;
};

#endif /* defined(__MagneticGame__Magnet__) */
