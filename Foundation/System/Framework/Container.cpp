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

	std::map<long, Object*>::iterator it = _objects.begin();

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

void Dictionary::removeObject( long id )
{
	if (_objects.find(id) == _objects.end())
	{
		return;
	}

	_objects[id]->release();

	_objects.erase(id);
}

Object* Dictionary::getObject( long id )
{
	if (_objects.find(id) == _objects.end())
	{
		return nullptr;
	}

	return _objects[id];
}

void Dictionary::clear()
{
	std::map<long, Object*>::iterator it = _objects.begin();

	while (it != _objects.end())
	{
		it->second->release();
		it++;
	}

	_objects.clear();
}

int Dictionary::count()
{
	return _objects.size();
}

std::map<long, Object*>::iterator Dictionary::begin()
{
	return _objects.begin();
}

std::map<long, Object*>::iterator Dictionary::end()
{
	return _objects.end();
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

void List::removeObject( long id )
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

Object* List::getObject( long id )
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

int List::count()
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
