#include "TestAudioNode.h"
#include "Utility.h"
#include "system.h"

using namespace sys;
using namespace render;

TestAudioNode::TestAudioNode()
{

}

TestAudioNode::~TestAudioNode()
{

}

void TestAudioNode::initNodes()
{

}

void TestAudioNode::testAudio()
{
	CtrlAudioSource* pSrcAudio = CREATE_NODE(CtrlAudioSource);
	pSrcAudio->loadDataFromFile("Resource/Audio/city_build.mp3");
	pSrcAudio->setMusicVolume(0.1f);
	pSrcAudio->play();
	this->addChild(pSrcAudio);

	PRINT("OK");
}

#define DISTANCEFACTOR 1

void TestAudioNode::testAudio3D()
{
	int nCount = G_AUDIO->get3DNumListeners();
	G_AUDIO->set3DNumListeners(1);
	G_AUDIO->set3DSettings(render::Audio3DSettings(1.0f, DISTANCEFACTOR, 1.0f));

	CtrlAudioListener* pListener = CREATE_NODE(CtrlAudioListener);
	pListener->setPosition(100, 25, 0);
	this->addChild(pListener);

	PrimitiveNode* pListenerDrawNode = CREATE_NODE(PrimitiveNode);
	pListenerDrawNode->setColor(phy::Color4F(0, 1, 0));
	pListenerDrawNode->setPointSize(100);
	pListenerDrawNode->setDrawMode(DrawMode::POINTS);
	pListenerDrawNode->appendPoint(math::Vector3());
	Utility::loadShaderVF(pListenerDrawNode, "Shader/geometry/draw_primitive.vs", "Shader/geometry/draw_primitive.fs");
	pListener->addChild(pListenerDrawNode);

	G_KEYBOARDMANAGER->addKeyboardDelegate(this, pListener, KEYBOARD_DELEGATE_SELECTOR(TestAudioNode::onKeyBoardListener));

	CtrlAudioSource3D* pSrcAudio = CREATE_NODE(CtrlAudioSource3D);
	pSrcAudio->loadDataFromFile("Resource/Audio/city_castle.mp3");
	pSrcAudio->set3DMinMaxDistance({ 0.5f, 10000 });
	pSrcAudio->setPosition(100, 50, 0);
	pSrcAudio->setVelocity({ 0, 0, 0 });
	pSrcAudio->setMusicVolume(100);
	pSrcAudio->play();
	this->addChild(pSrcAudio);

	PrimitiveNode* pSrcDrawNode = CREATE_NODE(PrimitiveNode);
	pSrcDrawNode->setColor(phy::Color4F(1, 1, 0));
	pSrcDrawNode->setPointSize(100);
	pSrcDrawNode->setDrawMode(DrawMode::POINTS);
	pSrcDrawNode->appendPoint(math::Vector3());
	Utility::loadShaderVF(pSrcDrawNode, "Shader/geometry/draw_primitive.vs", "Shader/geometry/draw_primitive.fs");
	pSrcAudio->addChild(pSrcDrawNode);


	pSrcAudio = CREATE_NODE(CtrlAudioSource3D);
	pSrcAudio->loadDataFromFile("Resource/Audio/m_city.mp3");
	pSrcAudio->set3DMinMaxDistance({ 0.5f, 10000 });
	pSrcAudio->setPosition(400, 100, 0);
	pSrcAudio->setVelocity({ 0, 0, 0 });
	pSrcAudio->setMusicVolume(100);
	pSrcAudio->play();
	this->addChild(pSrcAudio);

	pSrcDrawNode = CREATE_NODE(PrimitiveNode);
	pSrcDrawNode->setColor(phy::Color4F(1, 0, 0));
	pSrcDrawNode->setPointSize(100);
	pSrcDrawNode->setDrawMode(DrawMode::POINTS);
	pSrcDrawNode->appendPoint(math::Vector3());
	Utility::loadShaderVF(pSrcDrawNode, "Shader/geometry/draw_primitive.vs", "Shader/geometry/draw_primitive.fs");
	pSrcAudio->addChild(pSrcDrawNode);

	float maxSize = G_AUDIO->getGeometrySettings();
	G_AUDIO->setGeometrySettings(10);

	CtrlAudioGeometry* pGeometryNode = CREATE_NODE(CtrlAudioGeometry);
	pGeometryNode->init(6, 24);
	pGeometryNode->setForward({ 1, 0, 0 });
	pGeometryNode->setUp({ 0, 1, 0 });
	pGeometryNode->setPosition(300, 75);
	pGeometryNode->setVolume(200, 100, 100);
	pGeometryNode->setActive(true);
	this->addChild(pGeometryNode);
}

void TestAudioNode::onKeyBoardListener(render::Node* node, sys::BoardKey key, sys::ButtonStatus type)
{
	CtrlAudioListener* pNode = node->as<CtrlAudioListener>();
	if (pNode == nullptr)
	{
		return;
	}
	if (type == ButtonStatus::BUTTON_UP)
	{
		return;
	}

	math::Vector3 lastPos;
	math::Vector3 vel;
	math::Vector3 curPos;

	bool bMatch = true;
	float speed = 5;
	lastPos = pNode->getPosition();

	if (key == BoardKey::KLEFT)
	{
		pNode->setPositionX(pNode->getPositionX() - speed);
	}
	else if (key == BoardKey::KRIGHT)
	{
		pNode->setPositionX(pNode->getPositionX() + speed);
	}
	else if (key == BoardKey::KUP)
	{
		pNode->setPositionY(pNode->getPositionY() + speed);
	}
	else if (key == BoardKey::KDOWN)
	{
		pNode->setPositionY(pNode->getPositionY() - speed);
	}
	else
	{
		bMatch = false;
	}

	if (!bMatch)
	{
		return;
	}

	curPos = pNode->getPosition();
	vel = curPos - lastPos;
	pNode->setVelocity(vel);
}

