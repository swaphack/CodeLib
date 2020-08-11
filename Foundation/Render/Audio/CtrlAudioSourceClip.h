#include "macros.h"
#include "CtrlAudioSource.h"
#include <vector>

namespace sys
{
	class AudioDetail;
}

namespace render
{
	// ��ƵƬ��
	class CtrlAudioSourceClip :
		public CtrlAudioSource
	{
	public:
		CtrlAudioSourceClip();
		virtual ~CtrlAudioSourceClip();
	public:
		void loadAudioClip(const sys::AudioDetail*audioClip);
	protected:
		void initSoundExInfo(const sys::AudioDetail*audioClip);
	private:
		void* _soundExInfo = nullptr;
	};
}