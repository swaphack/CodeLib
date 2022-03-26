#pragma once

#include "MapObject.h"
#include <vector>

namespace alg
{
	namespace map
	{
		//��ͼ���󴴽��ӿ�
		class IMapObjectCreate
		{
		public:
			virtual~IMapObjectCreate() {}
		public:
			virtual MapObject* create() = 0;
		};

		/**
		*	��ͼ��һ���Ͷ������
		*/
		class MapObjects : public MapObject
		{
		public:
			MapObjects();
			virtual ~MapObjects();
		public:
			/**
			*	���ô����ӿ�, IMapObjectCreate��Ҫnew����
			*/
			void setCreateFunc(IMapObjectCreate* func);
			/**
			*	�Ƴ����ж���
			*/
			void removeAllObjects();
			/**
			*	��ȡ��ͼ����
			*/
			uint32_t getObjectCount() const;
			/**
			*	�Ƿ�Ϊ��
			*/
			bool isEmpty() const;
			/**
			*	��ȡ����
			*/
			const MapObject* getObject(uint32_t nIndex) const;
			/**
			*	��ȡ����
			*/
			MapObject* getObject(uint32_t nIndex);
			/**
			*	��������
			*/
			MapObject* create();
			/**
			*	����id
			*/
			void increaseID();
			/**
			*	��ȡ���ж���
			*/
			const std::map<uint32_t, MapObject*>& getAllObjects() const;
		protected:
			// ����
			uint32_t _mapObjectID = 0;
			// ��ͼ��
			std::map<uint32_t, MapObject*> _mapObjects;
			// �����ӿ�
			IMapObjectCreate* _createObjectFunc = nullptr;
		};
	}
}