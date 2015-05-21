//
//  HorizontalWall.h
//  MagneticGame
//
//  Created by Simon Hem Pedersen on 20/05/15.
//
//

#ifndef __MagneticGame__HorizontalWall__
#define __MagneticGame__HorizontalWall__

#include <stdio.h>
#include "cocos2d.h"

class HorizontalWall
{
public:
    HorizontalWall(int x, int y, int length, cocos2d::Layer* layer);
    const int wallLength = 16;
};

#endif /* defined(__MagneticGame__HorizontalWall__) */
