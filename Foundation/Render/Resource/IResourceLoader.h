#pragma once

#include "struct_common.h"

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

	// 加载文本接口
	class ILabelLoader
	{
	public:
		virtual ~ILabelLoader() {}
	public:
		virtual void load(const TextDefine& textDefine) = 0;
	};

	// 加载多媒体
	class IMediaLoader
	{
	public:
		virtual ~IMediaLoader() {}
	public:
		virtual void load(const MediaDefine& mediaDefine) = 0;
	};
}