#include "CGShader.h"
#include <Cg/cgD3D9.h>

static CGShader* sCGShader = nullptr;

CGShader::CGShader()
:mContext(nullptr)
{

}

CGShader::~CGShader()
{
	this->destory();
}

CGShader* CGShader::getInstance()
{
	if (sCGShader == nullptr) 
	{
		sCGShader = new CGShader();
		sCGShader->init();
	}

	return sCGShader;
}

void CGShader::init()
{
	mContext = cgCreateContext();

	//CGprogram program = cgCreateProgram(mContext, CG_SOURCE, )
}

void CGShader::destory()
{

}
