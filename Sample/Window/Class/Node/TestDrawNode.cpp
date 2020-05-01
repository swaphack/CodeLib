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

}

void TestDrawNode::testDrawNode()
{
	math::Vector2 points[] = {
		{ 100, 100 },
		{ 50, 50 },
		{ 75, 60 },
		{ 150, 50 },
		{ 200, 100 },
		{ 120, 110 },
	};

	int COUNT = (sizeof(points) / sizeof(math::Vector2));

	DrawNode* pDrawNode = CREATE_NODE(DrawNode);
	pDrawNode->setDrawMode(ShapeMode::POLYGON);
	pDrawNode->setColor(sys::Color3B(0, 255, 0));
	for (int i = 0; i < COUNT; i++)
	{
		pDrawNode->appendPoint(math::Vector3(points[i]));
	}
	this->addChild(pDrawNode);
}

