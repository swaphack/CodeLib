#pragma once

namespace render
{
	struct TextDefine;

	// 加载文本接口
	class ILabelLoader
	{
	public:
		virtual ~ILabelLoader() {}
	public:
		virtual void load(const TextDefine& textDefine) = 0;
	};
}