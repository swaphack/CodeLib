#include "SymbolDefine.h"
#include "ScriptText.h"

using namespace math;
/*
sample:

define:
	symbol	=>;
	var a, b;
	describe:
		if a is TRUE then b is True;
	end
	call:
		a=>b;
	end
	function:
		
	end
end
*/

#define SYMBOL_DEFINE_SIGNAL			"define"
#define SYMBOL_DEFINE_SYMBOL			"symbol"
#define SYMBOL_DEFINE_VARIABLE			"var"
#define SYMBOL_DEFINE_CALL				"call"
#define SYMBOL_DEFINE_DESCRIBE			"describe"
#define SYMBOL_DEFINE_FUNCTION			"function"
#define SYMBOL_DEFINE_SENTENCE_END		";"
#define SYMBOL_DEFINE_PARAGRAPH_BEGIN	":"
#define SYMBOL_DEFINE_PARAGRAPH_END		"end"

class SymbolDefineLoader
{
public:

protected:
private:
};


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
		return;
	}

	ScriptText* text = new ScriptText();
	text->loadString(value);
	text->getRoot()

}

const Symbol* SymbolDefine::getSymbol()
{

}
