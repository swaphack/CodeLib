#pragma once

#include <string>

namespace sys
{
	// 发起人
	struct Author
	{
	public:
		// 地址
		std::string url;
		// 端口
		int port = 0;
		// 用户名称
		std::string username;
		// 密码
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