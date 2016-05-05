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
		const float* getAmbient();

		// �����
		void setDiffuse(uchar red, uchar green, uchar blue, uchar alpha);
		const float* getDiffuse();

		// �����
		void setSpecular(uchar red, uchar green, uchar blue, uchar alpha);
		const float* getSpecular();

		// ����ָ��
		void setShiness(float value);
		float getShiness();

		// �������ɫ
		void setEmisiion(uchar red, uchar green, uchar blue, uchar alpha);
		const float* getEmisiion();
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