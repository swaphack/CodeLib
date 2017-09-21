#pragma once

#include "macros.h"

namespace FMOD
{
	class Sound;
	class Channel;
}
namespace render
{
	// ��Ƶ
	class CtrlAudioSource : public Node
	{
	public:
		CtrlAudioSource();
		virtual ~CtrlAudioSource();
	public:
		// ��������
		bool loadData(const uchar* data);
		// �����ļ�����
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
		// ����
		FMOD::Sound* _sound;
		// Ƶ������
		FMOD::Channel* _channel;
	};
}