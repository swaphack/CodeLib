#pragma once

#include <cstdint>
#include <string>
#include <map>

namespace business
{
	template<typename T, typename = std::enable_if<std::is_base_of<Object, T>::value, T>::type>
	class ObjectFactory
	{
	private:
		ObjectFactory(){}
		virtual ~ObjectFactory(){ this->clear(); }
	public:
		static ObjectFactory* singleton()
		{
			if (s_instance == nullptr)
			{
				s_instance = new ObjectFactory<T>();
			}
			return s_instance;
		}
		static void purge()
		{
			if (s_instance)
			{
				delete s_instance;
				s_instance = nullptr;
			}
		}

		T* create()
		{
			T* t = new T();
			if (t)
			{
				m_mapObjects[t->getID()] = t;
			}
			return t;
		}
		void destory(T* pTarget)
		{
			if (pTarget == nullptr)
			{
				return;
			}
			auto iter = m_mapObjects.find(pTarget->getID());
			if (iter != m_mapObjects.end())
			{
				m_mapObjects.erase(iter);
			}

			delete pTarget;
		}
		T* find(uint64_t id)
		{
			auto iter = m_mapObjects.find(pTarget->getID());
			if (iter != m_mapObjects.end())
			{
				return iter->second;
			}

			return nullptr;
		}
		void clear()
		{
			for (auto item : m_mapObjects)
			{
				delete item->second;
			}
			m_mapObjects.clear();
		}
	protected:
	private:
		// 工厂单例
		static ObjectFactory* s_instance;
		// 对象
		std::map<uint64_t, T*> m_mapObjects;
	};

	template<typename T, typename = std::enable_if<std::is_base_of<Object, T>::value, T>::type>
	ObjectFactory* ObjectFactory<T>::s_instance = nullptr;

}