#include "ShaderUniformBlock.h"
#include "ShaderProgram.h"
#include "Graphic/import.h"

using namespace render;
render::ShaderUniformBlockData::ShaderUniformBlockData()
{

}

render::ShaderUniformBlockData::~ShaderUniformBlockData()
{
	clearBlockData();
	clearBlockIndicesData();
}

void render::ShaderUniformBlockData::setBlockData(int size, const char* data)
{
	this->clearBlockData();
	_data.init(size, data);
}

const sys::MemoryData& render::ShaderUniformBlockData::getBlockData() const
{
	return _data;
}

void render::ShaderUniformBlockData::setBlockIndicesData(int count, const uint32_t* indices, int* offsets, int* sizes, int* types)
{
	this->clearBlockIndicesData();
	_indices.init(count, indices);
	_offsets.init(count, offsets);
	_sizes.init(count, sizes);
	_types.init(count, types);
}

void render::ShaderUniformBlockData::setValue(const std::string& name, void* data)
{
	if (getProgram() == nullptr)
	{
		return;
	}

	uint32_t nProgramID = getProgram()->getProgramID();

	const char* names[1] = { name.c_str() };
	uint32_t indice = 0;
	GLShader::getUniformIndices(nProgramID, 1, names, &indice);

	int32_t type = *((int32_t*)_types.getPtr(indice));
	int32_t offset = *((int32_t*)_offsets.getPtr(indice));
	int32_t size = *((int32_t*)_sizes.getPtr(indice));

	int sizeType = GLShader::getTypeSize((AttribType)type);

	memcpy(_data.getPtr(offset), data, size * sizeType);
}

void render::ShaderUniformBlockData::clearBlockData()
{
	_data.clear();
}

void render::ShaderUniformBlockData::clearBlockIndicesData()
{
	_indices.clear();
	_offsets.clear();
	_sizes.clear();
	_types.clear();
}

//////////////////////////////////////////////////////////////////////////
ShaderUniformBlock::ShaderUniformBlock()
{

}

ShaderUniformBlock::~ShaderUniformBlock()
{

}

bool render::ShaderUniformBlock::getBlockData(ShaderUniformBlockData& data)
{
	if (getProgram() == nullptr)
	{
		return false;
	}

	data.setProgram(getProgram());

	uint32_t nProgramID = getProgram()->getProgramID();
	uint32_t nUniformBlockID = getVarID();

	int nBlockSize = 0;
	GLShader::getActiveUniformBlock(nProgramID, nUniformBlockID, UniformBlockParameter::UNIFORM_BLOCK_DATA_SIZE, &nBlockSize);
	if (nBlockSize <= 0)
	{
		return false;
	}

	int nUniformCount = 0;
	GLShader::getActiveUniformBlock(nProgramID, nUniformBlockID, UniformBlockParameter::UNIFORM_BLOCK_ACTIVE_UNIFORMS, &nUniformCount);
	if (nUniformCount == 0)
	{
		return false;
	}

	int* indexes = new int[nUniformCount];
	GLShader::getActiveUniformBlock(nProgramID, nUniformBlockID, UniformBlockParameter::UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES, indexes);

	auto indices = new uint32_t[nUniformCount];
	memcpy(indices, indexes, nUniformCount * sizeof(uint32_t));

	auto buffer = new char[nBlockSize];
	auto offsets = new int[nUniformCount];
	auto sizes = new int[nUniformCount];
	auto types = new int[nUniformCount];

	GLShader::getActiveUniforms(nProgramID, nUniformCount, indices, UniformParameter::UNIFORM_OFFSET, offsets);
	GLShader::getActiveUniforms(nProgramID, nUniformCount, indices, UniformParameter::UNIFORM_SIZE, sizes);
	GLShader::getActiveUniforms(nProgramID, nUniformCount, indices, UniformParameter::UNIFORM_TYPE, types);

	data.setBlockData(nBlockSize, buffer);
	data.setBlockIndicesData(nUniformCount, indices, offsets, sizes, types);

	GLDebug::showError();

	delete[] indexes;
	delete[] indices;
	delete[] buffer;
	delete[] offsets;
	delete[] sizes;
	delete[] types;

	return true;
}

