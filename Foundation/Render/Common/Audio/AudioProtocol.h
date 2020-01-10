#pragma once

#include "system.h"

namespace render
{
	// �ռ�λ��
	struct AudioSpace
	{
	public:
		// λ��
		math::Vector3 position;
		// �ƶ��ٶ�
		math::Vector3 velocity;
		// ������
		math::Vector3 forward;
		// ͷ������
		math::Vector3 up;
		// ����
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

	// ��Ƶ3d����
	struct Audio3DSettings
	{
	public:
		// ���������ű���
		float dopplerscale = 1;
		// ����ϵ��
		float distancefactor = 1;
		// ˥�����ű���
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
		// ��׶��
		float insideconeangle = 0;
		// ��׶��
		float outsideconeangle = 0;
		// �����
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
		// λ��
		math::Vector3 position;
		// �ٶ�
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
		// ֱ������
		float directocclusion = 0;
		// ��������
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

	// ��������
	struct GeometrySettings
	{
		// 0.0f-1.0f
		float directocclusion = 0;
		// 0.0f-1.0f
		float reverbocclusion = 0;
		// �Ƿ�˫��
		bool doublesided = 0;
	};

	// ��������
	struct GeometryData
	{
		void *data = nullptr;
		int datasize = 0;
	};
}