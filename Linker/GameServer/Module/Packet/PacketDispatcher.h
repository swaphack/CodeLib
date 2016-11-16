#pragma once

#include <functional>
#include <map>

#include "web.h"

namespace gs
{
	// 报文处理
	typedef std::function<web::UserPacketHeader*(const web::UserPacketHeader& header)> PacketHandler;

	/**
	*	报文处理派发
	*/
	class PacketDispatcher
	{
	private:
		PacketDispatcher();
	public:
		~PacketDispatcher();
	public:
		static PacketDispatcher* getInstance();
		/**
		*	注册包处理
		*/
		void setPacketHandler(PacketHandler handler);
		/**
		*	收到包处理
		*/
		web::UserPacketHeader* dispathPacket(const web::UserPacketHeader& header);
	private:
		// 包处理
		PacketHandler m_PacketHandler;
	};
}