//
//  TimerLabel.cpp
//  MagneticGame
//
//  Created by Simon Hem Pedersen on 20/05/15.
//
//

#include "TimerLabel.h"
#include <string>
#include <sstream>

USING_NS_CC;


template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}

void TimerLabel::initialize(int x, int y, int startValue, Layer* layer) {
    this->xPos = x;
    this->yPos = y;
    this->startValue = startValue;
    this->parentLayer = layer;
    
    timerLabel = Label::createWithTTF(to_string(startValue), "fonts/arial.ttf", 20);
    timerLabel->setPosition(x, y);
    timer = startValue;
    
    this->addChild(timerLabel);
    parentLayer->addChild(this);
}

void TimerLabel::pause() {
    paused = true;
}

bool TimerLabel::init()
{
    this->scheduleUpdate();
    return true;
}

int TimerLabel::getTimer() {
    return timer;
}

void TimerLabel::update(float delta) {
    if (!paused) {
        currentDelta += delta;
        if (currentDelta > 1) {
            timer--;
            this->timerLabel->setString(to_string(timer));
            currentDelta = 0.0f;
        }
    }
}
