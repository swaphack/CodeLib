#include "TestModelNode.h"
#include "system.h"
#include "Utility.h"

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
	//this->testCubeMap();

	//this->testObj();
}

void TestModelNode::testCubeModel()
{
	std::string filepath = "Resource/Image/NeHe.png";

	render::Cube* pModel = CREATE_NODE(render::Cube);
	pModel->setFaceImage(filepath);

	pModel->setAnchorPoint(math::Vector3(0.5f, 0.5f, 0.5f));
	pModel->setPosition(512, 384, 0);
	pModel->setVolume(200, 200, 200);
	this->addChild(pModel);

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(0, 45, 0);
	pRotateByAction->setDuration(5);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pModel->getActionProxy()->runAction(pRepeateAction);
}

void TestModelNode::testSphereModel()
{
	
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
	std::string filepath = "Resource/Image/NeHe.png";
	std::string filepath1 = "Resource/Image/1.jpg";

	MultiFaceCube* pModel = CREATE_NODE(MultiFaceCube);
	pModel->setAllFacesImage(filepath);
	pModel->setFaceImage(CubeFace::FRONT, filepath1);
	pModel->setFaceImage(CubeFace::LEFT, filepath1);
	pModel->setFaceImage(CubeFace::TOP, filepath1);

	pModel->setAnchorPoint(math::Vector3(0.5f, 0.5f, 0.5f));
	pModel->setPosition(200, 200, -50);
	pModel->setVolume(200, 200, 200);
	this->addChild(pModel);

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(0, 45, 0);
	pRotateByAction->setDuration(5);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pModel->getActionProxy()->runAction(pRepeateAction);
}

void TestModelNode::testCubeMap()
{
	render::CubeMap* pCubMap = CREATE_NODE(render::CubeMap);
	pCubMap->setFaceImage(CubeFace::LEFT, "Resource/skybox/left.jpg");
	pCubMap->setFaceImage(CubeFace::RIGHT, "Resource/skybox/right.jpg");
	pCubMap->setFaceImage(CubeFace::FRONT, "Resource/skybox/front.jpg");
	pCubMap->setFaceImage(CubeFace::BACK, "Resource/skybox/back.jpg");
	pCubMap->setFaceImage(CubeFace::TOP, "Resource/skybox/top.jpg");
	pCubMap->setFaceImage(CubeFace::BOTTOM, "Resource/skybox/bottom.jpg");

	//pSkyBox->setScale(0.25f);
	pCubMap->setVolume(2048, 2048, 2048);
	pCubMap->setPosition(512, 384, 0);
	pCubMap->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pCubMap);

	Utility::loadShader(pCubMap->getMaterials(), "Shader/cubemap.vs", "Shader/cubemap.fs");

	RotateByAction* pAction = CREATE_ACTION(RotateByAction);
	pAction->setRotation(0, 180, 0);
	pAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pAction);

	pCubMap->getActionProxy()->runAction(pRepeateAction);
}

void TestModelNode::testFog()
{
	Fog* pFog = CREATE_NODE(Fog);
	pFog->setDensity(0.015);
	pFog->setNear(0);
	pFog->setFar(1000);
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
	G_KEYBOARDMANAGER->addKeyboardDelegate(this, camera, KEYBOARD_DELEGATE_SELECTOR(TestModelNode::onKeyBoardCamera));
}

void TestModelNode::onKeyBoardCamera(render::Node* node, sys::BoardKey key, sys::ButtonStatus type)
{
	Camera* pNode = node->as<Camera>();
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