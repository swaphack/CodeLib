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
		*	创建顶点着色器
		*/
		ShaderProgram* createVertexProgram(const std::string& vertexFilepath, bool link = true);
		/**
		*	创建顶点片元着色器
		*/
		ShaderProgram* createVertexFragmentProgram(const std::string& vertexFilepath, const std::string& fragFilepath, bool link = true);
		/**
		*	创建顶点细分片元着色器
		*/
		ShaderProgram* createVertexTessFragmentProgram(const std::string& vertexFilepath, const std::string& tessEvlFilepath, const std::string& fragFilepath, bool link = true);
		/**
		*	创建顶点细分片元着色器
		*/
		ShaderProgram* createVertexTessFragmentProgram(const std::string& vertexFilepath, const std::string& tessCtrFilepath, const std::string& tessEvlFilepath, const std::string& fragFilepath, bool link = true);

		/**
		*	创建顶点几何片元着色器
		*/
		ShaderProgram* createVertexGeometryFragmentProgram(const std::string& vertexFilepath, const std::string& geometryFilepath, const std::string& fragFilepath, bool link = true);
		/**
		*	创建顶点细分几何片元着色器
		*/
		ShaderProgram* createVertexTessGeometryFragmentProgram(const std::string& vertexFilepath, const std::string& tessEvlFilepath, const std::string& geometryFilepath, const std::string& fragFilepath, bool link = true);
		/**
		*	创建顶点细分几何片元着色器
		*/
		ShaderProgram* createVertexTessGeometryFragmentProgram(const std::string& vertexFilepath, const std::string& tessCtrFilepath, const std::string& tessEvlFilepath, const std::string& geometryFilepath, const std::string& fragFilepath, bool link = true);
		/**
		*	创建计算着色器
		*/
		ComputeShaderProgram* createComputeProgram(const std::string& computeFilepath, bool link = true);
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