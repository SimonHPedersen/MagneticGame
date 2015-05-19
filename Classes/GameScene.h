#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

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
    
    public:
    // implement the "static create()" method manually
    CREATE_FUNC(MagneticWorld);
    

};

#endif // __HELLOWORLD_SCENE_H__
