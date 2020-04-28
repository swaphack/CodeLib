#pragma once

#include "system.h"

namespace render
{
	class ShaderProgram;

	/**
	*	����
	*/
	class ShaderVariable : public sys::Object
	{
	public:
		ShaderVariable();
		virtual ~ShaderVariable();
	public:
		/**
		*	���ñ������
		*/
		void setVarID(uint32_t id);
		/**
		*	���Ա��
		*/
		uint32_t getVarID();
		/**
		*	������������
		*/
		void setName(const std::string& name);
		/**
		*	��������
		*/
		const std::string& getName();
		/**
		*	��������
		*/
		void setProgram(ShaderProgram* program);
		/**
		*	��������
		*/
		ShaderProgram* getProgram();
	private:
		/**
		*	���
		*/
		uint32_t _varID = 0;
		/**
		*	����
		*/
		std::string _name;
		/**
		*	����
		*/
		ShaderProgram* _program = nullptr;
	};
}