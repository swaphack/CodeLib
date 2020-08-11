#pragma once

#include "macros.h"

namespace render
{
	struct SpeakerSettings
	{
		FMOD_SPEAKER speaker = FMOD_SPEAKER_FRONT_CENTER;
		math::Vector2 pos;
		bool active = false;

	};
	// “Ù∆µº‡Ã˝
	class CtrlAudioSpeaker : public Node
	{
	public:
		CtrlAudioSpeaker();
		virtual ~CtrlAudioSpeaker();
	public:
		virtual bool init();

		void setMode(FMOD_SPEAKER speek);
		FMOD_SPEAKER getMode();

		void setActive(bool active);
		bool isActive();
	protected:
		void updateSpeaker();
	private:
		SpeakerSettings _speekSettings;
	};
}