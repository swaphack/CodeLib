#pragma once

#include "web.h"
using namespace web; 

// 登录请求
struct ReqPacketLogin : public UserPacketHeader
{                                                                                                                                                                                                                                                   
	// 用户名
	char Name[15];
	// 密码
	char Password[20];

	ReqPacketLogin()
	{
		PacketID=100;
		Length = sizeof(*this);
	}
};

// 返回玩家信息
struct RespPacketPlayerInfo : public UserPacketHeader
{
	// 玩家名称
	int PlayerID;
	// 玩家等级
	int Level;
	// 玩家经验
	int Experience;

	RespPacketPlayerInfo()
	{
		PacketID=101;
		Length = sizeof(*this);
	}
};
