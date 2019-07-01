#pragma once

#include <vector>
#include "../macros.h"

namespace game
{
	class Formation;
	/**
	*	������Ϣ
	*	��Ա״̬�����ȴ��ϳ����ϳ������滻��������������
	*/
	class LineUp : public Component
	{
	public:
		/**
		*	����״̬
		*/
		enum LineUpStatus
		{
			ELUS_OnLine,
			ELUS_OffLine,
		};
	public:
		LineUp();
		virtual ~LineUp();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(LineUp);
	public:
		/**
		*	��ȡ����
		*/
		const Formation* getFormation() const;
		/**
		*	��ȡ�ϳ���Ա��
		*/
		int getPlayCount();
		/**
		*	��ȡ�油��Ա��
		*/
		int getSubstituteCount();
		/**
		*	������Ա״̬
		*/
		void setPlayerStatus(uint64_t nPlayerID, int nStatus);
		/**
		*	��ȡ��Ա״̬
		*/
		int getPlayerStatus(uint64_t nPlayerID) const;
		/**
		*	��ȡָ��״̬����Ա
		*/
		void getPlayerByStatus(int nStatus, std::vector<uint64_t>& vPlayerIDs) const;
		/**
		*	��ȡ������Ա
		*/
		void getPlayIDs(std::vector<uint64_t>& vPlayerIDs) const;
		/**
		*	��ȡ��������Ա
		*/
		void getWaitIDs(std::vector<uint64_t>& vPlayerIDs) const;
	};
}