#pragma once

#include <map>
#include <string>
#include <vector>

namespace script
{
	// ���ʼ���
	class WordSet
	{
	private:
		WordSet();
	public:
		~WordSet();
	public:
		static WordSet* getInstance();
		/**
		*	���һ������
		*	@param name ��������
		*/
		void appendWord(const char* name);
		/**
		*	�ж��Ƿ�����ĵ���
		*	@param name ��������
		*/
		bool containWord(const char* name);
		/**
		*	���ַ�ͷ��ʼ���ж��Ƿ��������
		*	�ɹ����ص��ʳ��ȣ�ʧ�ܷ���-1
		*	@param name ����
		*	@param offset ���ʳ���
		*/
		bool pickWord(const char* name, int& offset);
		/**
		*	������е���
		*/
		void clear();
	private:
		typedef std::map<int,std::vector<std::string> > WordMap;
		WordMap m_mWords;
	};
}