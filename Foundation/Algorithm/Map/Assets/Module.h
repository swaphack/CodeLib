#pragma once

#include "Map/Base/MapObject.h"

namespace alg
{
	namespace map
	{
		class Slots;

		// ģ��
		class Module : public MapObject
		{
		public:
			Module();
			virtual ~Module();
		public:
			/**
			*	��ȡ���
			*/
			Slots* getModuleSlot() const;
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
			Slots* _slot = nullptr;
			// ��Դ���
			uint32_t _ressourceID = 0;
		};
	}
}