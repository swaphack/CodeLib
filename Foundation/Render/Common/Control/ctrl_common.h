#pragma once

#include "../Node/import.h"

namespace render
{
	//---------------------枚举---------------------

	// 雾的类型
	enum FogMode
	{
		EFM_EXP = GL_EXP,
		EFM_EXP2 = GL_EXP2,
		EFM_LINEAR = GL_LINEAR,
	};

	// 雾的效果类型
	enum FogEffect
	{
		EFE_DONT_CARE = GL_DONT_CARE,
		EFE_NICEST = GL_NICEST,
		EFE_FASTEST = GL_FASTEST,
	};

	// 光索引
	enum LightIndex
	{
		ELI_NONE,
		ELI_LIGHT0 = GL_LIGHT0,
		ELI_LIGHT1 = GL_LIGHT1,
		ELI_LIGHT2 = GL_LIGHT2,
		ELI_LIGHT3 = GL_LIGHT3,
		ELI_LIGHT4 = GL_LIGHT4,
		ELI_LIGHT5 = GL_LIGHT5,
		ELI_LIGHT6 = GL_LIGHT6,
		ELI_LIGHT7 = GL_LIGHT7,
	};

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
		// 图片格式
		ImageFormat format;

		Ctrl_ImageDefine() 
			:format(EIF_PNG)
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