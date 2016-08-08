#pragma once

#include <string>
#include <map>
#include <set>
#include <vector>

#include "../Target/import.h"


namespace search
{
	// Ŀ¼
	class Content
	{
	public:
		Content();
		~Content();
	public:
		void addTarget(const char* key, Target* target);
		void removeTarget(const char* key);
		Target* findTarget(const char* key);
		// �Ƴ����е�����Ŀ��
		void removeAllTargets();
	private:
		// ��ǩ��Ӧ����Ŀ�꼯��key->targets��
		std::map<std::string*, Target*> _targets;
	};
}