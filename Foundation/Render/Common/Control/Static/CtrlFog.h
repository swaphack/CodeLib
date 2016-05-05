#pragma once

#include "macros.h"

namespace render
{
	// ��
	class CtrlFog : public ColorNode
	{
	public:
		CtrlFog();
		virtual ~CtrlFog();
	public:
		virtual void draw();

		float getNear() const { return _near; }
		void setNear(float val) { _near = val; }

		float getFar() const { return _far; }
		void setFar(float val) { _far = val; }

		FogMode getFogMode() const { return _fogMode; }
		void setFogMode(FogMode val) { _fogMode = val; }

		FogEffect getFogEffect() const { return _fogEffect; }
		void setFogEffect(FogEffect val) { _fogEffect = val; }

		float getDensity() const { return _density; }
		void setDensity(float val) { _density = val; }
	protected:
	private:
		// ������
		float _near;
		// Զ����
		float _far;
		// �������
		FogMode _fogMode;
		// ���Ч��
		FogEffect _fogEffect;
		// �ܶ�
		float _density;
	};
}