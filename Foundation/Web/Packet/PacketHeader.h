#pragma once

namespace web
{
	// ����ͷ��
	struct PacketHeader
	{
		// Э�鳤��
		int Length;
		// ���ı��
		int PacketID;
	};

	// �û�����ͷ��
	struct UserPacketHeader : public PacketHeader
	{
		// �û���ʶ
		int Mark;
	};
}