#pragma once

namespace render
{
	// ��Դ���ؽӿ�
	class IResourceLoader
	{
	public:
		virtual ~IResourceLoader(){}
	public:
		virtual void load(const char* filename) = 0;
	};
}