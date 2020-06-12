#pragma once

#include "system.h"
#include "ShaderVariableType.h"
#include <string>

namespace render
{
	/**
	*	参数
	*/
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
		/**
		*	类型
		*/
		void setValue(uint32_t len, const char* value);
		/**
		*	类型
		*/
		const char* getValue() const;
	private:
		/**
		*	名字
		*/
		std::string _name;
		/**
		*	类型
		*/
		ShaderParamterType _type = ShaderParamterType::FLOAT;
		/**
		*	数据
		*/
		sys::MemoryData _value;
	};
}
