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
		*	��������ƬԪ program
		*/
		VertexFragmentProgram* createVertexFragmentProgram(const std::string& vertexFilepath, const std::string& fragFilepath);
		/**
		*	�������� program
		*/
		ComputeProgram* createComputeProgram(const std::string& computeFilepath);
		/**
		*	���
		*/
		void clear();
	protected:
		/**
		*	����shader
		*/
		Shader* createShader(ShaderType type, const std::string& filepath);
		/**
		*	����shader
		*/
		Shader* createShader(ShaderType type, const std::string& filepath, const char* shaderData);
		/**
		*	�������й����ļ�
		*/
		bool findAllFile(const std::string& filepath, std::map<std::string, std::string>& fileDatas);
	private:
		std::map<std::string, ShaderProgram*> _shaderPrograms;

		std::map<std::string, std::map<std::string, std::string> > _shaderFiles;

		std::map<std::string, Shader* > _shaders;
	};
	

#define G_SHANDER sys::Instance<render::ShaderManager>::getInstance()
}