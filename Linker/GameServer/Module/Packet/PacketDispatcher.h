#pragma once

#include <functional>
#include <map>

#include "web.h"

namespace gs
{
	// ���Ĵ���
	typedef std::function<web::UserPacketHeader*(const web::UserPacketHeader& header)> PacketHandler;

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
		void setPacketHandler(PacketHandler handler);
		/**
		*	�յ�������
		*/
		web::UserPacketHeader* dispathPacket(const web::UserPacketHeader& header);
	private:
		// ������
		PacketHandler m_PacketHandler;
	};
}