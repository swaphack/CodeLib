#include "TestTextNode.h"
#include "system.h"

using namespace sys;
using namespace render;

TestTextNode::TestTextNode()
{

}

TestTextNode::~TestTextNode()
{
	
}

void TestTextNode::testFunc()
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
	pCtrlText->setPosition(522, 450, 0);
	pCtrlText->setVerticalAlignment(EVA_CENTER);
	pCtrlText->setTextColor(sys::Color3B(255, 255, 255));
	this->addChild(pCtrlText);


	CallFuncN* pCallFunc = CREATE_ACTION(CallFuncN);
	pCallFunc->setFunc([](sys::Object* sender){
		char strVal[255] = {};
		Time* t = Time::getNow();
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
	pCtrlText->setHorizontalAlignment(EHA_CENTER);
	pCtrlText->setVerticalAlignment(EVA_CENTER);
	pCtrlText->setFontPath("Resource/Font/font_2.ttf");
	pCtrlText->setFontSize(58);
	pCtrlText->setScale(1);
	pCtrlText->setString("�л� fdsaf545�Ŵ����񹲺͹�");
	pCtrlText->setPosition(512, 384, 0);
	pCtrlText->setDimensions(300, 600);
	pCtrlText->setTextColor(sys::Color3B(125, 0, 0));
	this->addChild(pCtrlText);
}