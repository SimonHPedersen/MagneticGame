
#ifndef __MagneticGame__MainMenuScheme__
#define __MagneticGame__MainMenuScheme__

#include "cocos2d.h"

class MainMenuScene : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    
    bool init();
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuNewGameCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(MainMenuScene);
protected:
private:
};

#endif /* defined(__MagneticGame__MainMenuScheme__) */
