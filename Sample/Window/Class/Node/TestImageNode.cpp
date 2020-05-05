#include "TestImageNode.h"
#include "mathlib.h"
#include "system.h"

using namespace sys;
using namespace render;
using namespace math;

TestImageNode::TestImageNode()
{

}

TestImageNode::~TestImageNode()
{

}

void TestImageNode::testFunc()
{
	testImage();
}

void TestImageNode::testImage()
{
	auto frameSize = Canvas::getInstance()->getView()->getFrameSize();

	std::string filepath = "Resource/Image/world.jpg";

	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(Vector2());
	//pImage->setVolume(frameSize);
	this->addChild(pImage);
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

	pImage->getTouchProxy()->addTouchDelegate(ETT_DOWN, this, TOUCH_DELEGATTE_SELECTOR(TestImageNode::onTouchBegin));

	pImage->getTouchProxy()->addTouchDelegate(ETT_ON, this, TOUCH_DELEGATTE_SELECTOR(TestImageNode::onTouchMove));

	pImage->getTouchProxy()->addTouchDelegate(ETT_UP, this, TOUCH_DELEGATTE_SELECTOR(TestImageNode::onTouchEnd));

	G_KEYBOARDMANAGER->addDispatcher(pImage, this, KEYBOARD_DELEGATTE_SELECTOR(TestImageNode::onKeyBoard));
}

void TestImageNode::onTouchBegin(sys::Object* object, float x, float y)
{
	CtrlImage* pNode = dynamic_cast<CtrlImage*>(object);
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<math::Vector3>* pAry = new std::vector<math::Vector3>(2);
	(*pAry)[0].set(pNode->getPositionX(), pNode->getPositionY());
	(*pAry)[1].set(x, y);

	pNode->setUserData(pAry);
}

void TestImageNode::onTouchMove(sys::Object* object, float x, float y)
{
	CtrlImage* pNode = dynamic_cast<CtrlImage*>(object);
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<math::Vector3>* pAry = static_cast<std::vector<math::Vector3>*>(pNode->getUserData());
	pNode->setPosition((*pAry)[0].getX() + x - (*pAry)[1].getX(), (*pAry)[0].getY() + y - (*pAry)[1].getY(), 0);
}

void TestImageNode::onTouchEnd(sys::Object* object, float x, float y)
{
	CtrlImage* pNode = dynamic_cast<CtrlImage*>(object);
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<math::Vector3>* pAry = static_cast<std::vector<math::Vector3>*>(pNode->getUserData());
	SAFE_DELETE(pAry);
}

void TestImageNode::onKeyBoard(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type)
{
	CtrlImage* pNode = dynamic_cast<CtrlImage*>(object);
	if (pNode == nullptr)
	{
		return;
	}
	if (type == EBS_BUTTON_UP)
	{
		return;
	}

	float speed = 5;
	if (key == EBK_W)
	{
		pNode->setPositionY(pNode->getPositionY() + speed);
	}
	else if (key == EBK_S)
	{
		pNode->setPositionY(pNode->getPositionY() - speed);
	}
	else if (key == EBK_A)
	{
		pNode->setPositionX(pNode->getPositionX() - speed);
	}
	else if (key == EBK_D)
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
	pImage->getTouchProxy()->addTouchDelegate(ETT_ON, this, TOUCH_DELEGATTE_SELECTOR(TestImageNode::onTouchImage));
}

void TestImageNode::onTouchImage(sys::Object* object, float x, float y)
{
	CtrlImage* pImage = dynamic_cast<CtrlImage*>(object);
	if (pImage == nullptr)
	{
		return;
	}
	CtrlText* pText = static_cast<CtrlText*>(pImage->getUserData());
	if (pText == nullptr)
	{
		return;
	}

	sys::Color4B color = Pixel::getPixel(x, y);
	pText->setString(getCString("##%02x%02x%02x%02x", color.red, color.green, color.blue, color.alpha));
	pText->setColor(color);
}
