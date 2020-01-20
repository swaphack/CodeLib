#pragma once

#include "Stream.h"
#include "StreamReader.h"
#include "StreamWriter.h"

namespace sys
{
	// 文件流
	class FileStream : public Stream
	{
	public:
		FileStream();
		FileStream(const std::string& filepath);
		virtual ~FileStream();
	public:
		// 加载文件
		void load(const std::string& filepath);
		// 保存文件
		void save(const std::string& filepath);
	};
}