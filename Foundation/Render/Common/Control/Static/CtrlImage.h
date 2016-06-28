#pragma once

#include "macros.h"

namespace render
{
	// 2d图片 
	// 默认逆时针绘制
	class CtrlImage : public ColorNode
	{
	public:
		CtrlImage();
		virtual ~CtrlImage();
	public:
		virtual void draw();

		// 设置图片路径
		void setImagePath(const char* path, ImageFormat format = EIF_PNG);
		// 设置图片纹理
		void setTexture(const Texture* texture);
		// 设置要显示的纹理区域
		void setTexRect(sys::Rect rect);
		// 设置图片纹理帧
		void setTexFrame(const TexFrame* texFrame);
		// 获取纹理帧
		const TexFrame* getTexFrame();
		// 设置水平翻转
		void setFlipX(bool status);
		bool isFlipX();
		// 设置垂直翻转
		void setFlipY(bool status);
		bool isFlipY();
	protected:
		virtual void initSelf();
	protected:
		// 图片结构
		Ctrl_ImageDefine _imageDefine;
		// 纹理帧
		TexFrame _texFrame;
		// 纹理坐标
		TextureRect _texRect;
		// 是否水平翻转
		bool _bFlipX;
		// 是否垂直翻转
		bool _bFlipY;
	};
}