#include "CtrlAudioSource.h"
#include "AudioManager.h"
#include <map>

using namespace render;

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

void CtrlAudioSource::load(const std::string& filepath)
{
	std::string fullpath = G_FILEPATH->getFilePath(filepath.c_str());
	if (fullpath.empty())
	{
		return;
	}
	std::string data;
	if (!sys::File::read(fullpath.c_str(), data))
	{
		return;
	}

	if (_sound)
	{
		_sound->release();
		_sound = nullptr;
	}

	FMOD::System* system = G_AUDIO->getSystem();
	if (system == nullptr)
	{
		return;
	}
	FMOD_RESULT result = system->createStream(data.c_str(), FMOD_DEFAULT, 0, &_sound);
	if (result != FMOD_OK)
	{
		return;
	}

	setMode(FMOD_LOOP_NORMAL);
	system->playSound(_sound, nullptr, false, &_channel);
}

void CtrlAudioSource::setMusicSpeed(float speed)
{
	AUDIO_SET_FUNC(_sound, setMusicSpeed, speed);
}

float CtrlAudioSource::getMusicSpeed()
{
	AUDIO_GET_FUNC(_sound, getMusicSpeed, float);
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

void CtrlAudioSource::setVolume(float volume)
{
	AUDIO_SET_FUNC(_channel, setVolume, volume);
}

float CtrlAudioSource::getVolume()
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


