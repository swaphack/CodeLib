#pragma once

#include <map>
#include <string>

namespace web
{
	// http����
	class HttpCommand
	{
	public:
		HttpCommand();
		virtual ~HttpCommand();
	public:
		// ������Ϣ
		void setMessage(const char* msg, int size);
		// ��ȡ��Ϣ
		char* getMessage();
		// ��Ϣ��С
		int size();
		// �Ƿ���ֵ
		virtual bool empty();
	protected:
		// ������Ϣ
		virtual void parseMessage();
	protected:
		std::string _msg;
	};
}