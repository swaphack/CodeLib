#pragma once

#include "Common/DrawNode/DrawNode.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	// ��
	class Fog : public DrawNode
	{
	public:
		Fog();
		virtual ~Fog();
	protected:
		virtual void onDraw();
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

		void setFogColor(const sys::Color4F& color);
		const sys::Color4F& getFogColor() const;
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

		sys::Color4F _fogColor;
	};
}