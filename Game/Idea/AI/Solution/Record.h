#pragma once

#include "macros.h"
#include "system.h"
#include <string>

namespace idea
{
	// 记录事件
	class Record : public Event
	{
	public:
		Record();
		virtual ~Record();
	public:
		// 获取记录创建日期
		const sys::Time* getTime();
		// 设置记录创建日期
		void setTime(sys::Time* time);
		// 获取记录内容
		const char* getText();
		// 设置记录内容
		void setText(const char* text);
		// 获取记录标识等级
		int getLevel();
		// 设置记录标识等级
		void setLevel(int level);
	private:
		// 时间
		sys::Time _time;
		// 文本
		std::string _text;
		// 级别
		int _level;
	};
}