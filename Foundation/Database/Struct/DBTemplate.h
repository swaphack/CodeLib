#pragma once

#include <map>
#include <string>

namespace db
{
	template<typename T>
	class DBTemplate
	{
	public:
		DBTemplate();
		virtual ~DBTemplate();
	public:
		void add(std::string name, T t);
		void remove(std::string name);
		T find(std::string name);
		void clear();
	private:
		std::map<std::string, T> _items;
	};

	template<typename T>
	DBTemplate<T>::DBTemplate()
	{

	}

	template<typename T>
	DBTemplate<T>::~DBTemplate()
	{
		this->clear();
	}

	template<typename T>
	void DBTemplate<T>::add( std::string name, T t )
	{
		if (t == nullptr)
		{
			return;
		}

		std::map<std::string, T>::iterator iter = _items.find(name);
		if (iter != _items.end())
		{
			delete iter->second;
		}

		_items[name] = t;
	}

	template<typename T>
	void DBTemplate<T>::remove( std::string name )
	{
		std::map<std::string, T>::iterator iter = _items.find(name);
		if (iter != _items.end())
		{
			delete iter->second;
		}
	}

	template<typename T>
	T DBTemplate<T>::find( std::string name )
	{
		std::map<std::string, T>::iterator iter = _items.find(name);
		if (iter != _items.end())
		{
			return iter->second;
		}

		return nullptr;
	}

	template<typename T>
	void DBTemplate<T>::clear()
	{
		std::map<std::string, T>::iterator iter = _items.begin();
		while (iter != _items.end())
		{
			delete iter->second;

			iter++;
		}

		_items.clear();
	}
}