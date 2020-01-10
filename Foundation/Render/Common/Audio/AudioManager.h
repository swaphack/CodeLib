#pragma once

#include <string>
#include <map>
#include "macros.h"
#include "AudioProtocol.h"

namespace FMOD
{
	class Sound;
	class System;
}

namespace math
{
	struct Vector3;
}

namespace render
{
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

		// 几何特性
		void setGeometrySettings(float maxworldsize);
		float getGeometrySettings();

		inline FMOD::System* getSystem() const { return _system; };
	private:
		FMOD::System* _system = nullptr;
	};

#define G_AUDIO sys::Instance<render::AudioManager>::getInstance()
}