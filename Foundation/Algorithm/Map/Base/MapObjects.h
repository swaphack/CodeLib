#pragma once

#include "MapObject.h"
#include <vector>

namespace alg
{
	namespace map
	{
		/**
		*	��ͼ�������
		*/
		template<typename T>
		class MapObjects : public MapObject
		{
			static_assert(std::is_base_of<MapObject, T>::value, "T must inherit from MapObject");
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
			*	�Ƴ����ж���
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
			*	��ȡ��ͼ����
			*/
			uint32_t getObjectCount() const
			{
				return _mapObjects.size();
			}
			/**
			*	�Ƿ�Ϊ��
			*/
			bool isEmpty() const
			{
				return _mapObjects.empty();
			}
			/**
			*	��ȡ����
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
			*	��ȡ����
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
			*	��������
			*/
			T* create()
			{
				T* temp = new T();
				SAFE_RETAIN(temp);
				temp->setMapObjectID(_mapObjectID);
				_mapObjects[_mapObjectID] = temp;

				_mapObjectID++;
				return temp;
			}
			/**
			*	����id
			*/
			void increaseID()
			{
				_mapObjectID++;
			}
			/**
			*	��������
			*/
			template<typename Type, typename = std::enable_if<std::is_base_of<MapObject, Type>::value, Type>::type>
			Type* create()
			{
				_mapObjectID++;

				Type* temp = new Type();
				SAFE_RETAIN(temp);
				temp->setMapObjectID(_mapObjectID);
				_mapObjects[_mapObjectID] = temp;

				return temp;
			}
			/**
			*	��ȡ���ж���
			*/
			const std::map<uint32_t, T*>& getAllObjects() const
			{
				return _mapObjects;
			}
		protected:
			// ����
			uint32_t _mapObjectID = 0;
			// ��ͼ��
			std::map<uint32_t, T*> _mapObjects;
		};
	}
}