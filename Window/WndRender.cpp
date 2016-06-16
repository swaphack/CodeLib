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
	Time* t = Time::getNow();
	LOG("%d-%d-%d %02d:%02d:%02d\n", t->getYear(), t->getMonth(), t->getMonthDay(), t->getHour(), t->getMinute(), t->getSecond());
	t->addSecond(-1989456);
	LOG("%d-%d-%d %02d:%02d:%02d\n", t->getYear(), t->getMonth(), t->getMonthDay(), t->getHour(), t->getMinute(), t->getSecond());
	t->addSecond(10989456);
	LOG("%d-%d-%d %02d:%02d:%02d\n", t->getYear(), t->getMonth(), t->getMonthDay(), t->getHour(), t->getMinute(), t->getSecond());

	//this->testStencil();

	this->testEditBox();
}

void WndRender::testImage()
{
	CtrlImage* pImage = new CtrlImage();
	pImage->setImagePath("Resource/sqi.png");
	pImage->setPosition(512, 384, 0);
	pImage->setRectVisible(true);
	pImage->setRectColor(sys::Color4B(255, 0, 0, 255));
	AUTO_RELEASE_OBJECT(pImage);
	this->getCanvas()->getRoot()->addChild(pImage);

	pImage->getTouchProxy()->addTouchDelegate(ETT_ON, [](sys::Object* object, float x, float y){
		CtrlImage* pNode = dynamic_cast<CtrlImage*>(object);
		if (pNode == nullptr)
		{
			return;
		}

		pNode->setPosition(x, y, 0);
	});

	G_KEYBOARDMANAGER->addDispatcher(pImage, [](sys::Object* object, sys::BoardKey key, sys::ButtonStatus type){
		CtrlImage* pNode = dynamic_cast<CtrlImage*>(object);
		if (pNode == nullptr)
		{
			return;
		}
		if (type == EBS_BUTTON_UP)
		{
			return;
		}
		if (key == EBK_W)
		{
			pNode->setPositionY(pNode->getPositionY() + 1);
		}
		else if (key == EBK_S)
		{
			pNode->setPositionY(pNode->getPositionY() - 1);
		}
		else if (key == EBK_A)
		{
			pNode->setPositionX(pNode->getPositionX() - 1);
		}
		else if (key == EBK_D)
		{
			pNode->setPositionX(pNode->getPositionX() + 1);
		}
	});
}

void WndRender::testClock()
{
	LineNode* pSecondLineNode = new LineNode();
	AUTO_RELEASE_OBJECT(pSecondLineNode);

	pSecondLineNode->setWidth(2);
	pSecondLineNode->setPosition(512, 384, 0);
	pSecondLineNode->setSource(0, 0);
	pSecondLineNode->setDestination(300, 300);
	
	this->getCanvas()->getRoot()->addChild(pSecondLineNode);

	LineNode* pMinuteLineNode = new LineNode();
	AUTO_RELEASE_OBJECT(pMinuteLineNode);
	pMinuteLineNode->setWidth(5);
	pMinuteLineNode->setPosition(512, 384, 0);
	pMinuteLineNode->setSource(0, 0);
	pMinuteLineNode->setDestination(300, 300);
	pMinuteLineNode->setColor(sys::Color4B(255, 0, 0, 255));
	
	this->getCanvas()->getRoot()->addChild(pMinuteLineNode);

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

	Cube* pModel = new Cube();
	AUTO_RELEASE_OBJECT(pModel);
	pModel->setTexFrame(frame);
	//pModel->setPosition(512, 384, 0);
	pModel->setVolume(256.0f, 256.0f, 256.0f);
	pModel->setRotation(0, 0, 10);
	pModel->getMatrial()->setShiness(1.0f);
	pModel->getMatrial()->setAmbient(255, 255, 255, 255);
	pModel->getMatrial()->setDiffuse(255, 255, 255, 255);
	pModel->getMatrial()->setSpecular(255, 255, 255, 255);
	pModel->getMatrial()->setEmisiion(255, 255, 255, 255);
	this->getCanvas()->getRoot()->addChild(pModel);

// 	int count = 1024;
// 	float interval = 5;
// 	float rx = 45;
// 	float ry = 45;
// 	float rz = 0;
// 	RotateToAction* pRotateToAction = new RotateToAction();
// 	pRotateToAction->setRotation(rx * count, ry * count, rz * count);
// 	pRotateToAction->setInterval(interval * count);
// 	pModel->getActionProxy()->runAction(pRotateToAction);

// 	CtrlSpotLight1* pCtrlSpotLight = new CtrlSpotLight1();
// 	AUTO_RELEASE_OBJECT(pCtrlSpotLight);
// 	pCtrlSpotLight->setExponent(1.0f);
// 	pCtrlSpotLight->setPosition(0, 0, -1);
// 	pCtrlSpotLight->setAmbient(255, 255, 255, 255);
// 	pCtrlSpotLight->setDiffuse(255, 255, 255, 255);
// 	pCtrlSpotLight->setCutOff(45);
// 	pCtrlSpotLight->setDirection(0.0f, 0.0f, 1.0f);
// 	
// 	this->getCanvas()->getRoot()->addChild(pCtrlSpotLight);
}

