#include "macros.h"
#include "ext-config.h"

void ConvertToFMODVector(const math::Vector3& src, FMOD_VECTOR* dest)
{
	dest->x = src.getX();
	dest->y = src.getY();
	dest->z = src.getZ();
}

void ConvertToSysVector(const FMOD_VECTOR* src, math::Vector3& dest)
{
	dest.setX(src->x);
	dest.setY(src->y);
	dest.setZ(src->z);
}