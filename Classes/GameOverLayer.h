#ifndef __MagneticGame__GameOverLayer__
#define __MagneticGame__GameOverLayer__

#include "cocos2d.h"

class GameOverLayer  : public cocos2d::Layer {
public:
    virtual bool init() override;
    
    void show(bool won);
    
    CREATE_FUNC(GameOverLayer);
private:
};

#endif /* defined(__MagneticGame__GameOverLayer__) */
