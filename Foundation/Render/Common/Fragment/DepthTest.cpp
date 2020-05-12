#include "DepthTest.h"
#include "Graphic/import.h"

void render::DepthTest::setFunc(DepthFunction func)
{
	GLState::setDepthFunc(func);
}
