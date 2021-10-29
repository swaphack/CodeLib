#pragma once

#include <string>
#include <cstdint>

namespace sys
{
	// ������
	struct Author
	{
	public:
		// ��ַ
		std::string host;
		// �˿�
		int32_t port = 0;
		// �û�����
		std::string username;
		// ����
		std::string password;
	public:
		Author()
		{}
		Author(const std::string& host, int32_t port)
			:host(host), port(port)
		{}
	};
}