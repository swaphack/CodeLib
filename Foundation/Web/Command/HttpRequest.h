#pragma once

#include <string>
#include "HttpCommand.h"

namespace web
{
	// http «Î«Û
	struct HttpRequest : public HttpCommand
	{
	public:
		HttpRequest();
		~HttpRequest();
	public:
		void setSrcID(int id);
		int getSrcID();
	private:
		int _srcID;
	};
}