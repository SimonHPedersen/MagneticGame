#include "GameScene.h"

USING_NS_CC;

Scene* MagneticWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    
    // 'layer' is an autorelease object
    auto layer = MagneticWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);

    layer->setPhyWorld(scene->getPhysicsWorld());
    
    // return the scene
    return scene;
}

void MagneticWorld::setPhyWorld(cocos2d::PhysicsWorld *world) {
    m_world = world;
    
    auto joint = PhysicsJointSpring::construct(physicsBody, physicsBodyStatic, Vec2(0,0), Vec2(0,0), 1.0f, 1.0f);
    auto joint2 = PhysicsJointSpring::construct(physicsBody, physicsBodyStatic2, Vec2(0,0), Vec2(0,0), 10.0f, 0.0f);
    auto joint3 = PhysicsJointSpring::construct(physicsBody, physicsBodyStatic3, Vec2(0,0), Vec2(0,0), 10.0f, 0.0f);
    m_world->addJoint(joint);
    m_world->addJoint(joint2);
    m_world->addJoint(joint3);
}

// on "init" you need to initialize your instance
bool MagneticWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MagneticWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);

    //magnet1
    physicsBodyStatic = PhysicsBody::createCircle(30.0f,
                                               PhysicsMaterial(0.1f, 1.0f, 0.0f));
    this->physicsBodyStatic->setDynamic(false);

    //create a sprite
    auto sprite = Sprite::create("magnet.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x + 200, visibleSize.height/2 + origin.y + 200));
    //apply physicsBody to the sprite
    sprite->setPhysicsBody(physicsBodyStatic);

    addChild(sprite);

    //magnet2
    physicsBodyStatic2 = PhysicsBody::createCircle(30.0f,
                                                   PhysicsMaterial(0.1f, 1.0f, 0.0f));
    this->physicsBodyStatic2->setDynamic(false);
    
    auto sprite2 = Sprite::create("magnet.png");
    sprite2->setPosition(Vec2(visibleSize.width/2 + origin.x - 200, visibleSize.height/2 + origin.y - 200));
    //apply physicsBody to the sprite
    sprite2->setPhysicsBody(physicsBodyStatic2);

    addChild(sprite2);

    
    //magnet3
    physicsBodyStatic3 = PhysicsBody::createCircle(30.0f,
                                                   PhysicsMaterial(0.1f, 1.0f, 0.0f));
    this->physicsBodyStatic3->setDynamic(false);
    
    auto sprite3 = Sprite::create("magnet.png");
    sprite3->setPosition(Vec2(visibleSize.width/2 + origin.x + 200, visibleSize.height/2 + origin.y - 200));
    //apply physicsBody to the sprite
    sprite3->setPhysicsBody(physicsBodyStatic3);
    
    addChild(sprite3);
    

    this->physicsBody = PhysicsBody::createCircle(30.0f,
                                                  PhysicsMaterial(0.1f, 1.0f, 0.0f));
    //set the body isn't affected by the physics world's gravitational force
    this->physicsBody->setGravityEnable(false);

    //set initial velocity of physicsBody
    this->physicsBody->setVelocity(Vec2(20,
                                  20));
    //physicsBody->setTag("Dynamic");

    // add "MagneticWorld" splash screen"
    auto spriteBall = Sprite::create("ball.png");

    // position the sprite on the center of the screen
    spriteBall->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));


    spriteBall->setPhysicsBody(this->physicsBody);

    // add the sprite as a child to this layer
    this->addChild(spriteBall, 0);
    
    return true;
}

void MagneticWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->popScene();
}
