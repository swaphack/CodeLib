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
	class VertexShaderProgram;
	class VertexFragmentShaderProgram;
	class ComputeShaderProgram;

	class ShaderManager
	{
	public:
		ShaderManager();
		virtual ~ShaderManager();
	public:
		/**
		*	��������ƬԪ program
		*/
		ShaderProgram* createVertexProgram(const std::string& vertexFilepath, bool link = true);
		/**
		*	��������ƬԪ program
		*/
		ShaderProgram* createVertexFragmentProgram(const std::string& vertexFilepath, const std::string& fragFilepath, bool link = true);
		/**
		*	�������㼸��ƬԪ program
		*/
		ShaderProgram* createVertexGeometryFragmentProgram(const std::string& vertexFilepath, const std::string& geometryFilepath, const std::string& fragFilepath, bool link = true);
		/**
		*	�������� program
		*/
		ComputeShaderProgram* createComputeProgram(const std::string& computeFilepath, bool link = true);
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