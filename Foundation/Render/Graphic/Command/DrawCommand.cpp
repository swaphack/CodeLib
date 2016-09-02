#include "DrawCommand.h"

using namespace render;

DrawCommand::DrawCommand()
:_id(0)
{

}

DrawCommand::~DrawCommand()
{

}

int DrawCommand::getID()
{
	return _id;
}

void DrawCommand::setID(int id)
{
	_id = id;
}