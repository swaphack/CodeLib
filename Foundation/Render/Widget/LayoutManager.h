#pragma once

#include <map>
#include <string>

namespace render
{
	class Layout;
	// 布局管理
	class LayoutManager
	{
	private:
		LayoutManager();
		virtual ~LayoutManager();
	public:
		static LayoutManager* getInstance();

		// 添加一个布局
		void addLayout(Layout* layout);
		// 移除一个布局
		void removeLayout(const char* name);
		// 获取布局
		Layout* getLayout(const char* name);
		// 移除所有布局
		void removeAllLayouts();
	private:
		std::map<std::string, Layout*> _layoutStack;
	};
}