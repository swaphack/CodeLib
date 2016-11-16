#include "web.h"
#include "system.h"

using namespace sys;
using namespace web;

namespace gw
{
	// 报文应答
	class PacketActivityReceiver : public web::PacketActivity
	{
	protected:
		// 接收请求处理
		virtual void doGet(const char* buffer, int size);
		// 发送数据给服务端
		void postToGameServer(const PacketHeader& packet);
		// 发送给客户端
		void postToClient(int socketID, const PacketHeader& packet);
		// 是否是服务端id
		bool isGameServer();
	};
}