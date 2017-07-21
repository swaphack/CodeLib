#pragma once

#include "macros.h"
#include <string>

namespace script
{
	// ������ʽ����
	class VariableFilter : public ITextFilter
	{
	public:
		VariableFilter();
		virtual ~VariableFilter();
	public:
		virtual bool match(const std::string& text);
	};

	// ��ֵ��ʽ����
	class NumberFilter : public ITextFilter
	{
	public:
		NumberFilter();
		virtual ~NumberFilter();
	public:
		virtual bool match(const std::string& text);
	};

	// �ַ�����ʽ����
	class StringFilter : public ITextFilter
	{
	public:
		StringFilter();
		virtual ~StringFilter();
	public:
		virtual bool match(const std::string& text);
	};

	// ��ֵ��ʽ����
	class NoneFilter : public ITextFilter
	{
	public:
		NoneFilter();
		virtual ~NoneFilter();
	public:
		virtual bool match(const std::string& text);
	};
}