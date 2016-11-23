#pragma once

namespace render
{
	struct MediaDefine;

	// ���ض�ý��ӿ�
	class IMediaLoader
	{
	public:
		virtual ~IMediaLoader() {}
	public:
		virtual void load(const MediaDefine& mediaDefine) = 0;
	};
}