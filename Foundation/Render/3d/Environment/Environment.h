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
		Light* getLight(LightName name) const;
		/**
		*	获取所有光源
		*/
		const std::map<int, Light*>& getAllLights() const;
		/**
		*	是否有光源
		*/
		bool hasLight() const;
	private:
		std::map<int, Light*> _lights;
	};

#define G_ENVIRONMENT sys::Instance<render::Environment>::getInstance()
}
