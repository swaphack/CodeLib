#include "TestEnvironmentNode.h"
#include "Utility.h"

using namespace render;

TestEnvironmentNode::TestEnvironmentNode()
{
}

TestEnvironmentNode::~TestEnvironmentNode()
{
}

void TestEnvironmentNode::initNodes()
{
	this->testMatrix();
}

void TestEnvironmentNode::testMatrix()
{
	math::Vector3 rotate(0, 90, 0);

	math::Vector3 radian = Tool::convertToRadian(rotate);

	math::Matrix4x4 mat;
	mat.setRotate(radian);

	math::Vector3 up(0, 0, 1);

	math::Vector3 result = mat * up;

	std::vector<math::Vector3> vecData;
	vecData.push_back(math::Vector3(1, 2, 4));
	vecData.push_back(math::Vector3(5, 21, 74));
	vecData.push_back(math::Vector3(11, 52, 44));

	float aryData[9] = { 0 };
	memcpy(aryData, vecData[0].getValue(), 9 * sizeof(float));

	int a = 1;
}

void TestEnvironmentNode::testMultiPort()
{
	math::Size size = Tool::getViewSize();
	Canvas::getInstance()->setViewPort(0, 0, size.getWidth() * 0.5f, size.getHeight() * 0.5f);
}
