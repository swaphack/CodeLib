#pragma once

#include "CtrlWidget.h"
#include "mathlib.h"
#include "Common/struct/texture_common.h"

namespace render
{
	class Texture2D;
	class Material;
	class Mesh;

	// 帧图片，默认逆时针绘制
	class CtrlFrame : public CtrlWidget
	{
	public:
		CtrlFrame();
		virtual ~CtrlFrame();
	public:
		virtual bool init();
	public:
		// 设置图片纹理
		void setTexture(const Texture2D* texture);
		// 设置图片纹理
		void setTextureWithRect(const Texture2D* texture);
		// 设置要显示的纹理区域
		void setTexRect(const math::Rect& rect);
		// 设置水平翻转
		void setFlipX(bool status);
		// 是否水平翻转
		bool isFlipX();
		// 设置垂直翻转
		void setFlipY(bool status);
		// 是否垂直翻转
		bool isFlipY();
	public:
		Material* getMaterial();
		Mesh* getMesh();
	protected:
		void onTextureChange();

		virtual void drawSampleWithClientArray();
		virtual void initBufferObject();
		virtual void updateBufferData();
	protected:
		// 纹理坐标
		TextureRectVertex _texRect;
		// 是否水平翻转
		bool _bFlipX = false;
		// 是否垂直翻转
		bool _bFlipY = false;
		
	};
}