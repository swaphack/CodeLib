#pragma once

#include "macros.h"

#include "CtrlAudioSource.h"

namespace render
{
	struct Cone3DSettings
	{
	public:
		// 内锥角
		float insideconeangle = 0;
		// 外锥角
		float outsideconeangle = 0;
		// 外体积
		float outsidevolume = 0;
	public:
		Cone3DSettings() {}
		Cone3DSettings(float insideconeangle, float outsideconeangle, float outsidevolume)
		{
			this->insideconeangle = insideconeangle;
			this->outsideconeangle = outsideconeangle;
			this->outsidevolume = outsidevolume;
		}
	};

	struct Attribute3DSettings
	{
	public:
		// 位置
		sys::Vector3 position;
		// 速度
		sys::Vector3 velocity;
	public:
		Attribute3DSettings() {}
		Attribute3DSettings(const sys::Vector3& pos, const sys::Vector3& vel)
		{
			this->position = pos;
			this->velocity = vel;
		}
	};

	struct Occlusion3DSettings
	{
	public:
		// 直接吸收
		float directocclusion = 0;
		// 混响吸收
		float reverbocclusion = 0;
	public:
		Occlusion3DSettings() {}
		Occlusion3DSettings(float directocclusion, float reverbocclusion)
		{
			this->directocclusion = directocclusion;
			this->reverbocclusion = reverbocclusion;
		}
	};

	struct Distance3DFilterSettings
	{
	public:
		bool custom = false;
		float customLevel = 0;
		float centerFreq = 0;
	public:
		Distance3DFilterSettings() {}
		Distance3DFilterSettings(bool custom, float customLevel, float centerFreq)
		{
			this->custom = custom;
			this->customLevel = customLevel;
			this->centerFreq = centerFreq;
		}
	};

	// 音频
	class CtrlAudioSource3D : public CtrlAudioSource
	{
	public:
		CtrlAudioSource3D();
		virtual ~CtrlAudioSource3D();
	public:
		virtual bool init();

		void set3DAttributes(const Attribute3DSettings& setting);
		Attribute3DSettings get3DAttributes();
		void set3DMinMaxDistance(const sys::Range& distance);
		sys::Range get3DMinMaxDistance();
		void set3DConeSettings(const Cone3DSettings& setting);
		Cone3DSettings get3DConeSettings();
		void set3DConeOrientation(const sys::Vector3& orientation);
		sys::Vector3 get3DConeOrientation();
		void set3DCustomRolloff(const std::vector<sys::Vector3>& points);
		std::vector<sys::Vector3> get3DCustomRolloff();
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

		void setVelocity(const sys::Vector3& velocity);
		const sys::Vector3& getVelocity();
	protected:
		// 初始化默认配置
		virtual int getInitMode();
	private:
		Attribute3DSettings _3dSettings;
	};
}