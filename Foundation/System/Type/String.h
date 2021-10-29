#pragma once

#include <string>
#include <vector>
#include <cstdint>

namespace sys
{
	class MemoryData;

	// �ַ�������'\0'��β
	class String
	{
	public:
		String();
		String(const String& value);
		String(const std::string& value);
		String(const char* value, size_t count);
		String(const char* value, int32_t count);
		~String();
	public:
		// ��ֵ
		String& operator=(const String& value);
		String& operator=(const std::string& value);

		String operator+(const String& value);
		String operator+(const std::string& value);

		// ��ȡ�������ַ�
		char operator[](size_t index) const;
		char& at(size_t index) const;

		// β��׷���ַ�
		void append(size_t count, char value);
		// β��׷���ַ���
		void append(size_t count, const std::string& value);
		// �滻ָ�����ַ�
		String replace(char spot, const std::string& value);
		// �滻ָ�����ַ���
		String replace(const std::string& spot, const std::string& value);

		// ƴ��
		String& concat(const std::string& value);
		String& concat(const std::string& value1, const std::string& value2);
		String& concat(const std::string& value1, const std::string& value2, const std::string& value3);

		// �Ƿ����
		bool contains(const std::string& value) const;

		// �Ƚ����ַ����Ƿ���ͬ
		bool compare(const std::string& value) const;
		bool compare(size_t offset, const std::string& value) const;
		bool compare(size_t offset, const std::string& value, size_t count) const;
		// ��ָ���ַ�����β
		bool endWith(const std::string& value) const;
		// ��ָ���ַ�����ͷ
		bool startWith(const std::string& value) const;
		// �Ƴ���ָ��λ�ÿ�ʼ��һ���ַ���
		String& removeAt(size_t offset);
		// �Ƴ���ָ��λ�ÿ�ʼ��һ���ַ���
		String& remove(size_t offset, size_t count);
		// �����ַ���
		String& insert(size_t offset, const std::string& value);
		// �Ƴ���ָ��λ�ÿ�ʼ��һ�ι̶����ȵ��ַ���
		String subString(size_t offset, size_t count);
		// �Ƴ���ָ��λ�ÿ�ʼ��һ���ַ���
		String subString(size_t offset);

		// ��ʼλ�ò���ƥ���ַ�������λ��
		int32_t findFirstOf(char value) const;
		// ��ʼλ�ò���ƥ���ַ���������λ��
		int32_t findFirstOf(const std::string& value) const;
		// ����λ�ò���ƥ���ַ�������λ��
		int32_t findLastOf(char value) const;
		// ����λ�ò���ƥ���ַ�������λ��
		int32_t findLastOf(const std::string& value) const;
		// �Ƿ��Ǿ���
		bool isLine() const;

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
	public:
		// ��ʽ��
		static std::string makeCString(const char* format, ...);
		// ��ʽ��
		static String makeString(const char* format, ...);
	public:
		// �ָ�
		void split(char spot, std::vector<String>& dest);
		// �ָ�
		void split(const std::string& spot, std::vector<String>& dest);
		// �ָ�
		void split(char spot, std::vector<std::string>& dest);
		// �ָ�
		void split(const std::string& spot, std::vector<std::string>& dest);
		// �Ƿ�����Ϊ��
		bool empty() const;
		// ��ת
		String reverse();

		// ��ȡ�ַ�������
		const char* getString() const;

		char* getString();
		// ��ȡ�ַ�������
		size_t getSize() const;
	protected:
		void initString(size_t size, const char* value);
		static void allocString(size_t size, MemoryData& data);
	private:
		MemoryData* _data = nullptr;
	};
}
