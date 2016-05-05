#pragma once

#include "macros.h"

namespace render
{
	// 雾
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
		// 近距离
		float _near;
		// 远距离
		float _far;
		// 雾的类型
		FogMode _fogMode;
		// 雾的效果
		FogEffect _fogEffect;
		// 密度
		float _density;
	};
}