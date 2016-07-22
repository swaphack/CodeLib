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
		void setAmbient(uchar red, uchar green, uchar blue, uchar alpha);
		const float* getAmbient() const;

		// �����
		void setDiffuse(uchar red, uchar green, uchar blue, uchar alpha);
		const float* getDiffuse() const;

		// �����
		void setSpecular(uchar red, uchar green, uchar blue, uchar alpha);
		const float* getSpecular() const;

		// ����ָ��
		void setShiness(float value);
		float getShiness() const;

		// �������ɫ
		void setEmisiion(uchar red, uchar green, uchar blue, uchar alpha);
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