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

void TestModelNode::initNodes()
{
	addLight();
	this->testCubeModel();
	//this->testSphereModel();
	//this->testCubeMap();
	//this->testObj();

	//this->testObj();
	//this->test3ds();
	this->testFbx();
}

void TestModelNode::testCubeModel()
{
	std::string filepath = "Resource/Image/NeHe.png";

	render::Cube* pModel = CREATE_NODE(render::Cube);
	pModel->setSupportLight(true);
	pModel->setTexture(filepath);
	pModel->setAnchorPoint(math::Vector3(0.5f, 0.5f, 0.5f));
	pModel->setPosition(512, 384, 0);
	pModel->setVolume(200, 200, 200);
	Utility::loadShaderVF(pModel, "Shader/texture/texture.vs", "Shader/texture/texture.fs");
	this->addChild(pModel);
	
	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setDifferentRotation(0, 360, 0);
	pRotateByAction->setDuration(5);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pModel->getActionProxy()->runAction(pRepeateAction);

}

void TestModelNode::testSphereModel()
{
	auto pTexture = G_TEXTURE_CACHE->createTexture2D("Resource/Image/world_texture.jpg");
	render::Sphere* pModel = CREATE_NODE(render::Sphere);
	pModel->setTexture(pTexture);
	pModel->setRadius(200);
	pModel->setVolume(400, 400, 400);
	pModel->setAnchorPoint(0.5, 0.5f, 0.5f);
	pModel->setPosition(512, 384, 0);
	this->addChild(pModel);

	Utility::loadShaderVF(pModel, "Shader/texture/texture.vs", "Shader/texture/texture.fs");
	Utility::runRotateAction(pModel);
}

void TestModelNode::addLight()
{
	Light* pSpotLight = CREATE_NODE(Light);
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
	pModel->setAllFacesTexture(filepath);
	pModel->setFaceTexture(CubeFace::FRONT, filepath1);
	pModel->setFaceTexture(CubeFace::LEFT, filepath1);
	pModel->setFaceTexture(CubeFace::TOP, filepath1);

	pModel->setAnchorPoint(math::Vector3(0.5f, 0.5f, 0.5f));
	pModel->setPosition(200, 200, -50);
	pModel->setVolume(200, 200, 200);
	this->addChild(pModel);

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setDifferentRotation(0, 45, 0);
	pRotateByAction->setDuration(5);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pModel->getActionProxy()->runAction(pRepeateAction);
}

void TestModelNode::testCubeMap()
{
	render::CubeMap* pCubMap = CREATE_NODE(render::CubeMap);
	pCubMap->setFaceTexture(CubeFace::LEFT, "Resource/skybox/left.jpg");
	pCubMap->setFaceTexture(CubeFace::RIGHT, "Resource/skybox/right.jpg");
	pCubMap->setFaceTexture(CubeFace::FRONT, "Resource/skybox/front.jpg");
	pCubMap->setFaceTexture(CubeFace::BACK, "Resource/skybox/back.jpg");
	pCubMap->setFaceTexture(CubeFace::TOP, "Resource/skybox/top.jpg");
	pCubMap->setFaceTexture(CubeFace::BOTTOM, "Resource/skybox/bottom.jpg");

	//pSkyBox->setScale(0.25f);
	pCubMap->setVolume(2048, 2048, 2048);
	pCubMap->setPosition(512, 384, 0);
	pCubMap->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pCubMap);

	Utility::loadShaderVF(pCubMap, "Shader/cubemap/cubemap.vs", "Shader/cubemap/cubemap.fs");

	RotateByAction* pAction = CREATE_ACTION(RotateByAction);
	pAction->setDifferentRotation(0, 180, 0);
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
	pModel->load("Resource/Model/3DS/Bld_38.3ds");
	pModel->setScale(100);
	pModel->setPosition(500, 500, 0);
	pModel->setVolume(400, 400, 400);
	this->addChild(pModel);

	Utility::loadShaderVF(pModel, "Shader/material/material_texture.vs", "Shader/material/material_one_texture_light.fs");

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setDifferentRotation(180, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pModel->getActionProxy()->runAction(pRepeateAction);
}

void TestModelNode::testObj()
{
	//std::string filename = "Resource/Model/Obj/SCI_FRS_13_HD/SCI_FRS_13_HD.obj";
	std::string filename = "Resource/Model/Obj/Skull_v3_L2/12140_Skull_v3_L2.obj";

	ModelObj* pModel = CREATE_NODE(ModelObj);
	pModel->load(filename);
	pModel->setScale(50);
	pModel->setPosition(512, 384, 0);
	pModel->setVolume(400, 400, 400);
	this->addChild(pModel);

	Utility::loadShaderVF(pModel, "Shader/texture/texture.vs", "Shader/texture/texture.fs");

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setDifferentRotation(180, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pModel->getActionProxy()->runAction(pRepeateAction);
}

void TestModelNode::testFbx()
{
	ModelFbx* pModel = CREATE_NODE(ModelFbx);
	pModel->load("Resource/Model/fbx/LANCER_EVOLUTION/LANCEREVOX.FBX");
	pModel->setScale(200);
	pModel->setPosition(512, 384);
	pModel->setRotation(90, 0, 90);
	this->addChild(pModel);

	Utility::loadShaderVF(pModel, "Shader/texture/texture.vs", "Shader/texture/texture.fs");

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setDifferentRotation(0, 180, 0);
	pRotateByAction->setDuration(4);

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