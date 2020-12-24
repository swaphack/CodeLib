#pragma once

#include "mathlib.h"
#include "Common/struct/vertex_common.h"
#include "Common/DrawNode/DrawNode2D.h"
#include "Common/DrawNode/DrawProtocol.h"

namespace render
{
	// 帧图片，默认逆时针绘制
	class DrawTexture2D : 
		public DrawNode2D,
		public BlendProtocol
	{
	public:
		DrawTexture2D();
		virtual ~DrawTexture2D();
	public:
		virtual bool init();
	public:
		// 设置图片纹理
		void setTextureWithRect(const std::string& filepath);
		// 设置图片纹理
		void setTextureWithRect(const Texture* texture);
		// 设置水平翻转
		void setFlipX(bool status);
		// 是否水平翻转
		bool isFlipX();
		// 设置垂直翻转
		void setFlipY(bool status);
		// 是否垂直翻转
		bool isFlipY();
	protected:
		/**
		*	混合改变
		*/
		virtual void onBlendChange();
	protected:
		virtual void updateTexture2DMeshData();
	protected:
		// 是否水平翻转
		bool _bFlipX = false;
		// 是否垂直翻转
		bool _bFlipY = false;
	};
}
