#include "CompilerDocument.h"
#include "../Compile/import.h"

using namespace script;

CompilerDocument::CompilerDocument()
{
	m_pCompiler = new Compiler();
}

CompilerDocument::~CompilerDocument()
{
	delete m_pCompiler;
}

bool CompilerDocument::parse()
{
	if (getPtr() == nullptr)
	{
		return false;
	}

	bool bRet = m_pCompiler->compile(this);
	if (bRet == false)
	{
		return false;
	}

	return true;
}
