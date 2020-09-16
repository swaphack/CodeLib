#pragma once

#include "Map/Base/MapCell.h"

namespace alg
{
	class MapSlot;
	// 配件
	class MapModule : public MapCell
	{
	public:
		MapModule();
		virtual ~MapModule();
	public:
		/**
		*	获取插槽
		*/
		MapSlot* getSlot() const;
	protected:
		// 插槽信息
		MapSlot* _slot = nullptr;
	};
}

