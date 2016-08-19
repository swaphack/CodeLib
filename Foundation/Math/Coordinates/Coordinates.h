#pragma once

namespace math
{
	/**
	*	����ϵ
	*/
	class Coordinates
	{
	public:
		Coordinates();
		virtual ~Coordinates();
	public:
		// ��x��Ϊ���ģ���ת����
		void setRotationX(float rotation);
		float getRotaionX();

		// ��y��Ϊ���ģ���ת����
		void setRotationY(float rotation);
		float getRotaionY();

		// ��z��Ϊ���ģ���ת����
		void setRotationZ(float rotation);
		float getRotaionZ();

		void setAngleX(float angle);
		float getAngleX();

		void setAngleY(float angle);
		float getAngleY();

		void setAngleZ(float angle);
		float getAngleZ();
	private:
		// ��x��Ϊ���ģ���ת����
		float _rotationX;
		// ��y��Ϊ���ģ���ת����
		float _rotationY;
		// ��z��Ϊ���ģ���ת����
		float _rotationZ;
		// x��ƫ�ƶ���
		float _angelX;
		// y��ƫ�ƶ���
		float _angelY;
		// z��ƫ�ƶ���
		float _angelZ;
	};
}