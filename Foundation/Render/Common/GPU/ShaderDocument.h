#pragma once

#include "system.h"
#include "ShaderVariableType.h"
#include <map>
#include <string>

namespace render
{
	class ShaderParameter;
	/**
	*	��ɫ���ĵ�
	*/
	class ShaderDocument : public sys::Object
	{
	public:
		ShaderDocument();
		virtual ~ShaderDocument();
	public:
		/**
		*	�汾
		*/
		void setVersion(const std::string& version);
		/**
		*	�汾
		*/
		const std::string& getVersion() const;
	public:
		/**
		*	����������
		*/
		void addInputParameter(const std::string& name, ShaderParamterType type);
		/**
		*	�Ƴ��������
		*/
		void removeInputParameter(const std::string& name);
		/**
		*	�Ƴ������������
		*/
		void removeAllInputParameters();
		/**
		*	��ȡ�����������
		*/
		const std::map<std::string, ShaderParameter*>& getAllInputParameters() const;
	public:
		/**
		*	����������
		*/
		void addOutputParameter(const std::string& name, ShaderParamterType type);
		/**
		*	�Ƴ��������
		*/
		void removeOutputParameter(const std::string& name);
		/**
		*	�Ƴ������������
		*/
		void removeAllOutputParameters();
		/**
		*	��ȡ�����������
		*/
		const std::map<std::string, ShaderParameter*>& getAllOutputParameters() const;
	public:
		/**
		*	����
		*/
		void setContent(const std::string& content);
		/**
		*	����
		*/
		const std::string& getContent() const;
	public:
		/**
		*	�ı�
		*/
		std::string getText();
		/**
		*	��ȡ�����ı�
		*/
		const std::string& getTypeMark(ShaderParamterType type);
		/**
		*	��ȡ���ʹ�С
		*/
		uint32_t getTypeSize(ShaderParamterType type);
	protected:
		void initTypes();
	private:
		std::map<int, ShaderVariableType> _shaderTypes;
		/**
		*	�汾
		*/
		std::string _version;
		/**
		*	�������
		*/
		std::map<std::string, ShaderParameter*> _inputParameters;
		/**
		*	�������
		*/
		std::map<std::string, ShaderParameter*> _outputParameters;
		/**
		*	����
		*/
		std::string _content;
	};
}
