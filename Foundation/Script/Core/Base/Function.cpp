#include "Function.h"

using namespace script;


Function::Function()
{

}

Function::~Function()
{
}

Function* Function::create(const char* funcName, ScopeHandler handler, AccessType accesType /*= E_ACCESSTYPE_PUBLIC*/)
{
	if (funcName == nullptr || handler == nullptr)
	{
		return nullptr;
	}

	Function* func = new Function();
	func->setName(funcName);
	func->setAccessType(accesType);
	func->setHandler(handler);

	return func;
}