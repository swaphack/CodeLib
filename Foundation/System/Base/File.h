#pragma once

#include <string>

namespace sys
{
	// �ṹ����ֻ�ܱ��泣��������ָ��Ĵ洢�������⣬��Ϊ�洢��ָ��Ŀ���ָ���ַ
	class File
	{
	private:
		File() {}
		~File() {}
	public:
		// ������д������
		static bool write(const char* url, const char* data, long size);
		// �ӱ��ض�ȡ����
		static char* read(const char* url, long& size);
		// �ӱ��ض�ȡ����
		static bool read(const char* url, std::string& data);
		// ׷�����ݵ�����
		static bool append(const char* url, const char* data, long size);
		// �ж��ļ��Ƿ����
		static bool isFileExists(const char* url);
	};
}