#pragma once

#include "macros.h"

namespace FMOD
{
	class Sound;
	class Channel;
}
namespace render
{

#define AUDIO_DO_FUNC(Target, FuncName, ...) \
	if (Target) { Target->FuncName(__VA_ARGS__); }

#define AUDIO_SET_FUNC AUDIO_DO_FUNC

#define AUDIO_GET_FUNC(Target, FuncName, Type) \
	{ Type value = 0; AUDIO_DO_FUNC(Target, FuncName, &value); return value; }

	// ÒôÆµ
	class CtrlAudioSource : public Node
	{
	public:
		CtrlAudioSource();
		virtual ~CtrlAudioSource();
	public:
		void load(const std::string& filepath);

		void setMusicSpeed(float speed);
		float getMusicSpeed();

		void stop();
		void setPaused(bool paused);
		bool getPaused();
		void setVolume(float volume);
		float getVolume();
		void setVolumeRamp(bool ramp);
		bool getVolumeRamp();
		float getAudibility();
		void setPitch(float pitch);
		float getPitch();
		void setMute(bool mute);
		bool getMute();
		void setMode(int mode);
		int getMode();
		bool isPlaying();

		void setFrequency(float frequency);
		float getFrequency();
		void setPriority(int priority);
		int getPriority();
		void setLoopCount(int loopcount);
		int getLoopCount();

	protected:
		// ÉùÒô
		FMOD::Sound* _sound;
		// ÆµµÀµ÷Õû
		FMOD::Channel* _channel;
	};
}