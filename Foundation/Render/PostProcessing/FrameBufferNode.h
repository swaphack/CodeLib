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
		*	�Ƿ��ʼ��
		*/
		bool isInitedFBN();
	public:
		/**
		*	��ʼ��¼
		*/
		virtual void beginRecord();
		/**
		*	������¼
		*/
		virtual void endRecord();
	protected:
		/**
		*	֡����
		*/
		FrameBuffer* _frameBuffer = nullptr;
		/**
		*	�Ƿ��ʼ������
		*/
		bool _bInitedFBN = false;
	};
}