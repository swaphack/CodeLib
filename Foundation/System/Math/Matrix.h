#pragma once

#include "macros.h"

namespace sys
{
	/**
	*	����
	*/
	struct Matrix
	{
	protected:
		// ��Ԫֵ
		float* values;
		// ����
		uint width;
		// ����
		uint height;
	public:
		Matrix();
		Matrix(uint w, uint h);
		~Matrix();
		/**
		*	����
		*/
		uint getWidth();
		/**
		*	����
		*/
		uint getHeight();
		/**
		*	����
		*/
		void reset(uint w, uint h);
		/**
		*	����
		*/
		void reset();
		/**
		*	��ȡָ��λ�õ�����
		*/
		float getValue(uint index) const;
		/**
		*	��ȡh�У�w�е�����
		*/
		float getValue(uint w, uint h) const;
		/**
		*	����h�У�w�е�����
		*/
		void setValue(uint w, uint h, float value);
		/**
		*	����ָ��λ�õ�����
		*/
		void setValue(uint index, float value);

		/**
		*	��ȡת�þ���
		*/
		Matrix transpose();
		/**
		*	���
		*/
		void dispose();

		/**
		*	���ƾ���Ԫ��
		*/
		Matrix& operator=(const Matrix& mat);
		/**
		*	��ȡָ��λ�õ�����
		*/
		float& operator[](uint index);
		/**
		*	��ȡָ��λ�õ�����
		*/
		float operator[](uint index) const;
		
		/**
		*	�������
		*/
		Matrix operator+(const Matrix& mat);
		/**
		*	�������
		*/
		Matrix operator-(const Matrix& mat);
		/**
		*	�������
		*/
		Matrix operator*(const Matrix& mat);
		/**
		*	�������
		*/
		Matrix& operator+=(const Matrix& mat);
		/**
		*	�������
		*/
		Matrix& operator-=(const Matrix& mat);
		/**
		*	�������
		*/
		Matrix& operator*=(const Matrix& mat);
		/**
		*	������չϵ��
		*/
		Matrix& operator*=(float k);
	};
}