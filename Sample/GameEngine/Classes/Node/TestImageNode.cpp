#include "TestImageNode.h"
#include "mathlib.h"
#include "system.h"
#include "Utility.h"
#include "ui.h"
using namespace sys;
using namespace render;
using namespace math;
using namespace ui;
TestImageNode::TestImageNode()
{

}

TestImageNode::~TestImageNode()
{

}

void TestImageNode::initNodes()
{
	testScale9Image();
	//testPointSprite();
}

void TestImageNode::testImage()
{
	auto frameSize = Canvas::getInstance()->getView()->getViewSize();
	
	if (0)
	{
		std::string filepath = "Resource/Image/world.jpg";

		CtrlImage* pImage = CREATE_NODE(CtrlImage);
		pImage->setImagePath(filepath);
		pImage->setAnchorPoint(0.5f, 0.5f);
		pImage->setPosition(512, 384);
		pImage->setVolume(frameSize);
		
		Utility::loadShaderVF(pImage, "Shader/texture/texture.vs", "Shader/texture/texture.fs");
		Utility::loadDefaultShader(pImage);

		this->addChild(pImage);
	}

	if (1)
	{
		std::string filepath = "Resource/Image/2k_earth_specular_map.tif";

		CtrlImage* pImage = CREATE_NODE(CtrlImage);
		pImage->setImagePath(filepath);
		pImage->setAnchorPoint(0.5f, 0.5f);
		pImage->setPosition(512, 384);
		pImage->setVolume(512, 384);
		Utility::loadShaderVF(pImage, "Shader/texture/texture.vs", "Shader/texture/texture.fs");
		Utility::loadDefaultShader(pImage);

		this->addChild(pImage);
	}
}

void TestImageNode::testDifferentImages()
{
	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Model/Obj/SCI_FRS_13_HD/lights_lod0.bmp");
	pImage->setPosition(0, 0, 0);
	pImage->setScale(1, 1, 1);
	pImage->setVolume(100, 100);
	//pImage->setRotation(0, 0, 30);
	this->addChild(pImage);

	pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Model/Obj/SCI_FRS_13_HD/BRAKES.png");
	pImage->setPosition(200, 200, 0);
	pImage->setScale(1, 1, 1);
	pImage->setVolume(100, 100);
	//pImage->setRotation(0, 0, 30);
	this->addChild(pImage);

	pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Model/Obj/SCI_FRS_13_HD/grille2.tga");
	pImage->setPosition(400, 400, 0);
	pImage->setScale(1, 1, 1);
	pImage->setVolume(100, 100);
	//pImage->setRotation(0, 0, 30);
	this->addChild(pImage);

	pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Image/1.jpg");
	pImage->setPosition(600, 600, 0);
	pImage->setScale(1, 1, 1);
	pImage->setVolume(100, 100);
	//pImage->setRotation(0, 0, 30);
	this->addChild(pImage);
}

void TestImageNode::testMoveImage()
{
	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Image/world.jpg");
	pImage->setPosition(512, 384, 0);
	this->addChild(pImage);

	pImage->addTouchDelegate(TouchType::BEGAN, this, TOUCH_DELEGATTE_SELECTOR(TestImageNode::onTouchBegin));

	pImage->addTouchDelegate(TouchType::MOVED, this, TOUCH_DELEGATTE_SELECTOR(TestImageNode::onTouchMove));

	pImage->addTouchDelegate(TouchType::ENDED, this, TOUCH_DELEGATTE_SELECTOR(TestImageNode::onTouchEnd));

	G_KEYBOARDMANAGER->addKeyboardDelegate(this, pImage, KEYBOARD_DELEGATE_SELECTOR(TestImageNode::onKeyBoard));
}

void TestImageNode::onTouchBegin(Node* node, const math::Vector2& touchPoint)
{
	CtrlImage* pNode = node->as<CtrlImage>();
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<math::Vector3>* pAry = new std::vector<math::Vector3>(2);
	(*pAry)[0].set(pNode->getPositionX(), pNode->getPositionY());
	(*pAry)[1] = touchPoint;

	pNode->setUserData(pAry);
}

void TestImageNode::onTouchMove(Node* node, const math::Vector2& touchPoint)
{
	CtrlImage* pNode = node->as<CtrlImage>();
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<math::Vector3>* pAry = static_cast<std::vector<math::Vector3>*>(pNode->getUserData());
	pNode->setPosition((*pAry)[0].getX() + touchPoint.getX() - (*pAry)[1].getX(), (*pAry)[0].getY() + touchPoint.getY() - (*pAry)[1].getY(), 0);
}

