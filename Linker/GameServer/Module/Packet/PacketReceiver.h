#include "web.h"
#include "system.h"

using namespace sys;
using namespace web;

namespace gs
{
	// 报文应答
	class PacketReceiver : public web::PacketActivity
	{
	protected:
		// 接收请求处理
		virtual void doGet(const char* buffer, int size);
	};
}