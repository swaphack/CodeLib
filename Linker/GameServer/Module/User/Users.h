#pragma once

#include <functional>
#include <map>

#include "web.h"

namespace gs
{
	class Player;

	// 用户信息
	struct T_UserInfo
	{
		// socket编号
		int Mark;
		// 用户id, 随机生成
		int UserID;
	};

	/**
	*	用户信息
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
		*	添加角色
		*/
		void addUser(const T_UserInfo& userInfo);
		/**
		*	获取角色
		*/
		const T_UserInfo* getUser(int nUserID);
		/**
		*	获取角色
		*/
		const T_UserInfo* getUserByMark(int nMark);
		/**
		*	移除角色
		*/
		void removeUser(int nUserID);
		/**
		*	清空角色数据
		*/
		void removeAllUsers();
	private:
		typedef std::map<int, T_UserInfo> T_UserInfos;
		typedef std::map<int, T_UserInfo*> T_PtrUserInfos;
		// 用户数据
		T_UserInfos m_mUserInfos;
		// 用户通信
		T_PtrUserInfos m_mUserMarks;
	};
}