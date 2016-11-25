#pragma once

#include "../macros.h"

namespace render
{
	// 雾
	class Fog : public ColorNode
	{
	public:
		Fog();
		virtual ~Fog();
	public:
		virtual void draw();
		// 近距离
		float getNear() const { return _near; }
		void setNear(float val) { _near = val; }
		// 远距离
		float getFar() const { return _far; }
		void setFar(float val) { _far = val; }
		// 雾的类型
		FogMode getFogMode() const { return _fogMode; }
		void setFogMode(FogMode val) { _fogMode = val; }
		// 雾的效果
		FogEffect getFogEffect() const { return _fogEffect; }
		void setFogEffect(FogEffect val) { _fogEffect = val; }
		// 密度
		float getDensity() const { return _density; }
		void setDensity(float val) { _density = val; }
	protected:
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