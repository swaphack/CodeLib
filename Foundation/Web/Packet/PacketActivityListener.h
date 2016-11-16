#pragma once

#include "system.h"

#include "PacketRecvHandler.h"

#include "../Listener/IActivityListener.h"

namespace web
{
	// 报文监听
	class PacketActivityListener : public IActivityListener
	{
	public:
		PacketActivityListener();
		virtual ~PacketActivityListener();
	public:
		// 添加接受数据处理
		void addRecvHandler(sys::Object* target, PACKET_RECV_HANDLER handler);
		// 移除接受数据处理
		void removeRecvHandler(sys::Object* target, PACKET_RECV_HANDLER handler);

		virtual bool onDispatch(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize);
	protected:
		// 接受请求处理
		void onRecvHander(const char* sessionID, const char* buffer, int size);
		// 从接收的数据中创建报文请求，并且删除已完成的数据
		const char* createRequest(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize);
	private:
		// http接受处理
		std::vector<PacketRecvHandler> _recvHandlers;
	};
}