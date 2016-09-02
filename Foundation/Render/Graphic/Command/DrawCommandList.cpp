#include "DrawCommandList.h"

using namespace render;

DrawCommandList::DrawCommandList()
{

}

DrawCommandList::~DrawCommandList()
{

}

void DrawCommandList::appendCommand(DrawCommand* pCommand)
{
	if (pCommand == nullptr)
	{
		return;
	}

	_commandList.push_back(pCommand);
}

void DrawCommandList::draw()
{
	std::vector<DrawCommand*>::iterator iter = _commandList.begin();

	while (iter != _commandList.end())
	{
		(*iter)->draw();
		iter++;
	}

	_commandList.clear();
}
