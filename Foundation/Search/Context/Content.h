#pragma once

#include <string>
#include <map>
#include <set>
#include <vector>

#include "../Target/import.h"


namespace search
{
	// 目录
	class Content
	{
	public:
		Content();
		~Content();
	public:
		void addTarget(const char* key, Target* target);
		void removeTarget(const char* key);
		Target* findTarget(const char* key);
		// 移除所有的搜索目标
		void removeAllTargets();
	private:
		// 标签对应搜索目标集（key->targets）
		std::map<std::string*, Target*> _targets;
	};
}