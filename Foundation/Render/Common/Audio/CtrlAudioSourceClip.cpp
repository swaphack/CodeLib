#include "CtrlAudioSourceClip.h"
#include "AudioManager.h"
#include "Resource/Detail/AudioDetail.h"

using namespace render;

static AudioDetail* _sAudioDetail = nullptr;

CtrlAudioSourceClip::CtrlAudioSourceClip()
{

}

CtrlAudioSourceClip::~CtrlAudioSourceClip()
{
	SAFE_DELETE(_soundExInfo);
}

void CtrlAudioSourceClip::loadAudioClip(const AudioDetail* audioClip)
{
	if (audioClip == nullptr)
	{
		return;
	}

	_sAudioDetail = (AudioDetail*)audioClip;

	this->initSoundExInfo(audioClip);

	this->play();
}

void CtrlAudioSourceClip::initSoundExInfo(const AudioDetail*audioClip)
{
	if (audioClip == nullptr || audioClip->getData() == nullptr)
	{
		return;
	}

	if (_soundExInfo == nullptr)
	{
		_soundExInfo = new FMOD_CREATESOUNDEXINFO();

		memset(_soundExInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
		_soundExInfo->cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
		_soundExInfo->defaultfrequency = audioClip->getFrequency();
		_soundExInfo->numchannels = audioClip->getChannels();
		_soundExInfo->length = audioClip->getSize();
		_soundExInfo->format = (FMOD_SOUND_FORMAT)audioClip->getFormat();
		_soundExInfo->pcmreadcallback = [](FMOD_SOUND *sound, void *data, unsigned int datalen)->FMOD_RESULT{
			if (_sAudioDetail && _sAudioDetail->getData())
			{
				memcpy(data, _sAudioDetail->getData(), datalen);
			}

			return FMOD_OK;
		};
		_soundExInfo->pcmsetposcallback = [](FMOD_SOUND *sound, int subsound, unsigned int position, FMOD_TIMEUNIT postype)->FMOD_RESULT{
			return FMOD_OK;
		};
		_soundExInfo->nonblockcallback = [](FMOD_SOUND *sound, FMOD_RESULT result){
			return FMOD_OK;
		};
	}

	FMOD::System* system = G_AUDIO->getSystem();
	if (system == nullptr)
	{
		return;
	}

	if (!_sound)
	{
		FMOD_RESULT result = system->createStream(0, FMOD_2D | FMOD_OPENUSER | FMOD_LOOP_OFF, _soundExInfo, &_sound);
		if (result != FMOD_OK)
		{
			return;
		}
	}

	FMOD_RESULT result = system->playSound(_sound, nullptr, true, &_channel);
	if (result != FMOD_OK)
	{
		return;
	}
}
