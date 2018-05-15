#pragma once

#include "Cache/import.h"
#include <functional>

namespace sys
{
	class IResource
	{
	public:
		typedef std::function<void(std::string&)> GetDataCallback;
	public:
		virtual ~IResource() {}
	public:
		// �����ļ�����
		virtual bool loadFileData(const char* filename, GetDataCallback handler) = 0;
	};
}