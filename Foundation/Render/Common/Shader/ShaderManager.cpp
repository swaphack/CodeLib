#include "ShaderManager.h"
#include "ShaderProgram.h"
#include "Shader.h"

render::ShaderManager::ShaderManager()
{
}

render::ShaderManager::~ShaderManager()
{
	this->clear();
}

render::ShaderProgram* render::ShaderManager::createShaderProgram(const std::string& vertexFilepath, const std::string& fragFilepath)
{
	auto key = vertexFilepath + fragFilepath;
	auto it = _shaderPrograms.find(key);
	if (it != _shaderPrograms.end())
	{
		return it->second;
	}

	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	std::set<render::Shader*> vertexShaders;
	if (!createShaderFile(ShaderType::VERTEX_SHADER, vertexFilepath, vertexShaders))
	{
		return nullptr;
	}

	std::set<render::Shader*> fragShaders;
	if (!createShaderFile(ShaderType::FRAGMENT_SHADER, fragFilepath, fragShaders))
	{
		return nullptr;
	}

	for (auto item : vertexShaders)
	{
		pProgram->attachShader(item);
	}

	for (auto item : fragShaders)
	{
		pProgram->attachShader(item);
	}

	pProgram->bindFragDataLocation(0, "color");
	pProgram->link();

	SAFE_RETAIN(pProgram);

	_shaderPrograms[key] = pProgram;

	return pProgram;
}

void render::ShaderManager::clear()
{
	for (auto item : _shaders)
	{
		SAFE_RELEASE(item.second);
	}

	for (auto item : _shaderPrograms)
	{
		SAFE_RELEASE(item.second);
	}
}

bool render::ShaderManager::createShaderFile(ShaderType type, const std::string& filepath, std::set<render::Shader*>& shaders)
{
	auto it = _shaderFiles.find(filepath);
	if (it != _shaderFiles.end())
	{
		shaders = it->second;
		return true;
	}

	std::string data;
	if (!G_FILEPATH->getFileData(filepath, data))
	{
		return false;
	}

	std::vector<std::string> includeFiles;

	int startIndex = -1;
	int endIndex = -1;


	sys::String content = data;

	int len = strlen("#include \"");

	while ((startIndex = content.findFirstOf("#include \"")) != -1)
	{
		sys::String temp = content.subString(startIndex + len, content.getSize() - (startIndex + len));
		endIndex = temp.findFirstOf("\"");
		if (endIndex == -1) break;

		sys::String filename = temp.subString(0, endIndex);
		includeFiles.insert(includeFiles.begin(), filename.getString());

		content.remove(startIndex, endIndex + len - startIndex);
	}

	Shader* pShader = createShader(type, filepath, content.getString());
	if (pShader == nullptr)
	{
		return false;
	}
	shaders.insert(pShader);

	bool bRet = true;
	for (auto item : includeFiles)
	{
		if (!createShaderFile(type, item, shaders))
		{
			return false;
		}
	}

	return bRet;
}

render::Shader* render::ShaderManager::createShader(ShaderType type, const std::string& filepath, const char* shaderData)
{
	auto it = _shaders.find(filepath);
	if (it != _shaders.end())
	{
		return it->second;
	}

	Shader* pShader = Shader::createFromData(type, shaderData);
	if (pShader == nullptr)
	{
		return nullptr;
	}

	SAFE_RETAIN(pShader);

	return pShader;
}
