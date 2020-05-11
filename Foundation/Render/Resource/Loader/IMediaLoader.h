#pragma once

namespace render
{
	struct MediaDefine;

	// 加载多媒体接口
	class IMediaLoader
	{
	public:
		virtual ~IMediaLoader() {}
	public:
		virtual bool load(const MediaDefine& mediaDefine) = 0;
	};
}