#include "MultiModel.h"

render::MultiModel::MultiModel()
{

}

render::MultiModel::~MultiModel()
{

}

bool render::MultiModel::init()
{
	if (!MultiDrawNode::init())
	{
		return false;
	}

	return true;
}

