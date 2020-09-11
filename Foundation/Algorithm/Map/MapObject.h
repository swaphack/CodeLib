#pragma once

#include "mathlib.h"
#include "Struct/ObjectDetail.h"

namespace alg
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
		*	�ڵ�����
		*/
		void setObjectIndex(uint32_t nIndex);
		/**
		*	�ڵ�����
		*/
		uint32_t getObjectIndex() const;
	private:
		/**
		*	�ڵ�����
		*/
		uint32_t _objectIndex = 0;
	};
}