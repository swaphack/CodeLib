#include "DrawCommandList.h"

using namespace render;

DrawCommandList::DrawCommandList()
{

}

DrawCommandList::~DrawCommandList()
{
	this->removeAllCommands();
}

void DrawCommandList::appendCommand(DrawCommand* pCommand)
{
	if (pCommand == nullptr)
	{
		return;
	}

	_commands.push_back(pCommand);
}

void DrawCommandList::draw()
{
	std::vector<DrawCommand*>::iterator iter = _commands.begin();

	while (iter != _commands.end())
	{
		(*iter)->draw();
		iter++;
	}

	_commands.clear();
}

void DrawCommandList::removeAllCommands()
{
	std::vector<DrawCommand*>::iterator iter = _commands.begin();

	while (iter != _commands.end())
	{
		SAFE_RELEASE(*iter);
		iter++;
	}
	_commands.clear();
}