void WndRender::testText()
{
	char strVal[255] = {};
	Time* t = Time::getNow();
	LOG("%d-%d-%d %02d:%02d:%02d\n", t->getYear(), t->getMonth(), t->getMonthDay(), t->getHour(), t->getMinute(), t->getSecond());
	sprintf(strVal, "%d-%d-%d %02d:%02d:%02d\n", t->getYear(), t->getMonth(), t->getMonthDay(), t->getHour(), t->getMinute(), t->getSecond());

	CtrlText* pCtrlText = new CtrlText();
	AUTO_RELEASE_OBJECT(pCtrlText);
	pCtrlText->setFontPath("Resource/font_3.ttf");
	pCtrlText->setFontSize(58);
	pCtrlText->setString("中华人民共和国");
	pCtrlText->setPosition(512, 384, 0);
	pCtrlText->setRectVisible(true);
	pCtrlText->setRectColor(sys::Color4B(255, 0, 0, 255));
	pCtrlText->setColor(sys::Color4B(125, 80, 255, 255));
	this->getCanvas()->getRoot()->addChild(pCtrlText);
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
// 	pMask->setRectVisible(true);
// 	pMask->setRectColor(sys::Color4B(255, 0, 0, 100));
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
	node->setScale(2, 1, 1);
	node->init();
	node->start();
	AUTO_RELEASE_OBJECT(node);
	this->getCanvas()->getRoot()->addChild(node);
}

void WndRender::testStencil()
{
	CtrlStencil* pStencil = new CtrlStencil();
	pStencil->setPosition(512, 384, 0);
	AUTO_RELEASE_OBJECT(pStencil);
	this->getCanvas()->getRoot()->addChild(pStencil);

	CtrlImage* pNode = new CtrlImage();
	AUTO_RELEASE_OBJECT(pNode); 
	pNode->setImagePath("Resource/sqi.png");
	pNode->setColor(sys::Color4B(255, 0, 0, 255));
	pNode->setVolume(100, 100, 0);
	pStencil->setStencilNode(pNode);
	

	CtrlImage* pImage = new CtrlImage();
	AUTO_RELEASE_OBJECT(pImage);
	pImage->setImagePath("Resource/sqi.png");
	pImage->setVolume(200, 200, 0);
	pImage->setScale(1.5, 1.0, 2);
	pStencil->addChild(pImage);
}

void WndRender::testCamera()
{
	Camera* camera = this->getCanvas()->getCamera();
	G_KEYBOARDMANAGER->addDispatcher(camera, [](sys::Object* object, sys::BoardKey key, sys::ButtonStatus type){
		Camera* pNode = dynamic_cast<Camera*>(object);
		if (pNode == nullptr)
		{
			return;
		}
		if (type == EBS_BUTTON_UP)
		{
			return;
		}
		float zOrderDiff = 10;
		if (key == EBK_W)
		{
			pNode->setPositionZ(pNode->getPositionZ() + zOrderDiff);
		}
		else if (key == EBK_S)
		{
			pNode->setPositionZ(pNode->getPositionZ() - zOrderDiff);
		}
		else if (key == EBK_A)
		{
			//pNode->setro(pNode->getPositionX() - 1);
		}
		else if (key == EBK_D)
		{
			//pNode->setPositionX(pNode->getPositionX() + 1);
		}
	});
}

void WndRender::testEditBox()
{
	CtrlEditLabel* pEditLabel = new CtrlEditLabel();
	AUTO_RELEASE_OBJECT(pEditLabel);

	CtrlText* pCtrlText = pEditLabel->getCtrlText();
	pCtrlText->setFontPath("Resource/font_3.ttf");
	pCtrlText->setFontSize(58);
	pCtrlText->setAnchorPoint(0.0f, 0.0f, 0.0f);
	pCtrlText->setColor(sys::Color4B(125, 80, 255, 255));

	pEditLabel->setPosition(512, 384, 0);
	pEditLabel->setAnchorPoint(0.0f, 0.0f, 0.0f);
	pEditLabel->setVolume(200, 100, 0);
	pEditLabel->setKeyboardEnable(true);
	pEditLabel->setRectVisible(true);
	pEditLabel->setRectColor(sys::Color4B(255, 0, 0, 100));
	pEditLabel->setInputListen([](sys::Object* object, EditInputStatus status){
		CtrlEditLabel* pNode = dynamic_cast<CtrlEditLabel*>(object);
		if (pNode == nullptr)
		{
			return;
		}

		if (status == EEIS_BEGIN)
		{
			pNode->setString("");
		}
		else if (status == EEIS_END)
		{
			LOG("Input Text %s\n", pNode->getString());
		}
	});

	this->getCanvas()->getRoot()->addChild(pEditLabel);
}
