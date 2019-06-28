#pragma once

#include <map>

namespace game
{
	class IPlayer;
	/**
	*	λ������ {������(λ��,��Ա��}
	*/
	typedef std::map<int, std::pair<int, int> > IndexPosition;
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
		*	��ȡλ��
		*/
		virtual int getPosition(int nIndex) const = 0;
		/**
		*	����ָ��λ�õ���Ա��λ
		*/
		virtual void setPosition(int nIndex, int nPosition) = 0;
		/**
		*	����ָ��λ�õ���Ա��λ
		*/
		virtual void resetPosition(int nIndex) = 0;
		/**
		*	��ȡ�˶�Ա
		*/
		virtual int getPlayer(int nIndex) const = 0;
		/**
		*	���������˶�Ա
		*/
		virtual bool putPlayer(int nIndex, int nPlayerID) = 0;
		/**
		*	�Ƴ������˶�Ա
		*/
		virtual bool movePlayer(int nIndex) = 0;
	};
}