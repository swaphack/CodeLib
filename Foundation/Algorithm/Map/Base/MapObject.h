#pragma once

#include "mathlib.h"
#include "Struct/ObjectDetail.h"

namespace alg
{
	namespace map
	{
		/**
		*	��ͼ�϶���
		*/
		class MapObject : public ObjectDetail
		{
		public:
			MapObject();
			virtual ~MapObject();
		public:
			/**
			*	�ڵ���
			*/
			void setMapObjectID(uint32_t nIndex);
			/**
			*	�ڵ���
			*/
			uint32_t getMapObjectID() const;
		private:
			/**
			*	�ڵ�����
			*/
			uint32_t _mapObjectID = 0;
		};
	}
}