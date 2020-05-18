#include "FragmentLogic.h"
#include "Graphic/import.h"
render::FragmentLogic::FragmentLogic()
{
	_fragmentType = FragmentType::LOGIC;
}

render::FragmentLogic::~FragmentLogic()
{
}

void render::FragmentLogic::setOpCode(LogicOpCode code)
{
	_opCode = code;
}

void render::FragmentLogic::begin()
{
	GLState::enable(EnableModel::COLOR_LOGIC_OP);
}

void render::FragmentLogic::update()
{
	GLState::setLogicOp(_opCode);
}

void render::FragmentLogic::end()
{
	GLState::disable(EnableModel::COLOR_LOGIC_OP);
}
