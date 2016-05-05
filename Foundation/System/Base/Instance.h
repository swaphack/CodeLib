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
	T* Instance<T>::_staticT = 0;

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
		if (_staticT == 0)
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
			_staticT = 0;
		}
	}
}