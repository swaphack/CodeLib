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

	// ��Ƶ
	class CtrlAudioSource : public Node
	{
	public:
		CtrlAudioSource();
		virtual ~CtrlAudioSource();
	public:
		// �����ļ�����
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
		// ��ʼ��Ĭ������
		virtual int getInitMode();
	protected:
		// ����
		FMOD::Sound* _sound = nullptr;
		// Ƶ������
		FMOD::Channel* _channel = nullptr;
	};
}