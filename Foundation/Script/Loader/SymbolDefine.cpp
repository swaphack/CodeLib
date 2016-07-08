#include "SymbolDefine.h"
#include "ScriptText.h"

using namespace math;

SymbolDefine::SymbolDefine()
{

}

SymbolDefine::~SymbolDefine()
{

}

bool SymbolDefine::loadString(const char* value)
{
	if (value == nullptr)
	{
		return false;
	}

	ScriptText* text = new ScriptText();
	text->loadString(value);
	

	return true;
}

const Symbol* SymbolDefine::getSymbol()
{

}
