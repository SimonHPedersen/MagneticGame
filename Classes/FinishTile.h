
#ifndef __MagneticGame__FinishTile__
#define __MagneticGame__FinishTile__

#include "cocos2d.h"
#include "TimerLabel.h"

typedef std::function<void()> finishCallBackRef;

class FinishTile : public cocos2d::Sprite {
public:
    FinishTile() : ball(nullptr) {}

    virtual bool init() override;
    virtual void update(float delta);
    
    void setBall(cocos2d::Sprite* ball) { this->ball = ball; }
    
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    
    CREATE_FUNC(FinishTile);

    void setGameEndedCallback(finishCallBackRef param);
    void setTimer(TimerLabel* timer);

protected:
    cocos2d::Sprite* ball;
    finishCallBackRef finishCallback;
    bool gameFinished = false;
    TimerLabel* timer;
};

#endif /* defined(__MagneticGame__FinishTile__) */
