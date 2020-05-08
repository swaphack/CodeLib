#include "CtrlAudioListener.h"
#include "AudioManager.h"

using namespace render;

int CtrlAudioListener::s_ListenerCount = 0;

CtrlAudioListener::CtrlAudioListener()
:_listenerID(0)
{
	_listenerBody.forward = math::Vector3(0, 0, 1);
	_listenerBody.up = math::Vector3(0, 1, 0);
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

	_listenerID = s_ListenerCount++;

	_notify->addListen(ENP_SPACE, [this](){
		math::Matrix44 mat = this->getWorldMatrix();
		_listenerBody.position = mat.getPosition();
		updateListener();
	});

	_notify->addListen(ENP_AUDIO, [this](){
		updateListener();
	});

	return true;
}

int CtrlAudioListener::getListenerID()
{
	return _listenerID;
}

void CtrlAudioListener::setVelocity(const math::Vector3& velocity)
{
	_listenerBody.velocity = velocity;
	onListenerChange();
}

const math::Vector3& CtrlAudioListener::getVelocity()
{
	return _listenerBody.velocity;
}

void CtrlAudioListener::setForward(const math::Vector3& forward)
{
	_listenerBody.forward = forward;
	onListenerChange();
}

const math::Vector3& CtrlAudioListener::getForward()
{
	return _listenerBody.forward;
}

void CtrlAudioListener::setUp(const math::Vector3& up)
{
	_listenerBody.up = up;
	onListenerChange();
}

const math::Vector3& CtrlAudioListener::getUp()
{
	return _listenerBody.up;
}

void CtrlAudioListener::onListenerChange()
{
	this->notify(ENP_AUDIO);
}

void CtrlAudioListener::updateListener()
{
	FMOD_VECTOR position;
	FMOD_VECTOR velocity;
	FMOD_VECTOR forward;
	FMOD_VECTOR up;

	ConvertToFMODVector(_listenerBody.position, position);
	ConvertToFMODVector(_listenerBody.velocity, velocity);
	ConvertToFMODVector(_listenerBody.forward, forward);
	ConvertToFMODVector(_listenerBody.up, up);

	AUDIO_SET_FUNC(G_AUDIO->getSystem(), set3DListenerAttributes, _listenerID, &position, &velocity, &forward, &up);
}
