#pragma once

#include "Common/Node/Node.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	// ��Դ
	class Light : public Node
	{
	public:
		Light();
		virtual ~Light();
	public:
		// ��Դ����
		virtual LightName getLightName();
		// ��Դ����
		int getLightIndex();
		// ����Դ��
		static int getLightMaxCount();
	public:
		virtual void draw();
		virtual bool init();
	public:
		// ��ɫ
		void setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		const float* getColor();

		// ������
		void setAmbient(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		const float* getAmbient();

		/*�·�������shader����*/
		// �����
		void setDiffuse(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		const float* getDiffuse();

		// �����
		void setSpecular(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		const float* getSpecular();
	protected:
		// ��ɫ
		float _lightColor[4];
		// ������
		float _lightAmbient[4];
		// �����
		float _lightDiffuse[4];
		// �����
		float _lightSpecular[4];
	};

#define CTREATE_LIGHT(index) \
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

	CTREATE_LIGHT(0);
	CTREATE_LIGHT(1);
	CTREATE_LIGHT(2);
	CTREATE_LIGHT(3);
	CTREATE_LIGHT(4);
	CTREATE_LIGHT(5);
	CTREATE_LIGHT(6);
	CTREATE_LIGHT(7);
}