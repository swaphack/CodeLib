#include "None.h"
using namespace script;


None::None()
{
	this->setDataType(E_DATATYPE_NULL);
}

None::~None()
{

}

void* None::getValue()
{
	return nullptr;
}

None* None::clone()
{
	None* pVar = new None();
	pVar->setDataType(getDataType());
	return pVar;
}

None* None::alloct(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}
	None* pVal = this->clone();
	pVal->setName(name);
	return pVal;
}