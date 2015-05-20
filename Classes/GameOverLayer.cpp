
#include "GameOverLayer.h"
#include "GameScene.h"

USING_NS_CC;

bool GameOverLayer::init()
{
    if (LayerColor::initWithColor(Color4B(0, 0, 0, 125), 400, 200)) {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        this->setPosition(visibleSize.width / 2 - 200, visibleSize.height / 2 - 100);
        
        auto retryItem = MenuItemFont::create("- Retry -", CC_CALLBACK_1(GameOverLayer::retryCallback, this));
        retryItem->setAnchorPoint(Vec2(0, 1));
        retryItem->setFontSizeObj(34);
        retryItem->setPosition(200 - (retryItem->getContentSize().width / 2), 100);
        
        auto menu = Menu::create(retryItem, NULL);
        menu->setPosition(Vec2::ZERO);
        this->addChild(menu, 1);
        
        return true;
    }
    return false;
}

void GameOverLayer::show(bool won)
{
    Sprite *sprite;
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
    sprite->setAnchorPoint(Vec2(0, 1));
    sprite->setPosition(40,
                        this->getContentSize().height - 10);
    addChild(sprite);
    if (won) {
        auto emitter = ParticleFireworks::create();
        emitter->setPosition(40, this->getContentSize().height - 10);
        addChild(emitter, 10);
    }
    
    auto gameOverLabel = Label::createWithTTF("Game Over!", "fonts/Marker Felt.ttf", 50);
    gameOverLabel->setAnchorPoint(Vec2(0, 1));
    gameOverLabel->setPosition(Vec2(sprite->getContentSize().width + 60,
                                    this->getContentSize().height - 20));
    addChild(gameOverLabel);
    
    setVisible(true);
}

void GameOverLayer::retryCallback(cocos2d::Ref* pSender)
{
    auto gameScene = MagneticWorld::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, gameScene, Color3B(0,0,0)));
}
