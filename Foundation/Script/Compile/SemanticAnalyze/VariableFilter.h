#pragma once

#include "macros.h"
#include <string>

namespace script
{
	// 变量格式过滤
	class VariableFilter : public ITextFilter
	{
	public:
		VariableFilter();
		virtual ~VariableFilter();
	public:
		virtual bool match(const std::string& text);
	};

	// 数值格式过滤
	class NumberFilter : public ITextFilter
	{
	public:
		NumberFilter();
		virtual ~NumberFilter();
	public:
		virtual bool match(const std::string& text);
	};

	// 字符串格式过滤
	class StringFilter : public ITextFilter
	{
	public:
		StringFilter();
		virtual ~StringFilter();
	public:
		virtual bool match(const std::string& text);
	};

	// 空值格式过滤
	class NoneFilter : public ITextFilter
	{
	public:
		NoneFilter();
		virtual ~NoneFilter();
	public:
		virtual bool match(const std::string& text);
	};
}