#pragma once

#include <string>

namespace sys
{
	// ��Դ���ؽӿ�
	class IImageLoader
	{
	public:
		virtual ~IImageLoader(){}
	public:
		virtual bool load(const std::string& filename) = 0;
	};
}