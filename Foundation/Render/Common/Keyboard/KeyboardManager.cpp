#include "KeyboardManager.h"

using namespace render;


KeyboardManager::KeyboardManager()
{

}

KeyboardManager::~KeyboardManager()
{
	this->removeAllKeyboardDelegates();
}

void KeyboardManager::addKeyboardDelegate(sys::Object* target, Node* node, KEYBOARD_DELEGATE_HANDLER handler)
{
	if (node == nullptr || target == nullptr || handler == nullptr)
	{
		return;
	}

	KeyboardDelegate item;
	item.first = node;
	item.second = handler;

	_keyboardDelegates[target] = item;
}

void KeyboardManager::removeKeyboardDelegate(sys::Object* target)
{
	if (target == nullptr)
	{
		return;
	}

	auto it = _keyboardDelegates.find(target);
	if (it == _keyboardDelegates.end())
	{
		return;
	}

	_keyboardDelegates.erase(it);
}

void KeyboardManager::removeAllKeyboardDelegates()
{
	_keyboardDelegates.clear();
}

void render::KeyboardManager::addKeyboardFunc(Node* node, KeyboardFunc func)
{
	if (node == nullptr || func == nullptr)
	{
		return;
	}

	_keyboardFuncs[node] = func;
}

void render::KeyboardManager::removeKeyboardFunc(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	auto it = _keyboardFuncs.find(node);
	if (it == _keyboardFuncs.end())
	{
		return;
	}

	_keyboardFuncs.erase(it);
}

void render::KeyboardManager::removeAllKeyboardFuncs()
{
	_keyboardFuncs.clear();
}

void KeyboardManager::onDispatcher(sys::BoardKey key, sys::ButtonStatus type)
{
	for (auto item : _keyboardDelegates)
	{
		auto func = item.second.second;
		(item.first->*func)(item.second.first, key, type);
	}

	for (auto item : _keyboardFuncs)
	{
		item.second(item.first, key, type);
	}
}
