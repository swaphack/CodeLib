#pragma once

#include <map>
#include <string>

namespace web
{
	// http����
	class Command
	{
	public:
		Command();
		virtual ~Command();
	public:
		// ������Ϣ
		virtual void setMessage(const char* msg, int size);
		// ��ȡ��Ϣ
		const char* getMessage();
		// ��Ϣ��С
		int size();
		// �Ƿ���ֵ
		virtual bool empty();
	protected:
		std::string _msg;
	};
}