#include "KeyboardManager.h"

using namespace render;


KeyboardManager::KeyboardManager()
{

}

KeyboardManager::~KeyboardManager()
{
	this->removeAllDispatchers();
}

void KeyboardManager::addDispatcher(sys::Object* node, KEYBOARD_DELEGATE_HANDLER handler)
{
	if (node == nullptr || handler == nullptr)
	{
		return;
	}

	this->removeDispatcher(node);

	KeyBoardDelegate* del = new KeyBoardDelegate();
	del->target = node;
	del->handler = handler;

	_keyboardDispatchers.push_back(del);
}

void KeyboardManager::removeDispatcher(sys::Object* node)
{
	if (node == nullptr)
	{
		return;
	}

	std::vector<KeyBoardDelegate*>::iterator iter = _keyboardDispatchers.begin();

	while (iter != _keyboardDispatchers.end())
	{
		if ((*iter)->target == node)
		{
			delete (*iter);
			_keyboardDispatchers.erase(iter);
			break;
		}

		iter++;
	}
}

void KeyboardManager::removeAllDispatchers()
{
	std::vector<KeyBoardDelegate*>::iterator iter = _keyboardDispatchers.begin();

	while (iter != _keyboardDispatchers.end())
	{
		delete (*iter);
		iter++;
	}

	_keyboardDispatchers.clear();
}

void KeyboardManager::onDispatcher(sys::BoardKey key, sys::ButtonStatus type)
{
	std::vector<KeyBoardDelegate*>::iterator iter = _keyboardDispatchers.begin();

	while (iter != _keyboardDispatchers.end())
	{
		(*iter)->hand(key, type);
		iter++;
	}
}
