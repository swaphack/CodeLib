#include "MainScene.h"

#include "ui.h"
#include "algorithm.h"
#include "render.h"

using namespace render;
using namespace sys;
using namespace ui;

MainScene::MainScene()
{

}

MainScene::~MainScene()
{
	SAFE_DELETE(_concurFile);
	SAFE_DELETE(_httpDownload);
}

bool MainScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	// 	ImageDefine imageDefine = {"Resource/Image/world.jpg", EIF_JPEG};
	// 	Texture2D* pTexture = G_TEXTURE_CACHE->getTexture2D(imageDefine);
	// 	pTexture->retain();

	//testMoveImage();
	//testClock();
	testText();
	//testMask();
	//testMedia();

	//testAnimation();
	//testParticle();
	//testStencil();
	//testCamera();
	//testEditBox();


	testImages();

	//testString();
	//
	//testPixelImage();
	//testSequenceFrame();
	//
	//testClipPlane();
	//testScissor();
	//
	//testScrollView();
	//
	//testUI();
	//
	//testDrawNode();
	//
	//testConcurrent();
	//
	//testAudio();
	//testAudio3D();
	//testLayout();
	//
	addLight();
	//testFog();
	//testCubeModel();
	//testSphereModel();
	//testModel();

	//test3ds();

	testObj();

	//testFbx();

	//this->testCubeModel();
	//this->testMultiFaceCube();

	//testShaderProgram();

	//testMedia();
	//testImages();

	//testMatrix();

	//testHttpDownload();

	return true;
}

void MainScene::testMoveImage()
{
	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Image/world.jpg");
	pImage->setPosition(512, 384, 0);
	this->addChild(pImage);

	pImage->getTouchProxy()->addTouchDelegate(ETT_DOWN, this, TOUCH_DELEGATTE_SELECTOR(MainScene::onTouchBegin));

	pImage->getTouchProxy()->addTouchDelegate(ETT_ON, this, TOUCH_DELEGATTE_SELECTOR(MainScene::onTouchMove));

	pImage->getTouchProxy()->addTouchDelegate(ETT_UP, this, TOUCH_DELEGATTE_SELECTOR(MainScene::onTouchEnd));

	G_KEYBOARDMANAGER->addDispatcher(pImage, this, KEYBOARD_DELEGATTE_SELECTOR(MainScene::onKeyBoard));
}

void MainScene::testClock()
{
	DrawNode* pDrawNode = CREATE_NODE(DrawNode);

	pDrawNode->setDrawMode(ShapeMode::QUAD_STRIP);
	pDrawNode->setWidth(20);
	pDrawNode->setPosition(125, 125, 0);
	pDrawNode->appendPoint(math::Vector3(0, 200));
	pDrawNode->appendPoint(math::Vector3(150, 300));
	pDrawNode->appendPoint(math::Vector3(200, 200));
	pDrawNode->appendPoint(math::Vector3(150, 100));
	pDrawNode->setColor(sys::Color3B(0, 255, 0));

	//pDrawNode->setRotationZ(20);

	this->addChild(pDrawNode);
}

void MainScene::testCubeModel()
{
	auto pTexture = G_TEXTURE_CACHE->createTexture2D("Resource/Image/NeHe.png");
	CubeModel* pModel = CREATE_NODE(CubeModel);
	pModel->setTexture("face", pTexture);
	pModel->setAnchorPoint(math::Vector3(0.5f, 0.5f, 0.5f));
	pModel->setPosition(100, 100, 15);
	pModel->setVolume(200, 200, 200);
	this->addChild(pModel);
	/*
	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(0, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pModel->getActionProxy()->runAction(pRepeateAction);
	*/
}

