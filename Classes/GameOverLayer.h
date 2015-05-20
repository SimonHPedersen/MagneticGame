#ifndef __MagneticGame__GameOverLayer__
#define __MagneticGame__GameOverLayer__

#include "cocos2d.h"

class GameOverLayer  : public cocos2d::LayerColor {
public:
    virtual bool init() override;
    
    void show(bool won);
    void retryCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(GameOverLayer);
private:
};

#endif /* defined(__MagneticGame__GameOverLayer__) */
