#include "Control.h"

using namespace idea;


Control::Control()
:_arithmetical(nullptr)
, _input(nullptr)
, _output(nullptr)
, _memory(nullptr)
{

}

Control::~Control()
{
}

void Control::setInput(Input* input)
{
	_input = input;
}

void Control::setOutput(Output* output)
{
	_output = output;
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
	result = getMemory()->run(e->getMessage());
	if (result)
	{
		return result;
	}

	getArithmetical()->

}

Input* Control::getInput()
{
	return _input;
}

Output* Control::getOutput()
{
	return _output;
}

Arithmetical* Control::getArithmetical()
{
	return _arithmetical;
}

Memory* Control::getMemory()
{
	return _memory;
}