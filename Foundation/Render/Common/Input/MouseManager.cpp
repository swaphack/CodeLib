#include "MouseManager.h"

render::MouseManager::MouseManager()
{
}

render::MouseManager::~MouseManager()
{
	this->removeAllMouseScrollDelegates();
	this->removeAllMouseScrollFuncs();
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

void render::MouseManager::onDispatcher(sys::ScrollEvent evt, float param)
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
