#pragma once

#include "Common/DrawNode/DrawNode2D.h"
#include "Common/struct/shape_common.h"

namespace render
{
	class Texture2D;
	/**
	*	���غ��ڴ���
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
		// ���ο�
		RectPoints _rectPoints;
		/**
		*	��������
		*/
		Texture2D* _texture = nullptr;
		/**
		*	��������
		*/
		uint8_t* _textureData = nullptr;
	};
}
