#pragma once

#include "Common/DrawNode/DrawNode2D.h"

namespace render
{
	class FrameBuffer;

	class FrameBufferNode : public DrawNode2D
	{
	public:
		FrameBufferNode();
		virtual ~FrameBufferNode();
	public:
		virtual bool init();
	public:
		virtual void drawNode();

		virtual void beforeDrawNode();

		virtual void afterDrawNode();
	public:
		/**
		*	是否初始化
		*/
		bool isInitedFBN();
	public:
		/**
		*	开始记录
		*/
		virtual void beginRecord();
		/**
		*	结束记录
		*/
		virtual void endRecord();
	protected:
		/**
		*	帧缓存
		*/
		FrameBuffer* _frameBuffer = nullptr;
		/**
		*	是否初始化数据
		*/
		bool _bInitedFBN = false;
	};
}