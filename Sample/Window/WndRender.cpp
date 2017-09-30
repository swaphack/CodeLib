﻿#include "WndRender.h"

using namespace render;
using namespace sys;
using namespace ui;

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
// 	ImageDefine imageDefine = {"Resource/Image/world.jpg", EIF_JPEG};
// 	Texture2D* pTexture = G_TEXTURE_CACHE->getTexture2D(imageDefine);
// 	pTexture->retain();
	
	
	//this->testText();
	//this->testMedia();
	//this->testScissor();

	this->addLight();

	this->testStencil();
}

void WndRender::testMoveImage()
{
	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Image/world.jpg", EIF_JPEG);
	pImage->setPosition(512, 384, 0);
	this->getCanvas()->getRoot()->addChild(pImage);

	pImage->getTouchProxy()->addTouchDelegate(ETT_DOWN, this, TOUCH_DELEGATTE_SELECTOR(WndRender::onTouchBegin));

	pImage->getTouchProxy()->addTouchDelegate(ETT_ON, this, TOUCH_DELEGATTE_SELECTOR(WndRender::onTouchMove));

	pImage->getTouchProxy()->addTouchDelegate(ETT_UP, this, TOUCH_DELEGATTE_SELECTOR(WndRender::onTouchEnd));

	G_KEYBOARDMANAGER->addDispatcher(pImage, this, KEYBOARD_DELEGATTE_SELECTOR(WndRender::onKeyBoard));
}

void WndRender::testClock()
{
	DrawNode* pDrawNode = CREATE_NODE(DrawNode);

	pDrawNode->setDrawMode(EBM_TRIANGLE_STRIP);
	pDrawNode->setWidth(20);
	pDrawNode->setPosition(-400, -300, 0);
	pDrawNode->appendPoint(sys::Vector3(0, 200));
	pDrawNode->appendPoint(sys::Vector3(150, 300));
	pDrawNode->appendPoint(sys::Vector3(200, 200));
	pDrawNode->appendPoint(sys::Vector3(300, 100));
	pDrawNode->setColor(sys::Color3B(0, 255, 0));

	//pDrawNode->setRotationZ(20);
	
	this->getCanvas()->getRoot()->addChild(pDrawNode);
}

void WndRender::testCubeModel()
{
	int nCount = 100;
	for (int i = 0; i < nCount; i++)
	{
		ImageDefine imageDefine = { "Resource/Image/NeHe.png", EIF_PNG };
		Texture2D* texture2D = G_TEXTURE_CACHE->getTexture2D(imageDefine);

		TexFrame* frame = new TexFrame();
		AUTO_RELEASE_OBJECT(frame);
		frame->setTextureWithRect(texture2D);

		Cube* pModel = CREATE_NODE(Cube);
		pModel->setPosition(i % 200, i % 200, i % 200);
		pModel->setTexFrame(frame);
		pModel->setVolume(256.0f, 256.0f, 256.0f);
		//pModel->setRotation(0, 0, 10);
		pModel->getMatrial()->setShiness(1.0f);
		pModel->getMatrial()->setAmbient(255, 255, 255, 255);
		pModel->getMatrial()->setDiffuse(255, 255, 255, 255);
		pModel->getMatrial()->setSpecular(0, 0, 0, 255);
		pModel->getMatrial()->setEmisiion(255, 255, 255, 255);
		this->getCanvas()->getRoot()->addChild(pModel);

		float interval = 2;
		float rx = 180;
		float ry = 180;
		float rz = 45;
		RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
		pRotateByAction->setRotation(rx, ry, rz);
		pRotateByAction->setDuration(interval);

		MoveToAction* pMoveToAction = CREATE_ACTION(MoveToAction);
		pMoveToAction->setDuration(interval);
		pMoveToAction->setPosition(200, 200, 20);

		ScaleByAction* pScaleByAction = CREATE_ACTION(ScaleByAction);
		pScaleByAction->setDuration(interval);
		pScaleByAction->setScale(1.5f, 1.5f, 1.5f);

		ScaleByAction* pScaleByAction2 = CREATE_ACTION(ScaleByAction);
		pScaleByAction2->setDuration(interval);
		pScaleByAction2->setScale(-1.5f, -1.5f, -1.5f);

		SequenceAction* pSequenece = CREATE_ACTION(SequenceAction);
		pSequenece->addAction(pScaleByAction);
		pSequenece->addAction(pScaleByAction2);

		RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
		pRepeateAction->setAction(pSequenece);

		SpawnAction* pSpawnAction = CREATE_ACTION(SpawnAction);
		pSpawnAction->addAction(pRepeateAction);
		pSpawnAction->addAction(pMoveToAction);

		pModel->getActionProxy()->runAction(pRepeateAction);
	}

}

