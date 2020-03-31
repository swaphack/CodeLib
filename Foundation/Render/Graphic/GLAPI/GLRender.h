#pragma once

#include "macros.h"
namespace render
{
	/**
	*	��Ⱦ
	*/
	class GLRender
	{
	public:
		/**
		*	������Ⱦ��ʽ
		*/
		static void setRenderMode(RenderingMode mode);
	public:
		/**
		*	���ó���Ⱦ�� Ĭ��
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