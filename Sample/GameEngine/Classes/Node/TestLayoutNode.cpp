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

void TestLayoutNode::initNodes()
{
	this->testLayout();
}

void TestLayoutNode::testLayout()
{
	auto frameSize = Canvas::getInstance()->getView()->getViewSize();

	CtrlFile* pDisplay = CREATE_NODE(CtrlFile);
	pDisplay->setFilePath("Resource/Layout/Test.xml");
	this->addChild(pDisplay);

}

void TestLayoutNode::testLayouts()
{
	ui::CtrlLayout* pLayout = CREATE_NODE(ui::CtrlLayout);
	pLayout->setAnchorPoint(0, 0);
	pLayout->setPosition(0, 0);
	pLayout->setVolume(1027, 768);

	this->addChild(pLayout);

	auto pChildLayout = CREATE_NODE(ui::CtrlLayout);
	pLayout->setAnchorPoint(1, 1);
	pLayout->setPosition(1024, 768);
	pLayout->setVolume(500, 500);
	pLayout->setBackgroudMaskVisible(true);

	pLayout->addWidget(pChildLayout);

}





