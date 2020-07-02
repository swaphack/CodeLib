#include "TestImageNode.h"
#include "mathlib.h"
#include "system.h"
#include "Utility.h"
using namespace sys;
using namespace render;
using namespace math;

TestImageNode::TestImageNode()
{

}

TestImageNode::~TestImageNode()
{

}

void TestImageNode::initNodes()
{
	testImage();
	//testPointSprite();
}

void TestImageNode::testImage()
{
	auto frameSize = Canvas::getInstance()->getView()->getFrameSize();
	
	if (0)
	{
		std::string filepath = "Resource/Image/world.jpg";

		CtrlImage* pImage = CREATE_NODE(CtrlImage);
		pImage->setImagePath(filepath);
		pImage->setAnchorPoint(0.5f, 0.5f);
		pImage->setPosition(512, 384);
		pImage->setVolume(frameSize);
		
		Utility::loadShader(pImage, "Shader/texture/texture.vs", "Shader/texture/texture.fs");
		Utility::updateNodeShader(pImage);

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
		Utility::loadShader(pImage, "Shader/texture/texture.vs", "Shader/texture/texture.fs");
		Utility::updateNodeShader(pImage);

		this->addChild(pImage);
	}
}

void TestImageNode::testDifferentImages()
{
	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Obj/SCI_FRS_13_HD/lights_lod0.bmp");
	pImage->setPosition(0, 0, 0);
	pImage->setScale(1, 1, 1);
	pImage->setVolume(100, 100);
	//pImage->setRotation(0, 0, 30);
	this->addChild(pImage);

	pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Obj/SCI_FRS_13_HD/BRAKES.png");
	pImage->setPosition(200, 200, 0);
	pImage->setScale(1, 1, 1);
	pImage->setVolume(100, 100);
	//pImage->setRotation(0, 0, 30);
	this->addChild(pImage);

	pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Obj/SCI_FRS_13_HD/grille2.tga");
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

	pImage->getTouchProxy()->addTouchDelegate(TouchType::DOWN, this, TOUCH_DELEGATTE_SELECTOR(TestImageNode::onTouchBegin));

	pImage->getTouchProxy()->addTouchDelegate(TouchType::ON, this, TOUCH_DELEGATTE_SELECTOR(TestImageNode::onTouchMove));

	pImage->getTouchProxy()->addTouchDelegate(TouchType::UP, this, TOUCH_DELEGATTE_SELECTOR(TestImageNode::onTouchEnd));

	G_KEYBOARDMANAGER->addKeyboardDelegate(this, pImage, KEYBOARD_DELEGATE_SELECTOR(TestImageNode::onKeyBoard));
}

void TestImageNode::onTouchBegin(Node* node, float x, float y, bool include)
{
	CtrlImage* pNode = node->as<CtrlImage>();
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<math::Vector3>* pAry = new std::vector<math::Vector3>(2);
	(*pAry)[0].set(pNode->getPositionX(), pNode->getPositionY());
	(*pAry)[1].set(x, y);

	pNode->setUserData(pAry);
}

void TestImageNode::onTouchMove(Node* node, float x, float y, bool include)
{
	CtrlImage* pNode = node->as<CtrlImage>();
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<math::Vector3>* pAry = static_cast<std::vector<math::Vector3>*>(pNode->getUserData());
	pNode->setPosition((*pAry)[0].getX() + x - (*pAry)[1].getX(), (*pAry)[0].getY() + y - (*pAry)[1].getY(), 0);
}

void TestImageNode::onTouchEnd(Node* node, float x, float y, bool include)
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
	pCtrlText->setFontPath("Resource/font_3.ttf");
	pCtrlText->setAnchorPoint(0, 0, 0);
	pCtrlText->setFontSize(58);
	pCtrlText->setString("点击后移动鼠标，改变颜色");
	pCtrlText->setPosition(100, 100, 0);
	pCtrlText->setColor(sys::Color4B(255, 255, 255, 255));
	this->addChild(pCtrlText);

	//pImage->setUserData(pCtrlText);
	pImage->getTouchProxy()->addTouchDelegate(TouchType::ON, this, TOUCH_DELEGATTE_SELECTOR(TestImageNode::onTouchImage));
}

void TestImageNode::testPointSprite()
{
	CtrlPointSprite* pSprite = CREATE_NODE(CtrlPointSprite);
	pSprite->setTexture("Resource/Image/point_sprite.jpg");
	pSprite->setSpriteCount(200);
	pSprite->setPointSize(64);
	pSprite->setPosition(512, 384, 0);
	pSprite->setVolume(512, 384);
	pSprite->setAnchorPoint(0.5f, 0.5f);

	Utility::loadShader(pSprite, "Shader/point_sprite/point_sprite.vs", "Shader/point_sprite/point_sprite.fs");

	this->addChild(pSprite);
}

void TestImageNode::onTouchImage(Node* node, float x, float y, bool include)
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

	sys::Color4B color = Pixel::readPixelColor(x, y);
	pText->setString(getCString("##%02x%02x%02x%02x", color.red, color.green, color.blue, color.alpha));
	pText->setColor(color);
}
