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

		PacketHeader()
		{
			PacketID = 0;
			Length = sizeof(*this);
		}
	};

	// �û�����ͷ��
	struct UserPacketHeader : public PacketHeader
	{
		// �û���ʶ
		int Mark;

		UserPacketHeader()
		{
			Mark = 0;
			PacketID = 0;
			Length = sizeof(*this);
		}
	};
}