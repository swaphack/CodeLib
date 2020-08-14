#pragma once

#include "system.h"
#include <map>
#include "Graphic/GLAPI/macros.h"
namespace render
{
	class Light;

	class Environment : public sys::Object
	{
	public:
		Environment();
		virtual ~Environment();
	public:
		/**
		*	添加光源
		*/ 
		void addLight(Light* light);
		/**
		*	移除光源
		*/ 
		void removeLight(Light* light);
		/**
		*	获取光源
		*/ 
		Light* getLight(int index) const;
		/**
		*	获取所有光源
		*/
		const std::map<int, Light*>& getAllLights() const;
		/**
		*	是否有光源
		*/
		bool hasLight() const;
	public:
		/**
		*	gamma 值
		*/
		void setGamma(float value);
		/**
		*	gamma 值
		*/
		float getGamma() const;
	private:
		// 光源
		std::map<int, Light*> _lights;
		// gamma 值
		float _gamma = 0.0f;
	};

#define G_ENVIRONMENT sys::Instance<render::Environment>::getInstance()
}
