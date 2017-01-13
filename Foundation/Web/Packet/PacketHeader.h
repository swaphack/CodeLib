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

		PacketHeader()
		{
			PacketID = 0;
			Length = sizeof(*this);
		}
	};

	// 用户报文头部
	struct UserPacketHeader : public PacketHeader
	{
		// 用户标识
		int Mark;

		UserPacketHeader()
		{
			Mark = 0;
			PacketID = 0;
			Length = sizeof(*this);
		}
	};
}