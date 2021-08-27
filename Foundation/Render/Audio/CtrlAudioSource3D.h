#pragma once

#include "macros.h"

#include "CtrlAudioSource.h"
#include "AudioProtocol.h"

namespace render
{
	// “Ù∆µ
	class CtrlAudioSource3D : public CtrlAudioSource
	{
	public:
		CtrlAudioSource3D();
		virtual ~CtrlAudioSource3D();
	public:
		virtual bool init();

		void set3DAttributes(const Attribute3DSettings& setting);
		Attribute3DSettings get3DAttributes();
		void set3DMinMaxDistance(const math::FloatInterval& distance);
		math::FloatInterval get3DMinMaxDistance();
		void set3DConeSettings(const Cone3DSettings& setting);
		Cone3DSettings get3DConeSettings();
		void set3DConeOrientation(const math::Vector3& orientation);
		math::Vector3 get3DConeOrientation();
		void set3DCustomRolloff(const std::vector<math::Vector3>& points);
		std::vector<math::Vector3> get3DCustomRolloff();
		void set3DOcclusion(const Occlusion3DSettings& setting);
		Occlusion3DSettings get3DOcclusion();
		void set3DSpread(float angle);
		float get3DSpread();
		void set3DLevel(float level);
		float get3DLevel();
		void set3DDopplerLevel(float level);
		float get3DDopplerLevel();
		void set3DDistanceFilter(const Distance3DFilterSettings& setting);
		Distance3DFilterSettings get3DDistanceFilter();

		void setVelocity(const math::Vector3& velocity);
		const math::Vector3& getVelocity();
	protected:
		// ≥ı ºªØƒ¨»œ≈‰÷√
		virtual int getInitMode();
	private:
		Attribute3DSettings _3dSettings;
	};
}