#include "CtrlAudioSourceClip.h"
#include "AudioManager.h"

using namespace render;

static sys::AudioDetail* _sAudioDetail = nullptr;

CtrlAudioSourceClip::CtrlAudioSourceClip()
{

}

CtrlAudioSourceClip::~CtrlAudioSourceClip()
{
	SAFE_DELETE(_soundExInfo);
}

void CtrlAudioSourceClip::loadAudioClip(const sys::AudioDetail* audioClip)
{
	if (audioClip == nullptr)
	{
		return;
	}

	_sAudioDetail = (sys::AudioDetail*)audioClip;

	this->initSoundExInfo(audioClip);

	this->play();
}

void CtrlAudioSourceClip::initSoundExInfo(const sys::AudioDetail*audioClip)
{
	if (audioClip == nullptr || audioClip->getData() == nullptr)
	{
		return;
	}

	if (_soundExInfo == nullptr)
	{
		auto pSoundExInfo = new FMOD_CREATESOUNDEXINFO();

		memset(pSoundExInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
		pSoundExInfo->cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
		pSoundExInfo->defaultfrequency = audioClip->getFrequency();
		pSoundExInfo->numchannels = audioClip->getChannels();
		pSoundExInfo->length = audioClip->getSize();
		pSoundExInfo->format = (FMOD_SOUND_FORMAT)audioClip->getFormat();
		pSoundExInfo->pcmreadcallback = [](FMOD_SOUND *sound, void *data, unsigned int datalen)->FMOD_RESULT{
			if (_sAudioDetail && _sAudioDetail->getData())
			{
				memcpy(data, _sAudioDetail->getData(), datalen);
			}

			return FMOD_OK;
		};
		pSoundExInfo->pcmsetposcallback = [](FMOD_SOUND *sound, int subsound, unsigned int position, FMOD_TIMEUNIT postype)->FMOD_RESULT{
			return FMOD_OK;
		};
		pSoundExInfo->nonblockcallback = [](FMOD_SOUND *sound, FMOD_RESULT result){
			return FMOD_OK;
		};

		_soundExInfo = pSoundExInfo;
	}

	FMOD::System* system = G_AUDIO->getSystem();
	if (system == nullptr)
	{
		return;
	}

	if (!_sound)
	{
		FMOD_RESULT result = system->createStream(0, FMOD_2D | FMOD_OPENUSER | FMOD_LOOP_OFF, (FMOD_CREATESOUNDEXINFO*)_soundExInfo, &_sound);
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