void WndRender::testSphereModel()
{
	ImageDefine imageDefine = { "Resource/Image/NeHe.png", EIF_PNG };
	Texture2D* texture2D = G_TEXTURE_CACHE->getTexture2D(imageDefine);

	TexFrame* frame = new TexFrame();
	AUTO_RELEASE_OBJECT(frame);
	frame->setTextureWithRect(texture2D);

	render::Sphere* pSphere = CREATE_NODE(render::Sphere);
	pSphere->setRadius(512);
	pSphere->setTexFrame(frame);
	this->getCanvas()->getRoot()->addChild(pSphere);

	int count = 1024;
	float interval = 0.8f;
	float rx = 0;
	float ry = 45;
	float rz = 0;
	RotateToAction* pRotateToAction = CREATE_ACTION(RotateToAction);
	pRotateToAction->setRotation(rx * count, ry * count, rz * count);
	pRotateToAction->setDuration(interval * count);
	pSphere->getActionProxy()->runAction(pRotateToAction);
}

void WndRender::testText()
{
 	CtrlText* pCtrlText;
	pCtrlText = CREATE_NODE(CtrlText);
	pCtrlText->setFontPath("Resource/Font/font_3.ttf");
	pCtrlText->setFontSize(58);
	pCtrlText->setPosition(512, 450, 0);
	pCtrlText->setVerticalAlignment(EVA_CENTER);
	pCtrlText->setColor(sys::Color4B(125, 80, 255, 255));
	this->getCanvas()->getRoot()->addChild(pCtrlText);


	CallFuncN* pCallFunc = CREATE_ACTION(CallFuncN);
	pCallFunc->setFunc([](sys::Object* sender){
		char strVal[255] = {};
		Time* t = Time::getNow();
		sprintf(strVal, "%d-%d-%d %02d:%02d:%02d\n", t->getYear(), t->getMonth(), t->getMonthDay(), t->getHour(), t->getMinute(), t->getSecond());
		((CtrlText*)sender)->setString(strVal);
	});

	DelayAction* pDelayAction = CREATE_ACTION(DelayAction);
	pDelayAction->setDuration(1);

	SequenceAction* pSequenceAction = CREATE_ACTION(SequenceAction);
	pSequenceAction->addAction(pCallFunc);
	pSequenceAction->addAction(pDelayAction);

	RepeateForeverAction* pRepeateForeverAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateForeverAction->setAction(pSequenceAction);
	
	pCtrlText->getActionProxy()->runAction(pRepeateForeverAction);

	pCtrlText = CREATE_NODE(CtrlText);
	pCtrlText->setHorizontalAlignment(EHA_RIGHT);
	pCtrlText->setVerticalAlignment(EVA_CENTER);
	pCtrlText->setFontPath("Resource/Font/font_2.ttf");
	pCtrlText->setFontSize(58);
	pCtrlText->setString("中华\n人民共和国");
	pCtrlText->setPosition(512, 384, 0);
	pCtrlText->setDimensions(200, 600);
	pCtrlText->setColor(sys::Color4B(125, 255, 255, 255));
	this->getCanvas()->getRoot()->addChild(pCtrlText);
}

void WndRender::testMask()
{
	uchar opacity = 255;

	CtrlMask* pMask = CREATE_NODE(CtrlMask);
	pMask->setOpacity(opacity);
	pMask->setPosition(512, 384, 0.0f);
	pMask->setVolume(200, 300, 0);
	pMask->setColor(Color3B(0.299f * 255, 0.587f * 255, 0.114f * 255));
	this->getCanvas()->getRoot()->addChild(pMask);
}

