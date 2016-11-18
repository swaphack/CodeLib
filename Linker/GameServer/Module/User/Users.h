#pragma once

#include <functional>
#include <map>

#include "web.h"

namespace gs
{
	class Player;

	// �û���Ϣ
	struct T_UserInfo
	{
		// socket���
		int Mark;
		// �û�id, �������
		int UserID;
	};

	/**
	*	�û���Ϣ
	*/
	class Users
	{
	private:
		Users();
	public:
		~Users();
	public:
		static Users* getInstance();
		/**
		*	������
		*/
		void addPlayer(T_UserInfo pUserInfo);
		/**
		*	��ȡ���
		*/
		T_UserInfo* getPlayer(int nUserID);
		/**
		*	��ȡ���
		*/
		T_UserInfo* getPlayerByMark(int nMark);
		/**
		*	�Ƴ����
		*/
		void removePlayer(int nUserID);
		/**
		*	����û�����
		*/
		void clearAllPlayers();
	private:
		typedef std::map<int, T_UserInfo> T_UserInfos;
		typedef std::map<int, T_UserInfo*> T_PtrUserInfos;
		// �û�����
		T_UserInfos m_mUserInfos;
		// �û�ͨ��
		T_PtrUserInfos m_mUserMarks;
	};
}