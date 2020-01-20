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
		FileStream(const std::string& filepath);
		virtual ~FileStream();
	public:
		// �����ļ�
		void load(const std::string& filepath);
		// �����ļ�
		void save(const std::string& filepath);
	};
}