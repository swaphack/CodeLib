#pragma once

#include "Concurrent.h"

#include <string>
#include <cstdio>

namespace sys
{
	// �ļ���������
	class ConcurrentFile : public Concurrent
	{
	public:
		ConcurrentFile(const std::string& filepath);
		virtual ~ConcurrentFile();
	private:
		FILE* _fptr;
	};
}