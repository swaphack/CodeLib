#pragma once

#include "macros.h"

namespace render
{
	// 光,点光源
	class CtrlLight : public Node
	{
	public:
		CtrlLight();
		virtual ~CtrlLight();
	public:
		virtual LightIndex getLightIndex() { return ELI_NONE; }

		virtual void draw();
		// 环境光
		void setAmbient(uchar red, uchar green, uchar blue, uchar alpha);
		const float* getAmbient();

		// 漫射光
		void setDiffuse(uchar red, uchar green, uchar blue, uchar alpha);
		const float* getDiffuse();

		// 反射光
		void setSpecular(uchar red, uchar green, uchar blue, uchar alpha);
		const float* getSpecular();
	protected:
		virtual void initSelf();
	protected:
		// 环境光
		float _lightAmbient[4];
		// 漫射光
		float _lightDiffuse[4];
		// 反射光
		float _lightSpecular[4];
		// 关照位置
		float _lightPosition[4];
	};
#define CTREATE_LIGHT_CLASS_0(index) \
	class CtrlLight##index : public CtrlLight \
	{ \
	public: \
	virtual LightIndex getLightIndex() { return ELI_LIGHT##index; } \
	};

#define CTREATE_LIGHT_CLASS_1(index) \
	class CtrlLight##index : public CtrlLight \
	{ \
	public: \
	CtrlLight##index() \
	{ \
	_lightDiffuse[0] = 0.0f; \
	_lightDiffuse[1] = 0.0f; \
	_lightDiffuse[2] = 0.0f; \
	_lightDiffuse[3] = 1.0f; \
	_lightSpecular[0] = 0.0f; \
	_lightSpecular[1] = 0.0f; \
	_lightSpecular[2] = 0.0f; \
	_lightSpecular[3] = 1.0f; \
	} \
	virtual LightIndex getLightIndex() { return ELI_LIGHT##index; } \
	};

	CTREATE_LIGHT_CLASS_0(0);
	CTREATE_LIGHT_CLASS_1(1);
	CTREATE_LIGHT_CLASS_1(2);
	CTREATE_LIGHT_CLASS_1(3);
	CTREATE_LIGHT_CLASS_1(4);
	CTREATE_LIGHT_CLASS_1(5);
	CTREATE_LIGHT_CLASS_1(6);
	CTREATE_LIGHT_CLASS_1(7);
}