#include "WndRender.h"

using namespace render;
using namespace sys;

WndRender::WndRender()
{
	this->init();
	this->getCanvas()->setDimensions(render::ED_2D);
}

WndRender::~WndRender()
{
	this->dispose();
}

void WndRender::show()
{
	// for 3d

	//this->testFog();
	//this->testModel();

	this->testImage();

	this->testText();

	//this->testMask();

	//this->testMedia();

// 	TestDrawNode* pTestDrawNode = new TestDrawNode();
// 	pTestDrawNode->setScale(0.125f, 0.125f, 0.125f);
// 	pTestDrawNode->setPosition(200, 100, 0);
// 	AUTO_RELEASE_OBJECT(pTestDrawNode);
// 	this->getCanvas()->getRoot()->addChild(pTestDrawNode);

	//this->testParticle();

}

void WndRender::testImage()
{
	CtrlImage* pImage = new CtrlImage();
	pImage->setImagePath("Resource/sqi.png");
	pImage->setPosition(512, 384, 0);
	//pImage->setRectVisible(true);
	//pImage->setRectColor(sys::Color4B(255, 0, 0, 255));
	//pImage->setVolume(200, 200, 0);
	AUTO_RELEASE_OBJECT(pImage);
	this->getCanvas()->getRoot()->addChild(pImage);

	
// 	pImage = new CtrlImage();
// 	pImage->setImagePath("Resource/sqi.png");
// 	pImage->setPosition(500, 350, 0);
// 	AUTO_RELEASE_OBJECT(pImage);
// 	this->getCanvas()->getRoot()->addChild(pImage);
// 
// 	pImage = new CtrlImage();
// 	pImage->setImagePath("Resource/sqi.png");
// 	pImage->setPosition(550, 384, 0);
// 	AUTO_RELEASE_OBJECT(pImage);
// 	this->getCanvas()->getRoot()->addChild(pImage);
// 
// 	pImage = new CtrlImage();
// 	pImage->setImagePath("Resource/sqi.png");
// 	pImage->setPosition(450, 350, 0);
// 	AUTO_RELEASE_OBJECT(pImage);
// 	this->getCanvas()->getRoot()->addChild(pImage);
	
}

void WndRender::testClock()
{
	LineNode* pSecondLineNode = new LineNode();
	AUTO_RELEASE_OBJECT(pSecondLineNode);

	pSecondLineNode->setWidth(2);
	pSecondLineNode->setPosition(512, 384, 0);
	pSecondLineNode->setSource(0, 0);
	pSecondLineNode->setDestination(300, 300);
	//pSecondLineNode->setColor(sys::Color4B(255, 120, 0, 255));
	
	this->getCanvas()->getRoot()->addChild(pSecondLineNode);

	LineNode* pMinuteLineNode = new LineNode();
	AUTO_RELEASE_OBJECT(pMinuteLineNode);
	pMinuteLineNode->setWidth(5);
	pMinuteLineNode->setPosition(512, 384, 0);
	pMinuteLineNode->setSource(0, 0);
	pMinuteLineNode->setDestination(300, 300);
	pMinuteLineNode->setColor(sys::Color4B(255, 0, 0, 255));
	
	this->getCanvas()->getRoot()->addChild(pMinuteLineNode);
 
// 	LineNode* pHourLineNode = new LineNode();
// 	pHourLineNode->setWidth(10);
// 	pHourLineNode->setPosition(512, 384, 0);
// 	pHourLineNode->setSource(0, 0);
// 	pHourLineNode->setDestination(300, 300);
// 	pHourLineNode->setColor(sys::Color4B(255, 120, 0, 255));
// 	AUTO_RELEASE_OBJECT(pHourLineNode);
// 	this->getCanvas()->getRoot()->addChild(pHourLineNode);

	float ratio = 0.5;
	int count = 1024;

	RotateToAction* pSecondAction = new RotateToAction();
	pSecondAction->setRotation(0, 0, 360 * count);
	pSecondAction->setInterval(ratio * 60 * count);
	pSecondLineNode->getActionProxy()->runAction(pSecondAction);

	RotateToAction* pMinuteAction = new RotateToAction();
	pMinuteAction->setRotation(0, 0, 360 * count);
	pMinuteAction->setInterval(ratio * 60 * 60 * count);
	pMinuteLineNode->getActionProxy()->runAction(pMinuteAction);
}

