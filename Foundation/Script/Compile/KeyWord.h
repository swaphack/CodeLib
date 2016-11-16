#pragma once

#include <set>
#include <string>

namespace script
{
	typedef std::set<std::string> Words;
	// �ؼ���
	class KeyWord
	{
	private:
		KeyWord();
	public:
		~KeyWord();
	public:
		static KeyWord* getInstance();
		// ׷��һ���ؼ���
		void append(const char* keyword);
		// �ж��Ƿ�����Ĺؼ���,���عؼ��ֿ�ʼλ��
		int contain(const char* keyword);
		// ������йؼ���
		void clear();

		inline Words::const_iterator wordBegin(){ return m_sKeyWords.begin(); }
		inline Words::const_iterator wordEnd(){ return m_sKeyWords.end(); }
	protected:
		void init();
	private:
		// �ؼ���
		Words m_sKeyWords;
	};
}