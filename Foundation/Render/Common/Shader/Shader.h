#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class ShaderProgram;
	/**
	*	着色器
	*/
	class Shader : public sys::Object
	{
	public:
		Shader();
		virtual ~Shader();
	public:
		static Shader* create(ShaderType type);
		static Shader* createFromData(ShaderType type, const char* data);
		static Shader* createFromFile(ShaderType type, const std::string& filepath);
	public:
		/**
		*	着色器编号
		*/
		uint32_t getShaderID() const;
		/**
		*	着色器类型
		*/
		ShaderType getShaderType() const;
		/**
		*	设置着色器类型
		*/
		void setShaderType(ShaderType shaderType);
		/**
		*	加载程序代码
		*/
		bool loadFromData(const char* data);
		/**
		*	从文件加载程序
		*/
		bool loadFromFile(const std::string& filepath);
		/**
		*	从预处理的二进制数据加载程序 spir-v
		*/
		bool loadFromBindary(const void* binary, int length);
		/**
		*	spir-v
		*/
	public:
		/**
		*	初始化
		*/
		void initShader();
		/**
		*	释放
		*/
		void releaseShader();
		/**
		*	关联
		*/
		void attachProgram(ShaderProgram* program);
		/**
		*	取消关联
		*/
		void detachProgram();

		/**
		*	是否有效
		*/
		bool isValid() const;
	private:
		/**
		*	着色器编号
		*/
		uint32_t _shaderID = 0;
		/**
		*	着色器类型
		*/
		ShaderType _shaderType = ShaderType::VERTEX_SHADER;
		/**
		*	程序
		*/
		ShaderProgram* _program = nullptr;
		/**
		*	uniform 名字
		*/
		std::set<std::string> _uniformName;
	};
}