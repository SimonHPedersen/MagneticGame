
#include "GameOverLayer.h"

USING_NS_CC;

bool GameOverLayer::init()
{
    if (!Layer::init()) {
        setContentSize(Size(200, 200));
        setColor(Color3B::GRAY);
        return false;
    }
    return true;
}

void GameOverLayer::show(bool won)
{
    Sprite *sprite;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    int rand = cocos2d::random(0, RAND_MAX);
    if (won) {
        switch (rand % 3) {
            case 0:
                sprite = Sprite::create("won1.png");
                break;
            case 1:
                sprite = Sprite::create("won2.png");
                break;
            default: // 2
                sprite = Sprite::create("won3.png");
                break;
        }
    } else {
        switch (rand % 2) {
            case 0:
                sprite = Sprite::create("lost1.png");
                break;
            default: // 1
                sprite = Sprite::create("lost2.png");
                break;
        }
    }
    addChild(sprite);
    this->setVisible(true);
}
