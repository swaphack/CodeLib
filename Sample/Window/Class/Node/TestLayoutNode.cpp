#include "TestLayoutNode.h"

#include "ui.h"

using namespace ui;

TestLayoutNode::TestLayoutNode()
{

}

TestLayoutNode::~TestLayoutNode()
{

}

void TestLayoutNode::testFunc()
{

}

void TestLayoutNode::testLayout()
{
	Display* pDisplay = new Display();
	pDisplay->setUIRoot(this);
	pDisplay->setFilePath("Resource/Layout/test.xml");
	pDisplay->show();
}