void MainScene::testSphereModel()
{
	ImageDefine imageDefine = { "Resource/Image/NeHe.png", EIF_PNG };
	Texture2D* texture2D = G_TEXTURE_CACHE->createTexture2D(imageDefine);

	TexFrame* frame = CREATE_OBJECT(TexFrame);
	frame->setTextureWithRect(texture2D);

	render::SphereModel* pSphere = CREATE_NODE(render::SphereModel);
	pSphere->setRadius(512);
	pSphere->setTexFrame(frame);
	this->addChild(pSphere);

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

void MainScene::testText()
{
	CtrlText* pCtrlText;
	pCtrlText = CREATE_NODE(CtrlText);
	pCtrlText->setFontPath("Resource/Font/font_3.ttf");
	pCtrlText->setFontSize(58);
	pCtrlText->setScale(5);
	pCtrlText->setPosition(0, 450, 0);
	pCtrlText->setVerticalAlignment(EVA_CENTER);
	pCtrlText->setColor(sys::Color4B(255, 255, 255, 255));
	this->addChild(pCtrlText);


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
	pCtrlText->setHorizontalAlignment(EHA_CENTER);
	pCtrlText->setVerticalAlignment(EVA_CENTER);
	pCtrlText->setFontPath("Resource/Font/font_2.ttf");
	pCtrlText->setFontSize(58);
	pCtrlText->setScale(5);
	pCtrlText->setString("�л� fdsaf545�Ŵ����񹲺͹�");
	pCtrlText->setPosition(0, 384, 0);
	pCtrlText->setDimensions(300, 600);
	pCtrlText->setColor(sys::Color4B(125, 255, 255, 255));
	this->addChild(pCtrlText);
}

void MainScene::testMask()
{
	uint8_t opacity = 255;

	CtrlMask* pMask = CREATE_NODE(CtrlMask);
	pMask->setOpacity(opacity);
	pMask->setAnchorPoint(0, 0, 0);
	pMask->setPosition(0, 0, 0.0f);
	pMask->setVolume(1024, 768, 0);
	pMask->setColor(Color4B(120, 120, 120, 125));
	this->addChild(pMask);
}

void MainScene::testMedia()
{
	//std::string url1 = "https://ugcbsy.qq.com/uwMROfz2r5zIIaQXGdGnC2dfJ7wFnocHIQhYHck9TxbRMoti/y0647bdq0hl.p712.1.mp4?sdtfrom=v1010&guid=7a345dbc709c2cb45a0e756b1151771e&vkey=980A0DC3EEACFCD09C8F79C1B88447C42F046F272C6C2773A84844BB42FF9D640A7EA43D424046A119996CB0E9592558ADE4A7ED81F95E8C0B274F2210C1F2BDB414AB798BE622D7AB2D086181205CD0FDE5A2CDFC066DAF097A07F5729811EED0E8D3D535FD93898207F1A4FC0639148128BF7DDC5CEE920E1B02B6B2B07247";
	std::string url2 = "Resource/Video/1.flv";
	CtrlMedia* pMedia = CREATE_NODE(CtrlMedia);
	pMedia->setMediaURL(url2);
	pMedia->setAnchorPoint(0.0f, 0.0f);
	pMedia->start();
	this->addChild(pMedia);
}

void MainScene::testFog()
{
	Fog* pFog = CREATE_NODE(Fog);
	pFog->setDensity(0.015);
	pFog->setNear(0);
	pFog->setFar(1000);
	pFog->setColor(125, 125, 125, 125);
	this->addChild(pFog);
}

void MainScene::testAnimation()
{

}

void MainScene::testParticle()
{
	CtrlParticleSystem* node = CREATE_NODE(CtrlParticleSystem);
	node->setPosition(512, 386, 0);
	node->setCount(100);
	node->setScale(2, 1, 1);
	node->start();
	this->addChild(node);
}

void MainScene::testStencil()
{
	Texture2D* texture2D = G_TEXTURE_CACHE->createTexture2D("Resource/Image/NeHe.png");

	TexFrame* frame = CREATE_OBJECT(TexFrame);
	frame->setTextureWithRect(texture2D);

	Stencil* pStencil = CREATE_NODE(Stencil);
	pStencil->setVolume(400, 400, 400);

	this->addChild(pStencil);

	MultiFaceCube* pCube = CREATE_NODE(MultiFaceCube);
	pCube->setVolume(400, 400, 200);
	pCube->setColor(sys::Color3B(255, 255, 255));
	pCube->setAllFaceFrame(frame);
	pCube->setRotation(45, 45, 0);
	pStencil->setStencilNode(pCube);

	texture2D = G_TEXTURE_CACHE->createTexture2D("Resource/Image/sqi.png");

	frame = CREATE_OBJECT(TexFrame);
	frame->setTextureWithRect(texture2D);

	pCube = CREATE_NODE(MultiFaceCube);
	pCube->setVolume(100, 100, 100);
	pCube->setRotation(-45, -45, 0);
	pCube->setAllFaceFrame(frame);

	pStencil->addChild(pCube);
}

void MainScene::testCamera()
{
	Camera* camera = Camera::getMainCamera();
	G_KEYBOARDMANAGER->addDispatcher(camera, this, KEYBOARD_DELEGATTE_SELECTOR(MainScene::onKeyBoardCamera));
}

void MainScene::testEditBox()
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

	this->addChild(pEditLabel);
}

