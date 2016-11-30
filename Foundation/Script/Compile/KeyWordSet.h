#pragma once

#include <vector>
#include <string>

namespace script
{
	// �ؼ��ּ���
	class KeyWordSet
	{
	private:
		KeyWordSet();
	public:
		~KeyWordSet();
	public:
		static KeyWordSet* getInstance();
		// ׷��һ���ؼ���
		void append(const char* keyword);
		// �ж��Ƿ�����Ĺؼ���,���عؼ��ֿ�ʼλ��
		int contain(const char* keyword);
		// ������йؼ���
		void clear();
	protected:
		void init();
	private:
		typedef std::vector<std::string> Words;
		// �ؼ���
		Words m_vKeyWords;
	};
}