#pragma once

#include "macros.h"

namespace render
{
	// ��Ƶ����
	class CtrlAudioSpeaker : public Node
	{
	public:
		CtrlAudioSpeaker();
		virtual ~CtrlAudioSpeaker();
	public:
		virtual bool init();

		void setMode(FMOD_SPEAKER speek);
		FMOD_SPEAKER getMode();
	protected:
	private:
		FMOD_SPEAKER _speekMode;
	};
}