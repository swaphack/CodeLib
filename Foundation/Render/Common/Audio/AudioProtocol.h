#pragma once

#include "system.h"

namespace render
{
	// 空间位置
	struct AudioSpace
	{
	public:
		// 位置
		math::Vector3 position;
		// 移动速度
		math::Vector3 velocity;
		// 脸朝向
		math::Vector3 forward;
		// 头顶方向
		math::Vector3 up;
		// 缩放
		math::Vector3 scale;
	public:
		AudioSpace()
		{
			forward = { 0, 0, 1 };
			up = { 0, 1, 0 };
			scale = { 1, 1, 1 };
		}
		AudioSpace(const math::Vector3& position, const math::Vector3& velocity, const math::Vector3& forward, const math::Vector3& up)
		{
			this->position = position;
			this->velocity = velocity;
			this->forward = forward;
			this->up = up;
		}
	};

	// 音频3d设置
	struct Audio3DSettings
	{
	public:
		// 多普勒缩放比例
		float dopplerscale = 1;
		// 距离系数
		float distancefactor = 1;
		// 衰减缩放比例
		float rolloffscale = 1;
	public:
		Audio3DSettings()
			:dopplerscale(1), distancefactor(1), rolloffscale(1)
		{}
		Audio3DSettings(float dopplerscale, float distancefactor, float rolloffscale)
			:dopplerscale(dopplerscale), distancefactor(distancefactor), rolloffscale(rolloffscale)
		{}
	};

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
		math::Vector3 position;
		// 速度
		math::Vector3 velocity;
	public:
		Attribute3DSettings() {}
		Attribute3DSettings(const math::Vector3& pos, const math::Vector3& vel)
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

	// 几何设置
	struct GeometrySettings
	{
		// 0.0f-1.0f
		float directocclusion = 0;
		// 0.0f-1.0f
		float reverbocclusion = 0;
		// 是否双面
		bool doublesided = 0;
	};

	// 几何数据
	struct GeometryData
	{
		void *data = nullptr;
		int datasize = 0;
	};
}