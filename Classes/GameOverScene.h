#ifndef __MagneticGame__GameOverScene__
#define __MagneticGame__GameOverScene__

#include "cocos2d.h"

class GameOverScene  : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    
    void show(bool won);
    
    CREATE_FUNC(GameOverScene);
private:
};

#endif /* defined(__MagneticGame__GameOverScene__) */
