//
//  HorizontalWall.h
//  MagneticGame
//
//  Created by Simon Hem Pedersen on 20/05/15.
//
//

#ifndef __MagneticGame__VerticalWall__
#define __MagneticGame__VerticalWall__

#include <stdio.h>

class VerticalWall
{
public:
    VerticalWall(int x, int y, int length, cocos2d::Layer* layer);
    const int wallLength = 16;
};

#endif /* defined(__MagneticGame__VerticalWall__) */
