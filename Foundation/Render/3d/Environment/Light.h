#pragma once

#include "Common/Node/Node.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	// ��,���Դ
	class Light : public Node
	{
	public:
		Light();
		virtual ~Light();
	public:
		virtual LightName getLightName() { return LightName::LIGHT0; }

	public:
		virtual void draw();
		virtual bool init();
	public:
		// ������
		void setAmbient(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		const float* getAmbient();

		// �����
		void setDiffuse(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		const float* getDiffuse();

		// �����
		void setSpecular(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		const float* getSpecular();
	protected:
		virtual void onLightPositionChange();
	protected:
		// ������
		float _lightAmbient[4];
		// �����
		float _lightDiffuse[4];
		// �����
		float _lightSpecular[4];
		// ����λ��
		float _lightPosition[4];
	};
#define CTREATE_LIGHT_CLASS_0(index) \
	class Light##index : public Light \
	{ \
	public: \
	virtual LightName getLightName() { return LightName::LIGHT##index; } \
	};

#define CTREATE_LIGHT_CLASS_1(index) \
	class Light##index : public Light \
	{ \
	public: \
	Light##index() \
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
	virtual LightName getLightName() { return LightName::LIGHT##index; } \
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