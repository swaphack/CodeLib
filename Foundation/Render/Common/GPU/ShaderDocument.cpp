#include "ShaderDocument.h"
#include "ShaderParameter.h"

render::ShaderDocument::ShaderDocument()
{
	initTypes();
}

render::ShaderDocument::~ShaderDocument()
{
	this->removeAllInputParameters();
	this->removeAllOutputParameters();
}

void render::ShaderDocument::setVersion(const std::string& version)
{
	_version = version;
}

const std::string& render::ShaderDocument::getVersion() const
{
	return _version;
}

void render::ShaderDocument::addInputParameter(const std::string& name, ShaderParamterType type)
{
	auto it = _inputParameters.find(name);
	if (it != _inputParameters.end())
	{
		it->second->setType(type);
	}
	else
	{
		auto param = CREATE_OBJECT(ShaderParameter);
		SAFE_RETAIN(param);

		_inputParameters[name] = param;
	}
}

void render::ShaderDocument::removeInputParameter(const std::string& name)
{
	auto it = _inputParameters.find(name);
	if (it == _inputParameters.end())
	{
		return;
	}
	SAFE_RELEASE(it->second);
	_inputParameters.erase(it);
}

void render::ShaderDocument::removeAllInputParameters()
{
	for (auto item : _inputParameters)
	{
		SAFE_RELEASE(item.second);
	}
	_inputParameters.clear();
}

const std::map<std::string, render::ShaderParameter*>& render::ShaderDocument::getAllInputParameters() const
{
	return _inputParameters;
}

void render::ShaderDocument::addOutputParameter(const std::string& name, ShaderParamterType type)
{
	auto it = _outputParameters.find(name);
	if (it != _outputParameters.end())
	{
		it->second->setType(type);
	}
	else
	{
		auto param = CREATE_OBJECT(ShaderParameter);
		SAFE_RETAIN(param);

		_outputParameters[name] = param;
	}
}

void render::ShaderDocument::removeOutputParameter(const std::string& name)
{
	auto it = _outputParameters.find(name);
	if (it == _outputParameters.end())
	{
		return;
	}
	SAFE_RELEASE(it->second);
	_outputParameters.erase(it);
}

void render::ShaderDocument::removeAllOutputParameters()
{
	for (auto item : _outputParameters)
	{
		SAFE_RELEASE(item.second);
	}
	_outputParameters.clear();
}

const std::map<std::string, render::ShaderParameter*>& render::ShaderDocument::getAllOutputParameters() const
{
	return _outputParameters;
}

void render::ShaderDocument::setContent(const std::string& content)
{
	_content = content;
}

const std::string& render::ShaderDocument::getContent() const
{
	return _content;
}

std::string render::ShaderDocument::getText()
{
	sys::String version = sys::String::make("#version %s core", _version);
	sys::String input = "";
	for (auto item : _inputParameters)
	{
		std::string paramter = sys::String::make("in %s %s;\n", 
			this->getTypeMark(item.second->getType()).c_str(), item.second->getName().c_str());
		input.concat(paramter);
	}

	sys::String out = "";
	for (auto item : _inputParameters)
	{
		std::string paramter = sys::String::make("in %s %s;\n",
			this->getTypeMark(item.second->getType()).c_str(), item.second->getName().c_str());
		out.concat(paramter);
	}

	sys::String content = sys::String::make("void main(void) { %s };", _content);

	sys::String all = version + input + out + content;

	return std::string(all.getString(), all.getSize());
}

const std::string& render::ShaderDocument::getTypeMark(ShaderParamterType type)
{
	const ShaderVariableType& value = _shaderTypes[(int)type];
	return value.getMark();
}

uint32_t render::ShaderDocument::getTypeSize(ShaderParamterType type)
{
	const ShaderVariableType& value = _shaderTypes[(int)type];
	return value.getSize();
}

