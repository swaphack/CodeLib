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
	this->addLight();
}

void TestLightingNode::addLight()
{
	render::Sphere* pLightShape = CREATE_NODE(render::Sphere);
	pLightShape->setPosition(512, 384);
	pLightShape->setRadius(50);
	Utility::loadShader(pLightShape->getMaterials(), "Shader/env/light.vs", "Shader/env/light.fs");
	this->addChild(pLightShape);

	render::Light0* pLight = CREATE_NODE(render::Light0);
	pLight->setAmbient(255, 255, 255, 255);
	pLight->setDiffuse(255, 255, 255, 255);
	pLight->setSpecular(255, 255, 255, 255);
	pLightShape->addChild(pLight);
}

