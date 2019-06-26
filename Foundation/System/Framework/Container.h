#pragma once

#include "Object.h"

#include <map>
#include <vector>
#include <cstdint>

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

		virtual void removeObject(uint64 id) = 0;

		virtual Object* getObject(uint64 id) = 0;

		virtual bool contains(Object* object) = 0;

		virtual bool contains(uint64 id) = 0;

		virtual void clear() = 0; 

		virtual int32 count() = 0;

		virtual bool empty() = 0;
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

		virtual void removeObject(uint64 id);

		virtual Object* getObject(uint64 id);

		virtual void clear();

		virtual int32 count();

		virtual bool empty();

		virtual bool contains(Object* object);

		virtual bool contains(uint64 id);

		std::map<uint64, Object*>::iterator begin();
		std::map<uint64, Object*>::iterator end();
	protected:
		struct Node
		{
			Object* value = nullptr;
			Node* parent = nullptr;
			Node* left = nullptr;
			Node* right = nullptr;
		};
	private:
		Node* _root;
		std::map<uint64, Object*> _objects;
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

		virtual void removeObject(uint64 id);

		virtual Object* getObject(uint64 id);

		virtual void clear();

		virtual int32 count();

		virtual bool empty();

		virtual bool contains(Object* object);

		virtual bool contains(uint64 id);

		std::vector<Object*>::iterator begin();
		std::vector<Object*>::iterator end();
	private:
		std::vector<Object*> _objects;
	};
}