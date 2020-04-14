#include "CtrlAudioSource.h"
#include "AudioManager.h"
#include "Resource/Detail/AudioDetail.h"
#include <map>

using namespace render;

class CtrlAudioSourceMgr
{
public:
	static void addSound(FMOD::Sound* sound, CtrlAudioSource* src);
	static void removeSound(FMOD_SOUND* sound);
	static CtrlAudioSource* getSound(FMOD_SOUND* sound);
private:
};

static AudioDetail* _sAudioDetail = nullptr;

FMOD_RESULT F_CALLBACK pcmreadcallback(FMOD_SOUND *sound, void *data, unsigned int datalen)
{
	if (_sAudioDetail == nullptr)
	{
		return FMOD_ERR_MEMORY;
	}
	memcpy(data, _sAudioDetail->getData(), datalen);

	return FMOD_OK;
};

FMOD_RESULT F_CALLBACK pcmsetposcallback(FMOD_SOUND* /*sound*/, int /*subsound*/, unsigned int /*position*/, FMOD_TIMEUNIT /*postype*/)
{
	/*
	This is useful if the user calls Channel::setPosition and you want to seek your data accordingly.
	*/
	return FMOD_OK;
}

CtrlAudioSource::CtrlAudioSource()
{
	_channel = nullptr;
}

CtrlAudioSource::~CtrlAudioSource()
{
	if (_sound)
	{
		_sound->release();
	}
}

bool CtrlAudioSource::loadDataFromFile(const std::string& filepath)
{
	if (filepath.empty())
	{
		return false;
	}

	std::string fullpath = G_FILEPATH->getFilePath(filepath.c_str());
	if (fullpath.empty())
	{
		return false;
	}

	if (_sound)
	{
		_sound->release();
		_sound = nullptr;
	}

	FMOD::System* system = G_AUDIO->getSystem();
	if (system == nullptr)
	{
		return false;
	}
	FMOD_RESULT result = system->createSound(filepath.c_str(), getInitMode(), 0, &_sound);
	if (result != FMOD_OK)
	{
		return false;
	}

	result = system->playSound(_sound, nullptr, true, &_channel);
	if (result != FMOD_OK)
	{
		return false;
	}

	result = _channel->setMode(FMOD_DEFAULT);

	return result == FMOD_OK;
}

bool CtrlAudioSource::loadDataFromClip(AudioDetail* audioClip)
{
	if (audioClip == nullptr || audioClip->getData() == nullptr)
	{
		return false;
	}

	_sAudioDetail = audioClip;

	if (_sound)
	{
		_sound->release();
		_sound = nullptr;
	}

	FMOD::System* system = G_AUDIO->getSystem();
	if (system == nullptr)
	{
		return false;
	}

	FMOD_CREATESOUNDEXINFO exinfo;
	memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	exinfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
	exinfo.defaultfrequency = audioClip->getFrequency();
	exinfo.numchannels = audioClip->getChannels();
	exinfo.length = audioClip->getSize();
	exinfo.format = (FMOD_SOUND_FORMAT)audioClip->getFormat();
	exinfo.pcmreadcallback = pcmreadcallback;

	FMOD_RESULT result = system->createStream(0, FMOD_2D | FMOD_OPENUSER | FMOD_LOOP_OFF, &exinfo, &_sound);

	if (result != FMOD_OK)
	{
		return false;
	}

	result = system->playSound(_sound, nullptr, true, &_channel);
	if (result != FMOD_OK)
	{
		return false;
	}

	result = _channel->setMode(FMOD_DEFAULT);
	if (result != FMOD_OK)
	{
		return false;
	}

	return true;
}

void CtrlAudioSource::setMusicSpeed(float speed)
{
	AUDIO_SET_FUNC(_sound, setMusicSpeed, speed);
}

float CtrlAudioSource::getMusicSpeed()
{
	AUDIO_GET_FUNC(_sound, getMusicSpeed, float);
}

void CtrlAudioSource::play()
{
	this->setPaused(false);
}

void CtrlAudioSource::stop()
{
	AUDIO_DO_FUNC(_channel, stop);
}

void CtrlAudioSource::setPaused(bool paused)
{
	AUDIO_SET_FUNC(_channel, setPaused, paused);
}

bool CtrlAudioSource::getPaused()
{
	AUDIO_GET_FUNC(_channel, getPaused, bool);
}

void CtrlAudioSource::setMusicVolume(float volume)
{
	AUDIO_SET_FUNC(_channel, setVolume, volume);
}

float CtrlAudioSource::getMusicVolume()
{
	AUDIO_GET_FUNC(_channel, getVolume, float);
}

void CtrlAudioSource::setVolumeRamp(bool ramp)
{
	AUDIO_SET_FUNC(_channel, setVolumeRamp, ramp);
}

bool CtrlAudioSource::getVolumeRamp()
{
	AUDIO_GET_FUNC(_channel, getVolumeRamp, bool);
}

float CtrlAudioSource::getAudibility()
{
	AUDIO_GET_FUNC(_channel, getAudibility, float);
}

void CtrlAudioSource::setPitch(float pitch)
{
	AUDIO_SET_FUNC(_channel, setPitch, pitch);
}

float CtrlAudioSource::getPitch()
{
	AUDIO_GET_FUNC(_channel, getPitch, float);
}

void CtrlAudioSource::setMute(bool mute)
{
	AUDIO_SET_FUNC(_channel, setMute, mute);
}

bool CtrlAudioSource::getMute()
{
	AUDIO_GET_FUNC(_channel, getMute, bool);
}

void CtrlAudioSource::setMode(int mode)
{
	AUDIO_SET_FUNC(_channel, setMode, mode);
}

int CtrlAudioSource::getMode()
{
	AUDIO_GET_FUNC(_channel, getMode, FMOD_MODE);
}

bool CtrlAudioSource::isPlaying()
{
	AUDIO_GET_FUNC(_channel, isPlaying, bool);
}

void CtrlAudioSource::setFrequency(float frequency)
{
	AUDIO_SET_FUNC(_channel, setFrequency, frequency);
}

float CtrlAudioSource::getFrequency()
{
	AUDIO_GET_FUNC(_channel, getFrequency, float);
}

void CtrlAudioSource::setPriority(int priority)
{
	AUDIO_SET_FUNC(_channel, setPriority, priority);
}

int CtrlAudioSource::getPriority()
{
	AUDIO_GET_FUNC(_channel, getPriority, int);
}

void CtrlAudioSource::setLoopCount(int loopCount)
{
	AUDIO_SET_FUNC(_channel, setLoopCount, loopCount);
}

int CtrlAudioSource::getLoopCount()
{
	AUDIO_GET_FUNC(_channel, getLoopCount, int);
}

int CtrlAudioSource::getInitMode()
{
	return FMOD_2D;
}


