#pragma once

#include "Common/Node/ColorNode.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	// ��
	class Fog : public ColorNode
	{
	public:
		Fog();
		virtual ~Fog();
	protected:
		virtual void drawSample();
	public:
		// ������
		float getNear() const;
		void setNear(float val);
		// Զ����
		float getFar() const;
		void setFar(float val);
		// �������
		FogMode getFogMode() const;
		void setFogMode(FogMode val);
		// ���Ч��
		HintMode getFogEffect() const;
		void setFogEffect(HintMode val);
		// �ܶ�
		float getDensity() const;
		void setDensity(float val);
	protected:
		// ������
		float _near;
		// Զ����
		float _far;
		// �������
		FogMode _fogMode;
		// ���Ч��
		HintMode _fogEffect;
		// �ܶ�
		float _density;
	};
}