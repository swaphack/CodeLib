#pragma once

#include "FrameBufferNode.h"

namespace render
{
	class Texture2D;

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
		virtual void beginRecord();
		virtual void endRecord();
	public:
		virtual void afterDrawNode();
	protected:
		void updateShadowMapping();
	private:
		/**
		*	界面纹理
		*/
		Texture2D* _texture = nullptr;
	};
}