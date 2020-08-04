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
	this->addSun();

	this->testCubeModel();

	//this->addEarth();
}

void TestLightingNode::addSun()
{
	render::Sphere* pLightShape = CREATE_NODE(render::Sphere);
	pLightShape->setTexture("Resource/Image/2k_sun.jpg");
	pLightShape->setPosition(1000, 700, 50);
	pLightShape->setRadius(50);

	Utility::loadShader(pLightShape, "Shader/texture/texture.vs", "Shader/texture/texture.fs");
	this->addChild(pLightShape);

	Utility::runRotateAction(pLightShape);

	render::Light0* pLight = CREATE_NODE(render::Light0);
	pLight->setAmbient(100, 100, 100, 255);
	pLight->setDiffuse(255, 0, 0, 255);
	pLight->setSpecular(0, 255, 0, 255);
	pLightShape->addChild(pLight);

	render::EllipseAction* pAction = render::CREATE_ACTION(render::EllipseAction);
	pAction->setControlParameters(math::Vector3(150, 300), 500, 350, math::Vector3(120, 0, 0));
	pAction->setDuration(10);

	pLightShape->getActionProxy()->runAction(render::RepeateForeverAction::create(pAction));
}

void TestLightingNode::addEarth()
{
	render::Sphere* pEarth = CREATE_NODE(render::Sphere);
	pEarth->setTexture("Resource/Image/2k_earth_daymap.jpg");
	//pEarth->setDiffuseTexture("Resource/Image/2k_earth_normal_map.tif");
	//pEarth->setSpecularTexture("Resource/Image/2k_earth_specular_map.tif");
	pEarth->setRadius(150);
	pEarth->setPosition(512, 384);

	//pEarth->setShaderProgramFunc([](render::ShaderProgram* program) {
	//	auto specularPercent = program->getUniform("specularPercent");
	//	if (specularPercent) specularPercent->setValue(0.0f);
	//	auto diffusePercent = program->getUniform("diffusePercent");
	//	if (diffusePercent) diffusePercent->setValue(0.0f);
	//});

	//Utility::loadShader(pEarth, "Shader/material/material_texture_light.vs", "Shader/material/material_texture_light.fs");
	Utility::loadShader(pEarth, "Shader/material/material_single_light.vs", "Shader/material/material_single_light.fs");
	this->addChild(pEarth);

	Utility::runRotateAction(pEarth);

	/*
	render::EllipseAction* pAction = render::CREATE_ACTION(render::EllipseAction);
	pAction->setControlParameters(math::Vector3(512, 384), 400, 200, math::Vector3(0, 0, 0));
	pAction->setDuration(10);

	pEarth->getActionProxy()->runAction(render::RepeateForeverAction::create(pAction));
	*/
}

void TestLightingNode::testCubeModel()
{
	std::string filepath = "Resource/Image/NeHe.png";

	render::MultiFaceCube* pModel = CREATE_NODE(render::MultiFaceCube);
	pModel->setTexture(filepath);
	pModel->setColor(0.5f, 0.5f, 0.5f);
	pModel->setAnchorPoint(math::Vector3(0.5f, 0.5f, 0.5f));
	pModel->setPosition(512, 384, 0);
	pModel->setRotation(0, 45, 0);
	pModel->setVolume(150, 150, 150);
	Utility::loadShader(pModel, "Shader/material/material_texture.vs", "Shader/material/material_texture.fs");
	this->addChild(pModel);

	//Utility::runRotateAction(pModel);

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

