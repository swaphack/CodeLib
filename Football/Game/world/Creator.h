#pragma once

#include <map>
#include <cstdint>
#include <functional>

#include "../base/IdentityContainer.h"

namespace game
{
	/**
	*	������
	*/
	template<typename T>
	class Creator : public IdentityContainer
	{
	public:
		typedef std::function<void(const T* t)> CallFunc;
	public:
		Creator();
		virtual ~Creator();
	public:
		// ����һ����λ
		T* generate();
		// ����һ����λ
		bool purge(T* t);

		void foreach(CallFunc func);
	private:
		uint64_t _id = 0;
	};

	template<typename T>
	void Creator<T>::foreach(CallFunc func)
	{
		if (func == nullptr)
		{
			return;
		}
		this->foreach([](Identity* pID){
			func(static_cast<T*>(pID));
		});
	}

	template<typename T>
	bool Creator<T>::purge(T* t)
	{
		if (t == nullptr)
		{
			return false; 
		}

		this->remove(t->getID());

		return false;
	}

	template<typename T>
	T* Creator<T>::generate()
	{
		T* t = new T();
		t->setID(++_id);
		this->add(t);
		return t;
	}

	template<typename T>
	Creator<T>::Creator()
		:_id(0)
	{

	}
}