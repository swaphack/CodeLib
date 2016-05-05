#pragma once

#include <string>
#include <map>
#include <set>
#include <vector>

#include "../Target/import.h"


template<>
struct std::less<search::Target*>
{
	bool operator()( search::Target*_X, search::Target* _Y) const
	{
		return _X->getString() < _Y->getString();
	}
};


namespace search
{
	// 目录
	class Content
	{
	public:
		Content();
		~Content();
	public:
		// 获取指定标签的搜索目标
		std::set<Target*>* getTargetsByKey(const char* key);
		// 获取指定搜索目标的标签
		std::set<std::string*>* getKeysByTarget(Target* target);

		// 为标签添加新的搜索目标
		void addNewKeyTarget(const char* key, Target* target);
		// 移除搜索目标的标签
		void removeTargetsKey(Target* target, const char* key);
		// 移除标签的关键字
		void removeKeysTarget(const char* key, Target* target);
		// 添加一个新的搜索目标
		void addTarget(Target* target);
		// 移除的搜索目标
		void removeTarget(Target* target);
		// 添加一个新的标签
		void addKey(const char* key);
		// 移除的标签
		void removeKey(const char* key);

		// 为目标添加一个标签
		void addKeyToTarget(Target* target, const char* key);
		// 移除目标的标签
		void removeKeyFromTarget(Target* target, const char* key);
		// 为标签添加一个目标
		void addTargetToKey(const char* key, Target* target);
		// 移除标签的目标
		void removeTargetFromKey(const char* key, Target* target);		
		// 移除所有的搜索目标
		void removeAllTargets();
	private:
		// 标签对应搜索目标集（key->targets）
		std::map<std::string*, std::set<Target*>> _keyTargets;

		// 搜索目标的标签集（target->keys）
		std::map<Target*, std::set<std::string*>> _targetKeys;
	};
}