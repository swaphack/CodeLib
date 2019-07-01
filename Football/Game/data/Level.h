#pragma once

#include "../base/Component.h"

namespace game
{
	/**
	*	�ȼ�
	*/
	class Level : public Component
	{
	public:
		Level();
		virtual ~Level();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Level);
	public:
		/**
		*	��ȡ��ǰ�ȼ�
		*/
		CREATE_COMPONENT_PROPERTY(uint16_t, Level);
		/**
		*	��ȡ��ǰ����
		*/
		CREATE_COMPONENT_PROPERTY(uint64_t, Experience);
		/**
		*	��ǰ�ȼ�����
		*/
		CREATE_COMPONENT_PROPERTY(uint64_t, LevelExperience);
	public:
		/**
		*	�Ƿ��������
		*/
		bool canUpgrade();
		/**
		*	��ȡʣ���������辭��
		*/
		uint64_t getRemainUpgradeExp();
		/**
		*	����
		*/
		bool upgrade();
		/**
		*	���Ӿ���
		*/
		bool addExperience(uint64_t value);
	};
}