#include "FragmentLogicOp.h"
#include "Graphic/import.h"
render::FragmentLogicOp::FragmentLogicOp()
{
}

render::FragmentLogicOp::~FragmentLogicOp()
{
}

void render::FragmentLogicOp::setOpCode(LogicOpCode code)
{
	_opCode = code;
}

void render::FragmentLogicOp::begin()
{
	GLState::enable(EnableModel::COLOR_LOGIC_OP);
}

void render::FragmentLogicOp::update()
{
	GLState::setLogicOp(_opCode);
}

void render::FragmentLogicOp::end()
{
	GLState::disable(EnableModel::COLOR_LOGIC_OP);
}
