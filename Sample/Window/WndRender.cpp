#include "WndRender.h"

using namespace render;
using namespace sys;

WndRender::WndRender()
{
	this->init();
	this->getCanvas()->setDimensions(render::ED_3D);
}

WndRender::~WndRender()
{
	this->dispose();
}

void WndRender::show()
{
	ImageDefine imageDefine = {"Resource/Image/world.jpg", EIF_JPEG};
	Texture2D* pTexture = G_TEXTURE_CACHE->getTexture2D(imageDefine);
	pTexture->retain();

	//this->addLight();
	this->testModel();

	this->testSequenceFrame();

	//this->testFog();
}

void WndRender::testMoveImage()
{
	CtrlImage* pImage = new CtrlImage();
	pImage->setImagePath("Resource/Image/world.jpg", EIF_JPEG);
	pImage->setPosition(512, 384, 0);
	AUTO_RELEASE_OBJECT(pImage);
	this->getCanvas()->getRoot()->addChild(pImage);

	pImage->getTouchProxy()->addTouchDelegate(ETT_DOWN, this, TOUCH_DELEGATTE_SELECTOR(WndRender::onTouchBegin));

	pImage->getTouchProxy()->addTouchDelegate(ETT_ON, this, TOUCH_DELEGATTE_SELECTOR(WndRender::onTouchMove));

	pImage->getTouchProxy()->addTouchDelegate(ETT_UP, this, TOUCH_DELEGATTE_SELECTOR(WndRender::onTouchEnd));

	G_KEYBOARDMANAGER->addDispatcher(pImage, this, KEYBOARD_DELEGATTE_SELECTOR(WndRender::onKeyBoard));
}

void WndRender::testClock()
{
	DrawNode* pDrawNode = new DrawNode();
	AUTO_RELEASE_OBJECT(pDrawNode);

	pDrawNode->setDrawMode(EBM_TRIANGLE_STRIP);
	pDrawNode->setWidth(20);
	pDrawNode->setPosition(-400, -300, 0);
	pDrawNode->appendPoint(sys::Vector(0, 200));
	pDrawNode->appendPoint(sys::Vector(150, 300));
	pDrawNode->appendPoint(sys::Vector(200, 200));
	pDrawNode->appendPoint(sys::Vector(300, 100));
	pDrawNode->setColor(sys::Color3B(0, 255, 0));

	//pDrawNode->setRotationZ(20);
	
	this->getCanvas()->getRoot()->addChild(pDrawNode);
}

void WndRender::testCubeModel()
{
	int nCount = 1000;
	for (int i = 0; i < nCount; i++)
	{
		ImageDefine imageDefine = { "Resource/Image/NeHe.png", EIF_PNG };
		Texture2D* texture2D = G_TEXTURE_CACHE->getTexture2D(imageDefine);

		TexFrame* frame = new TexFrame();
		AUTO_RELEASE_OBJECT(frame);
		frame->setTextureWithRect(texture2D);

		Cube* pModel = new Cube();
		AUTO_RELEASE_OBJECT(pModel);
		pModel->setPosition(i % 100, i % 100, i % 100);
		pModel->setTexFrame(frame);
		pModel->setVolume(256.0f, 256.0f, 256.0f);
		pModel->setRotation(0, 0, 10);
		pModel->getMatrial()->setShiness(1.0f);
		pModel->getMatrial()->setAmbient(255, 255, 255, 255);
		pModel->getMatrial()->setDiffuse(255, 255, 255, 255);
		pModel->getMatrial()->setSpecular(255, 255, 255, 255);
		pModel->getMatrial()->setEmisiion(255, 255, 255, 255);
		this->getCanvas()->getRoot()->addChild(pModel);


		int count = 1024;
		float interval = 5;
		float rx = i % 360;
		float ry = i % 360;
		float rz = i % 360;
		RotateToAction* pRotateToAction = new RotateToAction();
		pRotateToAction->setRotation(rx * count, ry * count, rz * count);
		pRotateToAction->setInterval(interval * count);
		pModel->getActionProxy()->runAction(pRotateToAction);
	}

}

