#pragma once

#include "mathlib.h"
#include "Common/struct/vertex_common.h"
#include "Common/DrawNode/DrawNode2D.h"
#include "Common/DrawNode/DrawProtocol.h"
#include "Common/Texture/TexFrame.h"

namespace render
{
	// 帧图片，默认逆时针绘制
	class DrawTexture2D : 
		public DrawNode2D
	{
	public:
		DrawTexture2D();
		virtual ~DrawTexture2D();
	public:
		virtual bool init();
	public:
		// 混合读取方式，纹理或者纹理碎片
		void loadImage(const std::string& mixFilePath);
		// 根据图片路径加载
		void loadTexture(const std::string& filepath);
		// 根据纹理加载
		void loadTexture(const Texture* texture);
		// 根据碎片范围加载图片
		void loadTexture(const Texture* texture, const sys::TextureChip& chip);
		// 根据碎片名字加载图片
		void loadTextureChip(const std::string& chipname);
		// 设置成纹理大小
		void setNativeTextureSize();
		// 清空纹理
		void cleanTexture();
	public:
		/**
		*	设置纹理坐标
		*/
		void setUV(const math::Rect& rect, const math::Size& size, bool rotate = false);
		/**
		*	设置纹理帧
		*/
		void setTexFrame(const TexFrame* texFrame);
	public:
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
		*	根据纹理更改UV
		*/
		void updateUVWithTexture();
		/**
		*	更新网格数据
		*/
		virtual void updateTexture2DMeshData();
	protected:
		// 是否水平翻转
		bool _bFlipX = false;
		// 是否垂直翻转
		bool _bFlipY = false;
		// 纹理帧
		TexFrame* _texFrame = nullptr;
	};
}
