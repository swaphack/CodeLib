#pragma once

#include "FrameBufferNode.h"

namespace render
{
	class Texture2D;
	class ShaderProgram;
	class Light;
	class Scene;

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
		// ��ʼ������Ӱ
		void beginCastShadow(Node* light, Scene* root, const std::set<Node*>& castShadowNodes);
		// ��ʼ��Ⱦ��Ӱ
		void beginRenderShadow();
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