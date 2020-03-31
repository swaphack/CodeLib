#pragma once

#include <string>
#include <functional>

namespace sys
{
	class IResource
	{
	public:
		typedef std::function<void(const std::string&)> GetDataCallback;
	public:
		virtual ~IResource() {}
	public:
		// �����ļ�����
		virtual bool loadFileData(const std::string& filename, GetDataCallback handler) = 0;
	};
}