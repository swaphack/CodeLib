#pragma once

#include <string>
#include "HttpCommand.h"

namespace web
{
	struct HttpResponse : public HttpCommand
	{
	public:
		HttpResponse();
		~HttpResponse();
	public:
		void setDestID(int id);
		int getDestID();
	protected:
	private:
		int _destID;
	};
}