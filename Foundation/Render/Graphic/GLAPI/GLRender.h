#pragma once

#include "macros.h"
namespace render
{
	/**
	*	渲染
	*/
	class GLRender
	{
	public:
		/**
		*	设置渲染样式
		*/
		static void setRenderMode(RenderingMode mode);
	public:
		/**
		*	设置成渲染， 默认
		*/
		static void setRenderMode();
	public:
		static void setSelectMode();
		static void getSelectBuffer(int size, uint32_t* buffer);
	public:// name stack
		static void initNames();
		static void loadName(int name);
		static void pushName(int name);
		static void popName();
	public:
		static void setFeedbackMode();
		static void getFeedBackBuffer(int size, FeedBackMode mode, float* buffer);
		static void setPassThrough(float value);
	};
}