#include "TestMeshNode.h"
#include "Utility.h"

TestMeshNode::TestMeshNode()
{

}

TestMeshNode::~TestMeshNode()
{

}

void TestMeshNode::initNodes()
{
	this->testMesh();
}

void TestMeshNode::testMesh()
{
	render::PrimitiveNode* pNode = CREATE_NODE(render::PrimitiveNode);
	pNode->setDrawMode(DrawMode::POINTS);
	pNode->setPosition(512, 384, 0);
	pNode->setPointSize(10);

	for (int i = 0; i < 100; i++)
	{
		math::Vector3 pos1(i, i, 0);
		math::Vector3 pos2(i * i - i, i * i - i, 0);
		math::Vector3 pos3(i * i + i, i * i + i, 0);

		pNode->appendPoint(pos1);
		pNode->appendPoint(pos2);
		pNode->appendPoint(pos3);
	}

	Utility::loadShaderVF(pNode, "Shader/geometry/draw_primitive.vs", "Shader/geometry/draw_primitive.fs");
	this->addChild(pNode);
}

void TestMeshNode::testBrokenMesh()
{

}

