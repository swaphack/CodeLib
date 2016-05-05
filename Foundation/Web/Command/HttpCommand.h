#pragma once

#include <string>

namespace web
{
	struct HttpCommand
	{
	public:
		HttpCommand();
		virtual ~HttpCommand();
	public:
		void setMessage(const char* msg, int size);
		char* getMessage();

		int size();

		virtual bool empty();
	private:
		std::string _msg;
	};

	//////////////////////////////////////////////////////////////////////////
	struct HttpRequest: public HttpCommand
	{
	public:
		HttpRequest();
		~HttpRequest();
	public:
		void setSrcID(int id);
		int getSrcID();
	protected:
	private:
		int _srcID;
	};


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