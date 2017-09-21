#pragma once

#include "macros.h"

namespace FMOD
{
	class Sound;
	class Channel;
}
namespace render
{
	// 音频
	class CtrlAudioSource : public Node
	{
	public:
		CtrlAudioSource();
		virtual ~CtrlAudioSource();
	public:
		// 加载数据
		bool loadData(const uchar* data);
		// 加载文件数据
		bool loadFromFile(const std::string& filepath);

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
		// 声音
		FMOD::Sound* _sound;
		// 频道调整
		FMOD::Channel* _channel;
	};
}