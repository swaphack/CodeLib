#include "Container.h"

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

	this->removeObject(object->getID());

	object->retain();
	
	_objects[object->getID()] = object;
}

void Dictionary::removeObject(Object* object)
{
	if (object == nullptr)
	{
		return;
	}

	std::map<uint64, Object*>::iterator it = _objects.begin();

	while (it != _objects.end())
	{
		if (it->second == object)
		{
			it->second->release();
			_objects.erase(it);
			break;
		}
		it++;
	}
}

void Dictionary::removeObject(uint64 id)
{
	if (_objects.find(id) == _objects.end())
	{
		return;
	}

	_objects[id]->release();

	_objects.erase(id);
}

Object* Dictionary::getObject(uint64 id)
{
	if (_objects.find(id) == _objects.end())
	{
		return nullptr;
	}

	return _objects[id];
}

void Dictionary::clear()
{
	std::map<uint64, Object*>::iterator it = _objects.begin();

	while (it != _objects.end())
	{
		it->second->release();
		it++;
	}

	_objects.clear();
}

int32 Dictionary::count()
{
	return _objects.size();
}

std::map<uint64, Object*>::iterator Dictionary::begin()
{
	return _objects.begin();
}

std::map<uint64, Object*>::iterator Dictionary::end()
{
	return _objects.end();
}

bool Dictionary::contains(Object* object)
{
	if (object == nullptr)
	{
		return false;
	}

	return getObject(object->getID());
}

bool Dictionary::contains(uint64 id)
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

	object->retain();

	_objects.push_back(object);
}

void List::removeObject(Object* object)
{
	if (object == nullptr)
	{
		return;
	}

	std::vector<Object*>::iterator it = _objects.begin();

	while (it != _objects.end())
	{
		if (object == (*it))
		{
			object->release();
			_objects.erase(it);
			break;
		}
		it++;
	}
}

void List::removeObject(uint64 id)
{
	std::vector<Object*>::iterator it = _objects.begin();

	while (it != _objects.end())
	{
		Object* object = (*it);
		if (object->getID() == id)
		{
			object->release();

			_objects.erase(it);
			break;
		}
		it++;
	}
}

Object* List::getObject(uint64 id)
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
	std::vector<Object*>::iterator it = _objects.begin();

	while (it != _objects.end())
	{
		(*it)->release();
		it++;
	}

	_objects.clear();
}

int32 List::count()
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

bool List::contains(uint64 id)
{
	return getObject(id) != nullptr;
}

bool List::empty()
{
	return count() == 0;
}
