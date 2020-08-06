#include "TestLightingNode.h"
#include "render.h"
#include "Utility.h"

TestLightingNode::TestLightingNode()
{

}

TestLightingNode::~TestLightingNode()
{

}

void TestLightingNode::initNodes()
{
	this->addGround();

	this->addSun();

	this->addStar();

	this->testCubeModel();

	this->addEarth();
}

void TestLightingNode::addSun()
{
	render::Sphere* pLightShape = CREATE_NODE(render::Sphere);
	pLightShape->setTexture("Resource/Image/2k_sun.jpg");
	pLightShape->setPosition(1024, 768, 0);
	pLightShape->setRadius(50);

	Utility::loadShader(pLightShape, "Shader/texture/texture.vs", "Shader/texture/texture.fs");
	this->addChild(pLightShape);

	render::DirectionLight* pLight = CREATE_NODE(render::DirectionLight);
	pLight->setAmbient(100, 100, 100, 100);
	pLight->setDiffuse(100, 100, 100, 100);
	pLight->setSpecular(100, 100, 100, 100);
	pLight->setDirection(1, 1, 0);
	pLightShape->addChild(pLight);
}

void TestLightingNode::addStar()
{
	render::Sphere* pLightShape = CREATE_NODE(render::Sphere);
	pLightShape->setSupportLight(true);
	pLightShape->setTexture("Resource/Image/2k_venus_surface.jpg");
	pLightShape->setPosition(512, 384, 400);
	pLightShape->setRadius(50);

	Utility::loadShader(pLightShape, "Shader/texture/texture.vs", "Shader/texture/texture.fs");
	this->addChild(pLightShape);

	render::PointLight* pLight = CREATE_NODE(render::PointLight);
	pLight->setColor(255, 0, 0, 255);
	pLight->setAmbient(255, 255, 255, 255);
	pLight->setDiffuse(255, 255, 255, 255);
	pLight->setSpecular(255, 255, 255, 255);
	pLight->setLinearAttenuation(0);
	pLight->setQuadraticAttenuation(0);
	pLightShape->addChild(pLight);

	render::EllipseAction* pAction = render::CREATE_ACTION(render::EllipseAction);
	pAction->setControlParameters(math::Vector3(512, 384, 400), 400, 200, math::Vector3(0, 0, 0));
	pAction->setDuration(10);

	pLightShape->getActionProxy()->runAction(render::RepeateForeverAction::create(pAction));
}

void TestLightingNode::addEarth()
{
	render::Sphere* pEarth = CREATE_NODE(render::Sphere);
	pEarth->setSupportLight(true);
	//pEarth->setSupportMultiLight(true);
	pEarth->setTexture("Resource/Image/2k_earth_daymap.jpg");
	pEarth->setDiffuseTexture("Resource/Image/2k_earth_normal_map.tif");
	pEarth->setSpecularTexture("Resource/Image/2k_earth_specular_map.tif");
	pEarth->setRadius(300);
	pEarth->setPosition(200, 400);

	pEarth->setShaderProgramFunc([](render::ShaderProgram* program) {
		auto diffusePercent = program->getUniform("diffusePercent");
		if (diffusePercent) diffusePercent->setValue(0.2f);
		auto specularPercent = program->getUniform("specularPercent");
		if (specularPercent) specularPercent->setValue(0.8f);
	});

	//Utility::loadShader(pEarth, "Shader/material/material_texture_light.vs", "Shader/material/material_texture_light.fs");
	Utility::loadShader(pEarth, "Shader/material/material_emulate_diffuse.vs", "Shader/material/material_emulate_diffuse.fs");
	//Utility::loadShader(pEarth, "Shader/material/material_single_light.vs", "Shader/material/material_single_light.fs");
	this->addChild(pEarth);

	Utility::runRotateAction(pEarth);

	/*
	render::EllipseAction* pAction = render::CREATE_ACTION(render::EllipseAction);
	pAction->setControlParameters(math::Vector3(512, 384), 400, 200, math::Vector3(0, 0, 0));
	pAction->setDuration(10);

	pEarth->getActionProxy()->runAction(render::RepeateForeverAction::create(pAction));
	*/
}

void TestLightingNode::addGround()
{
	std::string filepath = "Resource/Image/ground.jpg";

	render::Plane* pModel = CREATE_NODE(render::Plane);
	pModel->setSupportLight(true);
	pModel->setSupportMultiLight(true);
	pModel->setTexture(filepath);
	pModel->setColor(0.5f, 0.5f, 0.5f);
	pModel->setAnchorPoint(math::Vector3(0.5f, 0.5f, 0.5f));
	pModel->setPosition(512, 384, -300);
	pModel->setRotation(0, 0, 0);
	pModel->setVolume(1024, 768);
	//Utility::loadShader(pModel, "Shader/material/material_texture.vs", "Shader/material/material_texture.fs");
	Utility::loadShader(pModel, "Shader/material/material_single_light.vs", "Shader/material/material_multi_lights.fs");
	this->addChild(pModel);

	pModel->setShaderProgramFunc([](render::ShaderProgram* program) {
		auto gamma = program->getUniform("env.gamma");
		if (gamma) gamma->setValue(5.0f);
	});

	render::MoveByAction* pAction0 = render::CREATE_ACTION(render::MoveByAction);
	pAction0->setDifferentPosition(math::Vector3(0, 0, 600));
	pAction0->setDuration(10);

	render::MoveByAction* pAction1 = render::CREATE_ACTION(render::MoveByAction);
	pAction1->setDifferentPosition(math::Vector3(0, 0, -600));
	pAction1->setDuration(10);

	render::SequenceAction* pAction2 = render::CREATE_ACTION(render::SequenceAction);
	pAction2->addAction(pAction0);
	pAction2->addAction(pAction1);

	pModel->getActionProxy()->runAction(render::RepeateForeverAction::create(pAction2));
}

void TestLightingNode::testCubeModel()
{
	std::string filepath = "Resource/Image/NeHe.png";

	render::MultiFaceCube* pModel = CREATE_NODE(render::MultiFaceCube);
	pModel->setSupportLight(true);
	pModel->setTexture(filepath);
	pModel->setColor(0.5f, 0.5f, 0.5f);
	pModel->setAnchorPoint(math::Vector3(0.5f, 0.5f, 0.5f));
	pModel->setPosition(512, 384, 0);
	pModel->setRotation(0, 45, 0);
	pModel->setVolume(200, 200, 200);
	//Utility::loadShader(pModel, "Shader/material/material_texture.vs", "Shader/material/material_texture.fs");
	Utility::loadShader(pModel, "Shader/material/material_single_light.vs", "Shader/material/material_single_light.fs");
	this->addChild(pModel);

	Utility::runRotateAction(pModel);

	pModel->getTouchProxy()->addTouchFunc(render::TouchType::DOWN, [](render::Node* node, float x, float y, bool include) {
		if (!include)
		{
			return;
		}
		auto cube = node->as<render::MultiFaceCube>();
		if (cube == nullptr)
		{
			return;
		}

		cube->setBoxVisible(!cube->isBoxVisible());
	});
}

