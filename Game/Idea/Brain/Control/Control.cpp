#include "Control.h"

using namespace idea;


Control::Control()
:_arithmetical(nullptr)
, _memory(nullptr)
{
	_ai = new AI();
}

Control::~Control()
{
	SAFE_DELETE(_ai);
}

void Control::setArithmetical(Arithmetical* arithmetical)
{
	_arithmetical = arithmetical;
}

void Control::setMemory(Memory* memory)
{
	_memory = memory;
}

Result* Control::run(Event* e)
{
	if (e == nullptr || e->getMessage() == nullptr)
	{
		return nullptr;
	}

	Result* result;

	// 记忆查找
	result = getMemory()->run(e);
	if (result)
	{
		return result;
	}

	// 逻辑运算
	result = getArithmetical()->run(e);
	if (result)
	{
		return result;
	}

	// ai 处理
	result = _ai->run(e);
	if (result)
	{
		// 写入题目-答案组合
		getMemory()->alloc(e->getMessage()->getStringValue(), result);
		return result;
	}

	return nullptr;
}

Arithmetical* Control::getArithmetical()
{
	return _arithmetical;
}

Memory* Control::getMemory()
{
	return _memory;
}