void WndRender::testModel()
{
	ImageDefine imageDefine = { "Resource/NeHe.png"};
	Texture2D* texture2D = G_TEXTURE_CACHE->getTexture2D(imageDefine);

	TexFrame* frame = new TexFrame();
	AUTO_RELEASE_OBJECT(frame);
	frame->setTextureWithRect(texture2D);

	CtrlModel* pModel = new CtrlModel();
	AUTO_RELEASE_OBJECT(pModel);
	pModel->setAllFacesFrame(frame);
	pModel->setPosition(512, 384, 0);
	pModel->setVolume(256.0f, 256.0f, 256.0f);
	pModel->getMatrial()->setShiness(1.0f);
	pModel->getMatrial()->setAmbient(255, 255, 255, 255);
	pModel->getMatrial()->setDiffuse(255, 255, 255, 255);
	pModel->getMatrial()->setSpecular(255, 255, 255, 255);
	pModel->getMatrial()->setEmisiion(255, 255, 255, 255);
	this->getCanvas()->getRoot()->addChild(pModel);

	int count = 1024;
	float interval = 5;
	float rx = 45;
	float ry = 45;
	float rz = 0;
	RotateToAction* pRotateToAction = new RotateToAction();
	pRotateToAction->setRotation(rx * count, ry * count, rz * count);
	pRotateToAction->setInterval(interval * count);
	pModel->getActionProxy()->runAction(pRotateToAction);

	CtrlSpotLight1* pCtrlSpotLight = new CtrlSpotLight1();
	AUTO_RELEASE_OBJECT(pCtrlSpotLight);
	pCtrlSpotLight->setExponent(1.0f);
	pCtrlSpotLight->setPosition(0, 0, -1);
	pCtrlSpotLight->setAmbient(255, 255, 255, 255);
	pCtrlSpotLight->setDiffuse(255, 255, 255, 255);
	pCtrlSpotLight->setCutOff(45);
	pCtrlSpotLight->setDirection(0.0f, 0.0f, 1.0f);
	
	this->getCanvas()->getRoot()->addChild(pCtrlSpotLight);
}

void WndRender::testText()
{
	CtrlText* pCtrlText = new CtrlText();
	AUTO_RELEASE_OBJECT(pCtrlText);
	pCtrlText->setFontPath("Resource/font_2.ttf");
	pCtrlText->setFontSize(58);
	pCtrlText->setString("abc");
	pCtrlText->setPosition(512, 384, 0);
	pCtrlText->setRotation(0, 0, 20);
	pCtrlText->setRectVisible(true);
	pCtrlText->setRectColor(sys::Color4B(255, 0, 0, 255));
	pCtrlText->setColor(sys::Color4B(125, 80, 255, 255));
	this->getCanvas()->getRoot()->addChild(pCtrlText);

// 	pCtrlText = new CtrlText();
// 	AUTO_RELEASE_OBJECT(pCtrlText);
// 	pCtrlText->setFontPath("Resource/font_2.ttf");
// 	pCtrlText->setFontSize(36);
// 	pCtrlText->setString("gdafa87/*s");
// 	pCtrlText->setPosition(512, 384 - 36, 0);
// 	pCtrlText->setRectVisible(true);
// 	pCtrlText->setRectColor(sys::Color4B(255, 0, 0, 255));
// 	pCtrlText->setColor(sys::Color4B(125, 80, 255, 255));
// 	this->getCanvas()->getRoot()->addChild(pCtrlText);

}

void WndRender::testMask()
{
// 	CtrlPixel* pImage = new CtrlPixel();
// 	AUTO_RELEASE_OBJECT(pImage);
// 	this->getCanvas()->getRoot()->addChild(pImage);
	//Color4B color = pImage->getPixel(512, 384);

	uchar opacity = 200;

	CtrlMask* pMask = new CtrlMask();
	AUTO_RELEASE_OBJECT(pMask);
	pMask->setOpacity(opacity);
	pMask->setPosition(512, 384, 0.0f);
	pMask->setVolume(200, 300, 0);
	pMask->setRectVisible(true);
	pMask->setRectColor(sys::Color4B(255, 0, 0, 100));
	this->getCanvas()->getRoot()->addChild(pMask);
	
}

void WndRender::testMedia()
{
	CtrlMedia* pMedia = new CtrlMedia();
	AUTO_RELEASE_OBJECT(pMedia);
	pMedia->setMediaPath("Resource/1.flv");
	pMedia->setPosition(512, 384, 0.0f);
	pMedia->start();
	this->getCanvas()->getRoot()->addChild(pMedia);
}

void WndRender::testFog()
{
	CtrlFog* pFog = new CtrlFog();
	pFog->setDensity(0.015);
	pFog->setNear(60);
	pFog->setFar(100);
	pFog->setColor(125, 125, 125, 125);
	AUTO_RELEASE_OBJECT(pFog);
	this->getCanvas()->getRoot()->addChild(pFog);
}

void WndRender::testAnimation()
{

}

void WndRender::testParticle()
{
	CtrlParticleSystem* node = new CtrlParticleSystem();
	node->setPosition(512, 386, 0);
	node->setCount(100);
	node->init();
	node->start();
	AUTO_RELEASE_OBJECT(node);
	this->getCanvas()->getRoot()->addChild(node);
}
