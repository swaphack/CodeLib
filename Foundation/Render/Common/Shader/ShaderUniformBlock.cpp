#include "ShaderUniformBlock.h"
#include "ShaderProgram.h"
#include "Graphic/import.h"

using namespace render;

ShaderUniformBlock::ShaderUniformBlock()
{

}

ShaderUniformBlock::~ShaderUniformBlock()
{
}

void ShaderUniformBlock::initUniformBlock()
{
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
	GLDebug::showError();

	int nLength = 0;
	GLShader::getActiveUniformBlock(nProgramID, nUniformBlockID, UniformBlockParameter::UNIFORM_BLOCK_NAME_LENGTH, &nLength);

	GLDebug::showError();

	char* strName = new char[nLength];
	int nLen = 0;
	GLShader::getActiveUniformBlockName(nProgramID, nUniformBlockID, nBlockSize, &nLen, strName);

	delete strName;

	GLDebug::showError();

	int a = 1;
}



