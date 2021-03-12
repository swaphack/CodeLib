#include "Model.h"


using namespace render;


Model::Model()
{
}

Model::~Model()
{
}

bool render::Model::init()
{
	if (!DrawNode3D::init())
	{
		return false;
	}
	return true;
}

