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
		/**
		*	添加一个关键字
		*	@param name 关键字名称
		*/
		void appendKeyWord(const char* name);
		/**
		*	判断是否包含改关键字
		*	@param keyword 运算符
		*/
		bool containKeyWord(const char* name);
		/**
		*	清空所有关键字
		*/
		void clear();
	protected:
		void init();
	private:
		typedef std::vector<std::string> Words;
		// 关键字
		Words m_vKeyWords;
	};
}