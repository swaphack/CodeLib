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
		*	名字
		*/
		void setName(const std::string& name);
		/**
		*	名字
		*/
		const std::string& getName() const;
		/**
		*	类型
		*/
		void setType(ShaderParamterType type);
		/**
		*	类型
		*/
		ShaderParamterType getType() const;
	private:
		/**
		*	名字
		*/
		std::string _name;
		/**
		*	类型
		*/
		ShaderParamterType _type = ShaderParamterType::FLOAT;
	};
}
