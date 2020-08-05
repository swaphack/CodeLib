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

	this->addStar();

	this->testCubeModel();

	this->addEarth();
}

void TestLightingNode::addSun()
{
	render::Sphere* pLightShape = CREATE_NODE(render::Sphere);
	pLightShape->setTexture("Resource/Image/2k_sun.jpg");
	pLightShape->setPosition(1024, 768, 00);
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
	pLightShape->setPosition(512, 384, 0);
	pLightShape->setRadius(50);

	Utility::loadShader(pLightShape, "Shader/texture/texture.vs", "Shader/texture/texture.fs");
	this->addChild(pLightShape);

	render::PointLight* pLight = CREATE_NODE(render::PointLight);
	pLight->setAmbient(100, 100, 100, 100);
	pLight->setDiffuse(100, 100, 100, 100);
	pLight->setSpecular(100, 100, 100, 100);
	pLight->setLinearAttenuation(0);
	pLight->setQuadraticAttenuation(0);
	pLightShape->addChild(pLight);

	render::EllipseAction* pAction = render::CREATE_ACTION(render::EllipseAction);
	pAction->setControlParameters(math::Vector3(512, 384), 400, 200, math::Vector3(0, 0, 0));
	pAction->setDuration(10);

	pLightShape->getActionProxy()->runAction(render::RepeateForeverAction::create(pAction));
}

void TestLightingNode::addEarth()
{
	render::Sphere* pEarth = CREATE_NODE(render::Sphere);
	pEarth->setSupportLight(true);
	//pEarth->setSupportMultiLight(true);
	pEarth->setTexture("Resource/Image/2k_earth_daymap.jpg");
	//pEarth->setDiffuseTexture("Resource/Image/2k_earth_normal_map.tif");
	//pEarth->setSpecularTexture("Resource/Image/2k_earth_specular_map.tif");
	pEarth->setRadius(150);
	pEarth->setPosition(200, 400);

	pEarth->setShaderProgramFunc([](render::ShaderProgram* program) {
		auto specularPercent = program->getUniform("specularPercent");
		if (specularPercent) specularPercent->setValue(0.25f);
		auto diffusePercent = program->getUniform("diffusePercent");
		if (diffusePercent) diffusePercent->setValue(0.25f);
	});

	//Utility::loadShader(pEarth, "Shader/material/material_texture.vs", "Shader/material/material_texture.fs");
	//Utility::loadShader(pEarth, "Shader/material/material_single_light.vs", "Shader/material/material_multi_lights.fs");
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
	pModel->setSupportLight(true);
	pModel->setTexture(filepath);
	pModel->setColor(0.5f, 0.5f, 0.5f);
	pModel->setAnchorPoint(math::Vector3(0.5f, 0.5f, 0.5f));
	pModel->setPosition(512, 384, 10);
	pModel->setRotation(0, 45, 0);
	pModel->setVolume(150, 150, 150);
	//Utility::loadShader(pModel, "Shader/material/material_texture.vs", "Shader/material/material_texture.fs");
	Utility::loadShader(pModel, "Shader/material/material_single_light.vs", "Shader/material/material_single_light.fs");
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

