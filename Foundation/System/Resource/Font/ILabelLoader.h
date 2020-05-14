#pragma once

namespace sys
{
	struct TextDefine;

	// 加载文本接口
	class ILabelLoader
	{
	public:
		virtual ~ILabelLoader() {}
	public:
		virtual bool load(const TextDefine& textDefine) = 0;
	};
}