#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"

#include <set>
#include <map>

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
		bool createShaderFile(ShaderType type, const std::string& filepath, std::set<Shader*>& shaders);

		Shader* createShader(ShaderType type, const std::string& filepath, const char* shaderData);
	private:
		std::map<std::string, ShaderProgram*> _shaderPrograms;

		std::map<std::string, std::set<Shader*> > _shaderFiles;

		std::map<std::string, Shader* > _shaders;
	};
	

#define G_SHANDER sys::Instance<ShaderManager>::getInstance()
}