#pragma once

#include <cstdint>
#include <string>

namespace math
{
	/**
	*	矩阵
	*/
	struct Matrix
	{
	protected:
		// 单元值
		float* _values = nullptr;
		// 列数
		uint32_t _width = 0;
		// 行数
		uint32_t _height = 0;
	public:
		Matrix();
		Matrix(uint32_t w, uint32_t h);
		Matrix(float* val, uint32_t w, uint32_t h);
		Matrix(const Matrix& mat);
		~Matrix();
	public:
		/**
		*	列数
		*/
		uint32_t getWidth();
		/**
		*	行数
		*/
		uint32_t getHeight();
		/**
		*	重置
		*/
		void reset(uint32_t w, uint32_t h);
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
		*	获取转置矩阵
		*/
		Matrix transpose();
		/**
		*	复制矩阵元素
		*/
		Matrix& operator=(const Matrix& mat);
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
		virtual Matrix operator+(const Matrix& mat);
		/**
		*	矩阵相减
		*/
		virtual Matrix operator-(const Matrix& mat);
		/**
		*	矩阵相乘
		*/
		virtual Matrix operator*(const Matrix& mat);
		/**
		*	矩阵相加
		*/
		virtual Matrix& operator+=(const Matrix& mat);
		/**
		*	矩阵相减
		*/
		virtual Matrix& operator-=(const Matrix& mat);
		/**
		*	矩阵扩展系数
		*/
		virtual Matrix& operator*=(float k);
		/**
		* 转成字符串
		*/
		std::string toString();
	private:
		/**
		*	清除
		*/
		void dispose();
	};
}