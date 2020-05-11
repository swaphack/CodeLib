#pragma once

#include <string>

namespace render
{
	// ��Դ���ؽӿ�
	class IResourceLoader
	{
	public:
		virtual ~IResourceLoader(){}
	public:
		virtual bool load(const std::string& filename) = 0;
	};
}