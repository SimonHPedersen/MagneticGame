#include "GameScene.h"
#include "Magnet.h"
#include "HorizontalWall.h"
#include "VerticalWall.h"
#include "FinishTile.h"

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
    
    // Tilføj et mål felt:
    auto finishTile = FinishTile::create();
    finishTile->setPosition(Vec2(32, visibleSize.height - 32));
    this->addChild(finishTile);

    /////////////////////////////
    // 3. add your codes below...
    auto magnet1 = new Magnet(400, 400, 100000, 200);
    auto magnetSprite1 = magnet1->getSprite();
    this->addChild(magnetSprite1);

    auto magnet2 = new Magnet(600, 600, -200000, 200);
    auto magnetSprite2 = magnet2->getSprite();
    this->addChild(magnetSprite2);

    auto magnet3 = new Magnet(200, 400, -200000, 200);
    auto magnetSprite3 = magnet3->getSprite();
    this->addChild(magnetSprite3);
    
    auto magnet4 = new Magnet(400, 200, 200000, 200);
    auto magnetSprite4 = magnet4->getSprite();
    this->addChild(magnetSprite4);

    auto magnet5 = new Magnet(800, 100, -100000, 200);
    auto magnetSprite5 = magnet5->getSprite();
    this->addChild(magnetSprite5);
    
    
    magnetList.push_back(magnet1);
    magnetList.push_back(magnet2);
    magnetList.push_back(magnet3);
    magnetList.push_back(magnet4);
    magnetList.push_back(magnet5);
    
    // wall setup
    new HorizontalWall(300, 300, 20, this);
    new HorizontalWall(800, 800, 20, this);
    new HorizontalWall(500, 500, 20, this);
    new HorizontalWall(100, 100, 20, this);
    
    new VerticalWall(10, 50, 20, this);
    new VerticalWall(500, 700, 20, this);
    new VerticalWall(800, 600, 20, this);
    new VerticalWall(700, 100, 20, this);
    
    //setup touch for dragging magnets
    // listen for touch events
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(MagneticWorld::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(MagneticWorld::onTouchesMoved, this);
    listener->onTouchesEnded = CC_CALLBACK_2(MagneticWorld::onTouchesEnded, this);
    listener->onTouchesCancelled = CC_CALLBACK_2(MagneticWorld::onTouchesEnded, this);
    
    this->getEventDispatcher()->
    addEventListenerWithSceneGraphPriority(listener, this);
    
    
    auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);

    //magnet1
    physicsBodyStatic = PhysicsBody::createCircle(30.0f,
                                               PhysicsMaterial(0.1f, 1.0f, 0.0f));
    this->physicsBodyStatic->setDynamic(false);

    
    this->physicsBody = PhysicsBody::createCircle(30.0f,
                                                  PhysicsMaterial(0.1f, 0.3f, 0.0f));
    //set the body isn't affected by the physics world's gravitational force
    this->physicsBody->setGravityEnable(false);

    //set initial velocity of physicsBody
    this->physicsBody->setVelocity(Vec2(1,
                                  1));
    //physicsBody->setTag("Dynamic");

    // add "MagneticWorld" splash screen"
    ballSprite = Sprite::create("ball.png");

    // position the sprite on the center of the screen
    ballSprite->setPosition(Vec2(visibleSize.width/2 + origin.x - 200, visibleSize.height/2 + origin.y + 200));


    ballSprite->setPhysicsBody(this->physicsBody);

    // add the sprite as a child to this layer
    this->addChild(ballSprite, 0);
    
    scheduleUpdate();
    return true;
}

bool MagneticWorld::isTouchingSprite(Sprite* sprite, Touch* touch) {
    float distance = sprite->getPosition().getDistance(this->
                                                       touchToPoint(touch));
    return (distance < 25.0f);
}

Point MagneticWorld::touchToPoint(Touch* touch)
{
    // convert the touch object to a position in our cocos2d space
    return CCDirector::getInstance()->convertToGL(touch->getLocationInView());
}

void MagneticWorld::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{
    // reset touch offset
    this->touchOffset = Point::ZERO;

    for( auto touch : touches )
    {
        // if this touch is within our sprite's boundary
        for ( auto magnet : magnetList) {
            if (touch && this->isTouchingSprite(magnet->getSprite(), touch)) {
                // calculate offset from sprite to touch point
                this->touchOffset = magnet->getSprite()->getPosition() - this->touchToPoint(touch);
            }
        }
    }
}

void MagneticWorld::onTouchesMoved(const std::vector<Touch*>& touches, Event* event)
{
    for( auto touch : touches )
    {
        // set the new sprite position
        if( touch && touchOffset.x && touchOffset.y )
            for ( auto magnet : magnetList) {
                if (this->isTouchingSprite(magnet->getSprite(), touch)) {
                    magnet->getSprite()->setPosition(this->touchToPoint(touch) + this->touchOffset);
                }
            }
    }
}

void MagneticWorld::onTouchesEnded(const std::vector<Touch*>& touches, Event* event)
{
    for( auto touch : touches )
    {
        if( touch && touchOffset.x && touchOffset.y  )
        {
            // set the new sprite position
            for ( auto magnet : magnetList) {
                if (this->isTouchingSprite(magnet->getSprite(), touch)) {
                    magnet->getSprite()->setPosition(this->touchToPoint(touch) + this->touchOffset);

                    // stop any existing actions and reset the scale
                    magnet->getSprite()->stopAllActions();
                    magnet->getSprite()->setScale(1.0f);

                    // animate letting go of the sprite
                    magnet->getSprite()->runAction(Sequence::create(
                                                                    ScaleBy::create(0.125f, 1.111f),
                                                                    ScaleBy::create(0.125f, 0.9f),
                                                                    nullptr
                                                                    ));
                }
            }
        }
    }
}



void MagneticWorld::update(float delta) {
    
    for (std::list<Magnet*>::const_iterator iterator = magnetList.begin(); iterator != magnetList.end(); ++iterator) {
        auto magnet = (*iterator);
        auto xDiff = magnet->getSprite()->getPositionX() - ballSprite->getPositionX();
        auto yDiff = magnet->getSprite()->getPositionY() - ballSprite->getPositionY();
        auto rad2 = xDiff*xDiff + yDiff*yDiff;
        auto distance = sqrt(rad2);
        
        if (distance <= magnet->radius) {
            physicsBody->applyImpulse(Vec2((magnet->strength*xDiff)/rad2, (magnet->strength*yDiff)/rad2)), Vec2(ballSprite->getPositionX(), ballSprite->getPositionY());

        }
        
    }
    

}

void MagneticWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->popScene();
}
