#include "Body.h"

using namespace game;


Body::Body()
{

}

Body::~Body()
{

}

bool Body::intersectBody(IBody* pBody)
{
	// 后面补充
	return false;
}

Vector Body::getPosition()
{
	Vector vect;
	vect.X = getPositionX();
	vect.Y = getPositionY();
	vect.Z = getPositionZ();
	return vect;
}

void Body::lookAt(const Vector& point)
{
	// 后面补充
}
