#pragma once

namespace sys
{
	template<class T>
	class Instance
	{
	private:
		Instance();
		~Instance();
	public:
		static T* getInstance();
		static void purge();
	protected:
	private:
		static T* _staticT;
	};

	template<class T>
	T* Instance<T>::_staticT = nullptr;

	template<class T>
	Instance<T>::Instance()
	{

	}

	template<class T>
	Instance<T>::~Instance()
	{

	}

	template<class T>
	T* Instance<T>::getInstance()
	{
		if (_staticT == nullptr)
		{
			_staticT = new T();
		}

		return _staticT;
	}

	template<class T>
	void Instance<T>::purge()
	{
		if (_staticT)
		{
			delete _staticT;
			_staticT = nullptr;
		}
	}
}