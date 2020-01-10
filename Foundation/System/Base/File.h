#pragma once

#include "Base/Types.h"

namespace sys
{
	enum FileModel
	{
		// ��
		eFM_OPEN = 0,
		// ��ȡ
		eFM_READ = 0x0001,
		// д��
		eFM_WRITE = 0x0010,
		// ׷��
		eFM_APPEND = 0x0100,
		// ������
		eFM_BINARY = 0x00010000,
	};
	// �ṹ����ֻ�ܱ��泣��������ָ��Ĵ洢�������⣬��Ϊ�洢��ָ��Ŀ���ָ���ַ
	class File
	{
	public:
		File(const char* url);
		File(const char* url, int32_t mode);
		~File();
	public:
		// ������д������
		static bool write(const char* url, const char* data, int64_t size, int64_t& writtenSize);
		// �ӱ��ض�ȡ����
		static char* read(const char* url, int64_t& readSize);
		// �ӱ��ض�ȡ����
		static bool read(const char* url, std::string& data);
		// ׷�����ݵ�����
		static bool append(const char* url, const char* data, int64_t size, int64_t& appendSize);
		// �ж��ļ��Ƿ����
		static bool exists(const char* url);
	public:
		bool open();
		// ������д������
		bool write(const char* data, int64_t size, int64_t& writtenSize);
		// �ӱ��ض�ȡ����
		char* read(int64_t& size);
		// �ӱ��ض�ȡ����
		bool read(std::string& data);
		// ׷�����ݵ�����
		bool append(const char* data, int64_t size);
		// �ж��ļ��Ƿ����
		bool exists();
		// �ر�
		bool close();
	private:
		// �ļ�Ŀ¼
		std::string m_strUrl;
		// ���id
		FILE* m_pFile;
		// ģʽ
		int32_t m_nModel;
	};
}