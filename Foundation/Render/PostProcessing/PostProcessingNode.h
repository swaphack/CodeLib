#pragma once

#include "FrameBufferNode.h"
#include "Common/struct/shape_common.h"
namespace render
{
	class Texture2D;

	/**
	*	֡������ڴ���
	*	��Ҫ���ü��Ӵ�С
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
		*	��������
		*/
		Texture2D* _texture = nullptr;
	};
}
