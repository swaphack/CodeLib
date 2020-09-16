#include "ObjectDetail.h"

alg::ObjectDetail::ObjectDetail()
{

}

alg::ObjectDetail::~ObjectDetail()
{

}

void alg::ObjectDetail::setName(const std::string& name)
{
	_name = name;
}

const std::string& alg::ObjectDetail::getName() const
{
	return _name;
}

void alg::ObjectDetail::setTag(int tag)
{
	_tag = tag;
}

int alg::ObjectDetail::getTag() const
{
	return _tag;

}
