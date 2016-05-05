#pragma once

#include <map>

namespace user
{

#define DATABASE_DEFINE(Name, CLS) \
	class Name##s \
	{ \
	public: \
	void add##Name(long id, CLS* item)\
	{ \
		if (item == nullptr) \
		{ \
			return; \
		} \
		_items[id] = item; \
	} \
	\
	void remove##Name(long id) \
	{ \
		_items.erase(id); \
	} \
	\
	CLS* get##Name(long id) \
	{ \
		std::map<long, CLS*>::iterator it = _items.find(id); \
		if (it != _items.end()) \
		{ \
			return it->second; \
		} \
		return nullptr; \
	} \
	long count() \
	{ \
		return _items.size(); \
	} \
	private: \
	std::map<long, CLS*> _items; \
	}; \

}