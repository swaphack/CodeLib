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

	class ShaderManager
	{
	public:
		ShaderManager();
		virtual ~ShaderManager();
	public:
		ShaderProgram* createShaderProgram(const std::string& vertexFilepath, const std::string& fragFilepath);

		void clear();
	protected:
		render::Shader* createShader(ShaderType type, const std::string& filepath);

		Shader* createShader(ShaderType type, const std::string& filepath, const char* shaderData);

		bool findAllFile(const std::string& filepath, std::map<std::string, std::string>& fileDatas);
	private:
		std::map<std::string, ShaderProgram*> _shaderPrograms;

		std::map<std::string, std::map<std::string, std::string> > _shaderFiles;

		std::map<std::string, Shader* > _shaders;
	};
	

#define G_SHANDER sys::Instance<ShaderManager>::getInstance()
}