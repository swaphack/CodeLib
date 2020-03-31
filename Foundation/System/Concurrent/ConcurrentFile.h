#pragma once

#include "Concurrent.h"
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