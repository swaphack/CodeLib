#include "ShaderUniformBlock.h"
#include "ShaderProgram.h"
#include "Graphic/import.h"

using namespace render;

ShaderUniformBlock::ShaderUniformBlock()
{

}

ShaderUniformBlock::~ShaderUniformBlock()
{
	this->clearData();
}

void ShaderUniformBlock::initUniformBlock()
{
	this->clearData();

	if (getProgram() == nullptr)
	{
		return;
	}

	uint32_t nProgramID = getProgram()->getProgramID();
	uint32_t nUniformBlockID = getVarID();

	int nBlockSize = 0;
	GLShader::getActiveUniformBlock(nProgramID, nUniformBlockID, UniformBlockParameter::UNIFORM_BLOCK_DATA_SIZE, &nBlockSize);
	if (nBlockSize <= 0)
	{
		return;
	}

	int nUniformCount = 0;
	GLShader::getActiveUniformBlock(nProgramID, nUniformBlockID, UniformBlockParameter::UNIFORM_BLOCK_ACTIVE_UNIFORMS, &nUniformCount);
	if (nUniformCount == 0)
	{
		return;
	}

	_indexCount = nUniformCount;

	int* indices = new int[nUniformCount];
	GLShader::getActiveUniformBlock(nProgramID, nUniformBlockID, UniformBlockParameter::UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES, indices);

	_indices = new uint32_t[nUniformCount];
	memcpy(_indices, indices, nUniformCount * sizeof(uint32_t));
	
	_offsets = new int[nUniformCount];
	_sizes = new int[nUniformCount];
	_types = new int[nUniformCount];

	GLShader::getActiveUniforms(nProgramID, nUniformCount, _indices, UniformParameter::UNIFORM_OFFSET, _offsets);
	GLShader::getActiveUniforms(nProgramID, nUniformCount, _indices, UniformParameter::UNIFORM_SIZE, _sizes);
	GLShader::getActiveUniforms(nProgramID, nUniformCount, _indices, UniformParameter::UNIFORM_TYPE, _types);

	GLDebug::showError();
	delete indices;
}

void render::ShaderUniformBlock::clearData()
{
	SAFE_DELETE(_blockData);
	SAFE_DELETE(_indices);
	SAFE_DELETE(_offsets);
	SAFE_DELETE(_sizes);
	SAFE_DELETE(_types);

	_blockData = nullptr;
	_indices = nullptr;
	_offsets = nullptr;
	_sizes = nullptr;
	_types = nullptr;

	_blockSize = 0;
	_indexCount = 0;
}

void render::ShaderUniformBlock::setValue(const std::string& name, void* data)
{
	if (getProgram() == nullptr)
	{
		return;
	}

	if (_blockData == nullptr || _blockSize == 0)
	{
		return;
	}

	uint32_t nProgramID = getProgram()->getProgramID();
	uint32_t nUniformBlockID = getVarID();

	const char* names[1] = { name.c_str() };
	uint32_t indice = 0;
	GLShader::getUniformIndices(nProgramID, 1, names, &indice);

	memcpy(_blockData + _offsets[indice], data, _sizes[indice] * GLShader::getTypeSize((AttribType)_types[indice]));
}



