#pragma once

#include <cstdint>
#include <string>

namespace math
{
	/**
	*	����
	*/
	struct Matrix
	{
	protected:
		// ��Ԫֵ
		float* _values = nullptr;
		// ����
		uint32_t _width = 0;
		// ����
		uint32_t _height = 0;
	public:
		Matrix();
		Matrix(uint32_t w, uint32_t h);
		Matrix(float* val, uint32_t w, uint32_t h);
		Matrix(const Matrix& mat);
		~Matrix();
	public:
		/**
		*	����
		*/
		uint32_t getWidth();
		/**
		*	����
		*/
		uint32_t getHeight();
		/**
		*	����
		*/
		void reset(uint32_t w, uint32_t h);
		/**
		*	����
		*/
		void reset();
		/**
		*	��ȡָ��λ�õ�����
		*/
		float getValue(uint32_t index) const;
		/**
		*	��ȡh�У�w�е�����
		*/
		float getValue(uint32_t w, uint32_t h) const;
		/**
		*	����h�У�w�е�����
		*/
		void setValue(uint32_t w, uint32_t h, float value);
		/**
		*	����ָ��λ�õ�����
		*/
		void setValue(uint32_t index, float value);

		/**
		*	��ȡת�þ���
		*/
		Matrix transpose();
		/**
		*	���ƾ���Ԫ��
		*/
		Matrix& operator=(const Matrix& mat);
		/**
		*	��ȡָ��λ�õ�����
		*/
		float& operator[](uint32_t index);
		/**
		*	��ȡָ��λ�õ�����
		*/
		float operator[](uint32_t index) const;
		
		/**
		*	�������
		*/
		virtual Matrix operator+(const Matrix& mat);
		/**
		*	�������
		*/
		virtual Matrix operator-(const Matrix& mat);
		/**
		*	�������
		*/
		virtual Matrix operator*(const Matrix& mat);
		/**
		*	�������
		*/
		virtual Matrix& operator+=(const Matrix& mat);
		/**
		*	�������
		*/
		virtual Matrix& operator-=(const Matrix& mat);
		/**
		*	������չϵ��
		*/
		virtual Matrix& operator*=(float k);
		/**
		* ת���ַ���
		*/
		std::string toString();
	private:
		/**
		*	���
		*/
		void dispose();
	};
}