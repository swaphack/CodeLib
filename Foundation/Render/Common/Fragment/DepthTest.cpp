#include "DepthTest.h"
#include "Graphic/import.h"

render::DepthTest::DepthTest()
{
	_func = DepthFunction::LESS;
}

render::DepthTest::~DepthTest()
{

}

void render::DepthTest::setFunc(DepthFunction func)
{
	_func = func;
}

void render::DepthTest::startTest()
{
	GLState::enable(EnableModel::DEPTH_TEST);
}

void render::DepthTest::test()
{
	GLState::setDepthFunc(_func);
}

void render::DepthTest::endTest()
{
	GLState::disable(EnableModel::DEPTH_TEST);
}
