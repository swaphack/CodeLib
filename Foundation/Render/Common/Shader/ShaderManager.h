#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"

#include <set>
#include <map>
#include <string>

namespace render
{
	class Shader;
	class ShaderProgram;
	class VertexFragmentProgram;
	class ComputeProgram;

	class ShaderManager
	{
	public:
		ShaderManager();
		virtual ~ShaderManager();
	public:
		/**
		*	创建顶点片元 program
		*/
		VertexFragmentProgram* createVertexFragmentProgram(const std::string& vertexFilepath, const std::string& fragFilepath);
		/**
		*	创建计算 program
		*/
		ComputeProgram* createComputeProgram(const std::string& computeFilepath);
		/**
		*	清空
		*/
		void clear();
	protected:
		/**
		*	创建shader
		*/
		Shader* createShader(ShaderType type, const std::string& filepath);
		/**
		*	创建shader
		*/
		Shader* createShader(ShaderType type, const std::string& filepath, const char* shaderData);
		/**
		*	查找所有关联文件
		*/
		bool findAllFile(const std::string& filepath, std::map<std::string, std::string>& fileDatas);
	private:
		std::map<std::string, ShaderProgram*> _shaderPrograms;

		std::map<std::string, std::map<std::string, std::string> > _shaderFiles;

		std::map<std::string, Shader* > _shaders;
	};
	

#define G_SHANDER sys::Instance<render::ShaderManager>::getInstance()
}