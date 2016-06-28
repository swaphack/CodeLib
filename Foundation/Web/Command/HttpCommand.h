#pragma once

#include <map>
#include <string>

namespace web
{
	// http����
	struct HttpCommand
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
		void parseMessage();
	private:
		std::string _msg;
		std::map<std::string, std::string> _params;
	};
}