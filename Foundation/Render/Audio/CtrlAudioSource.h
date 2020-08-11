#pragma once

#include "macros.h"

namespace FMOD
{
	class Sound;
	class Channel;
}
namespace render
{
	class AudioDetail;

	// 音频
	class CtrlAudioSource : public Node
	{
	public:
		CtrlAudioSource();
		virtual ~CtrlAudioSource();
	public:
		// 加载文件数据
		bool loadDataFromFile(const std::string& filepath);

		void setMusicSpeed(float speed);
		float getMusicSpeed();

		void play();
		void stop();
		void setPaused(bool paused);
		bool getPaused();
		void setMusicVolume(float volume);
		float getMusicVolume();
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

		//0 = oneshot, 1 = loop once then stop, -1 = loop forever, default = -1
		void setLoopCount(int loopcount);
		int getLoopCount();
	protected:
		// 初始化默认配置
		virtual int getInitMode();
	protected:
		// 声音
		FMOD::Sound* _sound = nullptr;
		// 频道调整
		FMOD::Channel* _channel = nullptr;
	};
}