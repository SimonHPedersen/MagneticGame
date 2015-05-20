
#include "FinishTile.h"
#include <iostream>

USING_NS_CC;

bool FinishTile::init()
{
    if (initWithFile("finish.png")) {
        this->scheduleUpdate();
        return true;
    }
    return false;
}

void FinishTile::update(float delta)
{
    if (ball != nullptr) {
        const Vec2& position = this->getPosition();
        const Size& size = this->getContentSize();
        Rect boundingBox(position.x, position.y, size.width, size.height);
        
        if (boundingBox.intersectsCircle(ball->getPosition(), ball->getContentSize().width / 2)) {
            std::cout << "WE GOT A WINNER!!" << std::endl;
        }
    }
}

