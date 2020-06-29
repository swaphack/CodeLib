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
		*	设置Bump 纹理
		*/
		void setBumpTextureMap(const std::string& name);
		/**
		*	获取Bump纹理
		*/
		const std::string& getBumpTextureMap();
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
		void setShiness(float value);
		/**
		*	镜面指数
		*/
		float getShiness() const;

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
		float*  _matrialAmbient = nullptr;
		// 漫射光
		float*  _matrialDiffuse = nullptr;
		// 反射光
		float*  _matrialSpecular = nullptr;
		// 镜面指数
		float _matrialShiness = 0;
		// 辐射光颜色
		float* _matrialEmission = nullptr;

		// 纹理名称
		std::string _mapTextureAmbient;
		// 纹理名称
		std::string _mapTextureDiffuse;
		// 纹理名称
		std::string _mapTextureSpecular;
		// 纹理名称
		std::string _mapTextureAlpha;
		// 纹理名称
		std::string _mapTextureBump;
	};
}