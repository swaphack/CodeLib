#pragma once

#include "system.h"

#include <string>

namespace render
{
	// ����
	class Material : public sys::Object
	{
	public:
		Material();
		virtual ~Material();
	public:
		/**
		*	��������
		*/
		void setName(const std::string& name);
		/**
		*	��ȡ����
		*/
		const std::string& getName();
		/**
		*	��������1����
		*/
		void setTexture1(const std::string& name);
		/**
		*	��ȡ����1����
		*/
		const std::string& getTexture1();
		/**
		*	��������2����
		*/
		void setTexture2(const std::string& name);
		/**
		*	��ȡ����2����
		*/
		const std::string& getTexture2();
		/**
		*	������
		*/
		void setAmbientByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		/**
		*	������
		*/
		void setAmbient(float red, float green, float blue, float alpha = 1);
		/**
		*	������
		*/
		const float* getAmbient() const;

		/**
		*	�����
		*/ 
		void setDiffuseByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		/**
		*	�����
		*/
		void setDiffuse(float red, float green, float blue, float alpha = 1);
		/**
		*	�����
		*/
		const float* getDiffuse() const;

		/**
		*	�����
		*/  
		void setSpecularByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		/**
		*	�����
		*/
		void setSpecular(float red, float green, float blue, float alpha = 1);
		/**
		*	�����
		*/
		const float* getSpecular() const;

		/**
		*	����ָ��
		*/   
		void setShiness(float value);
		/**
		*	����ָ��
		*/
		float getShiness() const;

		/**
		*	�������ɫ
		*/  
		void setEmisiionByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		/**
		*	�������ɫ
		*/
		void setEmisiion(float red, float green, float blue, float alpha = 1);
		/**
		*	�������ɫ
		*/
		const float* getEmisiion() const;

		Material& operator = (const Material& value);
	public:
		// �ָ�Ĭ��
		static void applyDefault();
		// Ӧ��
		void apply();
	protected:
		// ����
		std::string _name;
		// ������
		float*  _matrialAmbient = nullptr;
		// �����
		float*  _matrialDiffuse = nullptr;
		// �����
		float*  _matrialSpecular = nullptr;
		// ����ָ��
		float _matrialShiness = 0;
		// �������ɫ
		float* _matrialEmission = nullptr;

		// ��������
		std::string _texture1;
		// ��������
		std::string _texture2;

	};
}