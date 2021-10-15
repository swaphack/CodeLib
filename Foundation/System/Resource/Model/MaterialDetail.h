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
		const std::string& getName() const;
		/**
		*	��������
		*/
		void setTexture(const std::string& name);
		/**
		*	��ȡ����
		*/
		const std::string& getTexture() const;
		/**
		*	����Ambient����
		*/
		void setAmbientTextureMap(const std::string& name);
		/**
		*	��ȡAmbient����
		*/
		const std::string& getAmbientTextureMap() const;
		/**
		*	����Diffuse����
		*/
		void setDiffuseTextureMap(const std::string& name);
		/**
		*	��ȡDiffuse����
		*/
		const std::string& getDiffuseTextureMap() const;
		/**
		*	����Specular����
		*/
		void setSpecularTextureMap(const std::string& name);
		/**
		*	��ȡSpecular����
		*/
		const std::string& getSpecularTextureMap() const;
		/**
		*	����Alpha����
		*/
		void setAlphaTextureMap(const std::string& name);
		/**
		*	��ȡAlpha����
		*/
		const std::string& getAlphaTextureMap() const;
		/**
		*	���ð�͹����
		*/
		void setBumpTextureMap(const std::string& name);
		/**
		*	��ȡ��͹����
		*/
		const std::string& getBumpTextureMap() const;
		/**
		*	���÷�������
		*/
		void setNormalTextureMap(const std::string& name);
		/**
		*	��ȡ��������
		*/
		const std::string& getNormalTextureMap() const;
		/**
		*	������Ӱ����
		*/
		void setShadowTextureMap(const std::string& name);
		/**
		*	��ȡ��Ӱ����
		*/
		const std::string& getShadowTextureMap() const;
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
		void setSpecularShiness(float value);
		/**
		*	����ָ��
		*/
		float getSpecularShiness() const;
		/**
		*	������ǿϵ��
		*/
		void setSpecularStrength(float value);
		/**
		*	������ǿϵ��
		*/
		float getSpecularStrength() const;
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
	public:
		/**
		*	��ֵ
		*/
		MaterialDetail& operator = (const MaterialDetail& value);

		bool equals(const MaterialDetail& detail);
	protected:
		// ����
		std::string _name;
		// ������
		float _ambientColor[4];
		// �����
		float  _diffuseColor[4];
		// �����
		float  _specularColor[4];
		// ����ָ��
		float _specularShiness = 0;
		// ����ָ��
		float _specularStrength = 0;
		// �������ɫ
		float _emissionColor[4];

		// ������������
		std::string _ambientTextureMap;
		// ����������
		std::string _diffuseTextureMap;
		// �߹ⷢ������
		std::string _specularTextureMap;
		// ͸������
		std::string _alphaTextureMap;
		// ��͹����
		std::string _bumpTextureMap;
		// ��������
		std::string _normalTextureMap;
		// ��Ӱ����
		std::string _shadowTextureMap;
	};
}