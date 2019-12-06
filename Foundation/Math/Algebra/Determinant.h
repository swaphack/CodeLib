#pragma once
#include <cstdint>
#include <string>

namespace math
{
	/**
	*	����ʽ
	*/
	struct Determinant
	{
	protected:
		// ��Ԫֵ
		float* _values = nullptr;
		// ����
		uint32_t _width = 0;
	public:
		Determinant();
		Determinant(uint32_t w);
		Determinant(float* val, uint32_t w);
		Determinant(const Determinant& det);
		~Determinant();
	public:
		/**
		*	����
		*/
		uint32_t getWidth();
		/**
		*	����
		*/
		void reset(uint32_t w);
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
		*	���ƾ���Ԫ��
		*/
		Determinant& operator=(const Determinant& mat);
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
		virtual Determinant operator+(const Determinant& mat);
		/**
		*	�������
		*/
		virtual Determinant operator-(const Determinant& mat);
		/**
		*	�������
		*/
		virtual Determinant operator*(const Determinant& mat);
		/**
		*	�������
		*/
		virtual Determinant& operator+=(const Determinant& mat);
		/**
		*	�������
		*/
		virtual Determinant& operator-=(const Determinant& mat);
		/**
		*	������չϵ��
		*/
		virtual Determinant& operator*=(float k);
		/**
		* ת���ַ���
		*/
		std::string toString();
		/**
		*	ֵ
		*/
		float getValue();
	private:
		/**
		*	���
		*/
		void dispose();
	};
}