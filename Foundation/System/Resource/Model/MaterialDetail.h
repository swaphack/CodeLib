#pragma once

#include "Framework/Object.h"

#include <string>

namespace sys
{
	// ����
	class MaterialDetail : public Object
	{
	public:
		MaterialDetail();
		virtual ~MaterialDetail();
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
		*	����Ambient����
		*/
		void setAmbientTextureMap(const std::string& name);
		/**
		*	��ȡAmbient����
		*/
		const std::string& getAmbientTextureMap();
		/**
		*	����Diffuse����
		*/
		void setDiffuseTextureMap(const std::string& name);
		/**
		*	��ȡDiffuse����
		*/
		const std::string& getDiffuseTextureMap();
		/**
		*	����Specular����
		*/
		void setSpecularTextureMap(const std::string& name);
		/**
		*	��ȡSpecular����
		*/
		const std::string& getSpecularTextureMap();
		/**
		*	����Alpha����
		*/
		void setAlphaTextureMap(const std::string& name);
		/**
		*	��ȡAlpha����
		*/
		const std::string& getAlphaTextureMap();
		/**
		*	����Bump ����
		*/
		void setBumpTextureMap(const std::string& name);
		/**
		*	��ȡBump����
		*/
		const std::string& getBumpTextureMap();
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
		void setEmissionByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		/**
		*	�������ɫ
		*/
		void setEmission(float red, float green, float blue, float alpha = 1);
		/**
		*	�������ɫ
		*/
		const float* getEmission() const;
		/**
		*	��ֵ
		*/
		MaterialDetail& operator = (const MaterialDetail& value);
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
		std::string _mapTextureAmbient;
		// ��������
		std::string _mapTextureDiffuse;
		// ��������
		std::string _mapTextureSpecular;
		// ��������
		std::string _mapTextureAlpha;
		// ��������
		std::string _mapTextureBump;
	};
}