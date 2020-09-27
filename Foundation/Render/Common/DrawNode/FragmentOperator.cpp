#include "FragmentOperator.h"

render::FragmentOperator::FragmentOperator()
{
}

render::FragmentOperator::~FragmentOperator()
{
	this->removeAllHandles();
}

void render::FragmentOperator::removeHandle(FragmentType fragType)
{
	auto it = _handles.find(fragType);
	if (it != _handles.end())
	{
		SAFE_RELEASE(it->second);
		_handles.erase(it);
	}
}

void render::FragmentOperator::addHandle(FragmentHandle* handle)
{
	if (handle == nullptr)
	{
		return;
	}
	auto type = handle->getFragmentType();
	SAFE_RETAIN(handle);
	_handles[type] = handle;
}

void render::FragmentOperator::removeAllHandles()
{
	for (auto item : _handles)
	{
		SAFE_RELEASE(item.second);
	}
	_handles.clear();
}

void render::FragmentOperator::begin()
{
	for (auto item : _handles)
	{
		item.second->begin();
	}
}

void render::FragmentOperator::update()
{
	for (auto item : _handles)
	{
		item.second->updateFragmentHand();
	}
}

void render::FragmentOperator::end()
{
	for (auto item : _handles)
	{
		item.second->end();
	}
}