void WndRender::testSphereModel()
{
	Sphere* pSphere = new Sphere();
	AUTO_RELEASE_OBJECT(pSphere);
	pSphere->setRadius(512);
	this->getCanvas()->getRoot()->addChild(pSphere);

	int count = 1024;
	float interval = 0.8f;
	float rx = 0;
	float ry = 45;
	float rz = 0;
	RotateToAction* pRotateToAction = new RotateToAction();
	pRotateToAction->setRotation(rx * count, ry * count, rz * count);
	pRotateToAction->setInterval(interval * count);
	pSphere->getActionProxy()->runAction(pRotateToAction);
}

void WndRender::testText()
{
	char strVal[255] = {};
	Time* t = Time::getNow();
	PRINT("%d-%d-%d %02d:%02d:%02d\n", t->getYear(), t->getMonth(), t->getMonthDay(), t->getHour(), t->getMinute(), t->getSecond());
	sprintf(strVal, "%d-%d-%d %02d:%02d:%02d\n", t->getYear(), t->getMonth(), t->getMonthDay(), t->getHour(), t->getMinute(), t->getSecond());

	CtrlText* pCtrlText = new CtrlText();
	AUTO_RELEASE_OBJECT(pCtrlText);
	pCtrlText->setFontPath("Resource/font_3.ttf");
	pCtrlText->setFontSize(58);
	pCtrlText->setString(strVal);
	pCtrlText->setPosition(512, 384, 0);
	pCtrlText->setColor(sys::Color4B(125, 80, 255, 255));
	this->getCanvas()->getRoot()->addChild(pCtrlText);
}

void WndRender::testMask()
{
// 	CtrlPixel* pImage = new CtrlPixel();
// 	AUTO_RELEASE_OBJECT(pImage);
// 	this->getCanvas()->getRoot()->addChild(pImage);
	//Color4B color = pImage->getPixel(512, 384);

	uchar opacity = 255;

	CtrlMask* pMask = new CtrlMask();
	AUTO_RELEASE_OBJECT(pMask);
	pMask->setOpacity(opacity);
	pMask->setPosition(512, 384, 0.0f);
	pMask->setVolume(200, 300, 0);
	pMask->setColor(Color3B(0.299f * 255, 0.587f * 255, 0.114f * 255));
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
	Fog* pFog = new Fog();
	pFog->setDensity(0.015);
	pFog->setNear(0);
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
// 	CtrlStencil* pStencil = new CtrlStencil();
// 	pStencil->setPosition(512, 384, 0);
// 	AUTO_RELEASE_OBJECT(pStencil);
// 	this->getCanvas()->getRoot()->addChild(pStencil);
// 
// 	CtrlImage* pNode = new CtrlImage();
// 	AUTO_RELEASE_OBJECT(pNode); 
// 	pNode->setImagePath("Resource/sqi.png");
// 	pNode->setColor(sys::Color4B(255, 0, 0, 255));
// 	pNode->setVolume(100, 100, 0);
// 	pStencil->setStencilNode(pNode);
// 	
// 
// 	CtrlImage* pImage = new CtrlImage();
// 	AUTO_RELEASE_OBJECT(pImage);
// 	pImage->setImagePath("Resource/sqi.png");
// 	pImage->setVolume(200, 200, 0);
// 	pImage->setScale(1.5, 1.0, 2);
// 	pStencil->addChild(pImage);
}

void WndRender::testCamera()
{
	Camera* camera = this->getCanvas()->getCamera();
	G_KEYBOARDMANAGER->addDispatcher(camera, this, KEYBOARD_DELEGATTE_SELECTOR(WndRender::onKeyBoardCamera));
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
	pEditLabel->setVolume(400, 100, 0);
	pEditLabel->setKeyboardEnable(true);
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
			PRINT("Input Text %s\n", pNode->getString());
		}
	});

	this->getCanvas()->getRoot()->addChild(pEditLabel);
}