void TestImageNode::onTouchEnd(Node* node, const math::Vector2& touchPoint)
{
	CtrlImage* pNode = node->as<CtrlImage>();
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<math::Vector3>* pAry = static_cast<std::vector<math::Vector3>*>(pNode->getUserData());
	SAFE_DELETE(pAry);
}

void TestImageNode::onKeyBoard(Node* node, sys::BoardKey key, sys::ButtonStatus type)
{
	CtrlImage* pNode = node->as<CtrlImage>();
	if (pNode == nullptr)
	{
		return;
	}
	if (type == ButtonStatus::BUTTON_UP)
	{
		return;
	}

	float speed = 5;
	if (key == BoardKey::KW)
	{
		pNode->setPositionY(pNode->getPositionY() + speed);
	}
	else if (key == BoardKey::KS)
	{
		pNode->setPositionY(pNode->getPositionY() - speed);
	}
	else if (key == BoardKey::KA)
	{
		pNode->setPositionX(pNode->getPositionX() - speed);
	}
	else if (key == BoardKey::KD)
	{
		pNode->setPositionX(pNode->getPositionX() + speed);
	}
}

void TestImageNode::testPixelImage()
{
	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Image/sqi.png");
	pImage->setPosition(512, 384, 0);
	this->addChild(pImage);

	CtrlText* pCtrlText = CREATE_NODE(CtrlText);
	pCtrlText->setFontPath("Resource/Font/font_3.ttf");
	pCtrlText->setAnchorPoint(0, 0, 0);
	pCtrlText->setFontSize(58);
	pCtrlText->setString("点击后移动鼠标，改变颜色");
	pCtrlText->setPosition(100, 100, 0);
	pCtrlText->setColor(phy::Color4B(255, 255, 255, 255));
	this->addChild(pCtrlText);

	//pImage->setUserData(pCtrlText);
	pImage->addTouchDelegate(TouchType::MOVED, this, TOUCH_DELEGATTE_SELECTOR(TestImageNode::onTouchImage));
}

void TestImageNode::testPointSprite()
{
	PointSprite* pSprite = CREATE_NODE(PointSprite);
	pSprite->setTexture("Resource/Image/point_sprite.jpg");
	pSprite->setSpriteCount(200);
	pSprite->setPointSize(64);
	pSprite->setPosition(512, 384, 0);
	pSprite->setVolume(512, 384);
	pSprite->setAnchorPoint(0.5f, 0.5f);

	Utility::loadShaderVF(pSprite, "Shader/point_sprite/point_sprite.vs", "Shader/point_sprite/point_sprite.fs");

	this->addChild(pSprite);
}

void TestImageNode::testImages()
{
	std::string filepath = "Resource/Image/world.jpg";

	Node* node = nullptr;
	node = CREATE_NODE(CtrlLayout);
	node->setAnchorPoint(0.0f, 0.0f);
	node->setPosition(0, 0);
	node->setVolume(1024, 768);
	this->addChild(node);

	for (int i = 0; i < 10; i++)
	{
		auto pChild = CREATE_NODE(CtrlImage);
		pChild->setImagePath(filepath);
		pChild->setAnchorPoint(0.0f, 0.0f);
		pChild->setPosition(20 * i, 20 * i);
		pChild->setVolume(200, 200);
		this->addChild(pChild);

		Utility::loadDefaultShader(pChild);
	}

}

void TestImageNode::testScale9Image()
{


	std::string filepath = "Resource/Image/sqi.png";
	/*
	{
		auto pChild = CREATE_NODE(CtrlImage);
		pChild->setImagePath(filepath);
		pChild->setAnchorPoint(0.0f, 0.0f);
		pChild->setPosition(500, 500);
		pChild->setVolume(200, 200);
		this->addChild(pChild);
	}
	*/
	{
		auto pChild = CREATE_NODE(CtrlScale9Image);
		pChild->setImagePath(filepath);
		pChild->setAnchorPoint(0.0f, 0.0f);
		pChild->setVolume(400, 400);
		pChild->setMargin(50, 50, 50, 50);
		this->addChild(pChild);
	}

	//Utility::loadDefaultShader(pChild);
}

void TestImageNode::onTouchImage(Node* node, const math::Vector2& touchPoint)
{
	CtrlImage* pImage = node->as<CtrlImage>();
	if (pImage == nullptr)
	{
		return;
	}
	CtrlText* pText = static_cast<CtrlText*>(pImage->getUserData());
	if (pText == nullptr)
	{
		return;
	}

	phy::Color4B color = Pixel::readPixelColor(touchPoint.getX(), touchPoint.getY());
	pText->setString(getCString("##%02x%02x%02x%02x", color[0], color[1], color[2], color[3]));
	pText->setColor(color);
}
