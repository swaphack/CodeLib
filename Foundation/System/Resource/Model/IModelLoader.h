#pragma once

#include <string>

namespace sys
{
	// ��Դ���ؽӿ�
	class IModelLoader
	{
	public:
		virtual ~IModelLoader(){}
	public:
		virtual bool load(const std::string& filename) = 0;
	};
}