#pragma once

#include "macros.h"

namespace sys
{
	/**
	*	矩阵
	*/
	struct Matrix
	{
	protected:
		// 单元值
		float* values;
		// 列数
		uint width;
		// 行数
		uint height;
	public:
		Matrix();
		Matrix(uint w, uint h);
		~Matrix();
		/**
		*	列数
		*/
		uint getWidth();
		/**
		*	行数
		*/
		uint getHeight();
		/**
		*	重置
		*/
		void reset(uint w, uint h);
		/**
		*	重置
		*/
		void reset();
		/**
		*	获取指定位置的数据
		*/
		float getValue(uint index) const;
		/**
		*	获取h行，w列的数据
		*/
		float getValue(uint w, uint h) const;
		/**
		*	设置h行，w列的数据
		*/
		void setValue(uint w, uint h, float value);
		/**
		*	设置指定位置的数据
		*/
		void setValue(uint index, float value);

		/**
		*	获取转置矩阵
		*/
		Matrix transpose();
		/**
		*	清除
		*/
		void dispose();

		/**
		*	复制矩阵元素
		*/
		Matrix& operator=(const Matrix& mat);
		/**
		*	获取指定位置的数据
		*/
		float& operator[](uint index);
		/**
		*	获取指定位置的数据
		*/
		float operator[](uint index) const;
		
		/**
		*	矩阵相加
		*/
		Matrix operator+(const Matrix& mat);
		/**
		*	矩阵相减
		*/
		Matrix operator-(const Matrix& mat);
		/**
		*	矩阵相乘
		*/
		Matrix operator*(const Matrix& mat);
		/**
		*	矩阵相加
		*/
		Matrix& operator+=(const Matrix& mat);
		/**
		*	矩阵相减
		*/
		Matrix& operator-=(const Matrix& mat);
		/**
		*	矩阵相乘
		*/
		Matrix& operator*=(const Matrix& mat);
		/**
		*	矩阵扩展系数
		*/
		Matrix& operator*=(float k);
	};
}