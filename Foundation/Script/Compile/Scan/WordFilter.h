#pragma once

#include "macros.h"

#include <vector>

namespace script
{
	// ���ʹ�����
	class WordFilter
	{
	public:
		WordFilter();
		virtual ~WordFilter();
	public:
		// ���һ������
		void addFilter(ITextFilter* filter);
		// �Ƴ�һ������
		void removeFilter(ITextFilter* filter);
		// �Ƴ����й���
		void removeAllFilters();
		// ƥ�䵥��
		bool match(const char* text, int& size);
	private:
		std::vector<ITextFilter*> m_vWordFilters;
	};
}