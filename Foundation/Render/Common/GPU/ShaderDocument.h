#pragma once

#include "system.h"
#include "ShaderVariableType.h"
#include <map>
#include <string>

namespace render
{
	class ShaderParameter;
	/**
	*	着色器文档
	*/
	class ShaderDocument : public sys::Object
	{
	public:
		ShaderDocument();
		virtual ~ShaderDocument();
	public:
		/**
		*	版本
		*/
		void setVersion(const std::string& version);
		/**
		*	版本
		*/
		const std::string& getVersion() const;
	public:
		/**
		*	添加输入参数
		*/
		void addInputParameter(const std::string& name, ShaderParamterType type);
		/**
		*	移除输入参数
		*/
		void removeInputParameter(const std::string& name);
		/**
		*	移除所有输入参数
		*/
		void removeAllInputParameters();
		/**
		*	获取所有输入参数
		*/
		const std::map<std::string, ShaderParameter*>& getAllInputParameters() const;
	public:
		/**
		*	添加输出参数
		*/
		void addOutputParameter(const std::string& name, ShaderParamterType type);
		/**
		*	移除输出参数
		*/
		void removeOutputParameter(const std::string& name);
		/**
		*	移除所有输出参数
		*/
		void removeAllOutputParameters();
		/**
		*	获取所有输出参数
		*/
		const std::map<std::string, ShaderParameter*>& getAllOutputParameters() const;
	public:
		/**
		*	主体
		*/
		void setContent(const std::string& content);
		/**
		*	主体
		*/
		const std::string& getContent() const;
	public:
		/**
		*	文本
		*/
		std::string getText();
		/**
		*	获取类型文本
		*/
		const std::string& getTypeMark(ShaderParamterType type);
		/**
		*	获取类型大小
		*/
		uint32_t getTypeSize(ShaderParamterType type);
	protected:
		void initTypes();
	private:
		std::map<int, ShaderVariableType> _shaderTypes;
		/**
		*	版本
		*/
		std::string _version;
		/**
		*	输入参数
		*/
		std::map<std::string, ShaderParameter*> _inputParameters;
		/**
		*	输出参数
		*/
		std::map<std::string, ShaderParameter*> _outputParameters;
		/**
		*	主体
		*/
		std::string _content;
	};
}
