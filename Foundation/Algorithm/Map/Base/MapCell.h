#pragma once

#include "MapObject.h"

namespace alg
{
	namespace map
	{
		// ��ͼ�ϵ�Ԫ��
		class MapCell : public MapObject
		{
		public:
			MapCell();
			virtual ~MapCell();
		public:
			/**
			*	�����������
			*/
			void setModuleID(uint32_t moduleID);
			/**
			*	��ȡ�������
			*/
			uint32_t getModuldeID() const;
			/**
			*	��������
			*/
			void setPosition(const math::Vector3& pos);
			/**
			*	��ȡ����
			*/
			const math::Vector3& getPosition() const;
		private:
			// �������
			uint32_t _moduleID = 0;
			// ����
			math::Vector3 _position;
		};
	}
}