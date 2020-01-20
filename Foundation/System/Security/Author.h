#pragma once

#include <string>
#include <cstdint>

namespace sys
{
	// 发起人
	struct Author
	{
	public:
		// 地址
		std::string host;
		// 端口
		int32_t port = 0;
		// 用户名称
		std::string username;
		// 密码
		std::string password;
	public:
		Author()
			:host(""), port(0), username(""), password("")
		{}
		Author(const std::string& host, int32_t port)
			:host(host), port(port), username(""), password("")
		{}
	};
}