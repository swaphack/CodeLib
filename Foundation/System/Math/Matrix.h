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
		uint32 width;
		// ����
		uint32 height;
	public:
		Matrix();
		Matrix(uint32 w, uint32 h);
		~Matrix();
		/**
		*	����
		*/
		uint32 getWidth();
		/**
		*	����
		*/
		uint32 getHeight();
		/**
		*	����
		*/
		void reset(uint32 w, uint32 h);
		/**
		*	����
		*/
		void reset();
		/**
		*	��ȡָ��λ�õ�����
		*/
		float getValue(uint32 index) const;
		/**
		*	��ȡh�У�w�е�����
		*/
		float getValue(uint32 w, uint32 h) const;
		/**
		*	����h�У�w�е�����
		*/
		void setValue(uint32 w, uint32 h, float value);
		/**
		*	����ָ��λ�õ�����
		*/
		void setValue(uint32 index, float value);

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
		float& operator[](uint32 index);
		/**
		*	��ȡָ��λ�õ�����
		*/
		float operator[](uint32 index) const;
		
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