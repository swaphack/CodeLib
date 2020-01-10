#include "App.h"
#include "Maze.h"
#include "MazeMap.h"

using namespace render;
using namespace sys;

App::App()
{
	this->init();
	this->getCanvas()->setDimensions(render::ED_2D);
}

App::~App()
{
	this->dispose();
}

void App::show()
{
	Maze* pMaze = new Maze();
	pMaze->autoGenerate(12122, 20, 10);

	MazeMap* pMazeMap = CREATE_NODE(MazeMap);
	pMazeMap->setVolume(math::Size(1024, 768));
	pMazeMap->flush(pMaze);

	this->getCanvas()->getRoot()->addChild(pMazeMap);

	int nCount = G_AUDIO->get3DNumListeners();
	G_AUDIO->set3DNumListeners(1);
	G_AUDIO->set3DSettings(render::Audio3DSettings(1.0f, 1.0f, 1.0f));

	CtrlAudioListener* pListener = CREATE_NODE(CtrlAudioListener);
	pListener->setPosition(100, 25, -1);
	this->getCanvas()->getRoot()->addChild(pListener);

	DrawNode* pListenerDrawNode = CREATE_NODE(DrawNode);
	pListenerDrawNode->setColor(Color3B(0, 255, 0));
	pListenerDrawNode->setWidth(100);
	pListenerDrawNode->setDrawMode(EBM_POINTS);
	pListenerDrawNode->appendPoint(Vector3::Zero);
	pListener->addChild(pListenerDrawNode);

	G_KEYBOARDMANAGER->addDispatcher(pListener, this, KEYBOARD_DELEGATTE_SELECTOR(App::onKeyBoardListener));
}

void App::onKeyBoardListener(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type)
{
	CtrlAudioListener* pNode = dynamic_cast<CtrlAudioListener*>(object);
	if (pNode == nullptr)
	{
		return;
	}
	if (type == EBS_BUTTON_UP)
	{
		return;
	}

	math::Vector3 lastPos;
	math::Vector3 vel;
	math::Vector3 curPos;

	bool bMatch = true;
	float speed = 5;
	lastPos = pNode->getPosition();

	if (key == EBK_LEFT)
	{
		pNode->setPositionX(pNode->getPositionX() - speed);
	}
	else if (key == EBK_RIGHT)
	{
		pNode->setPositionX(pNode->getPositionX() + speed);
	}
	else if (key == EBK_UP)
	{
		pNode->setPositionY(pNode->getPositionY() + speed);
	}
	else if (key == EBK_DOWN)
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