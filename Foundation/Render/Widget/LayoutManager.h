#pragma once

#include <map>
#include <string>

namespace render
{
	class Layout;
	// ���ֹ���
	class LayoutManager
	{
	private:
		LayoutManager();
		virtual ~LayoutManager();
	public:
		static LayoutManager* getInstance();

		// ���һ������
		void addLayout(Layout* layout);
		// �Ƴ�һ������
		void removeLayout(const char* name);
		// ��ȡ����
		Layout* getLayout(const char* name);
		// �Ƴ����в���
		void removeAllLayouts();
	private:
		std::map<std::string, Layout*> _layoutStack;
	};
}