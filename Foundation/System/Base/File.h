#pragma once

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
		static void write(const char* url, const char* data, long size);
		// �ӱ��ض�ȡ����
		static char* read(const char* url, long& size);
		// �ж��ļ��Ƿ����
		static bool isExistsFile(const char* url);
	};
}