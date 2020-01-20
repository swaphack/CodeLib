#pragma once

#include <string>
#include <vector>
#include <cstdint>

namespace sys
{
	// �ַ�������'\0'��β
	class String
	{
	public:
		String();
		String(const String& value);
		String(const std::string& value);
		String(const char* value, int32_t count);
		~String();
	public:
		// ��ֵ
		String& operator=(const String& value);
		String& operator=(const std::string& value);

		String operator+(const String& value);
		String operator+(const std::string& value);

		// ��ȡ�������ַ�
		char operator[](int32_t index);
		char& at(int32_t index);

		// β��׷���ַ�
		void append(int32_t count, char value);
		// β��׷���ַ���
		void append(int32_t count, const std::string& value);
		// �滻ָ�����ַ�
		String replace(char spot, const std::string& value);
		// �滻ָ�����ַ���
		String replace(const std::string& spot, const std::string& value);

		// ƴ��
		String& concat(const std::string& value);
		String& concat(const std::string& value1, const std::string& value2);
		String& concat(const std::string& value1, const std::string& value2, const std::string& value3);

		// �Ƿ����
		bool contains(const std::string& value);

		// �Ƚ����ַ����Ƿ���ͬ
		bool compare(const std::string& value);
		bool compare(int32_t offset, const std::string& value);
		bool compare(int32_t offset, const std::string& value, int32_t count);
		// ��ָ���ַ�����β
		bool endWith(const std::string& value);
		// ��ָ���ַ�����ͷ
		bool startWith(const std::string& value);
		// �Ƴ���ָ��λ�ÿ�ʼ��һ���ַ���
		String& remove(int32_t offset, int32_t count);
		// �����ַ���
		String& insert(int32_t offset, const std::string& value);
		// �Ƴ���ָ��λ�ÿ�ʼ��һ���ַ���
		String subString(int32_t offset, int32_t count);

		// ��ʼλ�ò���ƥ���ַ�������λ��
		int32_t findFirstOf(char value);
		// ��ʼλ�ò���ƥ���ַ���������λ��
		int32_t findFirstOf(const std::string& value);
		// ����λ�ò���ƥ���ַ�������λ��
		int32_t findLastOf(char value);
		// ����λ�ò���ƥ���ַ�������λ��
		int32_t findLastOf(const std::string& value);
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
		void split(const std::string& spot, std::vector<String>& dest);
		// �ָ�
		void split(char spot, std::vector<std::string>& dest);
		// �ָ�
		void split(const std::string& spot, std::vector<std::string>& dest);
		// �Ƿ�����Ϊ��
		bool empty();
		// ��ת
		String reverse();

		// ��ȡ�ַ�������
		const char* getString() const;
		// ��ȡ�ַ�������
		int32_t getSize() const;
	private:
		// ����
		char* _value;
		// ����
		int32_t _size;
	};
}