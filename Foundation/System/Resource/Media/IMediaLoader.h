#pragma once

#include <string>
namespace sys
{
	// ���ض�ý��ӿ�
	class IMediaLoader
	{
	public:
		virtual ~IMediaLoader() {}
	public:
		virtual bool load(const std::string& filepath) = 0;
	};
}