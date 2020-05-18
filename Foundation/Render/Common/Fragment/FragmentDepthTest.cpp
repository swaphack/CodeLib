#include "FragmentDepthTest.h"
#include "Graphic/import.h"

render::FragmentDepthTest::FragmentDepthTest()
{
	_fragmentType = FragmentType::DEPTH_TEST;
	_func = DepthFunction::LESS;
}

render::FragmentDepthTest::~FragmentDepthTest()
{

}

void render::FragmentDepthTest::setFunc(DepthFunction func)
{
	_func = func;
}

void render::FragmentDepthTest::begin()
{
	GLState::enable(EnableModel::DEPTH_TEST);
}

void render::FragmentDepthTest::update()
{
	GLState::setDepthFunc(_func);
}

void render::FragmentDepthTest::end()
{
	GLState::disable(EnableModel::DEPTH_TEST);
}
