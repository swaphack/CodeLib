#pragma once

#include "FrameBufferNode.h"

namespace render
{
	class Texture2D;

	/**
	*	��Ӱ
	*	��������Ƶ���Դ�����գ��������ͼ
	*	�ٽ����ɵ����ͼͶӰ��Ŀ��
	*/
	class ShadowMapping : public FrameBufferNode
	{
	public:
		ShadowMapping();
		virtual ~ShadowMapping();
	public:
		virtual bool init();
	public:
		virtual void beginRecord();
		virtual void endRecord();
	public:
		virtual void afterDrawNode();
	protected:
		void updateShadowMapping();
	private:
		/**
		*	��������
		*/
		Texture2D* _texture = nullptr;
	};
}