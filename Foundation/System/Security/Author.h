#pragma once

#include <string>

namespace sys
{
	// ������
	struct Author
	{
	public:
		// ��ַ
		std::string host;
		// �˿�
		int port = 0;
		// �û�����
		std::string username;
		// ����
		std::string password;
	public:
		Author()
			:host(""), port(0), username(""), password("")
		{}
		Author(const std::string& host, int port)
			:host(host), port(port), username(""), password("")
		{}
	};
}