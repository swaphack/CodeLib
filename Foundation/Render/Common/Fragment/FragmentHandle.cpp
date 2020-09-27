#include "FragmentHandle.h"
#include "Graphic/import.h"
render::FragmentHandle::FragmentHandle(FragmentType type, EnableMode mode)
	:_fragmentType(type), _enableMode(mode)
{
}

render::FragmentHandle::FragmentHandle(FragmentType type)
	: _fragmentType(type)
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

void render::FragmentHandle::setEnableMode(EnableMode mode)
{
	_enableMode = mode;
}

EnableMode render::FragmentHandle::getEnableMode()
{
	return _enableMode;
}

void render::FragmentHandle::updateFragmentHand()
{
	if (_enabled)
	{
		GLState::enable(_enableMode);
	}
	else
	{
		GLState::disable(_enableMode);
	}
	if (_enabled)
	{
		this->update();
	}
}

void render::FragmentHandle::begin()
{
	if (_enableMode != EnableMode::NONE)
	{
		GLState::getInteger((uint32_t)_enableMode, &_lastEnableModeStatus);
	}
	this->saveData();
}

void render::FragmentHandle::update()
{
	
}

void render::FragmentHandle::end()
{
	if (_enableMode != EnableMode::NONE)
	{
		bool lastEnabled = _lastEnableModeStatus == 1;
		if (lastEnabled)
		{
			GLState::enable(_enableMode);
		}
		else
		{
			GLState::disable(_enableMode);
		}
	}
	
	this->reloadData();
}

void render::FragmentHandle::saveData()
{
}

void render::FragmentHandle::reloadData()
{
}
