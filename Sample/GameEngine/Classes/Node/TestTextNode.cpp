#include "TestTextNode.h"
#include "system.h"
#include "ui.h"

using namespace sys;
using namespace render;
using namespace ui;

TestTextNode::TestTextNode()
{

}

TestTextNode::~TestTextNode()
{
	
}

void TestTextNode::initNodes()
{
	this->testTimeText();
	this->testChineseText();
}

void TestTextNode::testTimeText()
{
	CtrlText* pCtrlText = CREATE_NODE(CtrlText);
	pCtrlText->setFontPath("Resource/Font/font_3.ttf");
	pCtrlText->setFontSize(58);
	pCtrlText->setScale(1);
	pCtrlText->setString("hafkdfjkldafd");
	pCtrlText->setPosition(522, 600, 0);
	pCtrlText->setTextVerticalAlignment(VerticalAlignment::MIDDLE);
	pCtrlText->setTextColor(phy::Color3B(255, 255, 255));
	this->addChild(pCtrlText);


	CallFuncN* pCallFunc = CREATE_ACTION(CallFuncN);
	pCallFunc->setFunc([](sys::Object* sender){
		char strVal[255] = {};
		DateTime* t = DateTime::getNow();
		sprintf(strVal, "%d-%d-%d %02d:%02d:%02d\n", t->getYear(), t->getMonth(), t->getMonthDay(), t->getHour(), t->getMinute(), t->getSecond());
		((CtrlText*)sender)->setString(strVal);
	});

	DelayAction* pDelayAction = CREATE_ACTION(DelayAction);
	pDelayAction->setDuration(1);

	SequenceAction* pSequenceAction = CREATE_ACTION(SequenceAction);
	pSequenceAction->addAction(pCallFunc);
	pSequenceAction->addAction(pDelayAction);

	RepeateForeverAction* pRepeateForeverAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateForeverAction->setAction(pSequenceAction);

	pCtrlText->getActionProxy()->runAction(pRepeateForeverAction);
}

void TestTextNode::testChineseText()
{
	CtrlText* pCtrlText = CREATE_NODE(CtrlText);
	pCtrlText->setTextHorizontalAlignment(HorizontalAlignment::CENTER);
	pCtrlText->setTextVerticalAlignment(VerticalAlignment::MIDDLE);
	pCtrlText->setFontPath("Resource/Font/font_2.ttf");
	pCtrlText->setFontSize(58);
	pCtrlText->setScale(1);
	pCtrlText->setString("中华 fdsaf545放大发人民共和国");
	pCtrlText->setPosition(512, 384, 0);
	pCtrlText->setDimensions(300, 0);
	pCtrlText->setTextColor(phy::Color3B(125, 0, 0));
	this->addChild(pCtrlText);
}
