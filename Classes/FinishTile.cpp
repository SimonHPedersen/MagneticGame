
#include "FinishTile.h"
#include <iostream>

USING_NS_CC;

bool FinishTile::init()
{
    if (initWithFile("finish.png")) {
        auto body = PhysicsBody::createBox(getContentSize(), PhysicsMaterial(), Vec2::ZERO);
        setPhysicsBody(body);
        
        body->setContactTestBitmask(0xFFFFFFFF);
        body->setDynamic(false);
        
        auto contactListener = EventListenerPhysicsContact::create();
        contactListener->onContactBegin = CC_CALLBACK_1(FinishTile::onContactBegin, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
        
        return true;
    }
    return false;
}

bool FinishTile::onContactBegin(cocos2d::PhysicsContact& contact)
{
    std::cout << "onContactBegin" << std::endl;
    return false;
}
