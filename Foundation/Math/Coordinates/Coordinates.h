#pragma once

namespace math
{
	/**
	*	坐标系
	*/
	class Coordinates
	{
	public:
		Coordinates();
		virtual ~Coordinates();
	public:
		// 以x轴为中心，旋转度数
		void setRotationX(float rotation);
		float getRotaionX();

		// 以y轴为中心，旋转度数
		void setRotationY(float rotation);
		float getRotaionY();

		// 以z轴为中心，旋转度数
		void setRotationZ(float rotation);
		float getRotaionZ();

		void setAngleX(float angle);
		float getAngleX();

		void setAngleY(float angle);
		float getAngleY();

		void setAngleZ(float angle);
		float getAngleZ();
	private:
		// 以x轴为中心，旋转度数
		float _rotationX;
		// 以y轴为中心，旋转度数
		float _rotationY;
		// 以z轴为中心，旋转度数
		float _rotationZ;
		// x轴偏移度数
		float _angelX;
		// y轴偏移度数
		float _angelY;
		// z轴偏移度数
		float _angelZ;
	};
}