#pragma once

#include "Common/DrawNode/DrawNode2D.h"
#include "Common/struct/shape_common.h"

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

		virtual void drawNode();

		virtual void beforeDrawNode();

		virtual void afterDrawNode();

		bool isInitedNode();
	public:
		virtual void beginRecord();

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