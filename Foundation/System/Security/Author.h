#pragma once

#include <string>

namespace sys
{
	// ������
	struct Author
	{
	public:
		// ��ַ
		std::string url;
		// �˿�
		int port = 0;
		// �û�����
		std::string username;
		// ����
		std::string password;
	public:
		Author()
			:url(""), port(0), username(""), password("")
		{}
		Author(const std::string& url, int port) 
			:url(url), port(port), username(""), password("")
		{}
	};
}