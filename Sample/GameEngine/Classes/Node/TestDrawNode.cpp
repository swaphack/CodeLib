#include "TestDrawNode.h"

#include "mathlib.h"

using namespace render;

TestDrawNode::TestDrawNode()
{

}

TestDrawNode::~TestDrawNode()
{

}

void TestDrawNode::testFunc()
{
	testDrawNode();
}

void TestDrawNode::testDrawNode()
{
	math::Vector2 points[] = {
		{ 100, 100 },
		{ 100, 200 },
		{ 300, 300 },
		{ 200, 300 },
		{ 100, 200 },
		{ 100, 100 },
	};

	int COUNT = (sizeof(points) / sizeof(math::Vector2));

	PrimitiveNode* pDrawNode = CREATE_NODE(PrimitiveNode);
	pDrawNode->setDrawMode(ShapeMode::POLYGON);
	pDrawNode->setColor(sys::Color3B(0, 255, 0));
	for (int i = 0; i < COUNT; i++)
	{
		pDrawNode->appendPoint(math::Vector3(points[i]));
	}
	this->addChild(pDrawNode);
}

