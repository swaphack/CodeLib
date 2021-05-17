#pragma once

#include "Common/Node/Node.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class ShadowMapping;

	// 光源
	class Light : public Node
	{
	public:
		Light();
		virtual ~Light();
	public:
		// 最大光源数
		static int getLightMaxCount();
	public:
		// 光源名字
		LightName getLightName();
		// 光源索引
		int getLightIndex();
	public:
		virtual void draw();
		virtual bool init();
	public:
		// 颜色
		void setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		const float* getColor();

		// 环境光
		void setAmbient(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		const float* getAmbient();

		/*下方两个在shader无用*/
		// 漫射光
		void setDiffuse(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		const float* getDiffuse();

		// 反射光
		void setSpecular(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		const float* getSpecular();
	protected:
		friend class Environment;
		// 光源索引
		void setLightIndex(int index);
	protected:
		// 长生阴影
		void generateShadow();
		// 渲染阴影
		void renderShadow();
	protected:
		// 颜色
		float _lightColor[4];
		// 环境光
		float _lightAmbient[4];
		// 漫射光
		float _lightDiffuse[4];
		// 反射光
		float _lightSpecular[4];
		// 光源索引
		int _lightIndex = 0;
		// 阴影
		ShadowMapping* _shadowMapping = nullptr;
	};
}