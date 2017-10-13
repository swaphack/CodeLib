#pragma once

#include "system.h"

namespace web
{
	struct DBAuthor : public sys::Author
	{
	public:
		// Êý¾Ý¿âÃû³Æ
		std::string dbname;
	public:
		DBAuthor() 
			:dbname("")
		{}

		DBAuthor(const std::string& host, int port, 
			const std::string& username, const std::string& password, 
			const std::string& dbname)
			:dbname(dbname)
		{
			this->host = host;
			this->port = port;
			this->username = username;
			this->password = password;
		}
	};
}