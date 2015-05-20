//
//  TimerLabel.cpp
//  MagneticGame
//
//  Created by Simon Hem Pedersen on 20/05/15.
//
//

#include "TimerLabel.h"

USING_NS_CC;

void TimerLabel::initialize(int x, int y, int startValue, Layer* layer) {
    this->xPos = x;
    this->yPos = y;
    this->startValue = startValue;
    this->parentLayer = layer;
    
    timerLabel = Label::createWithTTF(std::to_string(startValue), "fonts/arial.ttf", 20);
    timerLabel->setPosition(x, y);
    timer = startValue;
    
    this->addChild(timerLabel);
    parentLayer->addChild(this);
}

bool TimerLabel::init()
{
    this->scheduleUpdate();
    return true;
}

void TimerLabel::update(float delta) {
    currentDelta += delta;
    if (currentDelta > 1) {
        timer--;
        this->timerLabel->setString(std::to_string(timer));
        currentDelta = 0.0f;
    }
}
