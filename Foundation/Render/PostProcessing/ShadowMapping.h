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
		virtual void beforeDrawNode();
		virtual void draw();
		virtual void afterDrawNode();
	protected:
		void updateShadowMapping();
	private:
		/**
		*	��������
		*/
		Texture2D* _texture = nullptr;
		/**
		*	���ؽڵ㣬��������Ӱ
		*/
		std::set<Node*> _setHideNode;
	};
}