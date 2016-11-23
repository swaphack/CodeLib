#pragma once

namespace render
{
	// 资源加载接口
	class IResourceLoader
	{
	public:
		virtual ~IResourceLoader(){}
	public:
		virtual void load(const char* filename) = 0;
	};
}