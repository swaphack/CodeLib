#pragma once

#include <vector>
#include <string>

namespace script
{
	// 关键字集合
	class KeyWordSet
	{
	private:
		KeyWordSet();
	public:
		~KeyWordSet();
	public:
		static KeyWordSet* getInstance();
		// 追加一个关键字
		void append(const char* keyword);
		// 判断是否包含改关键字,返回关键字开始位置
		int contain(const char* keyword);
		// 清空所有关键字
		void clear();
	protected:
		void init();
	private:
		typedef std::vector<std::string> Words;
		// 关键字
		Words m_vKeyWords;
	};
}