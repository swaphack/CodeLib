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
		uint32 width;
		// 行数
		uint32 height;
	public:
		Matrix();
		Matrix(uint32 w, uint32 h);
		~Matrix();
		/**
		*	列数
		*/
		uint32 getWidth();
		/**
		*	行数
		*/
		uint32 getHeight();
		/**
		*	重置
		*/
		void reset(uint32 w, uint32 h);
		/**
		*	重置
		*/
		void reset();
		/**
		*	获取指定位置的数据
		*/
		float getValue(uint32 index) const;
		/**
		*	获取h行，w列的数据
		*/
		float getValue(uint32 w, uint32 h) const;
		/**
		*	设置h行，w列的数据
		*/
		void setValue(uint32 w, uint32 h, float value);
		/**
		*	设置指定位置的数据
		*/
		void setValue(uint32 index, float value);

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
		float& operator[](uint32 index);
		/**
		*	获取指定位置的数据
		*/
		float operator[](uint32 index) const;
		
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