#pragma once

#include "macros.h"

#include <vector>

namespace script
{
	// ���ʹ�����
	class WordFilters
	{
	private:
		WordFilters();
		~WordFilters();
	public:
		static WordFilters* getInstance();
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