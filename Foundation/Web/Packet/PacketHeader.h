#pragma once

namespace web
{
	// 报文头部
	struct PacketHeader
	{
		// 协议长度
		int Length;
		// 报文编号
		int PacketID;
	};

	// 用户报文头部
	struct UserPacketHeader : public PacketHeader
	{
		// 用户标识
		int Mark;
	};
}