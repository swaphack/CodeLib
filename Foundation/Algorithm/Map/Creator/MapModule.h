#pragma once

#include "Map/Base/MapCell.h"

namespace alg
{
	class MapSlot;
	// ���
	class MapModule : public MapCell
	{
	public:
		MapModule();
		virtual ~MapModule();
	public:
		/**
		*	��ȡ���
		*/
		MapSlot* getSlot() const;
	protected:
		// �����Ϣ
		MapSlot* _slot = nullptr;
	};
}