void render::ShaderDocument::initTypes()
{
	_shaderTypes[(int)ShaderParamterType::FLOAT] = ShaderVariableType(ShaderParamterType::FLOAT, sizeof(float), "float");
	_shaderTypes[(int)ShaderParamterType::DOUBLE] = ShaderVariableType(ShaderParamterType::DOUBLE, sizeof(double), "double");
	_shaderTypes[(int)ShaderParamterType::INTEGER] = ShaderVariableType(ShaderParamterType::INTEGER, sizeof(int), "int");
	_shaderTypes[(int)ShaderParamterType::UNSIGNED_INTTEGER] = ShaderVariableType(ShaderParamterType::UNSIGNED_INTTEGER, sizeof(uint32_t), "uint");
	_shaderTypes[(int)ShaderParamterType::BOOL] = ShaderVariableType(ShaderParamterType::BOOL, sizeof(bool), "bool");


	_shaderTypes[(int)ShaderParamterType::FLOAT2] = ShaderVariableType(ShaderParamterType::FLOAT2, 2 * sizeof(float), "vec2");
	_shaderTypes[(int)ShaderParamterType::DOUBLE2] = ShaderVariableType(ShaderParamterType::DOUBLE2, 2 * sizeof(double), "dvec2");
	_shaderTypes[(int)ShaderParamterType::INTEGER2] = ShaderVariableType(ShaderParamterType::INTEGER2, 2 * sizeof(int), "ivec2");
	_shaderTypes[(int)ShaderParamterType::UNSIGNED_INTTEGER2] = ShaderVariableType(ShaderParamterType::UNSIGNED_INTTEGER2, 2 * sizeof(uint32_t), "uvec2");
	_shaderTypes[(int)ShaderParamterType::BOOL2] = ShaderVariableType(ShaderParamterType::BOOL2, 2 * sizeof(bool), "bvec2");

	_shaderTypes[(int)ShaderParamterType::FLOAT3] = ShaderVariableType(ShaderParamterType::FLOAT3, 3 * sizeof(float), "vec3");
	_shaderTypes[(int)ShaderParamterType::DOUBLE3] = ShaderVariableType(ShaderParamterType::DOUBLE3, 3 * sizeof(double), "dvec3");
	_shaderTypes[(int)ShaderParamterType::INTEGER3] = ShaderVariableType(ShaderParamterType::INTEGER3, 3 * sizeof(int), "ivec3");
	_shaderTypes[(int)ShaderParamterType::UNSIGNED_INTTEGER3] = ShaderVariableType(ShaderParamterType::UNSIGNED_INTTEGER3, 3 * sizeof(uint32_t), "uvec3");
	_shaderTypes[(int)ShaderParamterType::BOOL3] = ShaderVariableType(ShaderParamterType::BOOL3, 3 * sizeof(bool), "bvec3");

	_shaderTypes[(int)ShaderParamterType::FLOAT4] = ShaderVariableType(ShaderParamterType::FLOAT4, 4 * sizeof(float), "vec4");
	_shaderTypes[(int)ShaderParamterType::DOUBLE4] = ShaderVariableType(ShaderParamterType::DOUBLE4, 4 * sizeof(double), "dvec3");
	_shaderTypes[(int)ShaderParamterType::INTEGER4] = ShaderVariableType(ShaderParamterType::INTEGER4, 4 * sizeof(int), "ivec3");
	_shaderTypes[(int)ShaderParamterType::UNSIGNED_INTTEGER4] = ShaderVariableType(ShaderParamterType::UNSIGNED_INTTEGER4, 4 * sizeof(uint32_t), "uvec4");
	_shaderTypes[(int)ShaderParamterType::BOOL4] = ShaderVariableType(ShaderParamterType::BOOL4, 4 * sizeof(bool), "bvec4");

	_shaderTypes[(int)ShaderParamterType::MAT2] = ShaderVariableType(ShaderParamterType::MAT2, 2 * sizeof(float), "mat2");
	_shaderTypes[(int)ShaderParamterType::MAT3] = ShaderVariableType(ShaderParamterType::MAT3, 3 * sizeof(float), "mat3");
	_shaderTypes[(int)ShaderParamterType::MAT4] = ShaderVariableType(ShaderParamterType::MAT4, 4 * sizeof(float), "mat4");

	_shaderTypes[(int)ShaderParamterType::MAT2X2] = ShaderVariableType(ShaderParamterType::MAT2X2, 2 * 2 * sizeof(float), "mat2x2");
	_shaderTypes[(int)ShaderParamterType::MAT2X3] = ShaderVariableType(ShaderParamterType::MAT2X3, 2 * 3 * sizeof(float), "mat2x3");
	_shaderTypes[(int)ShaderParamterType::MAT2X4] = ShaderVariableType(ShaderParamterType::MAT2X4, 2 * 4 * sizeof(float), "mat2x4");

	_shaderTypes[(int)ShaderParamterType::MAT3X2] = ShaderVariableType(ShaderParamterType::MAT3X2, 3 * 2 * sizeof(float), "mat3x2");
	_shaderTypes[(int)ShaderParamterType::MAT3X3] = ShaderVariableType(ShaderParamterType::MAT3X3, 3 * 3 * sizeof(float), "mat3x3");
	_shaderTypes[(int)ShaderParamterType::MAT3X4] = ShaderVariableType(ShaderParamterType::MAT3X4, 3 * 4 * sizeof(float), "mat3x4");

	_shaderTypes[(int)ShaderParamterType::MAT4X2] = ShaderVariableType(ShaderParamterType::MAT4X2, 4 * 2 * sizeof(float), "mat4x2");
	_shaderTypes[(int)ShaderParamterType::MAT4X3] = ShaderVariableType(ShaderParamterType::MAT4X3, 4 * 3 * sizeof(float), "mat4x3");
	_shaderTypes[(int)ShaderParamterType::MAT4X4] = ShaderVariableType(ShaderParamterType::MAT4X4, 4 * 4 * sizeof(float), "mat4x4");

	_shaderTypes[(int)ShaderParamterType::DMAT2] = ShaderVariableType(ShaderParamterType::DMAT2, 2 * sizeof(double), "dmat2");
	_shaderTypes[(int)ShaderParamterType::DMAT3] = ShaderVariableType(ShaderParamterType::DMAT3, 3 * sizeof(double), "dmat3");
	_shaderTypes[(int)ShaderParamterType::DMAT4] = ShaderVariableType(ShaderParamterType::DMAT4, 4 * sizeof(double), "dmat4");
										  
	_shaderTypes[(int)ShaderParamterType::DMAT2X2] = ShaderVariableType(ShaderParamterType::DMAT2X2, 2 * 2 * sizeof(double), "dmat2x2");
	_shaderTypes[(int)ShaderParamterType::DMAT2X3] = ShaderVariableType(ShaderParamterType::DMAT2X3, 2 * 3 * sizeof(double), "dmat2x3");
	_shaderTypes[(int)ShaderParamterType::DMAT2X4] = ShaderVariableType(ShaderParamterType::DMAT2X4, 2 * 4 * sizeof(double), "dmat2x4");
																			   
	_shaderTypes[(int)ShaderParamterType::DMAT3X2] = ShaderVariableType(ShaderParamterType::DMAT3X2, 3 * 2 * sizeof(double), "dmat3x2");
	_shaderTypes[(int)ShaderParamterType::DMAT3X3] = ShaderVariableType(ShaderParamterType::DMAT3X3, 3 * 3 * sizeof(double), "dmat3x3");
	_shaderTypes[(int)ShaderParamterType::DMAT3X4] = ShaderVariableType(ShaderParamterType::DMAT3X4, 3 * 4 * sizeof(double), "dmat3x4");
																			   
	_shaderTypes[(int)ShaderParamterType::DMAT4X2] = ShaderVariableType(ShaderParamterType::DMAT4X2, 4 * 2 * sizeof(double), "dmat4x2");
	_shaderTypes[(int)ShaderParamterType::DMAT4X3] = ShaderVariableType(ShaderParamterType::DMAT4X3, 4 * 3 * sizeof(double), "dmat4x3");
	_shaderTypes[(int)ShaderParamterType::DMAT4X4] = ShaderVariableType(ShaderParamterType::DMAT4X4, 4 * 4 * sizeof(double), "dmat4x4");


}

