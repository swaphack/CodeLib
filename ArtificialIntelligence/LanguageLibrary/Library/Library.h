#pragma once

namespace ll
{
	class Dictionary;
	// ��
	class Library
	{
	public:
		Library();
		~Library();
	public:
		// ��������
		virtual void load(const char* content, int size) = 0;
		// ��ȡ�ֶ�
		Dictionary* getDictionary();
	private:
		Dictionary* _dictionary;
	};
}