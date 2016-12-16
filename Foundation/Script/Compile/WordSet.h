#pragma once

#include <map>
#include <string>
#include <vector>

namespace script
{
	// 单词集合
	class WordSet
	{
	private:
		WordSet();
	public:
		~WordSet();
	public:
		static WordSet* getInstance();
		/**
		*	添加一个单词
		*	@param name 单词名称
		*/
		void appendWord(const char* name);
		/**
		*	判断是否包含改单词
		*	@param name 单词名称
		*/
		bool containWord(const char* name);
		/**
		*	从字符头开始，判断是否包含单词
		*	成功返回单词长度，失败返回-1
		*	@param name 单词
		*	@param offset 单词长度
		*/
		bool pickWord(const char* name, int& offset);
		/**
		*	清空所有单词
		*/
		void clear();
	private:
		typedef std::map<int,std::vector<std::string> > WordMap;
		WordMap m_mWords;
	};
}