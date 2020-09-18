#pragma once

#include "Map/Base/MapObject.h"

namespace alg
{
	class ModuleSlots;

	// 模块
	class MapModule : public MapObject
	{
	public:
		MapModule();
		virtual ~MapModule();
	public:
		/**
		*	获取插槽
		*/
		ModuleSlots* getSlot() const;
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
		ModuleSlots* _slot = nullptr;
		// 资源编号
		uint32_t _ressourceID = 0;
	};
}

