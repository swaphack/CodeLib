#pragma once

#include <map>

namespace render
{
	// ��ͼ����ö��
	enum class ViewSetting
	{
		NONE,
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
		// ������ò���
		void addSetting(ViewSetting vs, int mark);
	private:
		// ����
		std::map<int, int> _settings;
	};
}