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
		*	��ӹ�Դ
		*/ 
		void addLight(Light* light);
		/**
		*	�Ƴ���Դ
		*/ 
		void removeLight(Light* light);
		/**
		*	��ȡ��Դ
		*/ 
		Light* getLight(LightName name) const;
		/**
		*	��ȡ���й�Դ
		*/
		const std::map<int, Light*>& getAllLights() const;
		/**
		*	�Ƿ��й�Դ
		*/
		bool hasLight() const;
	private:
		std::map<int, Light*> _lights;
	};

#define G_ENVIRONMENT sys::Instance<render::Environment>::getInstance()
}
