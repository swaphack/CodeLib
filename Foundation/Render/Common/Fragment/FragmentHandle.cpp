#include "FragmentHandle.h"

render::FragmentHandle::FragmentHandle()
{

}

render::FragmentHandle::~FragmentHandle()
{

}

void render::FragmentHandle::setEnabled(bool enabled)
{
	_enabled = enabled;
}

bool render::FragmentHandle::isEnabled()
{
	return _enabled;
}

render::FragmentType render::FragmentHandle::getFragmentType()
{
	return _fragmentType;
}

void render::FragmentHandle::begin()
{

}

void render::FragmentHandle::update()
{

}

void render::FragmentHandle::end()
{

}
