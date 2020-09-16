#pragma once

#include "system.h"

namespace alg
{
	class MapProtocol;
	/**
	*	路径
	*/
	class Path : public sys::Object
	{
	public:
		Path();
		virtual ~Path();
	public:
		
		/**
		*	获取直线距离
		*/
		float getDistance(const MapProtocol* map, uint32_t fromIndex, uint32_t toIndex);
	protected:
		/**
		*	添加距离
		*/
		void addDistance(const MapProtocol* map, uint32_t fromIndex, uint32_t toIndex);
	protected:
		// 距离
		std::map<std::string, float> _distances;
	};
}