void MainScene::testImages()
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

	/*
	int count = 100;
	CtrlImage* pChild = nullptr;
	while (count-- > 0)
	{
	pChild = CREATE_NODE(CtrlImage);
	pChild->setImagePath("Resource/Image/NeHe.png");
	pChild->setPosition(4, 4, 0);
	pChild->setScale(1, 1, 1);
	pChild->setRotation(0, 0, 30);
	pImage->addChild(pChild);
	pImage = pChild;
	}
	*/
}

void MainScene::testString()
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

void MainScene::addLight()
{
	Light0* pSpotLight = CREATE_NODE(Light0);
	pSpotLight->setPosition(0, 0, 50);
	pSpotLight->setAmbient(255, 255, 255, 255);
	pSpotLight->setDiffuse(255, 255, 255, 255);
	pSpotLight->setSpecular(255, 255, 255, 255);

	this->addChild(pSpotLight);
}

void MainScene::testPixelImage()
{
	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Image/sqi.png");
	pImage->setPosition(512, 384, 0);
	this->addChild(pImage);

	CtrlText* pCtrlText = CREATE_NODE(CtrlText);
	pCtrlText->setFontPath("Resource/font_3.ttf");
	pCtrlText->setAnchorPoint(0, 0, 0);
	pCtrlText->setFontSize(58);
	pCtrlText->setString("������ƶ���꣬�ı���ɫ");
	pCtrlText->setPosition(100, 100, 0);
	pCtrlText->setColor(sys::Color4B(255, 255, 255, 255));
	this->addChild(pCtrlText);

	//pImage->setUserData(pCtrlText);
	pImage->getTouchProxy()->addTouchDelegate(ETT_ON, this, TOUCH_DELEGATTE_SELECTOR(MainScene::onTouchImage));
}

void MainScene::testSequenceFrame()
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

	this->addChild(pSequenceFrame);
	G_KEYBOARDMANAGER->addDispatcher(pSequenceFrame, this, KEYBOARD_DELEGATTE_SELECTOR(MainScene::onKeyBoardRole));
}

void MainScene::onTouchBegin(sys::Object* object, float x, float y)
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

void MainScene::onTouchMove(sys::Object* object, float x, float y)
{
	CtrlImage* pNode = dynamic_cast<CtrlImage*>(object);
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<math::Vector3>* pAry = static_cast<std::vector<math::Vector3>*>(pNode->getUserData());
	pNode->setPosition((*pAry)[0].getX() + x - (*pAry)[1].getX(), (*pAry)[0].getY() + y - (*pAry)[1].getY(), 0);
}

void MainScene::onTouchEnd(sys::Object* object, float x, float y)
{
	CtrlImage* pNode = dynamic_cast<CtrlImage*>(object);
	if (pNode == nullptr)
	{
		return;
	}

	std::vector<math::Vector3>* pAry = static_cast<std::vector<math::Vector3>*>(pNode->getUserData());
	SAFE_DELETE(pAry);
}

void MainScene::onKeyBoard(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type)
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

void MainScene::onTouchImage(sys::Object* object, float x, float y)
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

void MainScene::onKeyBoardCamera(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type)
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

void MainScene::onKeyBoardRole(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type)
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

void MainScene::testModel()
{
	//pModel->setVolume(100, 100, 100);
	/*
	pModel->getMatrial()->setAmbient(255, 255, 255, 255);
	pModel->getMatrial()->setDiffuse(255, 255, 255, 255);
	pModel->getMatrial()->setSpecular(255, 0, 0, 255);
	pModel->getMatrial()->setEmisiion(255, 0, 0, 255);
	pModel->getMatrial()->setShiness(0.5f);
	*/
	/*
	int count = 1024;
	float interval = 5;
	float rx = 360;
	float ry = 360;
	float rz = 360;
	RotateToAction* pRotateToAction = CREATE_ACTION(RotateToAction);
	pRotateToAction->setRotation(rx * count, ry * count, rz * count);
	pRotateToAction->setDuration(interval * count);
	pModel->getActionProxy()->runAction(pRotateToAction);
	*/
	//this->getCanvas()->getCamera()->lookAt(pModel->getPosition());
}

