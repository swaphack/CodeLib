#include "web.h"
#include "system.h"

using namespace sys;
using namespace web;

namespace gw
{
	// ����Ӧ��
	class PacketActivityReceiver : public web::PacketActivity
	{
	protected:
		// ����������
		virtual void doGet(const char* buffer, int size);
		// �������ݸ������
		void postToGameServer(const PacketHeader& packet);
		// ���͸��ͻ���
		void postToClient(int socketID, const PacketHeader& packet);
		// �Ƿ��Ƿ����id
		bool isGameServer();
	};
}