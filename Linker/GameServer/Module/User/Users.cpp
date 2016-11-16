#include "Users.h"

#include "../macros.h"

using namespace gs;

Users::Users()
{
}

Users::~Users()
{
}


Users* Users::getInstance()
{
	static Users* s_UserInfo = nullptr;
	if (s_UserInfo == nullptr)
	{
		s_UserInfo = new Users();
	}
	return s_UserInfo;
}

void Users::addPlayer(T_UserInfo pUserInfo)
{
	m_mUserInfos[pUserInfo.UserID] = pUserInfo;

	m_mUserMarks[pUserInfo.Mark] = &m_mUserInfos[pUserInfo.UserID];
}

T_UserInfo* Users::getPlayer(int nUserID)
{
	T_UserInfos::iterator iter = m_mUserInfos.find(nUserID);
	if (iter == m_mUserInfos.end())
	{
		return nullptr;
	}

	return &iter->second;
}

T_UserInfo* Users::getPlayerByMark(int nMark)
{
	T_PtrUserInfos::iterator iter = m_mUserMarks.find(nMark);
	if (iter == m_mUserMarks.end())
	{
		return nullptr;
	}

	return iter->second;
}

void Users::removePlayer(int nUserID)
{
	T_UserInfos::iterator iter = m_mUserInfos.find(nUserID);
	if (iter == m_mUserInfos.end())
	{
		return;
	}

	m_mUserMarks.erase(iter->second.Mark);
	m_mUserInfos.erase(nUserID);
}

void Users::clearAllPlayers()
{
	m_mUserInfos.clear();
}