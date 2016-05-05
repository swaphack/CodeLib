#pragma once

#include "Object.h"

#include <map>
#include <vector>

namespace sys
{
	// 容器接口
	class IContainer
	{
	public:
		virtual ~IContainer() {}
	public:
		virtual void addObject(Object* object) = 0;

		virtual void removeObject(Object* object) = 0;

		virtual void removeObject(long id) = 0;

		virtual Object* getObject(long id) = 0;

		virtual void clear() = 0; 

		virtual int count() = 0;
	};

	// 字典
	class Dictionary : public IContainer
	{
	public:
		Dictionary();
		virtual ~Dictionary();
	public:
		virtual void addObject(Object* object);

		virtual void removeObject(Object* object);

		virtual void removeObject(long id);

		virtual Object* getObject(long id);

		virtual void clear();

		virtual int count();

		std::map<long, Object*>::iterator begin();
		std::map<long, Object*>::iterator end();

	private:
		std::map<long, Object*> _objects;
	};

	// 数组
	class List : public IContainer
	{
	public:
		List();
		virtual ~List();
	public:
		virtual void addObject(Object* object);

		virtual void removeObject(Object* object);

		virtual void removeObject(long id);

		virtual Object* getObject(long id);

		virtual void clear();

		virtual int count();

		std::vector<Object*>::iterator begin();
		std::vector<Object*>::iterator end();
	private:
		std::vector<Object*> _objects;
	};
}