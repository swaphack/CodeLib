#include "web.h"
#include "system.h"

#include "../Protocols/import.h"

using namespace sys;
using namespace web;

// 报文应答
class PacketActivityTest : public web::PacketActivity
{
protected:
	// 接收请求处理
	virtual void doGet(const char* buffer, int size);
};