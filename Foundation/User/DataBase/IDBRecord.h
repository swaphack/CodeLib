#pragma once

namespace user
{
	
	class IDBRecord
	{
	public:
		virtual long getID() = 0;

		template<typename T>
		T* getStatic();
	};

	template<typename T>
	T* IDBRecord::getStatic()
	{
		return dynamic_cast<T*>(this);
	}

}