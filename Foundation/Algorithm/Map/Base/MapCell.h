#pragma once

#include "MapObject.h"

namespace alg
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
		void setModuleIndex(uint32_t moduleIndex);
		/**
		*	��ȡ�������
		*/
		uint32_t getModuldeIndex() const;
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
		uint32_t _moduleIndex = 0;
		// ����
		math::Vector3 _position;
	};
}