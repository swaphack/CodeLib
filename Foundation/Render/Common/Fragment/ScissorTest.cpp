#include "ScissorTest.h"

#include "Graphic/import.h"

render::ScissorTest::ScissorTest()
{

}

render::ScissorTest::~ScissorTest()
{

}

void render::ScissorTest::setRect(int x, int y, int width, int height)
{
	_rect.setOrigin(x, y);
	_rect.setSize(width, height);
}

void render::ScissorTest::startTest()
{
	GLState::enable(EnableModel::SCISSOR_TEST);
}

void render::ScissorTest::test()
{
	GLState::setScissor(_rect.getX(), _rect.getY(), _rect.getWidth(), _rect.getHeight());
}

void render::ScissorTest::endTest()
{

	GLState::disable(EnableModel::SCISSOR_TEST);
}
