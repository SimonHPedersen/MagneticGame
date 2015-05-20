//
//  Magnet.cpp
//  MagneticGame
//
//  Created by Simon Hem Pedersen on 19/05/15.
//
//

#include "Magnet.h"

USING_NS_CC;

Magnet::Magnet(int x, int y, int strength, int magnetRadius) {

    magnetSprite = Sprite::create("magnet.png");
    if (strength < 0) {
        magnetSprite->setColor(Color3B::GREEN);
    }
    
    magnetSprite->setAnchorPoint(Vec2(0.5f, 0.5f));
    
    magnetSprite->setPosition(x,y);
    
    float scale = abs(strength)*1.0 / 100000;
    
    magnetSprite->setScale(scale, scale);
    
    auto physicsBody = PhysicsBody::createCircle(10.0f,
                                                   PhysicsMaterial(0.1f, 1.0f, 0.0f));
    physicsBody->setDynamic(false);
    
    magnetSprite->setPhysicsBody(physicsBody);
    
    this->strength = strength;
    this->radius = magnetRadius;
}


Sprite * Magnet::getSprite() { return magnetSprite; }