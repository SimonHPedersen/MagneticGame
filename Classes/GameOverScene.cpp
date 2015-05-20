
#include "GameOverScene.h"

USING_NS_CC;

bool GameOverScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    return true;
}

Scene* GameOverScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameOverScene::create();
    scene->setContentSize(Size(200, 200));
    scene->addChild(layer);
    return scene;
}

void GameOverScene::show(bool won)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Sprite *sprite;
    int rand = CCRANDOM_0_1() * 1000;
    if (won) {
        switch (rand % 3) {
            case 0:
                sprite = Sprite::create("won0.png");
                break;
            case 1:
                sprite = Sprite::create("won1.png");
                break;
            default: // 2
                sprite = Sprite::create("won2.png");
                break;
        }
    } else {
        switch (rand % 2) {
            case 0:
                sprite = Sprite::create("lost0.png");
                break;
            default: // 1
                sprite = Sprite::create("lost1.png");
                break;
        }
    }
    addChild(sprite);
//    auto gameScene = MagneticWorld::createScene();
//    Director::getInstance()->pushScene(TransitionFade::create(0.5, gameScene, Color3B(0,0,0)));
}
