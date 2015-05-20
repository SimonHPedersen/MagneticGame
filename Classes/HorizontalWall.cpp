//
//  HorizontalWall.cpp
//  MagneticGame
//
//  Created by Simon Hem Pedersen on 20/05/15.
//
//

#include "HorizontalWall.h"

USING_NS_CC;

HorizontalWall::HorizontalWall(int x, int y, int length, Layer* layer) {
    for (int i = 0; i < length; i++) {
        auto wallPiece = Sprite::create("wall.png");
        
        wallPiece->setAnchorPoint(Vec2(0.5f, 0.5f));
        
        wallPiece->setPosition(x + i * wallLength,y);
        
        auto physicsBody = PhysicsBody::createBox(Size(16.0f , 16.0f),
                                                     PhysicsMaterial(0.1f, 1.0f, 0.0f));
        physicsBody->setDynamic(false);
        
        wallPiece->setPhysicsBody(physicsBody);
        
        layer->addChild(wallPiece);
    }
}