#include "AudioManager.h"

using namespace render;

#define MAX_CHANNEL 512

AudioManager::AudioManager()
{
	this->init();
}

AudioManager::~AudioManager()
{
	this->dispose();
}

void AudioManager::init()
{
	FMOD_RESULT result = FMOD::System_Create(&_system);
	if (result != FMOD_OK)
	{
		return;
	}

	unsigned int version = 0;
	result = _system->getVersion(&version);
	if (result != FMOD_OK)
	{
		return;
	}

	result = _system->init(MAX_CHANNEL, FMOD_INIT_NORMAL, 0);
	if (result != FMOD_OK)
	{
		return;
	}
}

void AudioManager::process()
{
	if (!_system) return;

	_system->update();
}

void AudioManager::close()
{
	if (!_system) return;

	_system->close();
}

void AudioManager::dispose()
{
	if (!_system) return;

	_system->release();
	_system = nullptr;
}

void AudioManager::set3DSettings(const Audio3DSettings& setting)
{
	if (!_system) return;
	AUDIO_SET_FUNC(_system, set3DSettings, setting.dopplerscale, setting.distancefactor, setting.rolloffscale);
}

Audio3DSettings AudioManager::get3DSettings()
{
	Audio3DSettings setting;
	if (!_system) return setting;

	AUDIO_DO_FUNC(_system, get3DSettings, &setting.dopplerscale, &setting.distancefactor, &setting.rolloffscale);

	return setting;
}

void AudioManager::set3DNumListeners(int numlisteners)
{
	if (!_system) return;
	AUDIO_SET_FUNC(_system, set3DNumListeners, numlisteners);
}

int AudioManager::get3DNumListeners()
{
	if (!_system) return 0;
	AUDIO_GET_FUNC(_system, get3DNumListeners, int);
}

void AudioManager::setGeometrySettings(float maxworldsize)
{
	if (!_system) return;
	AUDIO_SET_FUNC(_system, setGeometrySettings, maxworldsize);
}

float AudioManager::getGeometrySettings()
{
	if (!_system) return 0;
	AUDIO_GET_FUNC(_system, getGeometrySettings, float);
}
