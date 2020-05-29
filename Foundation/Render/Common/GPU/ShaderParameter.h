#pragma once

#include "system.h"
#include "ShaderType.h"
#include <string>

namespace render
{
	

	class ShaderParameter : public sys::Object
	{
	public:
		ShaderParameter();
		ShaderParameter(const std::string& name, ShaderParamterType type);
		virtual ~ShaderParameter();
	public:
		/**
		*	����
		*/
		void setName(const std::string& name);
		/**
		*	����
		*/
		const std::string& getName() const;
		/**
		*	����
		*/
		void setType(ShaderParamterType type);
		/**
		*	����
		*/
		ShaderParamterType getType() const;
	private:
		/**
		*	����
		*/
		std::string _name;
		/**
		*	����
		*/
		ShaderParamterType _type = ShaderParamterType::FLOAT;
	};
}
