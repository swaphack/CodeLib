#include "web.h"
#include "system.h"

using namespace sys;
using namespace web;

namespace gs
{
	// ����Ӧ��
	class PacketReceiver : public web::PacketActivity
	{
	protected:
		// ����������
		virtual void doGet(const char* buffer, int size);
	};
}