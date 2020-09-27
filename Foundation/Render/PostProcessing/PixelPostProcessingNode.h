#pragma once

#include "Common/DrawNode/DrawNode2D.h"
#include "Common/struct/shape_common.h"

namespace render
{
	class Texture2D;
	/**
	*	像素后期处理
	*/
	class PixelPostProcessingNode : public DrawNode2D
	{
	public:
		PixelPostProcessingNode();
		virtual ~PixelPostProcessingNode();
	public:
		virtual bool init();

		virtual void beforeDrawNode();

		virtual void afterDrawNode();
	protected:
		void updateTextureSize();
	private:
		// 矩形框
		RectPoints _rectPoints;
		/**
		*	界面纹理
		*/
		Texture2D* _texture = nullptr;
		/**
		*	纹理数据
		*/
		uint8_t* _textureData = nullptr;
	};
}
