
#include "MainMenuScene.h"
#include "GameScene.h"

USING_NS_CC;


Scene* MainMenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainMenuScene::create();
    scene->addChild(layer);
    return scene;
}

bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    ///////////////////////////
    // Header
    auto headerLabel = Label::createWithTTF("MagneticWorld", "fonts/Marker Felt.ttf", 80);
    headerLabel->setTextColor(Color4B::GRAY);
    
    float currentY = origin.y + visibleSize.height - headerLabel->getContentSize().height;
    headerLabel->setPosition(Vec2(origin.x + visibleSize.width/2, currentY));
    this->addChild(headerLabel, 1);
    
    ///////////////////////////
    // Menu
    auto startItem = MenuItemFont::create("- Start -", CC_CALLBACK_1(MainMenuScene::menuNewGameCallback, this));
    startItem->setFontSizeObj(54);
    currentY -= (startItem->getContentSize().height + 80);
    startItem->setPosition(Vec2(origin.x + visibleSize.width/2, currentY));
    
    auto highScoreItem = MenuItemFont::create("- Highscore -", CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
    highScoreItem->setFontSizeObj(54);
    currentY -= (highScoreItem->getContentSize().height + 20);
    highScoreItem->setPosition(Vec2(origin.x + visibleSize.width/2, currentY));
    
    auto closeItem = MenuItemFont::create("- Quit -", CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
    closeItem->setFontSizeObj(54);
    currentY -= (closeItem->getContentSize().height + 120);
    closeItem->setPosition(Vec2(origin.x + visibleSize.width/2, currentY));

    // create menu, it's an autorelease object
    auto menu = Menu::create(startItem, highScoreItem, closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    return true;
}


void MainMenuScene::menuNewGameCallback(cocos2d::Ref* pSender)
{
    auto gameScene = MagneticWorld::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(0.5, gameScene, Color3B(0,0,0)));
}

void MainMenuScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
