//
//  Magnet.cpp
//  MagneticGame
//
//  Created by Simon Hem Pedersen on 19/05/15.
//
//

#include "Magnet.h"

USING_NS_CC;

Magnet::Magnet(int x, int y, int strength, int magnetRadius, b2World* world) {

    magnetSprite = Sprite::create("magnet.png");
    if (strength < 0) {
        magnetSprite->setColor(Color3B::GREEN);
    }
    
    magnetSprite->setAnchorPoint(Vec2(0.5f, 0.5f));
    
    magnetSprite->setPosition(x,y);
    
    auto radius = (magnetSprite->getBoundingBox().getMaxX() - magnetSprite->getBoundingBox().getMinX()) / 2;

    b2BodyDef* myBodyDef;
    myBodyDef->type = b2_staticBody; //this will be a static body
    myBodyDef->position = b2Vec2(x, y);
    myBodyDef->angle = magnetSprite->getRotation() * M_PI/180;
    
    auto body = world->CreateBody(myBodyDef);
    
    b2CircleShape circleShape;
    circleShape.m_p.Set(0,0);
    circleShape.m_radius = radius;
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0;
    fixtureDef.friction = 0.6;
    fixtureDef.restitution = 0.8;
    
    body->CreateFixture(&fixtureDef);
    
    magnetB2Body = body;
    this->strength = strength;
    this->radius = magnetRadius;
}


Sprite * Magnet::getSprite() { return magnetSprite; }

/*
function scene:magnet(x, y, strength, magnetRadius)
--create magnet bitmap object from magnet graphic
        local magnet = Bitmap.new(Texture.new("./magnet.png"))
--reference center of the magnet for positioning
        magnet:setAnchorPoint(0.5,0.5)

magnet:setPosition(x,y)

--get radius
local radius = magnet:getWidth()/2

--create box2d physical object
local body = self.world:createBody{type = b2.STATIC_BODY}
body:setPosition(magnet:getX(), magnet:getY())
body:setAngle(magnet:getRotation() * math.pi/180)


local circle = b2.CircleShape.new(0, 0, radius)
local fixture = body:createFixture{shape = circle, density = 1.0,
        friction = 0.6, restitution = 0.8}
magnet.body = body
magnet.body.type = "ball"

        --set two new properties
--radius of magnetic field
magnet.radius = magnetRadius
        --strength of magnet
        magnet.strength = strength

        --add to scene
        self:addChild(magnet)

--add magnet to mangnets table
        self.magnets[#self.magnets+1] = magnet

--return created object
return magnet
        end
*/