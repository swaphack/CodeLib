#pragma once

namespace game
{
	class ITeam;
	class IRank;
	class ISchedule;

	/**
	*	����
	*/
	class ILeague
	{
	public:
		virtual ~ILeague() {}
	public:
		/**
		*	���
		*/
		virtual int getID() const = 0;
		/**
		*	���ڹ���
		*/
		virtual int getCountryID() const = 0;
		/**
		*	�����ȼ�
		*/
		virtual int level() const = 0;
		/**
		*	�μӶ�����
		*/
		virtual int count() const = 0;
		/**
		*	��ȡ����
		*/
		virtual const ITeam* getTeam(int nID) const = 0;
		/**
		*	��Ӷ���
		*/
		virtual void addTeam(ITeam* pTeam) = 0;
		/**
		*	�Ƴ�����
		*/
		virtual void removeTeam(int nID) = 0;
		/**
		*	��ȡ����
		*/
		virtual const IRank* getRank() const = 0;
		/**
		*	��ȡ����
		*/
		virtual const ISchedule* getSchedule() const = 0;
	};
}