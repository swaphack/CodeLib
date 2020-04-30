#include "DrawCommander.h"
#include "DrawCommand.h"
using namespace render;


DrawCommander::DrawCommander()
{

}

DrawCommander::~DrawCommander()
{
	removeAllCommands();
}

void DrawCommander::addCommand(DrawCommand* pCommand)
{
	if (pCommand == nullptr)
	{
		return;
	}

	SAFE_RETAIN(pCommand);
	
	_commands.push_back(pCommand);
}

void DrawCommander::flush()
{
	std::vector<DrawCommand*>::iterator iter = _commands.begin();

	while (iter != _commands.end())
	{
		(*iter)->draw();
		iter++;
	}
}

void render::DrawCommander::removeAllCommands()
{
	std::vector<DrawCommand*>::iterator iter = _commands.begin();

	while (iter != _commands.end())
	{
		SAFE_RELEASE(*iter);
		iter++;
	}
	_commands.clear();
}
