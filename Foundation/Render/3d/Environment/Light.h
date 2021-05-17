#pragma once

#include "Common/Node/Node.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class ShadowMapping;

	// ��Դ
	class Light : public Node
	{
	public:
		Light();
		virtual ~Light();
	public:
		// ����Դ��
		static int getLightMaxCount();
	public:
		// ��Դ����
		LightName getLightName();
		// ��Դ����
		int getLightIndex();
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
		// ��Դ����
		void setLightIndex(int index);
	protected:
		// ������Ӱ
		void generateShadow();
		// ��Ⱦ��Ӱ
		void renderShadow();
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
		// ��Ӱ
		ShadowMapping* _shadowMapping = nullptr;
	};
}