#pragma once

#include <map>
#include <string>

namespace web
{
	// ����
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
		// �Ƿ��Ǹ�����������
		bool isFullCommand();
	protected:
		void setFullCommand(bool status);
	protected:
		// ��Ϣ
		std::string _msg;
		// �Ƿ��Ǹ�����������
		bool _bFullCommand;
	};
}