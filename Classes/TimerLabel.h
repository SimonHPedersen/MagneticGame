//
//  TimerLabel.h
//  MagneticGame
//
//  Created by Simon Hem Pedersen on 20/05/15.
//
//

#ifndef __MagneticGame__TimerLabel__
#define __MagneticGame__TimerLabel__

#include <stdio.h>

class TimerLabel : public cocos2d::Node
{
public:
    void initialize(int x, int y, int startValue, cocos2d::Layer* layer);
    void pause();
    
    virtual bool init() override;
    virtual void update(float delta);
    
    int getTimer();
    
    CREATE_FUNC(TimerLabel);

    
private:
    int xPos;
    int yPos;
    int startValue;
    int timer;
    float currentDelta = 0.0f;
    cocos2d::Layer* parentLayer;
    cocos2d::Label* timerLabel;
    bool paused = false;
    
};

#endif /* defined(__MagneticGame__TimerLabel__) */
