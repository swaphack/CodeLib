#pragma once

#include "system.h"

namespace render
{
	// ����
	class Material : public sys::Object
	{
	public:
		Material();
		virtual ~Material();
	public:
		// �ָ�Ĭ��
		static void applyDefault();
		// Ӧ��
		void apply();
		// ������
		void setAmbientByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		// ������
		void setAmbient(float red, float green, float blue, float alpha = 1);

		const float* getAmbient() const;

		// �����
		void setDiffuseByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		// �����
		void setDiffuse(float red, float green, float blue, float alpha = 1);

		const float* getDiffuse() const;

		// �����
		void setSpecularByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		// �����
		void setSpecular(float red, float green, float blue, float alpha = 1);
		const float* getSpecular() const;

		// ����ָ��
		void setShiness(float value);
		float getShiness() const;

		// �������ɫ
		void setEmisiionByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		// �����
		void setEmisiion(float red, float green, float blue, float alpha = 1);
		const float* getEmisiion() const;

		Material& operator = (const Material& value);
	protected:
		// ������
		float _matrialAmbient[4];
		// �����
		float _matrialDiffuse[4];
		// �����
		float _matrialSpecular[4];
		// ����ָ��
		float _matrialShiness;
		// �������ɫ
		float _matrialEmission[4];

	};
}