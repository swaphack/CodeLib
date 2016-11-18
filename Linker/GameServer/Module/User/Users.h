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
		*	添加玩家
		*/
		void addPlayer(T_UserInfo pUserInfo);
		/**
		*	获取玩家
		*/
		T_UserInfo* getPlayer(int nUserID);
		/**
		*	获取玩家
		*/
		T_UserInfo* getPlayerByMark(int nMark);
		/**
		*	移除玩家
		*/
		void removePlayer(int nUserID);
		/**
		*	清空用户数据
		*/
		void clearAllPlayers();
	private:
		typedef std::map<int, T_UserInfo> T_UserInfos;
		typedef std::map<int, T_UserInfo*> T_PtrUserInfos;
		// 用户数据
		T_UserInfos m_mUserInfos;
		// 用户通信
		T_PtrUserInfos m_mUserMarks;
	};
}