#include "FragmentScissorTest.h"

#include "Graphic/import.h"

render::FragmentScissorTest::FragmentScissorTest()
	:FragmentHandle(FragmentType::SCISSOR_TEST, EnableMode::SCISSOR_TEST)
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

void render::FragmentScissorTest::update()
{
	GLState::setScissor(_rect.getX(), _rect.getY(), _rect.getWidth(), _rect.getHeight());
}

void render::FragmentScissorTest::saveData()
{
	float value[4] = { 0 };
	GLState::getFloat(GetTarget::SCISSOR_BOX, value);
	_lastRect.setOrigin(value[0], value[1]);
	_lastRect.setSize(value[2], value[3]);
}

void render::FragmentScissorTest::reloadData()
{
	GLState::setScissor(_lastRect.getX(), _lastRect.getY(), _lastRect.getWidth(), _lastRect.getHeight());
}
