#include "web.h"
using namespace web;

// 登录请求
struct ReqPacket_Login: public PacketHeader
{
	// 用户名
	char Name[15];
	// 密码
	char Password[20];

	ReqPacket_Login()
	{
		PacketID=100;
		Length = sizeof(*this);
	}
};

// 返回玩家信息
struct RespPacket_PlayerInfo: public PacketHeader
{
	// 玩家名称
	int PlayerID;
	// 玩家等级
	int Level;
	// 玩家经验
	int Experience;

	RespPacket_PlayerInfo()
	{
		PacketID=100;
		Length = sizeof(*this);
	}
};
