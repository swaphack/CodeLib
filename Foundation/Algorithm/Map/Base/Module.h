#pragma once

#include "Map/Base/MapObject.h"

namespace alg
{
	namespace map
	{
		class Slots;

		// 模块
		class Module : public MapObject
		{
		public:
			Module();
			virtual ~Module();
		public:
			/**
			*	获取插槽
			*/
			Slots* getModuleSlot() const;
			/**
			*	设置资源编号
			*/
			void setResourceID(uint32_t resID);
			/**
			*	获取资源编号
			*/
			uint32_t getResourceID() const;
		protected:
			// 插槽信息
			Slots* _slot = nullptr;
			// 资源编号
			uint32_t _ressourceID = 0;
		};
	}
}