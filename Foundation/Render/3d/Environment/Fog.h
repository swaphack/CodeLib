#pragma once

#include "Common/Node/Node.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	// 雾
	class Fog : public Node
	{
	public:
		Fog();
		virtual ~Fog();
	protected:
		virtual void onDraw();
	public:
		// 近距离
		float getNear() const;
		void setNear(float val);
		// 远距离
		float getFar() const;
		void setFar(float val);
		// 雾的类型
		FogMode getFogMode() const;
		void setFogMode(FogMode val);
		// 雾的效果
		HintMode getFogEffect() const;
		void setFogEffect(HintMode val);
		// 密度
		float getDensity() const;
		void setDensity(float val);

		void setFogColor(const phy::Color4F& color);
		const phy::Color4F& getFogColor() const;
	protected:
		// 近距离
		float _near;
		// 远距离
		float _far;
		// 雾的类型
		FogMode _fogMode;
		// 雾的效果
		HintMode _fogEffect;
		// 密度
		float _density;

		phy::Color4F _fogColor;
	};
}