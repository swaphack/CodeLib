#pragma once

namespace render
{
	// ��Դ���ؽӿ�
	class IResourceLoader
	{
	public:
		virtual ~IResourceLoader(){}
	public:
		virtual void load(const std::string& filename) = 0;
	};
}