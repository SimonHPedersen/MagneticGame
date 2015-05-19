#include "GameScene.h"

USING_NS_CC;

Scene*MagneticWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    
    // 'layer' is an autorelease object
    auto layer = MagneticWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
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

    auto physicsBodyStatic = PhysicsBody::createBox(Size(65.0f, 81.0f),
                                              PhysicsMaterial(0.1f, 1.0f, 0.0f));
    physicsBodyStatic->setDynamic(false);

    //create a sprite
    auto sprite = Sprite::create("CloseSelected.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x + 100, visibleSize.height/2 + origin.y + 100));
    addChild(sprite);

    //apply physicsBody to the sprite
    sprite->setPhysicsBody(physicsBodyStatic);

    auto physicsBody = PhysicsBody::createBox(Size(65.0f, 81.0f),
                                         PhysicsMaterial(0.1f, 1.0f, 0.0f));
    //set the body isn't affected by the physics world's gravitational force
    physicsBody->setGravityEnable(false);

    //set initial velocity of physicsBody
    physicsBody->setVelocity(Vec2(50,
                                  50));
    //physicsBody->setTag("Dynamic");

    // add "MagneticWorld" splash screen"
    auto spriteBall = Sprite::create("CloseNormal.png");

    // position the sprite on the center of the screen
    spriteBall->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));


    spriteBall->setPhysicsBody(physicsBody);

    // add the sprite as a child to this layer
    this->addChild(spriteBall, 0);

    auto joint = PhysicsJointSpring::construct(physicsBody, physicsBodyStatic, Vec2(0,0), Vec2(0,0), 100.0f, 0.9f);

    return true;
}


void MagneticWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
