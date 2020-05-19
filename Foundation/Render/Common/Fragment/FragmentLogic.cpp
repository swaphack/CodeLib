#include "FragmentLogic.h"
#include "Graphic/import.h"
render::FragmentLogic::FragmentLogic()
	:FragmentHandle(FragmentType::LOGIC, EnableMode::COLOR_LOGIC_OP)
{
}

render::FragmentLogic::~FragmentLogic()
{
}

void render::FragmentLogic::setOpCode(LogicOpCode code)
{
	_opCode = code;
}

void render::FragmentLogic::update()
{
	GLState::setLogicOp(_opCode);
}

void render::FragmentLogic::saveData()
{
	int code;
	GLState::getInteger(GetTarget::LOGIC_OP_MODE, &code);
	_lastOpCode = (LogicOpCode)code;
}

void render::FragmentLogic::reloadData()
{
	GLState::setLogicOp(_lastOpCode);
}