void WndRender::testImages()
{
	CtrlImage* pImage = new CtrlImage();
	pImage->setImagePath("Resource/Image/NeHe.png");
	pImage->setPosition(0, 0, 0);
	AUTO_RELEASE_OBJECT(pImage);
	this->getCanvas()->getRoot()->addChild(pImage);

	int count = 100;
	CtrlImage* pChild = nullptr;
	while (count-- > 0)
	{
		pChild = new CtrlImage();
		pChild->setImagePath("Resource/Image/NeHe.png");
		pChild->setPosition(4, 4, 0);
		AUTO_RELEASE_OBJECT(pChild);
		pImage->addChild(pChild);
		pImage = pChild;
		pChild = nullptr;
	}
}

void WndRender::testString()
{
	Time* t = Time::getNow();
	PRINT("%d-%d-%d %02d:%02d:%02d\n", t->getYear(), t->getMonth(), t->getMonthDay(), t->getHour(), t->getMinute(), t->getSecond());

	const char* data = "{json; big; none}";

	String str = String(data);

	std::vector<String> dest;
	str.split("| ", dest);

	bool bContain = str.contains(";]");
	bContain = str.contains("}");
	bContain = str.contains("{j");
	bContain = str.contains("{ja");

	str.concat("hello");

	str.concat("hello", ", CN");

	str.concat("hello", ", CN", ", PNG");
}

void WndRender::addLight()
{
	Light0* pSpotLight = new Light0();
	AUTO_RELEASE_OBJECT(pSpotLight);
	pSpotLight->setPosition(0, 0, 200);
	pSpotLight->setAmbient(255, 255, 255, 255);
	pSpotLight->setDiffuse(255, 255, 255, 255);
	pSpotLight->setSpecular(255, 255, 255, 255);

	this->getCanvas()->getRoot()->addChild(pSpotLight);
}

void WndRender::testPixelImage()
{
	CtrlImage* pImage = new CtrlImage();
	pImage->setImagePath("Resource/Image/world.jpg", EIF_JPEG);
	pImage->setPosition(512, 384, 0);
	AUTO_RELEASE_OBJECT(pImage);
	this->getCanvas()->getRoot()->addChild(pImage);

	CtrlText* pCtrlText = new CtrlText();
	AUTO_RELEASE_OBJECT(pCtrlText);
	pCtrlText->setFontPath("Resource/font_3.ttf");
	pCtrlText->setAnchorPoint(0, 0, 0);
	pCtrlText->setFontSize(58);
	pCtrlText->setString("点击后移动鼠标，改变颜色");
	pCtrlText->setPosition(0, 0, 0);
	pCtrlText->setColor(sys::Color4B(125, 80, 255, 255));
	this->getCanvas()->getRoot()->addChild(pCtrlText);

	pImage->setUserData(pCtrlText);
	pImage->getTouchProxy()->addTouchDelegate(ETT_ON, this, TOUCH_DELEGATTE_SELECTOR(WndRender::onTouchImage));
}

void WndRender::testSequenceFrame()
{
	CtrlSequenceFrame* pSequenceFrame = new CtrlSequenceFrame();
	AUTO_RELEASE_OBJECT(pSequenceFrame);
	pSequenceFrame->setFrameImagePath("Resource/Role/1/20%d.png", 8);
	pSequenceFrame->setPosition(512, 384, 0);
	pSequenceFrame->setFrameRate(1.0f / 10);
	pSequenceFrame->start();

	//pSequenceFrame->getMovie()->setBlend(EBFS_SRC_ALPHA, EBFD_ONE_MINUS_SRC_ALPHA);
	//pSequenceFrame->getMovie()->setColor(Color3B(0.299f * 255, 0.587f * 255, 0.114f * 255));
	//pSequenceFrame->getMovie()->setOpacity(255);

	this->getCanvas()->getRoot()->addChild(pSequenceFrame);
	G_KEYBOARDMANAGER->addDispatcher(pSequenceFrame, this, KEYBOARD_DELEGATTE_SELECTOR(WndRender::onKeyBoardRole));
}

void WndRender::onTouchBegin(sys::Object* object, float x, float y)
{
	CtrlImage* pNode = dynamic_cast<CtrlImage*>(object);
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<sys::Vector>* pAry = new std::vector<sys::Vector>(2);
	(*pAry)[0].x = pNode->getPositionX();
	(*pAry)[0].y = pNode->getPositionY();

	(*pAry)[1].x = x;
	(*pAry)[1].y = y;

	pNode->setUserData(pAry);
}

