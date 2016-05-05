#pragma once

#include "Property.h"

namespace tribe
{
	// 工作
	class Job
	{
	public:
		Job();
		virtual ~Job();
	public:
		// 获取职业类型
		inline int getProfession() const { return _profession; }
		// 设置职业类型
		inline void setProfession(int val) { _profession = val; }
		// 获取工作开始时间
		inline int getBeginTime() const { return _beginTime; }
		// 设置工作开始时间
		inline void setBeginTime(int val) { _beginTime = val; }
		// 获取工作结束时间
		inline int getEndTime() const { return _endTime; }
		// 设置工作结束时间
		inline void setEndTime(int val) { _endTime = val; }

		// 获取工作等级
		inline int getLevel() const { return _level; }
		// 设置工作等级
		inline void setLevel(int val) { _level = val; }
		// 获取工作经验
		inline int getExp() const { return _exp; }
		// 设置工作经验
		inline void setExp(int val) { _exp = val; }
	protected:
	private:
		// 职业类型
		int _profession;
		// 属性
		Property* _property;
		// 工作开始时间
		int _beginTime;
		// 工作结束时间
		int _endTime;
		// 等级
		int _level;
		// 经验
		int _exp;
	};
}