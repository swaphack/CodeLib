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

void Users::addUser(const T_UserInfo& userInfo)
{
	m_mUserInfos[userInfo.UserID] = userInfo;

	m_mUserMarks[userInfo.Mark] = &m_mUserInfos[userInfo.UserID];
}

const T_UserInfo* Users::getUser(int nUserID)
{
	T_UserInfos::iterator iter = m_mUserInfos.find(nUserID);
	if (iter == m_mUserInfos.end())
	{
		return nullptr;
	}

	return &iter->second;
}

const T_UserInfo* Users::getUserByMark(int nMark)
{
	T_PtrUserInfos::iterator iter = m_mUserMarks.find(nMark);
	if (iter == m_mUserMarks.end())
	{
		return nullptr;
	}

	return iter->second;
}

void Users::removeUser(int nUserID)
{
	T_UserInfos::iterator iter = m_mUserInfos.find(nUserID);
	if (iter != m_mUserInfos.end())
	{
		m_mUserMarks.erase(iter->second.Mark);
	}

	m_mUserInfos.erase(nUserID);
}

void Users::removeAllUsers()
{
	m_mUserInfos.clear();
}