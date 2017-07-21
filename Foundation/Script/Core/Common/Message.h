#pragma once

#include <string>
#include <map>

namespace script
{
	// ��Ϣ
	class Message
	{
	private:
		Message();
		virtual ~Message();
	public:
		static Message* getInstance();
	public:
		// ���
		void clear();
		// ��ȡ��Ϣ�ı�
		const char* getText(int nID);
		// �����Ϣ�ı�
		void addText(int nID, const char* text);
	private:
		// �ı�
		std::map<int, std::string> m_pTexts;
	};
}