#include "web.h"
#include "system.h"

#include "../Protocols/import.h"

using namespace sys;
using namespace web;

// ����Ӧ��
class PacketActivityTest : public web::PacketActivity
{
protected:
	// ����������
	virtual void doGet(const char* buffer, int size);
};