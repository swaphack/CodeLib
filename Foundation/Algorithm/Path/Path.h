#pragma once

#include "system.h"

namespace alg
{
	class Map;
	/**
	*	·��
	*/
	class Path : public sys::Object
	{
	public:
		Path();
		virtual ~Path();
	public:
		
		/**
		*	��ȡֱ�߾���
		*/
		float getDistance(const Map* map, uint32_t fromIndex, uint32_t toIndex);
	protected:
		/**
		*	��Ӿ���
		*/
		void addDistance(const Map* map, uint32_t fromIndex, uint32_t toIndex);
	protected:
		// ����
		std::map<std::string, float> _distances;
	};
}
