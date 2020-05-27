#pragma once

#include "CtrlWidget.h"
#include "mathlib.h"
#include "Common/struct/vertex_common.h"

namespace render
{
	class Texture2D;
	class Materials;
	class Meshes;

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
		// 设置水平翻转
		void setFlipX(bool status);
		// 是否水平翻转
		bool isFlipX();
		// 设置垂直翻转
		void setFlipY(bool status);
		// 是否垂直翻转
		bool isFlipY();
	protected:
		void onTextureChange();
	protected:
		// 顶点坐标信息
		RectVertex _vertexes;
		// 是否水平翻转
		bool _bFlipX = false;
		// 是否垂直翻转
		bool _bFlipY = false;
		
	};
}