#pragma once

#include <string>
#include <map>

namespace FMOD
{
	class Sound;
	class System;
}

namespace render
{
	// ��Ƶ3d����
	struct Audio3DSettings
	{
	public:
		// ���������ű���
		float dopplerscale = 1;
		// ����ϵ��
		float distancefactor = 1;
		// ˥�����ű���
		float rolloffscale =1;
	public:
		Audio3DSettings()
			:dopplerscale(1), distancefactor(1), rolloffscale(1)
		{}
		Audio3DSettings(float dopplerscale, float distancefactor, float rolloffscale)
			:dopplerscale(dopplerscale), distancefactor(distancefactor), rolloffscale(rolloffscale)
		{}
	};
	// ��Ƶ����
	class AudioManager
	{
	public:
		AudioManager();
		~AudioManager();
	public:
		void init();
		void update();
		void close();
		void dispose();
		// 3dЧ��
		void set3DSettings(const Audio3DSettings& setting);
		Audio3DSettings get3DSettings();

		// 3d����������
		void set3DNumListeners(int numlisteners);
		int get3DNumListeners();

		inline FMOD::System* getSystem() const { return _system; };
	private:
		FMOD::System* _system = nullptr;
	};

#define G_AUDIO sys::Instance<render::AudioManager>::getInstance()
}