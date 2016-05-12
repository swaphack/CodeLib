#include "TouchProtocol.h"
#include "TouchManager.h"

using namespace render;


TouchProtocol::TouchProtocol()
:_target(nullptr)
{

}

TouchProtocol::~TouchProtocol()
{

}

bool TouchProtocol::onTouchBegan(float x, float y)
{
	return false;
}

void TouchProtocol::onTouchMove(float x, float y)
{

}

void TouchProtocol::onTouchEnd(float x, float y)
{

}
