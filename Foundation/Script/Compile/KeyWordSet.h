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
		/**
		*	���һ���ؼ���
		*	@param name �ؼ�������
		*/
		void appendKeyWord(const char* name);
		/**
		*	�ж��Ƿ�����Ĺؼ���
		*	@param keyword �����
		*/
		bool containKeyWord(const char* name);
		/**
		*	������йؼ���
		*/
		void clear();
	protected:
		void init();
	private:
		typedef std::vector<std::string> Words;
		// �ؼ���
		Words m_vKeyWords;
	};
}