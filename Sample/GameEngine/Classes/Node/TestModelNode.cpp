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
	//this->test3ds();
	//this->testFbx();
	this->testObj();
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
	pModel->setFaceTexture(ModelFace::FRONT, textureName1);
	pModel->setFaceTexture(ModelFace::LEFT, textureName1);
	pModel->setFaceTexture(ModelFace::TOP, textureName1);

	pModel->setAnchorPoint(math::Vector3(0.5f, 0.5f, 0.5f));
	pModel->setPosition(200, 200, -50);
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
	std::string filepath = "Resource/Image/NeHe.png";
	Texture2D* texture2D = G_TEXTURE_CACHE->createTexture2D(filepath);

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
	Model3DS* pModel = CREATE_NODE(Model3DS);
	pModel->load("Resource/3DS/Bld_38.3ds");
	pModel->setScale(100);
	pModel->setPosition(500, 500, 0);
	pModel->setVolume(400, 400, 400);
	this->addChild(pModel);

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(180, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pModel->getActionProxy()->runAction(pRepeateAction);
}

void TestModelNode::testObj()
{
	//std::string filename = "Resource/Obj/SCI_FRS_13_HD/SCI_FRS_13_HD.obj";
	std::string filename = "Resource/Obj/Skull_v3_L2/12140_Skull_v3_L2.obj";

	ModelObj* pModel = CREATE_NODE(ModelObj);
	pModel->load(filename);
	pModel->setScale(50);
	pModel->setPosition(512, 384, 0);
	pModel->setVolume(400, 400, 400);
	this->addChild(pModel);

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(180, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pModel->getActionProxy()->runAction(pRepeateAction);
}

void TestModelNode::testFbx()
{
	ModelFbx* pModel = CREATE_NODE(ModelFbx);
	pModel->load("Resource/fbx/LANCER_EVOLUTION/LANCEREVOX.FBX");
	pModel->setScale(200);
	pModel->setRotationX(0);
	this->addChild(pModel);

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(0, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pModel->getActionProxy()->runAction(pRepeateAction);
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
	if (type != ButtonStatus::BUTTON_DOWN)
	{
		return;
	}

	float speed = 2;
	if (key == BoardKey::KUP)
	{
		pNode->setPositionY(pNode->getPositionY() + speed);
	}
	else if (key == BoardKey::KDOWN)
	{
		pNode->setPositionY(pNode->getPositionY() - speed);
	}
	else if (key == BoardKey::KLEFT)
	{
		pNode->setPositionX(pNode->getPositionX() - speed);
	}
	else if (key == BoardKey::KRIGHT)
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