#include "FragmentDepthTest.h"
#include "Graphic/import.h"

render::FragmentDepthTest::FragmentDepthTest()
	:FragmentHandle(FragmentType::DEPTH_TEST, EnableMode::DEPTH_TEST)
{
}

render::FragmentDepthTest::~FragmentDepthTest()
{

}

void render::FragmentDepthTest::setFunc(DepthFunction func)
{
	_func = func;
}

void render::FragmentDepthTest::update()
{
	GLState::setDepthFunc(_func);
}

void render::FragmentDepthTest::saveData()
{
	int func;
	GLState::getInteger(GetTarget::DEPTH_FUNC, &func);
	_lastFunc = (DepthFunction)func;
}

void render::FragmentDepthTest::reloadData()
{
	GLState::setDepthFunc(_lastFunc);
}
