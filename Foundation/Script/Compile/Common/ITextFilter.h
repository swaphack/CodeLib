#pragma once

namespace script
{
	// 单词过滤接口
	class ITextFilter
	{
	public:
		virtual ~ITextFilter() {}
	public:
		/**
		*	单词是否匹配
		*/
		virtual bool match(const char* text, int& size) = 0;
	};
}