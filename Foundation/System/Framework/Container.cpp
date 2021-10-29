#include "Container.h"
#include "Object.h"

using namespace sys;


Dictionary::Dictionary()
{

}

Dictionary::~Dictionary()
{
	this->clear();
}

void Dictionary::addObject( Object* object )
{
	if (object == nullptr)
	{
		return;
	}
	SAFE_RETAIN(object);

	this->removeObject(object->getID());	
	
	_objects[object->getID()] = object;
}

void Dictionary::removeObject(Object* object)
{
	if (object == nullptr)
	{
		return;
	}

	auto it = _objects.begin();

	while (it != _objects.end())
	{
		if (it->second == object)
		{
			SAFE_RELEASE(it->second);
			_objects.erase(it);
			break;
		}
		it++;
	}
}

void Dictionary::removeObject(uint64_t id)
{
	auto it = _objects.find(id);
	if (it == _objects.end())
	{
		return;
	}
	SAFE_RELEASE(it->second);

	_objects.erase(id);
}

Object* Dictionary::getObject(uint64_t id)
{
	if (_objects.find(id) == _objects.end())
	{
		return nullptr;
	}

	return _objects[id];
}

void Dictionary::clear()
{
	for (auto item : _objects)
	{
		SAFE_RELEASE(item.second);
	}

	_objects.clear();
}

int32_t Dictionary::count()
{
	return _objects.size();
}

std::map<uint64_t, Object*>::iterator Dictionary::begin()
{
	return _objects.begin();
}

std::map<uint64_t, Object*>::iterator Dictionary::end()
{
	return _objects.end();
}

bool Dictionary::contains(Object* object)
{
	if (object == nullptr)
	{
		return false;
	}

	return getObject(object->getID()) != nullptr;
}

bool Dictionary::contains(uint64_t id)
{
	return getObject(id) != nullptr;
}

bool Dictionary::empty()
{
	return count() == 0;
}



//////////////////////////////////////////////////////////////////////////

List::List()
{

}

List::~List()
{
	this->clear();
}

void List::addObject( Object* object )
{
	if (object == nullptr)
	{
		return;
	}
	SAFE_RETAIN(object);

	_objects.push_back(object);
}

void List::removeObject(Object* object)
{
	if (object == nullptr)
	{
		return;
	}

	auto it = _objects.begin();

	while (it != _objects.end())
	{
		if (object == (*it))
		{
			SAFE_RELEASE(object);
			_objects.erase(it);
			break;
		}
		it++;
	}
}

void List::removeObject(uint64_t id)
{
	auto it = _objects.begin();

	while (it != _objects.end())
	{
		Object* object = (*it);
		if (object->getID() == id)
		{
			SAFE_RELEASE(object);

			_objects.erase(it);
			break;
		}
		it++;
	}
}

Object* List::getObject(uint64_t id)
{
	std::vector<Object*>::iterator it = _objects.begin();

	while (it != _objects.end())
	{
		Object* object = (*it);
		if (object->getID() == id)
		{
			return object;
		}
		it++;
	}

	return nullptr;
}

void List::clear()
{
	for (auto item : _objects)
	{
		SAFE_RELEASE(item);
	}

	_objects.clear();
}

int32_t List::count()
{
	return _objects.size();
}

std::vector<Object*>::iterator List::begin()
{
	return _objects.begin();
}

std::vector<Object*>::iterator List::end()
{
	return _objects.end();
}

bool List::contains(Object* object)
{
	if (object == nullptr)
	{
		return false;
	}

	return contains(object->getID());
}

bool List::contains(uint64_t id)
{
	return getObject(id) != nullptr;
}

bool List::empty()
{
	return count() == 0;
}
