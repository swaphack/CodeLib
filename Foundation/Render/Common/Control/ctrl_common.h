#pragma once

#include "../Node/import.h"

#include "../Touch/import.h"

#include "../Keyboard/import.h"

#include "../macros.h"

namespace render
{
	//---------------------枚举---------------------
	// 六个面
	enum ModelFace
	{
		EMF_FRONT,		// 前面
		EMF_BACK,		// 背面
		EMF_LEFT,		// 左面
		EMF_RIGHT,		// 右面
		EMF_TOP,		// 上面
		EMF_BOTTOM,		// 下面
	};

	// 水平对齐方式
	enum HorizontalAlignment
	{
		EHA_LEFT,		// 左对齐
		EHA_CENTER,		// 居中对齐
		EHA_RIGHT,		// 右对齐
	};

	// 垂直对齐方式
	enum VerticalAlignment
	{
		EVA_TOP,		// 顶对齐
		EVA_CENTER,		// 居中对齐
		EVA_BOTTOM,		// 底对齐
	};

	//---------------------结构---------------------
	// 控件图片数据描述结构
	struct Ctrl_ImageDefine : public ImageDefine
	{
		Ctrl_ImageDefine()
		{}
	};

	// 控件图片数据描述结构
	struct Ctrl_TextDefine : public TextDefine
	{
		// 水平对齐方式
		HorizontalAlignment horizontalAlignment;
		// 垂直对齐方式
		VerticalAlignment verticalAlignment;

		Ctrl_TextDefine()
			: horizontalAlignment(EHA_CENTER)
			, verticalAlignment(EVA_CENTER)
		{}
	};
}