#pragma once

namespace render
{
	struct TextDefine;

	// �����ı��ӿ�
	class ILabelLoader
	{
	public:
		virtual ~ILabelLoader() {}
	public:
		virtual bool load(const TextDefine& textDefine) = 0;
	};
}