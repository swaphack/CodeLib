#pragma once

#include "PacketProtocol.h"

#include <functional>
#include <set>
#include <map>

namespace gs
{
	/**
	*	���Ĵ����ɷ�
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
		*	ע�������
		*/
		void registerPacketHandler(PacketProtocol* protocol, int packetID, PacketHandler handler);
		/**
		*	ע��������
		*/
		void unregisterPacketHandler(PacketProtocol* protocol, int packetID);
		/**
		*	ע��������
		*/
		void unregisterPacketHandler(PacketProtocol* protocol);
		/**
		*	��հ�����
		*/
		void clearPacketHandler();
		/**
		*	�յ�������
		*/
		void dispathPacket(const web::UserPacketHeader& header);
		/**
		*	ע�������
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