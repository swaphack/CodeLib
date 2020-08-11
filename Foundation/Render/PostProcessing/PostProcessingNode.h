#pragma once

#include "FrameBufferNode.h"
#include "Common/struct/shape_common.h"
namespace render
{
	class Texture2D;

	/**
	*	帧缓存后期处理
	*	需要设置监视大小
	*/
	class PostProcessingNode : public FrameBufferNode
	{
	public:
		PostProcessingNode();
		virtual ~PostProcessingNode();
	public:
		virtual bool init();
	protected:
		void updateTextureSize();
	private:
		/**
		*	界面纹理
		*/
		Texture2D* _texture = nullptr;
	};
}
