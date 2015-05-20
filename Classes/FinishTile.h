
#ifndef __MagneticGame__FinishTile__
#define __MagneticGame__FinishTile__

#include "cocos2d.h"

class FinishTile : public cocos2d::Sprite {
public:
    virtual bool init() override;
    
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    
    CREATE_FUNC(FinishTile);
protected:
};

#endif /* defined(__MagneticGame__FinishTile__) */
