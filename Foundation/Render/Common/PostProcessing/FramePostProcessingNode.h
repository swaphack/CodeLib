#pragma once

#include "Common/DrawNode/DrawNode.h"
#include "Common/struct/shape_common.h"
namespace render
{
	class Texture2D;
	class FrameBuffer;
	class RenderBuffer;

	/**
	*	֡������ڴ���
	*	��������
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
	protected:
		void updateTextureSize();
	private:
		/**
		*	��������
		*/
		Texture2D* _texture = nullptr;
		/**
		*	֡����
		*/
		FrameBuffer* _frameBuffer = nullptr;
		/**
		*	��Ⱦ����
		*/
		RenderBuffer* _renderBuffer = nullptr;
		/**
		*	�Ƿ��ʼ������
		*/
		bool _bInitedFrameBufferData = false;
		// ���ο�
		RectVectices _rectVertex;
	};
}
