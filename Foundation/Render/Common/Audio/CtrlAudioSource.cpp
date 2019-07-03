#include "CtrlAudioSource.h"
#include "AudioManager.h"
#include "Resource/Component/Audio.h"
#include <map>

using namespace render;

FMOD_RESULT F_CALLBACK pcmreadcallback(FMOD_SOUND* /*sound*/, void *data, unsigned int datalen)
{
	static float  t1 = 0, t2 = 0;        // time
	static float  v1 = 0, v2 = 0;        // velocity
	signed short *stereo16bitbuffer = (signed short *)data;

	for (unsigned int count = 0; count < (datalen >> 2); count++)     // >>2 = 16bit stereo (4 bytes per sample)
	{
		*stereo16bitbuffer++ = (signed short)(sin(t1) * 32767.0f);    // left channel
		*stereo16bitbuffer++ = (signed short)(sin(t2) * 32767.0f);    // right channel

		t1 += 0.01f + v1;
		t2 += 0.0142f + v2;
		v1 += (float)(sin(t1) * 0.002f);
		v2 += (float)(sin(t2) * 0.002f);
	}

	return FMOD_OK;
}

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

	result = _channel->setMode(FMOD_LOOP_NORMAL);

	return result == FMOD_OK;
}

bool CtrlAudioSource::loadDataFromClip(Audio* audioClip)
{
	if (audioClip == nullptr || audioClip->getData() == nullptr)
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
	FMOD_CREATESOUNDEXINFO exinfo;
	memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	exinfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
	exinfo.defaultfrequency = audioClip->getFrequency();
	exinfo.numchannels = audioClip->getChannels();
	exinfo.length = audioClip->getSize();
	exinfo.format = (FMOD_SOUND_FORMAT)audioClip->getFormat();
	//exinfo.pcmreadcallback = pcmreadcallback;
	//exinfo.pcmsetposcallback = pcmsetposcallback;

	FMOD_RESULT result = system->createStream((char*)audioClip->getData(), FMOD_OPENMEMORY, &exinfo, &_sound);
	if (result != FMOD_OK)
	{
		return false;
	}

	result = system->playSound(_sound, nullptr, true, &_channel);
	if (result != FMOD_OK)
	{
		return false;
	}

	result = _channel->setMode(FMOD_LOOP_NORMAL);

	return result == FMOD_OK;
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


