#pragma once

#include <map>

namespace game
{
	template<typename T>
	class ISet
	{
	public:
		ISet();
		virtual ~ISet();
	public:
		T* generate();
		bool purge(T* t);
		T* find(int nID);
		void clear();
	private:
		typedef std::map<int, T*> Items;
		Items _items;
		int _id;
	};

	template<typename T>
	void ISet<T>::clear()
	{
		Items::iterator iter = _items.begin();
		while (iter != _items.end())
		{
			delete iter->second;
			iter++;
		}
		_items.clear();
	}

	template<typename T>
	T* ISet<T>::find(int nID)
	{
		Items::iterator iter = _items.find(nID);
		if (iter != _items.end())
		{
			return iter->second;
		}

		return nullptr;
	}

	template<typename T>
	bool ISet<T>::purge(T* t)
	{
		if (t == nullptr)
		{
			return false; 
		}

		Items::iterator iter = _items.find(t->getID());
		if (iter != _items.end())
		{
			delete iter->second;
			_items.erase(iter);
			return true;
		}

		return false;
	}

	template<typename T>
	T* ISet<T>::generate()
	{
		T* t = new T();
		t->setID(++_id);
		return t;
	}

	template<typename T>
	ISet<T>::~ISet()
	{
		this->clear();
	}

	template<typename T>
	ISet<T>::ISet()
		:_id(0)
	{

	}

}