#pragma once

#include "../Base/import.h"

#include <string>
#include <vector>

namespace sys
{
	// �ַ�������'\0'��β
	class String
	{
	public:
		String();
		String(const String& value);
		String(const std::string& value);
		String(const char* value);
		String(const char* value, int count);
		virtual ~String();
	public:
		// ��ֵ
		virtual String& operator=(const String& value);
		virtual String& operator=(const std::string& value);
		virtual String& operator=(const char* value);

		virtual String operator+(const String& value);
		virtual String operator+(const std::string& value);
		virtual String operator+(const char* value);

		// ƴ��
		virtual String& concat(const char* value);
		virtual String& concat(const char* value1, const char* value2);
		virtual String& concat(const char* value1, const char* value2, const char* value3);

		// �Ƿ����
		bool contains(const char* value);

		// �Ƚ����ַ����Ƿ���ͬ
		bool compare(const char* value);
		bool compare(int offset, const char* value);
		bool compare(int offset, const char* value, int count);
		// ��ָ���ַ�����β
		bool endWith(const char* value);
		// ��ָ���ַ�����ͷ
		bool startWith(const char* value);
		// ��ȡ�������ַ�
		virtual char operator[](int index);
		// �Ƴ���ָ��λ�ÿ�ʼ��һ���ַ���
		String& remove(int offset, int count);
		// �����ַ���
		String& insert(int offset, const char* value);
		// �Ƴ���ָ��λ�ÿ�ʼ��һ���ַ���
		String subString(int offset, int count);

		// ��ʼλ�ò���ƥ���ַ�������λ��
		int findFirstOf(char value);
		// ��ʼλ�ò���ƥ���ַ���������λ��
		int findFirstOf(const char* value);
		// ����λ�ò���ƥ���ַ�������λ��
		int findLastOf(char value);
		// ����λ�ò���ƥ���ַ�������λ��
		int findLastOf(const char* value);
		// �Ƿ��Ǿ���
		bool isLine();

		// ȥ���ո�
		String& trim();
		// ȥ����߿ո�
		String& trimLeft();
		// ȥ���ұ߿ո�
		String& trimRight();

		// ��ʽ��
		String& make(const char* format, ...);
		// �ָ�
		void split(char spot, std::vector<String>& dest);
		// �ָ�
		void split(const char* spot, std::vector<String>& dest);
		// �Ƿ�����Ϊ��
		bool empty();

		// ��ȡ�ַ�������
		const char* getString() const;
		// ��ȡ�ַ�������
		int getSize() const;
	private:
		// ����
		char* _value;
		// ����
		int _size;
	};
}