void WndRender::testMedia()
{
	CtrlMedia* pMedia = CREATE_NODE(CtrlMedia);
	pMedia->setVolume(Tool::getGLViewWidth(), Tool::getGLViewHeight());
	pMedia->setMediaPath("Resource/Video/1.flv", false);
	pMedia->setAnchorPoint(0, 0);
	pMedia->start();
	this->getCanvas()->getRoot()->addChild(pMedia);
}

void WndRender::testFog()
{
	Fog* pFog = CREATE_NODE(Fog);
	pFog->setDensity(0.015);
	pFog->setNear(0);
	pFog->setFar(100);
	pFog->setColor(125, 125, 125, 125);
	this->getCanvas()->getRoot()->addChild(pFog);
} 

void WndRender::testAnimation()
{

}

void WndRender::testParticle()
{
	CtrlParticleSystem* node = CREATE_NODE(CtrlParticleSystem);
	node->setPosition(512, 386, 0);
	node->setCount(100);
	node->setScale(2, 1, 1);
	node->start();
	this->getCanvas()->getRoot()->addChild(node);
}

void WndRender::testStencil()
{
	Texture2D* texture2D = G_TEXTURE_CACHE->getTexture2D({ "Resource/Image/NeHe.png", EIF_PNG });

	TexFrame* frame = new TexFrame();
	AUTO_RELEASE_OBJECT(frame);
	frame->setTextureWithRect(texture2D);

	Stencil* pStencil = CREATE_NODE(Stencil);
	pStencil->setVolume(400, 400, 400);

	this->getCanvas()->getRoot()->addChild(pStencil);	

	Cube* pCube = CREATE_NODE(Cube);
	pCube->setVolume(400, 400, 200);
	pCube->setColor(sys::Color3B(255, 255, 255));
	pCube->setTexFrame(frame);
	pCube->setRotation(45, 45, 0);
	pStencil->setStencilNode(pCube);

	texture2D = G_TEXTURE_CACHE->getTexture2D({ "Resource/Image/sqi.png", EIF_PNG });

	frame = new TexFrame();
	AUTO_RELEASE_OBJECT(frame);
	frame->setTextureWithRect(texture2D);

	pCube = CREATE_NODE(Cube);
	pCube->setVolume(100, 100, 100);
	pCube->setRotation(-45, -45, 0);
	pCube->setTexFrame(frame);

	pStencil->addChild(pCube);
}

void WndRender::testCamera()
{
	Camera* camera = this->getCanvas()->getCamera();
	G_KEYBOARDMANAGER->addDispatcher(camera, this, KEYBOARD_DELEGATTE_SELECTOR(WndRender::onKeyBoardCamera));
}

