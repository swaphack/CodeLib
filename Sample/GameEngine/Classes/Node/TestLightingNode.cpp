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

	this->addEarth();
}

void TestLightingNode::addSun()
{
	render::Sphere* pLightShape = CREATE_NODE(render::Sphere);
	pLightShape->setTexture("Resource/Image/2k_sun.jpg");
	pLightShape->setPosition(512, 384);
	pLightShape->setRadius(50);

	Utility::loadShader(pLightShape, "Shader/texture/texture.vs", "Shader/texture/texture.fs");
	this->addChild(pLightShape);

	Utility::runRotateAction(pLightShape);

	render::Light0* pLight = CREATE_NODE(render::Light0);
	pLight->setAmbient(100, 100, 100, 255);
	pLight->setDiffuse(255, 0, 0, 255);
	pLight->setSpecular(0, 255, 0, 255);
	pLightShape->addChild(pLight);
}

void TestLightingNode::addEarth()
{
	render::Sphere* pEarth = CREATE_NODE(render::Sphere);
	pEarth->setTexture("Resource/Image/2k_earth_daymap.jpg");
	pEarth->setRadius(25);

	//Utility::loadShader(pEarth, "Shader/texture/texture.vs", "Shader/texture/texture.fs");
	Utility::loadShader(pEarth, "Shader/material/material_texture.vs", "Shader/material/material_texture.fs");
	this->addChild(pEarth);

	Utility::runRotateAction(pEarth);

	render::EllipseAction* pAction = render::CREATE_ACTION(render::EllipseAction);
	pAction->setControlParameters(math::Vector3(512, 384), 400, 200, math::Vector3(45, 45, 0));
	pAction->setDuration(10);

	pEarth->getActionProxy()->runAction(render::RepeateForeverAction::create(pAction));
}

