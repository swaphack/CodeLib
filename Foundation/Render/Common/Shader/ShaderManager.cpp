#include "ShaderManager.h"
#include "ShaderProgram.h"
#include "VertexFragmentShaderProgram.h"
#include "ComputeShaderProgram.h"
#include "VertexShaderProgram.h"
#include "Shader.h"
#include "system.h"

render::ShaderManager::ShaderManager()
{
}

render::ShaderManager::~ShaderManager()
{
	this->clear();
}

render::VertexShaderProgram* render::ShaderManager::createVertexProgram(const std::string& vertexFilepath, bool link)
{
	auto it = _shaderPrograms.find(vertexFilepath);
	if (it != _shaderPrograms.end())
	{
		return it->second->as<render::VertexShaderProgram>();
	}

	VertexShaderProgram* pProgram = CREATE_OBJECT(VertexShaderProgram);
	render::Shader* pVertexShader = createShader(ShaderType::VERTEX_SHADER, vertexFilepath);
	if (!pVertexShader)
	{
		return nullptr;
	}

	pProgram->attachShader(pVertexShader);
	if (link)
	{
		pProgram->link();
	}

	SAFE_RETAIN(pProgram);

	_shaderPrograms[vertexFilepath] = pProgram;

	return pProgram;
}

render::VertexFragmentShaderProgram* render::ShaderManager::createVertexFragmentProgram(const std::string& vertexFilepath, const std::string& fragFilepath, bool link)
{
	auto key = vertexFilepath + fragFilepath;
	auto it = _shaderPrograms.find(key);
	if (it != _shaderPrograms.end())
	{
		return it->second->as<render::VertexFragmentShaderProgram>();
	}

	VertexFragmentShaderProgram* pProgram = CREATE_OBJECT(VertexFragmentShaderProgram);
	render::Shader* pVertexShader = createShader(ShaderType::VERTEX_SHADER, vertexFilepath);
	if (!pVertexShader)
	{
		return nullptr;
	}

	render::Shader* fragShader = createShader(ShaderType::FRAGMENT_SHADER, fragFilepath);
	if (!fragShader)
	{
		return nullptr;
	}

	pProgram->attachShader(pVertexShader);
	pProgram->attachShader(fragShader);

	pProgram->bindFragDataLocation(0, "color");
	if (link)
	{
		pProgram->link();
	}

	SAFE_RETAIN(pProgram);

	_shaderPrograms[key] = pProgram;

	return pProgram;
}

render::ComputeShaderProgram* render::ShaderManager::createComputeProgram(const std::string& computeFilepath, bool link)
{
	auto it = _shaderPrograms.find(computeFilepath);
	if (it != _shaderPrograms.end())
	{
		return it->second->as<render::ComputeShaderProgram>();
	}

	ComputeShaderProgram* pProgram = CREATE_OBJECT(ComputeShaderProgram);
	render::Shader* pComputeShader = createShader(ShaderType::COMPUTE_SHADER, computeFilepath);
	if (!pComputeShader)
	{
		return nullptr;
	}

	pProgram->attachShader(pComputeShader);

	if (link)
	{
		pProgram->link();
	}

	SAFE_RETAIN(pProgram);

	_shaderPrograms[computeFilepath] = pProgram;

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

render::Shader* render::ShaderManager::createShader(ShaderType type, const std::string& filepath)
{
	std::map<std::string, std::string> fileDatas;
	if (!findAllFile(filepath, fileDatas))
	{
		return nullptr;
	}

	PRINT("ShaderManager createShader, filepath :%s\n", filepath.c_str());

	sys::String root = fileDatas[filepath];
	std::set<std::string> includedFiles;
	std::function<void(sys::String& fileData)> pFunc = nullptr;
	pFunc = [&](sys::String& fileData) {

		for (auto item : fileDatas)
		{
			if (item.first == filepath)
			{
				continue;
			}
			std::string includeFile = sys::String::makeCString("#include \"%s\"", item.first.c_str());
			if (fileData.findFirstOf(includeFile) != -1)
			{
				sys::String subFileData = item.second;
				pFunc(subFileData);
				if (includedFiles.find(includeFile) == includedFiles.end())
				{
					fileData = fileData.replace(includeFile, subFileData.getString());
					includedFiles.insert(includeFile);
				}
				else
				{
					fileData = fileData.replace(includeFile, "");
				}
			}
		}
	};

	pFunc(root);

	
	render::Shader* pShader = render::Shader::createFromData(type, root.getString());
	if (pShader == nullptr)
	{
		std::string errFilePath = "error/";
		errFilePath += filepath;
		sys::File::write(errFilePath, root.getString(), root.getSize());
		PRINT("\n%s\n\n", root.getString());
		return nullptr;
	}

	return pShader;
}

bool render::ShaderManager::findAllFile(const std::string& filepath, std::map<std::string, std::string>& fileDatas)
{
	auto it = _shaderFiles.find(filepath);
	if (it != _shaderFiles.end())
	{
		fileDatas = it->second;
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

		content.remove(startIndex, len + filename.getSize() + 1);
	}

// 	if (content.empty())
// 	{
// 		return false;
// 	}

// 	int32_t index = content.findFirstOf("#");
// 	if (index != -1)
// 	{
// 		content.remove(0, index);
// 	}

	fileDatas[filepath] = data;

	for (auto item : includeFiles)
	{
		if (!findAllFile(item, fileDatas))
		{
			return false;
		}
	}

	return true;
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
