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
		Light* getLight(int index) const;
		/**
		*	��ȡ���й�Դ
		*/
		const std::map<int, Light*>& getAllLights() const;
		/**
		*	�Ƿ��й�Դ
		*/
		bool hasLight() const;
	public:
		/**
		*	gamma ֵ
		*/
		void setGamma(float value);
		/**
		*	gamma ֵ
		*/
		float getGamma() const;
	private:
		// ��Դ
		std::map<int, Light*> _lights;
		// gamma ֵ
		float _gamma = 0.0f;
	};

#define G_ENVIRONMENT sys::Instance<render::Environment>::getInstance()
}
