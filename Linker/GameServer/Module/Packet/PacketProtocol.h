#pragma once

namespace web
{
	struct UserPacketHeader;
}

namespace gs
{
	class PacketProtocol;
	// 报文处理
	typedef void (PacketProtocol::*PacketHandler)(const web::UserPacketHeader& header);

	// 包处理协议
	class PacketProtocol
	{
	public:
		~PacketProtocol();
	public:
		template<typename T>
		void registerPacketHandler(PacketHandler handler);
		void unregisterPacketHandler();
	};

	template<typename T>
	void PacketProtocol::registerPacketHandler(PacketHandler handler)
	{
		if (handler == nullptr)
		{
			return;
		}

		PacketDispatcher::getInstance()->registerPacketHandler<T>(this, handler);
	}
}