
#ifndef __MagneticGame__FinishTile__
#define __MagneticGame__FinishTile__

#include "cocos2d.h"

class FinishTile : public cocos2d::Sprite {
public:
    FinishTile() : ball(nullptr) {}
    
    virtual bool init() override;
    virtual void update(float delta);
    
    void setBall(cocos2d::Sprite* ball) { this->ball = ball; }
    
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    
    CREATE_FUNC(FinishTile);
protected:
    cocos2d::Sprite* ball;
};

#endif /* defined(__MagneticGame__FinishTile__) */
