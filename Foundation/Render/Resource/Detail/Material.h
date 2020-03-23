#pragma once

#include "system.h"

#include <string>

namespace render
{
	// 材质
	class Material : public sys::Object
	{
	public:
		Material();
		virtual ~Material();
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
		*	设置纹理1名称
		*/
		void setTexture1(const std::string& name);
		/**
		*	获取纹理1名称
		*/
		const std::string& getTexture1();
		/**
		*	设置纹理2名称
		*/
		void setTexture2(const std::string& name);
		/**
		*	获取纹理2名称
		*/
		const std::string& getTexture2();
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
		void setEmisiionByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		/**
		*	辐射光颜色
		*/
		void setEmisiion(float red, float green, float blue, float alpha = 1);
		/**
		*	辐射光颜色
		*/
		const float* getEmisiion() const;

		Material& operator = (const Material& value);
	public:
		// 恢复默认
		static void applyDefault();
		// 应用
		void apply();
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
		std::string _texture1;
		// 纹理名称
		std::string _texture2;

	};
}