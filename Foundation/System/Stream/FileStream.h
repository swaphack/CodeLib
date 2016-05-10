#pragma once

#include "Stream.h"
#include "StreamReader.h"
#include "StreamWriter.h"

namespace sys
{
	// �ļ���
	class FileStream : public Stream
	{
	public:
		FileStream();
		FileStream(const char* filepath);
		virtual ~FileStream();
	public:
		// ������������
		virtual void setData(const char* data, ss_t size);
		// �����ļ�
		void load(const char* filepath);
		// �����ļ�
		void save(const char* filepath);
	private:
	};
}