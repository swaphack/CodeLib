#pragma once

#include "MapObject.h"

namespace alg
{
	namespace map
	{
		// 地图上单元块
		class MapCell : public MapObject
		{
		public:
			MapCell();
			virtual ~MapCell();
		public:
			/**
			*	设置配件索引
			*/
			void setModuleID(uint32_t moduleID);
			/**
			*	获取配件索引
			*/
			uint32_t getModuldeID() const;
			/**
			*	设置坐标
			*/
			void setPosition(const math::Vector3& pos);
			/**
			*	获取坐标
			*/
			const math::Vector3& getPosition() const;
		private:
			// 配件索引
			uint32_t _moduleID = 0;
			// 坐标
			math::Vector3 _position;
		};
	}
}