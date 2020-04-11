#pragma once

#include "Common/Node/ColorNode.h"
#include "Common/struct/texture_common.h"

#include "mathlib.h"

namespace render
{
	class Texture;
	class TexFrame;

	// 帧图片，默认逆时针绘制
	class CtrlFrame : public ColorNode
	{
	public:
		CtrlFrame();
		virtual ~CtrlFrame();
	public:
		virtual bool init();
	protected:
		virtual void drawSample();
	public:
		// 设置图片纹理
		void setTexture(const Texture* texture);
		// 设置图片纹理
		void setTextureWithRect(const Texture* texture);
		// 设置要显示的纹理区域
		void setTexRect(const math::Rect& rect);
		// 设置图片纹理帧
		void setTexFrame(const TexFrame* texFrame);
		// 获取纹理帧
		const TexFrame* getTexFrame();
		// 设置水平翻转
		void setFlipX(bool status);
		// 是否水平翻转
		bool isFlipX();
		// 设置垂直翻转
		void setFlipY(bool status);
		// 是否垂直翻转
		bool isFlipY();
		// 是否顺时针
		bool isCounter();
		// 设置是否顺时针
		void setCounter(bool status);
	protected:
		void onTextureChange();
	protected:
		// 纹理帧
		TexFrame* _texFrame;
		// 纹理坐标
		TextureRectVertex _texRect;
		// 是否水平翻转
		bool _bFlipX;
		// 是否垂直翻转
		bool _bFlipY;
	};
}