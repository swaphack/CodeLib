#include "CtrlAudioListener.h"
#include "AudioManager.h"

using namespace render;

int render::CtrlAudioListener::s_ListenerCount = 0;

CtrlAudioListener::CtrlAudioListener()
:_listenerID(0)
{

}

CtrlAudioListener::~CtrlAudioListener()
{

}

bool CtrlAudioListener::init()
{
	if (!Node::init())
	{
		return false;
	}

	int num = G_AUDIO->get3DNumListeners();
	if (s_ListenerCount > num)
	{
		return false;
	}

	_listenerID = ++s_ListenerCount;

	_notify->addListen(ENP_SPACE, [this](){
		sys::Vector3 position = this->getPosition();
		G_AUDIO->getSystem()->set3DListenerAttributes
	});
}

int CtrlAudioListener::getListenerID()
{
	return _listenerID;
}
