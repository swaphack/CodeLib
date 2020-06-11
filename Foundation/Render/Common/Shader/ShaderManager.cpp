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

render::Shader* render::ShaderManager::createShader(ShaderType type, const std::string& filepath)
{
	std::map<std::string, std::string> fileDatas;
	if (!findAllFile(filepath, fileDatas))
	{
		return nullptr;
	}

	sys::String root = fileDatas[filepath];

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

				fileData = fileData.replace(includeFile, subFileData.getString());
			}
		}
	};

	pFunc(root);

	render::Shader* pShader = render::Shader::createFromData(type, root.getString());
	if (pShader == nullptr)
	{
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