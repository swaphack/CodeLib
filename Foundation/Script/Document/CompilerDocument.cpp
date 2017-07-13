#include "CompilerDocument.h"
#include "../Compile/import.h"

using namespace script;

CompilerDocument::CompilerDocument()
{
}

CompilerDocument::~CompilerDocument()
{
}

bool CompilerDocument::parse()
{
	if (getPtr() == nullptr)
	{
		return false;
	}

	bool bRet = Compiler::getInstance()->compile(this);
	if (bRet == false)
	{
		return false;
	}

	return true;
}
