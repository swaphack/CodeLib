#pragma once

#ifdef USE_STRING


#include "../Base/import.h"

#include <vector>

namespace sys
{
	class String
	{
	public:
		String(const char* value);
		~String();
	public:
		// ��ֵ
		virtual String& operator=(const char* value);
		// ƴ��
		virtual String& concat(const char* value);

		// �Ƚ����ַ����Ƿ���ͬ
		bool compare(const char* value);
		// ��ָ���ַ�����β
		bool endWith(const char* value);
		// ��ָ���ַ�����ͷ
		bool startWith(const char* value);
		// ��ȡ�������ַ�
		virtual char operator[](uint index);
		// �Ƴ���ָ��λ�ÿ�ʼ��һ���ַ���
		String& remove(int offset, int count);
		// �����ַ���
		String& insert(int offset, const char* value);
		// �Ƴ���ָ��λ�ÿ�ʼ��һ���ַ���
		String subString(int offset, int count);

		// ȥ���ո�
		String& trim();
		// ȥ����߿ո�
		String& trimLeft();
		// ȥ���ұ߿ո�
		String& trimRight();

		// ��ʽ��
		String& format(const char* format, ...);
		// �ָ�
		void split(char spot, std::vector<String>& dest);

		// ��ȡ�ַ�������
		const char* getString();
		// ��ȡ�ַ�������
		uint getSize();
	protected:
	private:
		char* _value;
		uint _size;
	};
}

#endif