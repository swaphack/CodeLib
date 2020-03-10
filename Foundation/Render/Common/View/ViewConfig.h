#pragma once

#include <map>

namespace render
{
	// 视图设置枚举
	enum ViewSetting
	{
		EVS_NONE,
	};
	// 视图配置
	class ViewConfig
	{
	public:
		ViewConfig();
		~ViewConfig();
	public:
		// 重置
		void reset();
		// 添加配置参数
		void addSetting(ViewSetting vs, int mark);
	private:
		// 设置
		std::map<int, int> _settings;
	};
}