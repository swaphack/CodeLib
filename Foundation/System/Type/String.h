#pragma once

#include "Base/import.h"

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
		String(const char* value, int32 count);
		~String();
	public:
		// ��ֵ
		String& operator=(const String& value);
		String& operator=(const std::string& value);
		String& operator=(const char* value);

		String operator+(const String& value);
		String operator+(const std::string& value);
		String operator+(const char* value);

		// ��ȡ�������ַ�
		char operator[](int32 index);
		char& at(int32 index);

		// β��׷���ַ�
		void append(int32 count, char value);
		// β��׷���ַ���
		void append(int32 count, char* value);
		// �滻ָ�����ַ�
		String replace(char spot, char* value);
		// �滻ָ�����ַ���
		String replace(char* spot, char* value);

		// ƴ��
		String& concat(const char* value);
		String& concat(const char* value1, const char* value2);
		String& concat(const char* value1, const char* value2, const char* value3);

		// �Ƿ����
		bool contains(const char* value);

		// �Ƚ����ַ����Ƿ���ͬ
		bool compare(const char* value);
		bool compare(int32 offset, const char* value);
		bool compare(int32 offset, const char* value, int32 count);
		// ��ָ���ַ�����β
		bool endWith(const char* value);
		// ��ָ���ַ�����ͷ
		bool startWith(const char* value);
		// �Ƴ���ָ��λ�ÿ�ʼ��һ���ַ���
		String& remove(int32 offset, int32 count);
		// �����ַ���
		String& insert(int32 offset, const char* value);
		// �Ƴ���ָ��λ�ÿ�ʼ��һ���ַ���
		String subString(int32 offset, int32 count);

		// ��ʼλ�ò���ƥ���ַ�������λ��
		int32 findFirstOf(char value);
		// ��ʼλ�ò���ƥ���ַ���������λ��
		int32 findFirstOf(const char* value);
		// ����λ�ò���ƥ���ַ�������λ��
		int32 findLastOf(char value);
		// ����λ�ò���ƥ���ַ�������λ��
		int32 findLastOf(const char* value);
		// �Ƿ��Ǿ���
		bool isLine();

		// ȥ�����пո�
		String trim();
		// ȥ����߿ո�
		String trimLeft();
		// ȥ���ұ߿ո�
		String trimRight();

		// תСд
		String toLower();
		// ת��д
		String toUpper();

		// ��ʽ��
		String& make(const char* format, ...);
		// �ָ�
		void split(char spot, std::vector<String>& dest);
		// �ָ�
		void split(const char* spot, std::vector<String>& dest);
		// �ָ�
		void split(char spot, std::vector<std::string>& dest);
		// �ָ�
		void split(const char* spot, std::vector<std::string>& dest);
		// �Ƿ�����Ϊ��
		bool empty();
		// ��ת
		String reverse();

		// ��ȡ�ַ�������
		const char* getString() const;
		// ��ȡ�ַ�������
		int32 getSize() const;
	private:
		// ����
		char* _value;
		// ����
		int32 _size;
	};
}