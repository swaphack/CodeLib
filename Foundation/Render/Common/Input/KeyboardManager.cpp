#include "KeyboardManager.h"

using namespace render;


KeyboardManager::KeyboardManager()
{

}

KeyboardManager::~KeyboardManager()
{
	this->removeAllKeyboardDelegates();
	this->removeAllKeyboardFuncs();
}

void KeyboardManager::addKeyboardDelegate(sys::Object* target, Node* node, KEYBOARD_DELEGATE_HANDLER handler)
{
	if (node == nullptr || target == nullptr || handler == nullptr)
	{
		return;
	}

	_keyboardDelegates[target][node] = handler;
}

void KeyboardManager::removeKeyboardDelegate(sys::Object* target, Node* node)
{
	if (target == nullptr || node == nullptr)
	{
		return;
	}

	auto it0 = _keyboardDelegates.find(target);
	if (it0 == _keyboardDelegates.end())
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

void KeyboardManager::removeAllKeyboardDelegates()
{
	_keyboardDelegates.clear();
}

void render::KeyboardManager::addKeyboardFunc(sys::Object* target, Node* node, KeyboardFunc func)
{
	if (target == nullptr || node == nullptr || func == nullptr)
	{
		return;
	}

	_keyboardFuncs[target][node] = func;
}

void render::KeyboardManager::removeKeyboardFunc(sys::Object* target, Node* node)
{
	if (target == nullptr || node == nullptr)
	{
		return;
	}

	auto it0 = _keyboardFuncs.find(target);
	if (it0 == _keyboardFuncs.end())
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

void render::KeyboardManager::removeAllKeyboardFuncs()
{
	_keyboardFuncs.clear();
}

void render::KeyboardManager::removeTargetAllEvents(sys::Object* target)
{
	if (target == nullptr)
	{
		return;
	}

	auto it0 = _keyboardFuncs.find(target);
	if (it0 != _keyboardFuncs.end())
	{
		_keyboardFuncs.erase(it0);
	}

	auto it1 = _keyboardDelegates.find(target);
	if (it1 != _keyboardDelegates.end())
	{
		_keyboardDelegates.erase(it1);
	}
}

void KeyboardManager::onDispatchButtonEvent(sys::BoardKey key, sys::ButtonStatus type)
{
	for (auto item0 : _keyboardDelegates)
	{
		for (auto item1 : item0.second)
		{
			((item0.first)->*(item1.second))(item1.first, key, type);
		}
	}

	for (auto item0 : _keyboardFuncs)
	{
		for (auto item1 : item0.second)
		{
			item1.second(item1.first, key, type);
		}
	}
}
