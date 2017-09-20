#include "macros.h"

void ConvertToFMODVector(const sys::Vector3& src, FMOD_VECTOR& dest)
{
	dest.x = src.x;
	dest.y = src.y;
	dest.z = src.z;
}

void ConvertToSysVector(const FMOD_VECTOR& src, sys::Vector3& dest)
{
	dest.x = src.x;
	dest.y = src.y;
	dest.z = src.z;
}