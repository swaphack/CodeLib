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
	// Ŀ¼
	class Content
	{
	public:
		Content();
		~Content();
	public:
		// ��ȡָ����ǩ������Ŀ��
		std::set<Target*>* getTargetsByKey(const char* key);
		// ��ȡָ������Ŀ��ı�ǩ
		std::set<std::string*>* getKeysByTarget(Target* target);

		// Ϊ��ǩ����µ�����Ŀ��
		void addNewKeyTarget(const char* key, Target* target);
		// �Ƴ�����Ŀ��ı�ǩ
		void removeTargetsKey(Target* target, const char* key);
		// �Ƴ���ǩ�Ĺؼ���
		void removeKeysTarget(const char* key, Target* target);
		// ���һ���µ�����Ŀ��
		void addTarget(Target* target);
		// �Ƴ�������Ŀ��
		void removeTarget(Target* target);
		// ���һ���µı�ǩ
		void addKey(const char* key);
		// �Ƴ��ı�ǩ
		void removeKey(const char* key);

		// ΪĿ�����һ����ǩ
		void addKeyToTarget(Target* target, const char* key);
		// �Ƴ�Ŀ��ı�ǩ
		void removeKeyFromTarget(Target* target, const char* key);
		// Ϊ��ǩ���һ��Ŀ��
		void addTargetToKey(const char* key, Target* target);
		// �Ƴ���ǩ��Ŀ��
		void removeTargetFromKey(const char* key, Target* target);		
		// �Ƴ����е�����Ŀ��
		void removeAllTargets();
	private:
		// ��ǩ��Ӧ����Ŀ�꼯��key->targets��
		std::map<std::string*, std::set<Target*>> _keyTargets;

		// ����Ŀ��ı�ǩ����target->keys��
		std::map<Target*, std::set<std::string*>> _targetKeys;
	};
}