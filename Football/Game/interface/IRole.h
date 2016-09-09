#pragma once

#include "IPerson.h"

namespace game
{
	class IScene;
	class IMind;
	/**
	*	���ݽ�ɫ
	*/
	class IRole : public IPerson
	{
	public:
		virtual ~IRole() {}
	public:
		/**
		*	�������ֲ�
		*/
		virtual int getClubID() const = 0;
		/**
		*	��������
		*/
		virtual int getTeamID() const = 0;
		/**
		*	ְλ����Ա������������
		*/
		virtual int getJob() const = 0;
		/**
		*	����λ��
		*/
		virtual int getPosition() const = 0;
		/**
		*	˼���Ĵ���
		*/
		virtual const IMind* getMind() const = 0;
	};
}