void MainScene::testClipPlane()
{
	ClipPlane0* pClipPlane = CREATE_NODE(ClipPlane0);
	pClipPlane->setPosition(512, 384);
	pClipPlane->setClipNormal(1, 1, 0);

	this->addChild(pClipPlane);
}

void MainScene::testScissor()
{
	CtrlScissor* pScissor1 = CREATE_NODE(CtrlScissor);
	pScissor1->setVolume(100, 200, 0);
	pScissor1->setPosition(512, 384);
	this->addChild(pScissor1);

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

void MainScene::testScrollView()
{
	CtrlScrollView* pScrollView = CREATE_NODE(CtrlScrollView);
	pScrollView->setPosition(512, 384);
	pScrollView->setVolume(200, 600);
	pScrollView->setItemSize(200, 200);
	this->addChild(pScrollView);

	for (int i = 0; i < 10; i++)
	{
		CtrlImage* pImage = CREATE_NODE(CtrlImage);
		pImage->setImagePath("Resource/Image/sqi.png");
		pImage->setVolume(200, 200, 0);
		pScrollView->append(pImage);
	}

	pScrollView->setScrollDirection(ESD_HORIZONTAL_LEFT);
}

void MainScene::testUI()
{
	Display* pUIFrame = new Display();
	pUIFrame->setUIRoot(this);
	pUIFrame->setFilePath("Resource/Layout/Test.xml");
	pUIFrame->show();

	int a = 1;
}

void MainScene::testDrawNode()
{
	math::Vector2 points[] = {
		{ 100, 100 },
		{ 50, 50 },
		{ 75, 60 },
		{ 150, 50 },
		{ 200, 100 },
		{ 120, 110 },
	};

	int COUNT = (sizeof(points) / sizeof(math::Vector2));

	DrawNode* pDrawNode = CREATE_NODE(DrawNode);
	pDrawNode->setDrawMode(ShapeMode::POLYGON);
	pDrawNode->setColor(sys::Color3B(0, 255, 0));
	for (int i = 0; i < COUNT; i++)
	{
		pDrawNode->appendPoint(math::Vector3(points[i]));
	}
	this->addChild(pDrawNode);
}

void MainScene::testConcurrent()
{
}

void MainScene::testAudio()
{
	CtrlAudioSource* pSrcAudio = CREATE_NODE(CtrlAudioSource);
	pSrcAudio->loadDataFromFile("Resource/Audio/city_build.mp3");
	pSrcAudio->setMusicVolume(0.1f);
	pSrcAudio->play();
	this->addChild(pSrcAudio);

	PRINT("OK");
}

#define DISTANCEFACTOR 1

void MainScene::testAudio3D()
{
	int nCount = G_AUDIO->get3DNumListeners();
	G_AUDIO->set3DNumListeners(1);
	G_AUDIO->set3DSettings(render::Audio3DSettings(1.0f, DISTANCEFACTOR, 1.0f));

	CtrlAudioListener* pListener = CREATE_NODE(CtrlAudioListener);
	pListener->setPosition(100, 25, 0);
	this->addChild(pListener);

	DrawNode* pListenerDrawNode = CREATE_NODE(DrawNode);
	pListenerDrawNode->setColor(Color3B(0, 255, 0));
	pListenerDrawNode->setWidth(100);
	pListenerDrawNode->setDrawMode(ShapeMode::POINTS);
	pListenerDrawNode->appendPoint(math::Vector3());
	pListener->addChild(pListenerDrawNode);

	G_KEYBOARDMANAGER->addDispatcher(pListener, this, KEYBOARD_DELEGATTE_SELECTOR(MainScene::onKeyBoardListener));

	CtrlAudioSource3D* pSrcAudio = CREATE_NODE(CtrlAudioSource3D);
	pSrcAudio->loadDataFromFile("Resource/Audio/city_castle.mp3");
	pSrcAudio->set3DMinMaxDistance({ 0.5f, 10000 });
	pSrcAudio->setPosition(100, 50, 0);
	pSrcAudio->setVelocity({ 0, 0, 0 });
	pSrcAudio->setMusicVolume(100);
	pSrcAudio->play();
	this->addChild(pSrcAudio);

	DrawNode* pSrcDrawNode = CREATE_NODE(DrawNode);
	pSrcDrawNode->setColor(Color3B(255, 255, 0));
	pSrcDrawNode->setWidth(100);
	pSrcDrawNode->setDrawMode(ShapeMode::POINTS);
	pSrcDrawNode->appendPoint(math::Vector3());
	pSrcAudio->addChild(pSrcDrawNode);


	pSrcAudio = CREATE_NODE(CtrlAudioSource3D);
	pSrcAudio->loadDataFromFile("Resource/Audio/m_city.mp3");
	pSrcAudio->set3DMinMaxDistance({ 0.5f, 10000 });
	pSrcAudio->setPosition(400, 100, 0);
	pSrcAudio->setVelocity({ 0, 0, 0 });
	pSrcAudio->setMusicVolume(100);
	pSrcAudio->play();
	this->addChild(pSrcAudio);

	pSrcDrawNode = CREATE_NODE(DrawNode);
	pSrcDrawNode->setColor(Color3B(255, 0, 0));
	pSrcDrawNode->setWidth(100);
	pSrcDrawNode->setDrawMode(ShapeMode::POINTS);
	pSrcDrawNode->appendPoint(math::Vector3());
	pSrcAudio->addChild(pSrcDrawNode);

	float maxSize = G_AUDIO->getGeometrySettings();
	G_AUDIO->setGeometrySettings(10);

	CtrlAudioGeometry* pGeometryNode = CREATE_NODE(CtrlAudioGeometry);
	pGeometryNode->init(6, 24);
	pGeometryNode->setForward({ 1, 0, 0 });
	pGeometryNode->setUp({ 0, 1, 0 });
	pGeometryNode->setPosition(300, 75);
	pGeometryNode->setVolume(200, 100, 100);
	pGeometryNode->setActive(true);
	this->addChild(pGeometryNode);
}

void MainScene::onKeyBoardListener(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type)
{
	CtrlAudioListener* pNode = dynamic_cast<CtrlAudioListener*>(object);
	if (pNode == nullptr)
	{
		return;
	}
	if (type == EBS_BUTTON_UP)
	{
		return;
	}

	math::Vector3 lastPos;
	math::Vector3 vel;
	math::Vector3 curPos;

	bool bMatch = true;
	float speed = 5;
	lastPos = pNode->getPosition();

	if (key == EBK_LEFT)
	{
		pNode->setPositionX(pNode->getPositionX() - speed);
	}
	else if (key == EBK_RIGHT)
	{
		pNode->setPositionX(pNode->getPositionX() + speed);
	}
	else if (key == EBK_UP)
	{
		pNode->setPositionY(pNode->getPositionY() + speed);
	}
	else if (key == EBK_DOWN)
	{
		pNode->setPositionY(pNode->getPositionY() - speed);
	}
	else
	{
		bMatch = false;
	}

	if (!bMatch)
	{
		return;
	}

	curPos = pNode->getPosition();
	vel = curPos - lastPos;
	pNode->setVelocity(vel);
}

void MainScene::testLayout()
{
	Display* pDisplay = new Display();
	pDisplay->setUIRoot(this);
	pDisplay->setFilePath("Resource/Layout/test.xml");
	pDisplay->show();
}

void MainScene::test3ds()
{
	Model3DS* model = CREATE_NODE(Model3DS);
	model->load("Resource/3DS/Bld_38.3ds");
	model->setScale(100);
	model->setPosition(-100, -100, 0);
	model->setVolume(400, 400, 400);
	this->addChild(model);

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(180, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	model->getActionProxy()->runAction(pRepeateAction);
}

void MainScene::testObj()
{
	std::string filename = "Resource/Obj/SCI_FRS_13_HD/SCI_FRS_13_HD.obj";
	//std::string filename = "Resource/Obj/Skull_v3_L2/12140_Skull_v3_L2.obj";

	ModelObj* model = CREATE_NODE(ModelObj);
	model->load(filename);
	model->setScale(50);
	model->setPosition(0, 0, 0);
	model->setVolume(400, 400, 400);
	this->addChild(model);

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(180, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	model->getActionProxy()->runAction(pRepeateAction);
}

void MainScene::testMultiFaceCube()
{
	int nCount = 2;
	for (int i = 0; i < nCount; i++)
	{
		ImageDefine imageDefine = { "Resource/Image/NeHe.png", EIF_PNG };
		Texture2D* texture2D = G_TEXTURE_CACHE->createTexture2D(imageDefine);

		TexFrame* frame = CREATE_OBJECT(TexFrame);
		frame->setTextureWithRect(texture2D);

		MultiFaceCube* pModel = CREATE_NODE(MultiFaceCube);
		pModel->setPosition(i * 100, i * 100, i * 100);
		pModel->setAllFaceFrame(frame);
		pModel->setVolume(200, 200, 200);
		pModel->setRotation(45, 45, 0);

		MaterialDetail* mat = CREATE_OBJECT(MaterialDetail);
		mat->setShiness(1.0f);
		mat->setAmbient(255, 255, 255, 255);
		mat->setDiffuse(255, 255, 255, 255);
		mat->setSpecular(0, 0, 0, 255);
		mat->setEmisiion(255, 255, 255, 255);
		pModel->setAllFaceMaterial(mat);

		this->addChild(pModel);

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
		pSequenece->addAction(pRotateByAction);
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

void MainScene::testFbx()
{
	ModelFbx* model = CREATE_NODE(ModelFbx);
	model->load("Resource/fbx/LANCER_EVOLUTION/LANCEREVOX.FBX");
	model->setScale(200);
	model->setRotationX(0);
	this->addChild(model);

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(0, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	model->getActionProxy()->runAction(pRepeateAction);
}

void MainScene::testShaderProgram()
{
	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Image/NeHe.png");
	pImage->setPosition(512, 400, 0);
	pImage->setScale(1, 1, 1);
	pImage->setRotation(0, 0, 30);
	this->addChild(pImage);

	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->load("Resource/shader/gray.vsh", "Resource/shader/gray.fsh");
	pProgram->link();
	pImage->setProgram(pProgram);
}

void MainScene::testMatrix()
{
	float data2x2[4] = {
		1, 2,
		-1, -3
	};


	math::Matrix mat22(data2x2, 2, 2);
	PRINT("src:\n%s\n", mat22.toString().c_str());
	math::Matrix inverse22 = mat22.getInverse();
	PRINT("transpose:\n%s\n", inverse22.toString().c_str());
	math::Matrix mul22 = mat22 * inverse22;
	PRINT("mul:\n%s\n", mul22.toString().c_str());

	float data3x3[9] = {
		1, 2, 3,
		3, 2, 1,
		1, 4, 5
	};


	math::Matrix mat33(data3x3, 3, 3);
	PRINT("src:\n%s\n", mat33.toString().c_str());
	math::Matrix inverse33 = mat33.getInverse();
	PRINT("transpose:\n%s\n", inverse33.toString().c_str());

	math::Matrix mul33 = mat33 * inverse33;
	PRINT("mul:\n%s\n", mul33.toString().c_str());
}

void MainScene::testHttpDownload()
{
	std::string url = "http://pgcvideo.cdn.xiaodutv.com/3655477038_3129027130_20200415121806.mp4?Cache-Control%3Dmax-age%3A8640000%26responseExpires%3DFri%2C_24_Jul_2020_12%3A18%3A16_GMT=&xcode=829315dc4b5218e61407710580f6c8325009948d0a4a4c20&time=1587101501&_=1587017616119";

	std::string localFilePath = "temp.mp4";
	sys::Directory::createFile(localFilePath);

	if (_concurFile == nullptr)
	{
		_concurFile = new sys::ConcurrentFile(localFilePath);
	}

	if (_httpDownload == nullptr)
	{
		_httpDownload = new sys::HttpDownload();
	}

	_httpDownload->setDownloadingFunc([this](int32_t tag, const char* data, int32_t len){
		_concurFile->write(data, len);
	});
	_httpDownload->startTask(url, localFilePath, [this](int32_t tag, const std::string& content){
		_concurFile->finish();
		SAFE_DELETE(_concurFile);
	});
}

