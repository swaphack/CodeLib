#pragma once

#include <string>
#include <cstdint>

#include "Memory/MemoryData.h"

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
		File(const std::string& url);
		File(const std::string& url, uint32_t mode);
		~File();
	public:
		// ������д������
		static bool write(const std::string& url, const char* data, size_t size, size_t& writtenSize);
		// �ӱ��ض�ȡ����
		static MemoryData read(const std::string& url, size_t& readSize);
		// �ӱ��ض�ȡ����
		static bool read(const std::string& url, std::string& data);
		// ׷�����ݵ�����
		static bool append(const std::string& url, const char* data, size_t size, size_t& appendSize);
		// �ж��ļ��Ƿ����
		static bool exists(const std::string& url);
	public:
		bool open();
		// ������д������
		bool write(const char* data, size_t size, size_t& writtenSize);
		// �ӱ��ض�ȡ����
		MemoryData read(size_t& size);
		// �ӱ��ض�ȡ����
		bool read(std::string& data);
		// ׷�����ݵ�����
		bool append(const char* data, size_t size);
		// �ж��ļ��Ƿ����
		bool exists();
		// �ر�
		bool close();
	private:
		// �ļ�Ŀ¼
		std::string m_strUrl;
		// ���id
		FILE* m_pFile = nullptr;
		// ģʽ
		uint32_t m_nModel = 0;
	};
}