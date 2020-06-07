#include "TestLayoutNode.h"
#include "mathlib.h"
#include "ui.h"

using namespace ui;
using namespace math;
using namespace render;

TestLayoutNode::TestLayoutNode()
{

}

TestLayoutNode::~TestLayoutNode()
{

}

void TestLayoutNode::testFunc()
{
	this->testLayout();
}

void TestLayoutNode::testLayout()
{
	auto frameSize = Canvas::getInstance()->getView()->getFrameSize();

	Display* pDisplay = new Display();
	pDisplay->setUIRoot(this);
	pDisplay->setFilePath("Resource/Layout/Test.xml");
	pDisplay->show();
}


