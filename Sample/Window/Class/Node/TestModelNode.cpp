#include "TestModelNode.h"
#include "system.h"

using namespace sys;
using namespace render;

TestModelNode::TestModelNode()
{

}

TestModelNode::~TestModelNode()
{

}

void TestModelNode::testFunc()
{
	this->testCubeModel();
}

void TestModelNode::testCubeModel()
{
	auto pTexture = G_TEXTURE_CACHE->createTexture2D("Resource/Image/NeHe.png");
	auto pTexture1 = G_TEXTURE_CACHE->createTexture2D("Resource/Image/1.jpg");
	std::string textureName = "face";
	std::string textureName1 = "face1";

	CubeModel* pModel = CREATE_NODE(CubeModel);
	pModel->addTexture(textureName, pTexture);
	pModel->addTexture(textureName1, pTexture1);

	pModel->setAllFacesTexture(textureName);
	pModel->setFaceTexture(EMF_FRONT, textureName1);
	pModel->setFaceTexture(EMF_LEFT, textureName1);
	pModel->setFaceTexture(EMF_TOP, textureName1);

	pModel->setAnchorPoint(math::Vector3(0.5f, 0.5f, 0.5f));
	pModel->setPosition(300, 300, 15);
	pModel->setVolume(200, 200, 200);
	this->addChild(pModel);

	// has bug
	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(0, 45, 0);
	pRotateByAction->setDuration(5);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pModel->getActionProxy()->runAction(pRepeateAction);
}

void TestModelNode::testSphereModel()
{
	ImageDefine imageDefine = { "Resource/Image/NeHe.png", EIF_PNG };
	Texture2D* texture2D = G_TEXTURE_CACHE->createTexture2D(imageDefine);

	TexFrame* frame = CREATE_OBJECT(TexFrame);
	frame->setTextureWithRect(texture2D);

	render::SphereModel* pSphere = CREATE_NODE(render::SphereModel);
	pSphere->setRadius(512);
	pSphere->setTexFrame(frame);
	this->addChild(pSphere);
}

void TestModelNode::addLight()
{
	Light0* pSpotLight = CREATE_NODE(Light0);
	pSpotLight->setPosition(0, 0, 50);
	pSpotLight->setAmbient(255, 255, 255, 255);
	pSpotLight->setDiffuse(255, 255, 255, 255);
	pSpotLight->setSpecular(255, 255, 255, 255);

	this->addChild(pSpotLight);
}

void TestModelNode::testMultiFaceCube()
{
	
}

void TestModelNode::testFog()
{
	Fog* pFog = CREATE_NODE(Fog);
	pFog->setDensity(0.015);
	pFog->setNear(0);
	pFog->setFar(1000);
	pFog->setColor(125, 125, 125, 125);
	this->addChild(pFog);
}

void TestModelNode::test3ds()
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

void TestModelNode::testObj()
{
	std::string filename = "Resource/Obj/SCI_FRS_13_HD/SCI_FRS_13_HD.obj";
	//std::string filename = "Resource/Obj/Skull_v3_L2/12140_Skull_v3_L2.obj";

	ModelObj* model = CREATE_NODE(ModelObj);
	model->load(filename);
	model->setScale(50);
	model->setPosition(512, 384, 0);
	model->setVolume(400, 400, 400);
	this->addChild(model);

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(180, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	model->getActionProxy()->runAction(pRepeateAction);
}

void TestModelNode::testFbx()
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

void TestModelNode::testStencil()
{
// 	Texture2D* texture2D = G_TEXTURE_CACHE->createTexture2D("Resource/Image/NeHe.png");
// 
// 	Stencil* pStencil = CREATE_NODE(Stencil);
// 	pStencil->setVolume(400, 400, 400);
// 
// 	this->addChild(pStencil);
// 
// 	CubeModel* pCube = CREATE_NODE(CubeModel);
// 	pCube->setVolume(400, 400, 200);
// 	pCube->setColor(sys::Color3B(255, 255, 255));
// 	pCube->setAllFacesTexture(texture2D);
// 	pCube->setRotation(45, 45, 0);
// 	pStencil->setStencilNode(pCube);
// 
// 	texture2D = G_TEXTURE_CACHE->createTexture2D("Resource/Image/sqi.png");
// 
// 	pCube = CREATE_NODE(CubeModel);
// 	pCube->setVolume(100, 100, 100);
// 	pCube->setRotation(-45, -45, 0);
// 	pCube->setAllFaceFrame(frame);
// 
// 	pStencil->addChild(pCube);
}

void TestModelNode::testCamera()
{
	Camera* camera = Camera::getMainCamera();
	G_KEYBOARDMANAGER->addDispatcher(camera, this, KEYBOARD_DELEGATTE_SELECTOR(TestModelNode::onKeyBoardCamera));
}

void TestModelNode::onKeyBoardCamera(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type)
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

void TestModelNode::testClipPlane()
{
	ClipPlane0* pClipPlane = CREATE_NODE(ClipPlane0);
	pClipPlane->setPosition(512, 384);
	pClipPlane->setClipNormal(1, 1, 0);

	this->addChild(pClipPlane);
}