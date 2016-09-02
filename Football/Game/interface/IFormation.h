#pragma once

namespace game
{
	class IPlayer;

	/**
	*	����
	*/
	class IFormation
	{
	public:
		virtual ~IFormation(){}
	public:
		/**
		*	��ȡ���ͱ��
		*/
		virtual int getID() const = 0;
		/**
		*	������������
		*/
		virtual void setDescribe(const char* pDescribe) = 0;
		/**
		*	��ȡ��������
		*/
		virtual const char* toDescribe() const = 0;
		/**
		*	��ȡ�˶�Ա
		*/
		virtual const IPlayer* getPlayer(int nIndex) const = 0;
		/**
		*	���������˶�Ա
		*/
		virtual bool putPlayer(int nIndex, IPlayer* pPlayer) = 0;
		/**
		*	�Ƴ������˶�Ա
		*/
		virtual bool movePlayer(int nIndex) = 0;
	};
}