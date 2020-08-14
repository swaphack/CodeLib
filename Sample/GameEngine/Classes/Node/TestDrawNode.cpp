#include "TestDrawNode.h"
#include "Utility.h"
#include "mathlib.h"

using namespace render;

TestDrawNode::TestDrawNode()
{

}

TestDrawNode::~TestDrawNode()
{

}

void TestDrawNode::initNodes()
{
	testDrawNode();
}

void TestDrawNode::testDrawNode()
{
	math::Vector2 points[] = {
		{ -200, -200 },
		{ 200, -200 },
		{ 200, 200 },
		{ -200, -200 },
		{ 200, 200 },
		{ -200, 200 },
	};

	int COUNT = (sizeof(points) / sizeof(math::Vector2));

	PrimitiveNode* pDrawNode = CREATE_NODE(PrimitiveNode);
	pDrawNode->setPointSize(10);
	pDrawNode->setDrawMode(DrawMode::TRIANGLES);
	pDrawNode->setColor(sys::Color4F(0, 1, 0));
	for (int i = 0; i < COUNT; i++)
	{
		pDrawNode->appendPoint(math::Vector3(points[i]));
	}

	Utility::loadShader(pDrawNode, "Shader/geometry/draw_primitive.vs", "Shader/geometry/draw_primitive.fs");
	this->addChild(pDrawNode);

	auto vector = pDrawNode->getPosition() - Camera::getMainCamera()->getPosition();

	auto pAction = CREATE_ACTION(CallFunc);
	pAction->setFunc([pDrawNode, vector]() {
		auto cameraPos = Camera::getMainCamera()->getPosition();
		auto cameraRotate = Camera::getMainCamera()->getRotation();
		math::Vector3 cameraRadian = Tool::convertToRadian(cameraRotate);
		math::Matrix4x4 mat; 
		mat.setRotate(1.0f * cameraRadian);
		auto pos = math::Matrix4x4::transpose(vector, mat);

		pDrawNode->setPosition(cameraPos + pos);
		pDrawNode->setRotation(-1.0f * cameraRotate);
	});

	auto pAction1 = CREATE_ACTION(RepeateForeverAction);
	pAction1->setAction(pAction);

	pDrawNode->getActionProxy()->runAction(pAction1);
}

