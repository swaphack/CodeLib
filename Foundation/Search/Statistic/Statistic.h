#pragma once

#include <map>
#include <string>

namespace search
{
	// 统计
	class Statistic
	{
	public:
		// 关键字搜索次数
		std::map<std::string, int>	keySearchCounts;
	public:
		// 添加关键字的次数
		void addSearchCount(const std::string& key, int count = 1);
		// 设置官架子的搜索次数
		void setSearchCount(const std::string& key, int count);
	protected:
	private:
	};
}