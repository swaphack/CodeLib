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
		*	��ӽ�ɫ
		*/
		void addUser(const T_UserInfo& userInfo);
		/**
		*	��ȡ��ɫ
		*/
		const T_UserInfo* getUser(int nUserID);
		/**
		*	��ȡ��ɫ
		*/
		const T_UserInfo* getUserByMark(int nMark);
		/**
		*	�Ƴ���ɫ
		*/
		void removeUser(int nUserID);
		/**
		*	��ս�ɫ����
		*/
		void removeAllUsers();
	private:
		typedef std::map<int, T_UserInfo> T_UserInfos;
		typedef std::map<int, T_UserInfo*> T_PtrUserInfos;
		// �û�����
		T_UserInfos m_mUserInfos;
		// �û�ͨ��
		T_PtrUserInfos m_mUserMarks;
	};
}