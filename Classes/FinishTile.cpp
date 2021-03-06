
#include "FinishTile.h"
#include "GameOverLayer.h"
#include <iostream>

USING_NS_CC;

bool FinishTile::init()
{
    if (initWithFile("finish.png")) {
        this->scheduleUpdate();
        return true;
    }
    return false;
}

void FinishTile::update(float delta)
{
    if (timer != nullptr && ball != nullptr && !gameFinished) {
        const Vec2& position = this->getPosition();
        const Size& size = this->getContentSize();
        Rect boundingBox(position.x, position.y, size.width, size.height);
        
        
        if (timer->getTimer() <= 0 || boundingBox.intersectsCircle(ball->getPosition(), ball->getContentSize().width / 2)) {
            auto gameOverLayer = GameOverLayer::create();
            this->getParent()->addChild(gameOverLayer, 1);
            gameOverLayer->show(timer->getTimer() <= 0 ? false : true);
            finishCallback();
            gameFinished = true;
//            auto gameOverScene = GameOverScene::createScene();
//            Director::getInstance()->pushScene(TransitionFade::create(0.5, gameOverScene, Color3B(0,0,0)));
        }
    }
}

void FinishTile::setGameEndedCallback(finishCallBackRef finishCallback) {
    this->finishCallback = finishCallback;
}

void FinishTile::setTimer(TimerLabel* timer) {
    this->timer = timer;
}
