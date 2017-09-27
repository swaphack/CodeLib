#pragma once

#include "Cache/import.h"

namespace sys
{
	class IResource
	{
	public:
		virtual ~IResource() {}
	public:
		// �����ļ�����
		virtual bool loadFileData(const char* filename, std::string& data) = 0;
	};
}