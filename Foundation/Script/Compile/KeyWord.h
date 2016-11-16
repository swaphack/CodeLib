#pragma once

#include <set>
#include <string>

namespace script
{
	typedef std::set<std::string> Words;
	// 关键字
	class KeyWord
	{
	private:
		KeyWord();
	public:
		~KeyWord();
	public:
		static KeyWord* getInstance();
		// 追加一个关键字
		void append(const char* keyword);
		// 判断是否包含改关键字,返回关键字开始位置
		int contain(const char* keyword);
		// 清空所有关键字
		void clear();

		inline Words::const_iterator wordBegin(){ return m_sKeyWords.begin(); }
		inline Words::const_iterator wordEnd(){ return m_sKeyWords.end(); }
	protected:
		void init();
	private:
		// 关键字
		Words m_sKeyWords;
	};
}