#include "DrawCommander.h"
#include "DrawCommand.h"

using namespace render;


DrawCommander::DrawCommander()
{

}

DrawCommander::~DrawCommander()
{

}

void DrawCommander::addCommand(DrawCommand* pCommand)
{
	if (pCommand == nullptr)
	{
		return;
	}

	_commands.push_back(pCommand);
}

void DrawCommander::flushAllCommands()
{
	std::vector<DrawCommand*>::iterator iter = _commands.begin();

	while (iter != _commands.end())
	{
		(*iter)->draw();
		iter++;
	}

	_commands.clear();
}