void WndRender::testEditBox()
{
	CtrlEditLabel* pEditLabel = CREATE_NODE(CtrlEditLabel);

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
	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Image/NeHe.png");
	pImage->setPosition(0, 0, 0);
	this->getCanvas()->getRoot()->addChild(pImage);

	int count = 100;
	CtrlImage* pChild = nullptr;
	while (count-- > 0)
	{
		pChild = CREATE_NODE(CtrlImage);
		pChild->setImagePath("Resource/Image/NeHe.png");
		pChild->setPosition(4, 4, 0);
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
	Light0* pSpotLight = CREATE_NODE(Light0);
	pSpotLight->setPosition(0, 0, 200);
	pSpotLight->setAmbient(255, 255, 255, 255);
	pSpotLight->setDiffuse(255, 255, 255, 255);
	pSpotLight->setSpecular(255, 255, 255, 255);

	this->getCanvas()->getRoot()->addChild(pSpotLight);
}

void WndRender::testPixelImage()
{
	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Image/world.jpg", EIF_JPEG);
	pImage->setPosition(512, 384, 0);
	this->getCanvas()->getRoot()->addChild(pImage);

	CtrlText* pCtrlText = CREATE_NODE(CtrlText);
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
	CtrlSequenceFrame* pSequenceFrame = CREATE_NODE(CtrlSequenceFrame);
	pSequenceFrame->setVolume(1024, 768);
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

	std::vector<sys::Vector3>* pAry = new std::vector<sys::Vector3>(2);
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

	std::vector<sys::Vector3>* pAry = static_cast<std::vector<sys::Vector3>*>(pNode->getUserData());
	pNode->setPosition((*pAry)[0].x + x - (*pAry)[1].x, (*pAry)[0].y + y - (*pAry)[1].y, 0);
}

void WndRender::onTouchEnd(sys::Object* object, float x, float y)
{
	CtrlImage* pNode = dynamic_cast<CtrlImage*>(object);
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<sys::Vector3>* pAry = static_cast<std::vector<sys::Vector3>*>(pNode->getUserData());
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
	Model* pModel = ModelFile::getInstance()->load("Resource/3DModel/Test.xml");

	this->getCanvas()->getRoot()->addChild(pModel);

	pModel->setPosition(512, 384);
	pModel->setColor(0, 255, 0);
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
	RotateToAction* pRotateToAction = CREATE_ACTION(RotateToAction);
	pRotateToAction->setRotation(rx * count, ry * count, rz * count);
	pRotateToAction->setDuration(interval * count);
	pModel->getActionProxy()->runAction(pRotateToAction);

	//this->getCanvas()->getCamera()->lookAt(pModel->getPosition());
}

void WndRender::testClipPlane()
{
	ClipPlane0* pClipPlane = CREATE_NODE(ClipPlane0);
	pClipPlane->setPosition(512, 384);
	pClipPlane->setClipNormal(1, 1, 0);

	this->getCanvas()->getRoot()->addChild(pClipPlane);
}

void WndRender::testScissor()
{
	CtrlScissor* pScissor1 = CREATE_NODE(CtrlScissor);
	pScissor1->setVolume(100, 200, 0);
	pScissor1->setPosition(512, 384);
	this->getCanvas()->getRoot()->addChild(pScissor1);

	CtrlImage* pImage;
	pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Image/sqi.png");
	pImage->setVolume(200, 200, 0);
	pImage->setPosition(100, 100);
	pScissor1->addChild(pImage);

	CtrlScissor* pScissor2 = CREATE_NODE(CtrlScissor);
	pScissor2->setVolume(100, 100, 0);
	pScissor1->addChild(pScissor2);

	pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Image/sqi.png");
	pImage->setVolume(200, 200, 0);
	pImage->setPosition(100, 100);
	pImage->setScale(3, 3, 1);
	pScissor2->addChild(pImage);
}

void WndRender::testScrollView()
{
	CtrlScrollView* pScrollView = CREATE_NODE(CtrlScrollView);
	pScrollView->setPosition(512, 384);
	pScrollView->setVolume(200, 600);
	pScrollView->setItemSize(200, 200);
	this->getCanvas()->getRoot()->addChild(pScrollView);

	for (int i = 0; i < 10; i++)
	{
		CtrlImage* pImage = CREATE_NODE(CtrlImage);
		pImage->setImagePath("Resource/Image/sqi.png");
		pImage->setVolume(200, 200, 0);
		pScrollView->append(pImage);
	}

	pScrollView->setScrollDirection(ESD_HORIZONTAL_LEFT);
}
    
void WndRender::testUI()
{
	Display* pUIFrame = new Display();
	pUIFrame->setUIRoot(this->getCanvas()->getRoot());
	pUIFrame->setFilePath("Resource/Layout/Test.xml");
	pUIFrame->show();

	int a = 1;
}

void WndRender::testDrawNode()
{
	Vector2 points[] = {
		{ 100, 100 },
		{ 50, 50 },
		{ 75, 60 },
		{ 150, 50 },
		{ 200, 100 },
		{ 120, 110 },
	};

	int COUNT = (sizeof(points) / sizeof(Vector2));

	DrawNode* pDrawNode = CREATE_NODE(DrawNode);
	pDrawNode->setDrawMode(EBM_POLYGON);
	pDrawNode->setColor(sys::Color3B(0, 255, 0));
	for (int i = 0; i < COUNT; i++)
	{
		pDrawNode->appendPoint(Vector3(points[i]));
	}
	this->getCanvas()->getRoot()->addChild(pDrawNode);
}

void WndRender::testConcurrent()
{
}
