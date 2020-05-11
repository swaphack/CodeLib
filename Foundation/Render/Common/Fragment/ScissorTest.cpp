#include "ScissorTest.h"

#include "Graphic/import.h"

void render::ScissorTest::enable()
{
	GLState::enable(EnableModel::SCISSOR_TEST);
}

void render::ScissorTest::disable()
{
	GLState::disable(EnableModel::SCISSOR_TEST);
}

bool render::ScissorTest::isEnabled()
{
	return GLState::isEnabled(EnableModel::SCISSOR_TEST);
}

void render::ScissorTest::setBox(int x, int y, int width, int height)
{
	GLState::setScissor(x, y, width, height);
}