void WndRender::onTouchMove(sys::Object* object, float x, float y)
{
	CtrlImage* pNode = dynamic_cast<CtrlImage*>(object);
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<sys::Vector>* pAry = static_cast<std::vector<sys::Vector>*>(pNode->getUserData());
	pNode->setPosition((*pAry)[0].x + x - (*pAry)[1].x, (*pAry)[0].y + y - (*pAry)[1].y, 0);
}

void WndRender::onTouchEnd(sys::Object* object, float x, float y)
{
	CtrlImage* pNode = dynamic_cast<CtrlImage*>(object);
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<sys::Vector>* pAry = static_cast<std::vector<sys::Vector>*>(pNode->getUserData());
	SAFE_DELETE(pAry);
}

void WndRender::onKeyBoard(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type)
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

void WndRender::onTouchImage(sys::Object* object, float x, float y)
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

void WndRender::onKeyBoardCamera(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type)
{
	Camera* pNode = dynamic_cast<Camera*>(object);
	if (pNode == nullptr)
	{
		return;
	}
	if (type != EBS_BUTTON_DOWN)
	{
		return;
	}

	float speed = 2;
	if (key == EBK_UP)
	{
		pNode->setPositionY(pNode->getPositionY() + speed);		
	}
	else if (key == EBK_DOWN)
	{
		pNode->setPositionY(pNode->getPositionY() - speed);
	}
	else if (key == EBK_LEFT)
	{
		pNode->setPositionX(pNode->getPositionX() - speed);
	}
	else if (key == EBK_RIGHT)
	{
		pNode->setPositionX(pNode->getPositionX() + speed);
	}
}

void WndRender::onKeyBoardRole(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type)
{
	if (type != EBS_BUTTON_DOWN)
	{
		return;
	}

	CtrlSequenceFrame* pRole = static_cast<CtrlSequenceFrame*>(object);
	if (pRole == nullptr)
	{
		return;
	}

	struct DirectionAction
	{
		bool bFlipX;
		char path[25];
		int count;
	};

	static DirectionAction ActionConfigs[4] = {
		{ false, "Resource/Role/3/24%d.png", 8 },
		{ false, "Resource/Role/1/20%d.png", 8 }, 
		{ false, "Resource/Role/2/22%d.png", 8 },
		{ true, "Resource/Role/2/22%d.png", 8 },
	};


	int index = 0;

	if (key == EBK_UP)
	{
		index = 0;
	}
	else if (key == EBK_DOWN)
	{
		index = 1;
	}
	else if (key == EBK_LEFT)
	{
		index = 2;
	}
	else if (key == EBK_RIGHT)
	{
		index = 3;
	}

	if (pRole)
	{
		DirectionAction* pConfig = &ActionConfigs[index];
		if (pRole->getMovie()->isFlipX() != pConfig->bFlipX)
		{
			pRole->getMovie()->setFlipX(pConfig->bFlipX);
		}
		pRole->setFrameImagePath(pConfig->path, pConfig->count);
	}
}

void WndRender::testModel()
{
	CtrlModel* pModel = ModelFile::getInstance()->load("Resource/3DModel/Test.xml");
	AUTO_RELEASE_OBJECT(pModel);
	pModel->setRotation(0, 45, 45);
	pModel->setPosition(512, 384);

	this->getCanvas()->getRoot()->addChild(pModel);

	pModel->getMatrial()->setAmbient(255, 255, 255, 255);
	pModel->getMatrial()->setDiffuse(255, 255, 255, 255);
	pModel->getMatrial()->setSpecular(255, 0, 0, 255);
	pModel->getMatrial()->setEmisiion(255, 0, 0, 255);
	pModel->getMatrial()->setShiness(0.5f);

	int count = 1024;
	float interval = 5;
	float rx = 360;
	float ry = 360;
	float rz = 360;
	RotateToAction* pRotateToAction = new RotateToAction();
	pRotateToAction->setRotation(rx * count, ry * count, rz * count);
	pRotateToAction->setInterval(interval * count);
	pModel->getActionProxy()->runAction(pRotateToAction);


	this->getCanvas()->getCamera()->lookAt(pModel->getPosition());
}
