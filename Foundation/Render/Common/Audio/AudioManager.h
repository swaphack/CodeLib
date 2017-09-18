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
	// 音频3d设置
	struct Audio3DSettings
	{
	public:
		// 多普勒缩放比例
		float dopplerscale = 1;
		// 距离系数
		float distancefactor = 1;
		// 衰减缩放比例
		float rolloffscale =1;
	public:
		Audio3DSettings()
			:dopplerscale(1), distancefactor(1), rolloffscale(1)
		{}
		Audio3DSettings(float dopplerscale, float distancefactor, float rolloffscale)
			:dopplerscale(dopplerscale), distancefactor(distancefactor), rolloffscale(rolloffscale)
		{}
	};
	// 音频管理
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
		// 3d效果
		void set3DSettings(const Audio3DSettings& setting);
		Audio3DSettings get3DSettings();

		// 3d监听者数量
		void set3DNumListeners(int numlisteners);
		int get3DNumListeners();

		inline FMOD::System* getSystem() const { return _system; };
	private:
		FMOD::System* _system = nullptr;
	};

#define G_AUDIO sys::Instance<render::AudioManager>::getInstance()
}