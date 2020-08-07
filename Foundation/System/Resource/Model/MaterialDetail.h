#pragma once

#include "Framework/Object.h"

#include <string>

namespace sys
{
	// 材质
	class MaterialDetail : public Object
	{
	public:
		MaterialDetail();
		virtual ~MaterialDetail();
	public:
		/**
		*	设置名称
		*/
		void setName(const std::string& name);
		/**
		*	获取名称
		*/
		const std::string& getName();
		/**
		*	设置Ambient纹理
		*/
		void setAmbientTextureMap(const std::string& name);
		/**
		*	获取Ambient纹理
		*/
		const std::string& getAmbientTextureMap();
		/**
		*	设置Diffuse纹理
		*/
		void setDiffuseTextureMap(const std::string& name);
		/**
		*	获取Diffuse纹理
		*/
		const std::string& getDiffuseTextureMap();
		/**
		*	设置Specular纹理
		*/
		void setSpecularTextureMap(const std::string& name);
		/**
		*	获取Specular纹理
		*/
		const std::string& getSpecularTextureMap();
		/**
		*	设置Alpha纹理
		*/
		void setAlphaTextureMap(const std::string& name);
		/**
		*	获取Alpha纹理
		*/
		const std::string& getAlphaTextureMap();
		/**
		*	设置凹凸纹理
		*/
		void setBumpTextureMap(const std::string& name);
		/**
		*	获取凹凸纹理
		*/
		const std::string& getBumpTextureMap();
		/**
		*	设置法线纹理
		*/
		void setNormalTextureMap(const std::string& name);
		/**
		*	获取法线纹理
		*/
		const std::string& getNormalTextureMap();
		/**
		*	环境光
		*/
		void setAmbientByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		/**
		*	环境光
		*/
		void setAmbient(float red, float green, float blue, float alpha = 1);
		/**
		*	环境光
		*/
		const float* getAmbient() const;

		/**
		*	漫射光
		*/ 
		void setDiffuseByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		/**
		*	漫射光
		*/
		void setDiffuse(float red, float green, float blue, float alpha = 1);
		/**
		*	漫射光
		*/
		const float* getDiffuse() const;

		/**
		*	反射光
		*/  
		void setSpecularByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		/**
		*	反射光
		*/
		void setSpecular(float red, float green, float blue, float alpha = 1);
		/**
		*	反射光
		*/
		const float* getSpecular() const;

		/**
		*	镜面指数
		*/   
		void setSpecularShiness(float value);
		/**
		*	镜面指数
		*/
		float getSpecularShiness() const;
		/**
		*	镜面增强系数
		*/
		void setSpecularStrength(float value);
		/**
		*	镜面增强系数
		*/
		float getSpecularStrength() const;
		/**
		*	辐射光颜色
		*/  
		void setEmissionByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		/**
		*	辐射光颜色
		*/
		void setEmission(float red, float green, float blue, float alpha = 1);
		/**
		*	辐射光颜色
		*/
		const float* getEmission() const;
		/**
		*	赋值
		*/
		MaterialDetail& operator = (const MaterialDetail& value);
	protected:
		// 名称
		std::string _name;
		// 环境光
		float _ambientColor[4];
		// 漫射光
		float  _diffuseColor[4];
		// 反射光
		float  _specularColor[4];
		// 镜面指数
		float _specularShiness = 0;
		// 镜面指数
		float _specularStrength = 0;
		// 辐射光颜色
		float _emissionColor[4];

		// 环境纹理（本身）
		std::string _ambientTextureMap;
		// 漫反射纹理
		std::string _diffuseTextureMap;
		// 高光发射纹理
		std::string _specularTextureMap;
		// 透明纹理
		std::string _alphaTextureMap;
		// 凹凸纹理
		std::string _bumpTextureMap;
		// 法线纹理
		std::string _normalTextureMap;
	};
}