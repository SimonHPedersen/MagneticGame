#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Magnet.h"
#include "TimerLabel.h"

class MagneticWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    void setPhyWorld(cocos2d::PhysicsWorld* world);
    
    private:
    cocos2d::PhysicsWorld* m_world;
    cocos2d::PhysicsBody* physicsBody;
    cocos2d::PhysicsBody* physicsBodyStatic;
    cocos2d::PhysicsBody* physicsBodyStatic2;
    cocos2d::PhysicsBody* physicsBodyStatic3;
    cocos2d::Sprite* ballSprite;
    virtual void update(float delta);
    std::list<Magnet*> magnetList;
    cocos2d::Vec2 touchOffset;
    TimerLabel* timerLabel;
    bool paused = false;
    
    public:
    // implement the "static create()" method manually
    CREATE_FUNC(MagneticWorld);

    bool isTouchingSprite(cocos2d::Sprite *sprite, cocos2d::Touch *touch);

    cocos2d::Point touchToPoint(cocos2d::Touch *touch);

    void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);

    void onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);

    void onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);

    void gameEnded();
};

#endif // __HELLOWORLD_SCENE_H__
