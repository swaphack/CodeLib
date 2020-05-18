#include "TestUINode.h"
#include "system.h"

using namespace sys;
using namespace render;

TestUINode::TestUINode()
{

}

TestUINode::~TestUINode()
{

}

void TestUINode::testFunc()
{
	this->testScissor();
}

void TestUINode::testEditBox()
{
	CtrlEditLabel* pEditLabel = CREATE_NODE(CtrlEditLabel);

	CtrlText* pCtrlText = pEditLabel->getCtrlText();
	pCtrlText->setFontPath("Resource/font_3.ttf");
	pCtrlText->setFontSize(58);
	pCtrlText->setAnchorPoint(0.0f, 0.0f, 0.0f);
	pCtrlText->setColor(sys::Color4B(125, 80, 255, 255));

	pEditLabel->setPosition(512, 384, 0);
	pEditLabel->setAnchorPoint(0.0f, 0.0f, 0.0f);
	pEditLabel->setVolume(400, 100, 0);
	pEditLabel->setKeyboardEnable(true);
	pEditLabel->setInputListen([](sys::Object* object, EditInputStatus status){
		CtrlEditLabel* pNode = dynamic_cast<CtrlEditLabel*>(object);
		if (pNode == nullptr)
		{
			return;
		}

		if (status == EditInputStatus::BEGIN)
		{
			pNode->setString("");
		}
		else if (status == EditInputStatus::END)
		{
			PRINT("Input Text %s\n", pNode->getString().c_str());
		}
	});

	this->addChild(pEditLabel);
}

void TestUINode::testSequenceFrame()
{
	CtrlSequenceFrame* pSequenceFrame = CREATE_NODE(CtrlSequenceFrame);
	pSequenceFrame->setVolume(1024, 768);
	pSequenceFrame->setFrameImagePath("Resource/Role/1/20%d.png", 8);
	pSequenceFrame->setPosition(512, 384, 0);
	pSequenceFrame->setFrameRate(1.0f / 10);
	pSequenceFrame->start();

	//pSequenceFrame->getMovie()->setBlend(EBFS_SRC_ALPHA, EBFD_ONE_MINUS_SRC_ALPHA);
	//pSequenceFrame->getMovie()->setColor(Color3B(0.299f * 255, 0.587f * 255, 0.114f * 255));
	//pSequenceFrame->getMovie()->setOpacity(255);

	this->addChild(pSequenceFrame);
	G_KEYBOARDMANAGER->addDispatcher(pSequenceFrame, this, KEYBOARD_DELEGATTE_SELECTOR(TestUINode::onKeyBoardRole));
}

void TestUINode::onKeyBoardRole(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type)
{
	if (type != ButtonStatus::BUTTON_DOWN)
	{
		return;
	}

	CtrlSequenceFrame* pRole = static_cast<CtrlSequenceFrame*>(object);
	if (pRole == nullptr)
	{
		return;
	}

	struct DirectionAction
	{
		bool bFlipX;
		char path[25];
		int count;
	};

	static DirectionAction ActionConfigs[4] = {
		{ false, "Resource/Role/3/24%d.png", 8 },
		{ false, "Resource/Role/1/20%d.png", 8 },
		{ false, "Resource/Role/2/22%d.png", 8 },
		{ true, "Resource/Role/2/22%d.png", 8 },
	};


	int index = 0;

	if (key == BoardKey::KUP)
	{
		index = 0;
	}
	else if (key == BoardKey::KDOWN)
	{
		index = 1;
	}
	else if (key == BoardKey::KLEFT)
	{
		index = 2;
	}
	else if (key == BoardKey::KRIGHT)
	{
		index = 3;
	}

	if (pRole)
	{
		DirectionAction* pConfig = &ActionConfigs[index];
		if (pRole->getMovie()->isFlipX() != pConfig->bFlipX)
		{
			pRole->getMovie()->setFlipX(pConfig->bFlipX);
		}
		pRole->setFrameImagePath(pConfig->path, pConfig->count);
	}
}

void TestUINode::testScissor()
{
	CtrlLayout* pLayout = CREATE_NODE(CtrlLayout);
	pLayout->setBackgroundColor(sys::Color4B(255, 0, 0, 125));
	pLayout->setBackgroundImage("Resource/Image/1.jpg");
	pLayout->setClip(true);
	pLayout->setVolume(200, 200, 0);
	pLayout->setPosition(200, 200);
	this->addChild(pLayout);

	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Image/sqi.png");
	pImage->setVolume(300, 300, 0);
	pImage->setScale(3, 3, 1);
	pLayout->addChild(pImage);
}

void TestUINode::testScrollView()
{
	CtrlScrollView* pScrollView = CREATE_NODE(CtrlScrollView);
	pScrollView->setPosition(512, 384);
	pScrollView->setVolume(200, 600);
	pScrollView->setItemSize(200, 200);
	this->addChild(pScrollView);

	for (int i = 0; i < 10; i++)
	{
		CtrlImage* pImage = CREATE_NODE(CtrlImage);
		pImage->setImagePath("Resource/Image/sqi.png");
		pImage->setVolume(200, 200, 0);
		pScrollView->append(pImage);
	}

	pScrollView->setScrollDirection(ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT);
}

void TestUINode::testMask()
{
	CtrlMask* pMask = CREATE_NODE(CtrlMask);
	pMask->setAnchorPoint(0, 0, 0);
	pMask->setPosition(0, 0, 0.0f);
	pMask->setVolume(1024, 768, 0);
	pMask->setColor(Color4B(120, 120, 120, 125));
	this->addChild(pMask);
}
