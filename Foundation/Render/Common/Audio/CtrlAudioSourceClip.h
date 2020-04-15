#include "macros.h"
#include "CtrlAudioSource.h"
#include <vector>

namespace render
{
	// “Ù∆µ∆¨∂Œ
	class CtrlAudioSourceClip :
		public CtrlAudioSource
	{
	public:
		CtrlAudioSourceClip();
		virtual ~CtrlAudioSourceClip();
	public:
		void loadAudioClip(const AudioDetail*audioClip);
	protected:
		void initSoundExInfo(const AudioDetail*audioClip);
	private:
		FMOD_CREATESOUNDEXINFO* _soundExInfo = nullptr;
	};
}