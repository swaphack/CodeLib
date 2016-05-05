#pragma once

#include <map>

namespace render
{
	// ��ͼ����ö��
	enum ViewSetting
	{
		EVS_NONE,
	};
	// ��ͼ����
	class ViewConfig
	{
	public:
		ViewConfig();
		~ViewConfig();
	public:
		// ����
		void reset();
		// Ӧ��
		void apply();

		void addSetting(ViewSetting vs, int mark);
	private:
		// ����
		std::map<int, int> _settings;
	};
}