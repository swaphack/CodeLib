#include "CtrlAudioSpeaker.h"
#include "AudioManager.h"

using namespace render;


CtrlAudioSpeaker::CtrlAudioSpeaker()
{

}

CtrlAudioSpeaker::~CtrlAudioSpeaker()
{

}

bool CtrlAudioSpeaker::init()
{
	if (!Node::init())
	{
		return false;
	}

	_notify->addListen(ENP_SPACE, [this](){
		_speekSettings.pos = this->getPosition();
		updateSpeaker();
	});

	_notify->addListen(ENP_AUDIO, [this](){
		updateSpeaker();
	});

	return true;
}

void CtrlAudioSpeaker::setMode(FMOD_SPEAKER speek)
{
	_speekSettings.speaker = speek;
	_notify->addMark(ENP_AUDIO);
}

FMOD_SPEAKER CtrlAudioSpeaker::getMode()
{
	return _speekSettings.speaker;
}

void CtrlAudioSpeaker::setActive(bool active)
{
	_speekSettings.active = active;
	_notify->addMark(ENP_AUDIO);
}

bool CtrlAudioSpeaker::isActive()
{
	return _speekSettings.active;
}

void CtrlAudioSpeaker::updateSpeaker()
{
	AUDIO_SET_FUNC(G_AUDIO->getSystem(), setSpeakerPosition, _speekSettings.speaker, _speekSettings.pos.getX(), _speekSettings.pos.getY(), _speekSettings.active);
}
