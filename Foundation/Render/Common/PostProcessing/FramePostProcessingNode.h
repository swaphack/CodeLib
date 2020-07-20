#pragma once

#include "Common/DrawNode/DrawNode.h"
#include "Common/struct/shape_common.h"
namespace render
{
	class Texture2D;
	class FrameBuffer;
	class RenderBuffer;

	/**
	*	帧缓存后期处理
	*	需要设置监视大小
	*/
	class FramePostProcessingNode : public DrawNode
	{
	public:
		FramePostProcessingNode();
		virtual ~FramePostProcessingNode();
	public:
		virtual bool init();

		virtual void drawNode();

		virtual void beforeDrawNode();

		//virtual void onDraw();

		virtual void afterDrawNode();

		bool isFrameInited();
	public:
		void beginRecord();

		void endRecord();
	protected:
		void updateTextureSize();
	private:
		/**
		*	界面纹理
		*/
		Texture2D* _texture = nullptr;
		/**
		*	帧缓存
		*/
		FrameBuffer* _frameBuffer = nullptr;
		/**
		*	是否初始化数据
		*/
		bool _bInitedFrameBufferData = false;
		// 矩形框
		RectVectices _rectVertex;
	};
}
