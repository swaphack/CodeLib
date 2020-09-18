#pragma once

#include "Map/Base/MapObject.h"

namespace alg
{
	class ModuleSlots;

	// ģ��
	class MapModule : public MapObject
	{
	public:
		MapModule();
		virtual ~MapModule();
	public:
		/**
		*	��ȡ���
		*/
		ModuleSlots* getSlot() const;
		/**
		*	������Դ���
		*/
		void setResourceID(uint32_t resID);
		/**
		*	��ȡ��Դ���
		*/
		uint32_t getResourceID() const;
	protected:
		// �����Ϣ
		ModuleSlots* _slot = nullptr;
		// ��Դ���
		uint32_t _ressourceID = 0;
	};
}

