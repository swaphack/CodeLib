#include "FragmentScissorTest.h"

#include "Graphic/import.h"

render::FragmentScissorTest::FragmentScissorTest()
{

}

render::FragmentScissorTest::~FragmentScissorTest()
{

}

void render::FragmentScissorTest::setRect(int x, int y, int width, int height)
{
	_rect.setOrigin(x, y);
	_rect.setSize(width, height);
}

void render::FragmentScissorTest::begin()
{
	GLState::enable(EnableModel::SCISSOR_TEST);
}

void render::FragmentScissorTest::update()
{
	GLState::setScissor(_rect.getX(), _rect.getY(), _rect.getWidth(), _rect.getHeight());
}

void render::FragmentScissorTest::end()
{

	GLState::disable(EnableModel::SCISSOR_TEST);
}
