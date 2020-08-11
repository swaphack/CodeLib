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
		LightName getLightName();
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
		friend class Environment;
		void setLightIndex(int index);
	protected:
		// ��ɫ
		float _lightColor[4];
		// ������
		float _lightAmbient[4];
		// �����
		float _lightDiffuse[4];
		// �����
		float _lightSpecular[4];
		// ��Դ����
		int _lightIndex = 0;
	};
}