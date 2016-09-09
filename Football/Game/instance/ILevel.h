#pragma once

namespace game
{
	/**
	*	�ȼ�
	*/
	class ILevel
	{
	public:
		virtual ~ILevel() {}
	public:
		/**
		*	��ȡ��ǰ�ȼ�
		*/
		virtual int getLevel() const = 0;
		/**
		*	��ȡ��ǰ����
		*/
		virtual int getExperience() const = 0;
		/**
		*	�Ƿ��������
		*/
		virtual bool canUpgrade() const = 0;
		/**
		*	��ȡʣ���������辭��
		*/
		virtual int getRemainUpgradeExp() const = 0;
		/**
		*	��ȡ��һ���������辭��
		*/
		virtual int getNextUpgradeExp() const = 0;
		/**
		*	����
		*/
		virtual bool upgrade() = 0;
		/**
		*	���Ӿ���
		*/
		virtual bool addExperience(int value) = 0;
	};
}