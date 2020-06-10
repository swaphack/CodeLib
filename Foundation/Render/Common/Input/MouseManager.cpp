#include "MouseManager.h"

render::MouseManager::MouseManager()
{
}

render::MouseManager::~MouseManager()
{
	this->removeAllMouseScrollDelegates();
	this->removeAllMouseScrollFuncs();
	this->removeAllMouseButtonDelegates();
	this->removeAllMouseButtonFuncs();
}

void render::MouseManager::addMouseScrollDelegate(sys::Object* target, Node* node, MOUSE_SCROLL_DELEGATE_HANDLER handler)
{
	if (node == nullptr || target == nullptr || handler == nullptr)
	{
		return;
	}

	_mouseScrollDelegates[target][node] = handler;
}

void render::MouseManager::removeMouseScrollDelegate(sys::Object* target, Node* node)
{
	if (target == nullptr || node == nullptr)
	{
		return;
	}

	auto it0 = _mouseScrollDelegates.find(target);
	if (it0 == _mouseScrollDelegates.end())
	{
		return;
	}

	auto it1 = it0->second.find(node);
	if (it1 == it0->second.end())
	{
		return;
	}
	it0->second.erase(it1);
}

void render::MouseManager::removeAllMouseScrollDelegates()
{
	_mouseScrollDelegates.clear();
}

void render::MouseManager::addMouseScrollFunc(sys::Object* target, Node* node, MouseScrollFunc func)
{
	if (target == nullptr || node == nullptr || func == nullptr)
	{
		return;
	}

	_mouseScrollFuncs[target][node] = func;
}

void render::MouseManager::removeMouseScrollFunc(sys::Object* target, Node* node)
{
	if (target == nullptr || node == nullptr)
	{
		return;
	}

	auto it0 = _mouseScrollFuncs.find(target);
	if (it0 == _mouseScrollFuncs.end())
	{
		return;
	}

	auto it1 = it0->second.find(node);
	if (it1 == it0->second.end())
	{
		return;
	}
	it0->second.erase(it1);
}

void render::MouseManager::removeAllMouseScrollFuncs()
{
	_mouseScrollFuncs.clear();
}

void render::MouseManager::onDispatchScrolleEvent(sys::ScrollEvent evt, float param)
{
	for (auto item0 : _mouseScrollDelegates)
	{
		for (auto item1 : item0.second)
		{
			((item0.first)->*(item1.second))(item1.first, evt, param);
		}
	}

	for (auto item0 : _mouseScrollFuncs)
	{
		for (auto item1 : item0.second)
		{
			item1.second(item1.first, evt, param);
		}
	}
}

void render::MouseManager::addMouseButtonDelegate(sys::Object* target, Node* node, MOUSE_BUTTON_DELEGATE_HANDLER handler)
{
	if (node == nullptr || target == nullptr || handler == nullptr)
	{
		return;
	}

	_mouseButtonDelegates[target][node] = handler;
}

void render::MouseManager::removeMouseButtonDelegate(sys::Object* target, Node* node)
{
	if (target == nullptr || node == nullptr)
	{
		return;
	}

	auto it0 = _mouseButtonDelegates.find(target);
	if (it0 == _mouseButtonDelegates.end())
	{
		return;
	}

	auto it1 = it0->second.find(node);
	if (it1 == it0->second.end())
	{
		return;
	}
	it0->second.erase(it1);
}

void render::MouseManager::removeAllMouseButtonDelegates()
{
	_mouseButtonDelegates.clear();
}

void render::MouseManager::addMouseButtonFunc(sys::Object* target, Node* node, MouseButtonFunc func)
{
	if (target == nullptr || node == nullptr || func == nullptr)
	{
		return;
	}

	_mouseButtonFuncs[target][node] = func;
}

void render::MouseManager::removeMouseButtonFunc(sys::Object* target, Node* node)
{
	if (target == nullptr || node == nullptr)
	{
		return;
	}

	auto it0 = _mouseButtonFuncs.find(target);
	if (it0 == _mouseButtonFuncs.end())
	{
		return;
	}

	auto it1 = it0->second.find(node);
	if (it1 == it0->second.end())
	{
		return;
	}
	it0->second.erase(it1);
}

void render::MouseManager::removeAllMouseButtonFuncs()
{
	_mouseButtonFuncs.clear();
}

void render::MouseManager::removeTargetAllEvents(sys::Object* target)
{
	auto it0 = _mouseScrollDelegates.find(target);
	if (it0 != _mouseScrollDelegates.end())
	{
		_mouseScrollDelegates.erase(it0);
	}

	auto it1 = _mouseScrollFuncs.find(target);
	if (it1 != _mouseScrollFuncs.end())
	{
		_mouseScrollFuncs.erase(it1);
	}

	auto it2 = _mouseButtonDelegates.find(target);
	if (it2 != _mouseButtonDelegates.end())
	{
		_mouseButtonDelegates.erase(it2);
	}

	auto it3 = _mouseButtonFuncs.find(target);
	if (it3 != _mouseButtonFuncs.end())
	{
		_mouseButtonFuncs.erase(it3);
	}
}

void render::MouseManager::onDispatchButtonEvent(sys::MouseKey key, sys::ButtonStatus status, float x, float y)
{
	for (auto item0 : _mouseButtonDelegates)
	{
		for (auto item1 : item0.second)
		{
			((item0.first)->*(item1.second))(item1.first, key, status, x, y);
		}
	}

	for (auto item0 : _mouseButtonFuncs)
	{
		for (auto item1 : item0.second)
		{
			item1.second(item1.first, key, status, x, y);
		}
	}
}
