#include "Brain.h"

using namespace idea;


Brain::Brain()
{
	_arithmetical = new Arithmetical();
	_input = new Input();
	_output = new Output();
	_memory = new Memory();

	_control = new Control();
	_control->setArithmetical(_arithmetical);
	_control->setMemory(_memory);
}

Brain::~Brain()
{
	SAFE_DELETE(_control);
	SAFE_DELETE(_arithmetical);
	SAFE_DELETE(_input);
	SAFE_DELETE(_output);
	SAFE_DELETE(_memory);
}

Input* Brain::getInput()
{
	return _input;
}

Output* Brain::getOutput()
{
	return _output;
}

Arithmetical* Brain::getArithmetical()
{
	return _arithmetical;
}

Memory* Brain::getMemory()
{
	return _memory;
}

void Brain::update()
{
	Message* inputMessage;

	// 从输入端读取事件信息单元
	inputMessage = getInput()->pick();
	if (inputMessage == nullptr)
	{
		return;
	}

	Event* inputEvent;
	Result* outputResult;
	Message* outputMessage;

	// 生成消息处理事件
	inputEvent = new Event();
	inputEvent->setMessage(inputMessage->getBody());

	// 控制器处理事件
	outputResult = _control->run(inputEvent);

	// 生成结果事件信息单元给输出端
	if (outputResult)
	{
		outputMessage = new Message();
		outputMessage->setBody(outputResult);
		getOutput()->push(outputMessage);
	}

	/*delete outputResult;*/

	delete inputMessage;
	delete inputEvent;
}
