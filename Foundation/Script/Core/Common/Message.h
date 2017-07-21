#pragma once

#include <string>
#include <map>

namespace script
{
	// 消息
	class Message
	{
	private:
		Message();
		virtual ~Message();
	public:
		static Message* getInstance();
	public:
		// 清空
		void clear();
		// 获取消息文本
		const char* getText(int nID);
		// 添加消息文本
		void addText(int nID, const char* text);
	private:
		// 文本
		std::map<int, std::string> m_pTexts;
	};
}