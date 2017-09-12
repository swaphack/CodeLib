#pragma once

#include "PacketProtocol.h"

#include <functional>
#include <set>
#include <map>

namespace gs
{
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
		void registerPacketHandler(PacketProtocol* protocol, int packetID, PacketHandler handler);
		/**
		*	注销包处理
		*/
		void unregisterPacketHandler(PacketProtocol* protocol, int packetID);
		/**
		*	注销包处理
		*/
		void unregisterPacketHandler(PacketProtocol* protocol);
		/**
		*	清空包处理
		*/
		void clearPacketHandler();
		/**
		*	收到包处理
		*/
		void dispathPacket(const web::UserPacketHeader& header);
		/**
		*	注册包处理
		*/
		template<typename T>
		void registerPacketHandler(PacketProtocol* protocol, PacketHandler handler);
	private:
		std::map<int, std::map<PacketProtocol*, PacketHandler> > _packetHandlers;

		std::map<PacketProtocol*, std::map<int, PacketHandler>> _protocolHandlers;
	};

	template<typename T>
	void PacketDispatcher::registerPacketHandler(PacketProtocol* protocol, PacketHandler handler)
	{
		if (protocol == nullptr || handler == nullptr)
		{
			return;
		}

		T t;
		registerPacketHandler(protocol, t.PacketID, handler);
	}
}