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

		// ��������
		void setGeometrySettings(float maxworldsize);
		float getGeometrySettings();

		inline FMOD::System* getSystem() const { return _system; };
	private:
		FMOD::System* _system = nullptr;
	};

#define G_AUDIO sys::Instance<render::AudioManager>::getInstance()
}