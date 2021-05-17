#pragma once

#include "FrameBufferNode.h"

namespace render
{
	class Texture2D;
	class ShaderProgram;
	class Light;
	class Scene;

	/**
	*	阴影
	*	将摄像机移到光源，拍照，生成深度图
	*	再将生成的深度图投影到目标
	*/
	class ShadowMapping : public FrameBufferNode
	{
	public:
		ShadowMapping();
		virtual ~ShadowMapping();
	public:
		virtual bool init();
	public:
		// 开始产生阴影
		void beginCastShadow(Node* light, Scene* root, const std::set<Node*>& castShadowNodes);
		// 开始渲染阴影
		void beginRenderShadow();
	protected:
		void updateShadowMapping();
	private:
		/**
		*	界面纹理
		*/
		Texture2D* _texture = nullptr;
		/**
		*	隐藏节点，不生成阴影
		*/
		std::set<Node*> _setHideNode;
		
	};
}