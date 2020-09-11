#pragma once

#include "MapObject.h"
#include <vector>

namespace alg
{
	/**
	*	地图对象管理
	*/
	template<typename T, typename = std::enable_if<std::is_base_of<MapObject, T>::value, T>::type>
	class MapObjects : public MapObject
	{
	public:
		MapObjects()
		{

		}
		virtual ~MapObjects()
		{
			this->removeAllObjects();
		}
	public:
		/**
		*	移除所有对象
		*/
		void removeAllObjects()
		{
			for (auto& item : _mapObjects)
			{
				SAFE_RELEASE(item.second);
			}

			_mapObjects.clear();
		}
		/**
		*	获取地图对象
		*/
		uint32_t getObjectCount() const
		{
			return _mapObjects.size();
		}
		/**
		*	是否为空
		*/
		bool isEmpty() const
		{
			return _mapObjects.empty();
		}
		/**
		*	获取对象
		*/
		const T* getObject(uint32_t nIndex) const
		{
			auto it = _mapObjects.find(nIndex);
			if (it == _mapObjects.end())
			{
				return nullptr;
			}

			return it->second;
		}
		/**
		*	获取对象
		*/
		T* getObject(uint32_t nIndex)
		{
			auto it = _mapObjects.find(nIndex);
			if (it == _mapObjects.end())
			{
				return nullptr;
			}

			return it->second;
		}
		/**
		*	创建对象
		*/
		T* create()
		{
			T* temp = new T();
			SAFE_RETAIN(temp);
			temp->setObjectIndex(_objectIndex);
			_mapObjects[_objectIndex] = temp;

			_objectIndex++;

			return temp;
		}
		/**
		*	创建对象
		*/
		template<typename Type, typename = std::enable_if<std::is_base_of<MapObject, Type>::value, Type>::type>
		Type* create()
		{
			Type* temp = new Type();
			SAFE_RETAIN(temp);
			temp->setObjectIndex(_objectIndex);
			_mapObjects[_objectIndex] = temp;

			_objectIndex++;

			return temp;
		}
		/**
		*	获取所有对象
		*/
		const std::map<uint32_t, T*>& getAllObjects() const
		{
			return _mapObjects;
		}
	protected:
		// 索引
		uint32_t _objectIndex = 0;
		// 地图点
		std::map<uint32_t, T*> _mapObjects;
	};
}
