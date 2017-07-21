#pragma once

#include "macros.h"

#include <vector>

namespace script
{
	// 文本过滤
	class TextFilter : public ITextFilter
	{
	public:
		TextFilter(){}
		virtual ~TextFilter(){}
	public:
		virtual bool match(const char* text, int& size)
		{
			return WordSet::getInstance()->pickWord(text, size);
		}
	};

	// 单词过滤器
	class WordFilters
	{
	private:
		WordFilters();
		~WordFilters();
	public:
		static WordFilters* getInstance();
		// 添加一个过滤
		void addFilter(ITextFilter* filter);
		// 移除一个过滤
		void removeFilter(ITextFilter* filter);
		// 移除所有过滤
		void removeAllFilters();
		// 匹配单词
		bool match(const char* text, int& size);
	private:
		std::vector<ITextFilter*> m_vWordFilters;
	};
}