#pragma once
#include <cstdint>
#include <string>

namespace math
{
	/**
	*	行列式
	*/
	struct Determinant
	{
	protected:
		// 单元值
		float* _values = nullptr;
		// 列数
		uint32_t _width = 0;
	public:
		Determinant();
		Determinant(uint32_t w);
		Determinant(float* val, uint32_t w);
		Determinant(const Determinant& det);
		~Determinant();
	public:
		/**
		*	列数
		*/
		uint32_t getWidth();
		/**
		*	重置
		*/
		void reset(uint32_t w);
		/**
		*	重置
		*/
		void reset();
		/**
		*	获取指定位置的数据
		*/
		float getValue(uint32_t index) const;
		/**
		*	获取h行，w列的数据
		*/
		float getValue(uint32_t w, uint32_t h) const;
		/**
		*	设置h行，w列的数据
		*/
		void setValue(uint32_t w, uint32_t h, float value);
		/**
		*	设置指定位置的数据
		*/
		void setValue(uint32_t index, float value);
		/**
		*	复制矩阵元素
		*/
		Determinant& operator=(const Determinant& mat);
		/**
		*	获取指定位置的数据
		*/
		float& operator[](uint32_t index);
		/**
		*	获取指定位置的数据
		*/
		float operator[](uint32_t index) const;

		/**
		*	矩阵相加
		*/
		virtual Determinant operator+(const Determinant& mat);
		/**
		*	矩阵相减
		*/
		virtual Determinant operator-(const Determinant& mat);
		/**
		*	矩阵相乘
		*/
		virtual Determinant operator*(const Determinant& mat);
		/**
		*	矩阵相加
		*/
		virtual Determinant& operator+=(const Determinant& mat);
		/**
		*	矩阵相减
		*/
		virtual Determinant& operator-=(const Determinant& mat);
		/**
		*	矩阵扩展系数
		*/
		virtual Determinant& operator*=(float k);
		/**
		* 转成字符串
		*/
		std::string toString();
		/**
		*	值
		*/
		float getValue();
	private:
		/**
		*	清除
		*/
		void dispose();
	};
}