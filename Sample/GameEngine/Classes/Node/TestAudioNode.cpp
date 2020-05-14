#include "TestAudioNode.h"

#include "system.h"

using namespace sys;
using namespace render;

TestAudioNode::TestAudioNode()
{

}

TestAudioNode::~TestAudioNode()
{

}

void TestAudioNode::testFunc()
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
	pListenerDrawNode->setColor(Color3B(0, 255, 0));
	pListenerDrawNode->setWidth(100);
	pListenerDrawNode->setDrawMode(ShapeMode::POINTS);
	pListenerDrawNode->appendPoint(math::Vector3());
	pListener->addChild(pListenerDrawNode);

	G_KEYBOARDMANAGER->addDispatcher(pListener, this, KEYBOARD_DELEGATTE_SELECTOR(TestAudioNode::onKeyBoardListener));

	CtrlAudioSource3D* pSrcAudio = CREATE_NODE(CtrlAudioSource3D);
	pSrcAudio->loadDataFromFile("Resource/Audio/city_castle.mp3");
	pSrcAudio->set3DMinMaxDistance({ 0.5f, 10000 });
	pSrcAudio->setPosition(100, 50, 0);
	pSrcAudio->setVelocity({ 0, 0, 0 });
	pSrcAudio->setMusicVolume(100);
	pSrcAudio->play();
	this->addChild(pSrcAudio);

	PrimitiveNode* pSrcDrawNode = CREATE_NODE(PrimitiveNode);
	pSrcDrawNode->setColor(Color3B(255, 255, 0));
	pSrcDrawNode->setWidth(100);
	pSrcDrawNode->setDrawMode(ShapeMode::POINTS);
	pSrcDrawNode->appendPoint(math::Vector3());
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
	pSrcDrawNode->setColor(Color3B(255, 0, 0));
	pSrcDrawNode->setWidth(100);
	pSrcDrawNode->setDrawMode(ShapeMode::POINTS);
	pSrcDrawNode->appendPoint(math::Vector3());
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

void TestAudioNode::onKeyBoardListener(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type)
{
	CtrlAudioListener* pNode = dynamic_cast<CtrlAudioListener*>(object);
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

