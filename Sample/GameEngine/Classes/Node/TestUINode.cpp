#include "TestUINode.h"
#include "system.h"
#include "../Env/Utility.h"
#include "ui.h"

using namespace sys;
using namespace render;
using namespace ui;

TestUINode::TestUINode()
{

}

TestUINode::~TestUINode()
{

}

void TestUINode::initNodes()
{
	this->testMask();

	//this->testScissor();
	
	//this->testScrollView();

	//this->testListView();
	
	//this->testStencil();

	//this->testSequenceFrame();

	//this->testImage();
	
	//this->testButton();
	//
	//this->testWidget();
	
	//this->testText();
}

void TestUINode::testEditBox()
{
	CtrlEditText* pEditLabel = CREATE_NODE(CtrlEditText);

	CtrlText* pCtrlText = pEditLabel->getTextControl();
	pCtrlText->setFontPath("Resource/Font/font_3.ttf");
	pCtrlText->setFontSize(58);
	pCtrlText->setAnchorPoint(0.0f, 0.0f, 0.0f);
	pCtrlText->setTextColor(phy::Color3B(125, 80, 255));
	Utility::loadDefaultShader(pCtrlText);

	pEditLabel->setPosition(512, 384, 0);
	pEditLabel->setAnchorPoint(0.0f, 0.0f, 0.0f);
	pEditLabel->setVolume(400, 100, 0);
	pEditLabel->setKeyboardEnable(true);
	pEditLabel->setInputListen([](sys::Object* object, EditInputStatus status){
		CtrlEditText* pNode = object->as<CtrlEditText>();
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
	Utility::loadDefaultShader(pEditLabel);
	this->addChild(pEditLabel);
}

void TestUINode::testSequenceFrame()
{
	SequenceFrame* pSequenceFrame = CREATE_NODE(SequenceFrame);
	pSequenceFrame->setVolume(1024, 768);
	pSequenceFrame->setFrameImagePath("Resource/Role/1/20%d.png", 8);
	pSequenceFrame->setPosition(512, 384, 0);
	pSequenceFrame->setFrameRate(1.0f / 10);

	Utility::loadDefaultShader(pSequenceFrame->getRenderNode());

	pSequenceFrame->start();

	this->addChild(pSequenceFrame);
	G_KEYBOARDMANAGER->addKeyboardDelegate(this, pSequenceFrame, KEYBOARD_DELEGATE_SELECTOR(TestUINode::onKeyBoardRole));
}

void TestUINode::onKeyBoardRole(render::Node* node, sys::BoardKey key, sys::ButtonStatus type)
{
	if (type != ButtonStatus::BUTTON_DOWN)
	{
		return;
	}

	SequenceFrame* pRole = node->as<SequenceFrame>();
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

	if (key == BoardKey::KW)
	{
		index = 0;
	}
	else if (key == BoardKey::KS)
	{
		index = 1;
	}
	else if (key == BoardKey::KA)
	{
		index = 2;
	}
	else if (key == BoardKey::KD)
	{
		index = 3;
	}

	if (pRole)
	{
		DirectionAction* pConfig = &ActionConfigs[index];

		pRole->setFlipX(pConfig->bFlipX);
		pRole->setFrameImagePath(pConfig->path, pConfig->count);
	}
}

void TestUINode::testScissor()
{
	CtrlLayout* pLayout = CREATE_NODE(CtrlLayout);
 	pLayout->getBackgroundMask()->setVisible(false);
	pLayout->getBackgroundImage()->setVisible(true);
 	pLayout->setBackgroundImagePath("Resource/Image/1.jpg");
 	Utility::loadDefaultShader(pLayout->getBackgroundImage());
	pLayout->setClippingEnabled(true);
	pLayout->setVolume(200, 400, 0);
	pLayout->setPosition(200, 200);
	this->addChild(pLayout);


	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->loadImage("Resource/Image/sqi.png");
	pImage->setVolume(200, 400, 0);
	pImage->setScale(1, 1, 1);
	Utility::loadDefaultShader(pImage);
	pLayout->addWidget(pImage, 3);
}

void TestUINode::testScrollView()
{
	CtrlScrollView* pScrollView = CREATE_NODE(CtrlScrollView);
	pScrollView->getBackgroundImage()->setVisible(false);
	pScrollView->getBackgroundImage()->loadImage("Resource/Image/sqi.png");

	pScrollView->getBackgroundMask()->setVisible(false);
	pScrollView->getBackgroundMask()->setColor(phy::Color4B(255,255,255,255));
	pScrollView->getBackgroundMask()->setVolume(200, 600);
	pScrollView->setClippingEnabled(true);
	pScrollView->setPosition(600, 200);
	pScrollView->setVolume(200, 400);

	Utility::loadPrimitiveShader(pScrollView->getBackgroundImage());
	Utility::loadPrimitiveShader(pScrollView->getBackgroundMask());
	this->addChild(pScrollView);

	for (int i = 0; i < 10; i++)
	{
		CtrlImage* pImage = CREATE_NODE(CtrlImage);
		pImage->loadImage("Resource/Image/sqi.png");
		pImage->setVolume(200, 200, 0);
		Utility::loadDefaultShader(pImage);
		pScrollView->addItem(pImage);
	}
}

void TestUINode::testListView()
{
	CtrlListView* pListView = CREATE_NODE(CtrlListView);
	pListView->getBackgroundImage()->setVisible(false);
	pListView->getBackgroundImage()->loadImage("Resource/Image/sqi.png");

	pListView->getBackgroundMask()->setVisible(true);
	pListView->getBackgroundMask()->setColor(phy::Color4B(120, 120, 120, 180));
	pListView->getBackgroundMask()->setVolume(200, 600);
	pListView->setHorizontalScroll(true);
	pListView->setMovingMultiple(20.0f);
	pListView->setClippingEnabled(true);
	pListView->setTouchEnabled(true);
	pListView->setPosition(200, 200);
	pListView->setVolume(200, 400);

	Utility::loadPrimitiveShader(pListView->getBackgroundImage());
	Utility::loadPrimitiveShader(pListView->getBackgroundMask());
	this->addChild(pListView);

	for (int i = 0; i < 10; i++)
	{
		CtrlImage* pImage = CREATE_NODE(CtrlImage);
		pImage->loadImage("Resource/Image/sqi.png");
		pImage->setVolume(200, 200, 0);
		Utility::loadDefaultShader(pImage);
		pListView->addItem(pImage);
	}
}

void TestUINode::testMask()
{
	Mask* pMask = CREATE_NODE(Mask);
	pMask->setAnchorPoint(0, 0, 0);
	pMask->setPosition(0, 0, 0.0f);
	pMask->setVolume(1024, 768, 0);
	pMask->setColor(phy::Color4B(120, 120, 120, 125));
	Utility::loadPrimitiveShader(pMask);
	this->addChild(pMask);
}

void TestUINode::testStencil()
{
	CtrlStencil* pStencil = CREATE_NODE(CtrlStencil);
	pStencil->setStencilMode(StencilMode::EXCLUDE);
	pStencil->setPosition(400, 400, 0.0f);
	pStencil->setVolume(400, 400, 0);
	this->addChild(pStencil);

	Mask* pMask = CREATE_NODE(Mask);
	pMask->setAnchorPoint(0, 0, 0);
	pMask->setPosition(0, 0, 0.0f);
	pMask->setVolume(400, 400, 0);
	pMask->setColor(phy::Color4B(255, 255, 255, 255));
	Utility::loadDefaultShader(pMask);
	pStencil->addChild(pMask);
	pStencil->setStencilNode(pMask);

	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->loadImage("Resource/Image/sqi.png");
	pImage->setVolume(300, 300, 0);
	pImage->setAnchorPoint(0, 0, 0);
	pImage->setPosition(0, 0, 0.0f);
	pImage->setScale(1, 1, 1);
	Utility::loadDefaultShader(pImage);
	pStencil->setStencilNode(pImage);
}

void TestUINode::testImage()
{
	auto frameSize = Tool::getViewSize();

	std::string filepath = "Resource/Image/world.jpg";

	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->loadImage(filepath);
	pImage->setAnchorPoint(math::Vector2(0.5f, 0.5f));
	pImage->setVolume(500, 500);
	pImage->setRotation(0, 0, 45);
	pImage->setPosition(math::Vector2(500, 500));
	Utility::loadDefaultShader(pImage);
	this->addChild(pImage);
	/*
	auto parent = pImage;
	for (size_t i = 0; i < 1; i++)
	{
		pImage = CREATE_NODE(CtrlImage);
		pImage->loadImage(filepath);
		pImage->setAnchorPoint(math::Vector2(0.5f, 0.5f));
		pImage->setVolume(500, 500);
		pImage->setRotation(0, 0, 15);
		pImage->setPosition(math::Vector2(10, 10));
		pImage->setTouchSwallowed(false);
		pImage->addTouchFunc(TouchType::BEGAN, [pImage](const math::Vector2& touchPoint, bool include)
		{
				pImage->setBoxVisible(include);
		});
		pImage->addTouchFunc(TouchType::MOVED, [pImage](const math::Vector2& touchPoint, bool include)
		{
				pImage->setBoxVisible(include);
		});
		pImage->addTouchFunc(TouchType::ENDED, [pImage](const math::Vector2& touchPoint, bool include)
		{
			pImage->setBoxVisible(include);
		});
		Utility::loadDefaultShader(pImage);
		parent->addChild(pImage);
		parent = pImage;
	}
	*/
}

void TestUINode::testButton()
{
	auto pBtn = CREATE_NODE(ui::CtrlButton);
	pBtn->setFontSize(32);
	pBtn->setAnchorPoint(0.5f, 0.5f);
	pBtn->setPosition(512, 384);
	pBtn->setVolume(200, 100);
	pBtn->setString("dsfsdfsa");
	pBtn->setTextColor(phy::Color3B(255,255,255));
	pBtn->setFontPath("Resource/Font/font_3.ttf");
	pBtn->setNormalImage("Resource/Image/sqi.png");
	Utility::loadDefaultShader(pBtn);
	this->addChild(pBtn);
}

void TestUINode::testWidget()
{
	auto pWidget = CREATE_NODE(ui::CtrlWidget);
	pWidget->setBoxVisible(true);
	pWidget->setTouchEnabled(true);
	pWidget->setAnchorPoint(0.5f, 0.5f);
	pWidget->setPosition(512, 384);
	pWidget->setVolume(200, 100);
	pWidget->setRotationZ(45);

	this->addChild(pWidget);
}

void TestUINode::testText()
{
	auto pText = CREATE_NODE(ui::CtrlText);
	pText->setBoxVisible(false);
	pText->setTextHorizontalAlignment(HorizontalAlignment::CENTER);
	pText->setTextVerticalAlignment(VerticalAlignment::MIDDLE);
	pText->setAnchorPoint(0.0f, 1.0f);
	pText->setPosition(0, 768);
	pText->setVolume(400, 100);
	pText->setString("dsfsdfsa");
	pText->setTextColor(phy::Color3B(255, 255, 255));
	pText->setFontPath("Resource/Font/font_3.ttf");
	pText->setFontSize(58);
	pText->setTextDimensions(400, 100);
	Utility::loadDefaultShader(pText);

	this->addChild(pText);
}
