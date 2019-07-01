#pragma once

#include <map>
#include <cstdint>
#include <functional>

#include "../base/Dictionary.h"

namespace game
{
	/**
	*	创造者
	*/
	template<typename T>
	class Creator : public Dictionary<uint64_t, T*>
	{
	protected:

	public:
		typedef std::function<void(const T* t)> CallFunc;
	public:
		Creator();
		virtual ~Creator();
	public:
		// 生成一个单位
		T* generate();
		// 销毁一个单位
		bool purge(T* t);
		// 遍历
		void foreach(const CallFunc& func);
	protected:
		virtual void destoryValue(T* value);
	private:
		uint64_t _id = 0;
	};

	template<typename T>
	void Creator<T>::destoryValue(T* value)
	{
		if (value)
		{
			delete value;
			value = nullptr;
		}
	}

	template<typename T>
	void Creator<T>::foreach(const CallFunc& func)
	{
		if (func == nullptr)
		{
			return;
		}
		this->foreach([](const T* &pID){
			func(pID);
		});
	}

	template<typename T>
	bool Creator<T>::purge(T* t)
	{
		if (t == nullptr)
		{
			return false; 
		}

		T** value = find(t->getID());
		if ((value != nullptr) && (*value != nullptr))
		{
			this->remove(t->getID());
			return true;
		}
		return false;
	}

	template<typename T>
	T* Creator<T>::generate()
	{
		T* t = new T();
		t->setID(++_id);
		this->add(t->getID(), t);
		return t;
	}

	template<typename T>
	Creator<T>::Creator()
		:_id(0)
	{

	}

	template<typename T>
	Creator<T>::~Creator()
	{

	}
}