#include "KeyboardManager.h"

using namespace render;


KeyboardManager::KeyboardManager()
{

}

KeyboardManager::~KeyboardManager()
{
	this->removeAllDispatchers();
}

void KeyboardManager::addDispatcher(sys::Object* node, sys::Object* target, KEYBOARD_DELEGATE_HANDLER handler)
{
	if (node == nullptr || handler == nullptr)
	{
		return;
	}

	this->removeDispatcher(node);

	_keyboardDispatchers.push_back(sys::make_tuple3(target, handler, node));
}

void KeyboardManager::removeDispatcher(sys::Object* node)
{
	if (node == nullptr)
	{
		return;
	}

	std::vector<KeyBoardDelegate>::iterator iter = _keyboardDispatchers.begin();

	while (iter != _keyboardDispatchers.end())
	{
		if ((*iter).t3 == node)
		{
			_keyboardDispatchers.erase(iter);
			break;
		}

		iter++;
	}
}

void KeyboardManager::removeAllDispatchers()
{
	_keyboardDispatchers.clear();
}

void KeyboardManager::onDispatcher(sys::BoardKey key, sys::ButtonStatus type)
{
	std::vector<KeyBoardDelegate>::iterator iter = _keyboardDispatchers.begin();

	while (iter != _keyboardDispatchers.end())
	{
		((*iter).t1->*(*iter).t2)((*iter).t3, key, type);
		iter++;
	}
}
