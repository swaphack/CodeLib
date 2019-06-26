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
		void setAmbient(uint8 red, uint8 green, uint8 blue, uint8 alpha);
		const float* getAmbient() const;

		// �����
		void setDiffuse(uint8 red, uint8 green, uint8 blue, uint8 alpha);
		const float* getDiffuse() const;

		// �����
		void setSpecular(uint8 red, uint8 green, uint8 blue, uint8 alpha);
		const float* getSpecular() const;

		// ����ָ��
		void setShiness(float value);
		float getShiness() const;

		// �������ɫ
		void setEmisiion(uint8 red, uint8 green, uint8 blue, uint8 alpha);
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