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
		/**
		*	��������id
		*/
		uint32_t getProgramID();
	protected:
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